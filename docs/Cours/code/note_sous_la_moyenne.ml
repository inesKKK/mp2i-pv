(* exemple en ocaml *)
let rec note_sous_la_moyenne note = match note with
  | [] -> false
  | n :: suite -> if n<10 then true
                  else note_sous_la_moyenne suite
