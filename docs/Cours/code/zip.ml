let rec zip lst1 lst2 =
  match lst1, lst2 with
  | [], _ | _, [] -> []
  | x1 :: lst1', x2 :: lst2' -> (x1, x2) :: zip lst1' lst2'
