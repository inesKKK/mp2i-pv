(** compte n est n, calculé en ajoutant 1 à lui-même n fois: la
    fonction compte de 1 à n. *)
let rec compte n =
  if n = 0 then 0 else 1 + compte (n - 1)
