type arbre = Nil | Noeud of int * arbre * arbre

let sauvegarde a f =
  let rec sauve a file =
    match a with
    | Nil -> output_string file "-1 "
    | Noeud (v, g, d) -> output_string file (string_of_int v ^ " ");
                         sauve g file;
                         sauve d file in
  let file = open_out f in
  sauve a file;
  close_out file


let chargement f =
  let rec charge lst file =
    let lst = if lst <> [] then lst else String.split_on_char ' ' (input_line file) in
    match lst with
    | [] -> failwith "probleme de format"
    | n :: lst' -> if n = "-1" then (Nil, lst)
                   else let g, lst2 = charge lst' file in
                        let d, lst3 = charge lst2 file
                        in (Noeud(int_of_string n, g, d), lst3) in
  let file = open_in f in
  let a = charge [] file in
  close_in file; a
          

let _ = let a = Noeud( 3, Noeud(5, Nil, Noeud(11, Nil, Nil)),
                                Noeud(43, Noeud(35, Nil, Nil), Nil) ) in
        sauvegarde a "toto"
