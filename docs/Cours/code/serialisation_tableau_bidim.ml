let sauvegarde t fichier =
  let haut = Array.length t in
  let larg = Array.length t.(0) in
  let f = open_out fichier in
  output_string f (string_of_int haut ^ "\n");
  output_string f (string_of_int larg ^ "\n");
  for i = 0 to haut - 1 do
    for j = 0 to larg - 1 do
      output_string f (string_of_int t.(i).(j) ^ ";")
    done;
    output_string f "\n"
  done;
  close_out f


let chargement fichier =
  let set t i j = function
    | [] -> failwith "probleme de format"
    | hd :: tl -> t.(i).(j) <- (int_of_string hd); tl in
  let f = open_in fichier in
  let haut = int_of_string (input_line f) in
  let larg = int_of_string (input_line f) in
  let t = Array.init haut (Array.make larg) in
  for i = 0 to haut - 1 do
    let ligne = ref (String.split_on_char ';' (input_line f)) in
    for j = 0 to larg - 1 do
      ligne := set t i j !ligne
    done
  done;
  close_in f; t
  
let () = let t = [| [| 1;2 |] ; [| 3;4 |] ; [| 5;6 |] |] in
         sauvegarde t "toto2"

let () = sauvegarde (chargement "toto2") "titi2"
