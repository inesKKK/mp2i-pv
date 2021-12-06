let rec compte_aux n acc =
  if n = 0 then acc else compte_aux (n - 1) (acc + 1)

let compte_rt n = compte_aux n 0
