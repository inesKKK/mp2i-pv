(* exemple en ocaml *)
let rec plus_grande_puissance_de_2 n =
  if n mod 2 != 0
  then 0
  else 1 + plus_grande_puissance_de_2 (n/2)
