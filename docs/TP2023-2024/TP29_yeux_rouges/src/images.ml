type couleur = int array
type image = {
    max : int;
    pix : couleur array array
  }

let noir : couleur = [|0;0;0|]
           
(** lecture image PPM P3 sans commentaires *)
let charger_image fichier =
  let file = open_in fichier in
  let _ = input_line file in
  let dim = Array.of_list (List.map int_of_string (String.split_on_char ' ' (input_line file)) ) in
  let haut = dim.(1) in
  let larg = dim.(0) in
  let mmm = int_of_string (input_line file) in
  let img = { max = mmm; pix = (Array.init haut) (fun i -> Array.init larg (fun j -> [|0;0;0|])) } in
  let i = ref 0 in
  let j = ref 0 in
  let c = ref 0 in
  try
    while true do
      let line = input_line file in
      let not_empty = List.filter (fun x-> String.length x > 0) (String.split_on_char ' ' line) in
      let coeffs = Array.of_list (List.map int_of_string not_empty) in
      for k = 0 to (Array.length coeffs) - 1 do
        img.pix.(!i).(!j).(!c) <- coeffs.(k);
        if !c <> 2 then
          incr c
        else ( c := 0;
               if !j = larg - 1 then
                 ( j := 0; incr i )
               else incr j
             )
      done
    done;
    close_in file;
    img
  with End_of_file -> close_in file; img
  

let sauvegarder_image img fichier =
  let file = open_out fichier in
  let larg = Array.length img.pix in
  let haut = Array.length img.pix.(0) in
  output_string file ("P3\n" ^ (string_of_int haut) ^ " " ^ (string_of_int larg) ^ "\n");
  output_string file (string_of_int img.max ^ "\n");
  for i = 0 to larg-1 do
    for j = 0 to haut-1 do
      for c = 0 to 2 do
        output_string file (string_of_int (img.pix.(i).(j).(c)) ^ " ")
      done
    done;
    output_string file "\n"
  done;
  close_out file
