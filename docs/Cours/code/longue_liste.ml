let liste n =
  let rec liste_aux m lst =
    if m = 0 then lst else liste_aux (m-1) (m::lst)
  in liste_aux n []
