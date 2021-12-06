(** entree : n >= 0 *)
let rec pair n =
  n = 0 || odd (n - 1)
and impair n =
  n <> 0 && pair (n - 1);; 
