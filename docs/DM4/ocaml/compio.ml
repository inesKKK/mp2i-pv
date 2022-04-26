type h_out_channel = {
    f : out_channel;
    mutable tampon : int;  (* le début du prochain caractère à écrire ou à lire *)
    mutable ou : int           (* où on en est pour l'écriture *)
  }

type h_in_channel = {
    f : in_channel;
    mutable tampon : int;  (* le début du prochain caractère à écrire ou à lire *)
    mutable ou : int           (* à partir d'où on ne lit plus *)
  }
   
let vide = 0
let debut = 7
let fin = (-1)
let masque = 255
          
(** ouverture d'un flux en écriture *)
let h_open_out pathname : h_out_channel =
  { f = open_out_bin pathname; tampon = vide; ou = debut }

(** ouverture d'un flux en lecture *)
let h_open_in pathname : h_in_channel =
  { f = open_in_bin pathname; tampon = vide; ou = debut }

(** écriture de la chaîne s supposée composée uniquement de 0 et de 1 dans
le flux stream, sous forme de suite de bits *)
let h_write (stream : h_out_channel) (s : string) =
  let n = ref 0 in
  while !n < String.length s do
    if stream.ou = fin
    then begin
        output_byte stream.f stream.tampon;
        stream.tampon <- vide;
        stream.ou <- debut
      end;
    if s.[!n] = '1' then stream.tampon <- stream.tampon lor (1 lsl stream.ou);
    stream.ou <- stream.ou - 1;
    incr n;
  done

(** lecture d'un bit dans le flux stream, résultat nul si bit à 0, non nul sinon *)
let h_read_bit (stream : h_in_channel) =
  if stream.ou = debut
  then begin
      stream.tampon <- input_byte stream.f;
      stream.ou <- debut
    end;
  let res = stream.tampon land (1 lsl debut) in
  stream.tampon <- (stream.tampon * 2) land masque;
  stream.ou <- stream.ou + 1;
  res

(** lecture de 8 bits dans le flux stream *)
let h_read_byte (stream : h_in_channel) =
  let res = ref stream.tampon in
  let ou = stream.ou in
  stream.tampon <- input_byte stream.f;
  stream.ou <- fin;
  res := !res lor (stream.tampon lsr (debut - ou));
  stream.tampon <- (stream.tampon lsl (ou + 1)) land masque;
  stream.ou <- ou;
  !res
  
(** fermeture d'un flux en écriture, le tampon d'écriture est vidé *)
let h_close_out (stream : h_out_channel) =
  output_byte stream.f stream.tampon;
  close_out stream.f

(** fermeture d'un flux en lecture *)
let h_close_in (stream : h_in_channel) =
  close_in stream.f

let _ =
  (* let h = h_open_out "toto" in
   * h_write h "01100001101100100";
   * h_close_out h *)
  let h = h_open_in "toto" in
  print_char (char_of_int (h_read_byte h));
  ignore (h_read_bit h);
  print_char (char_of_int (h_read_byte h)); 
  h_close_in h
