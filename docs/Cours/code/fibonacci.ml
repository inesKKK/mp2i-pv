(* exemple en ocaml *)
let rec fibonacci n =
  match n with
  | 0 -> 0
  | 1 -> 1
  | _ -> fibonacci (n-1) + fibonacci (n-2)
