let rec zip2 lst1 lst2 =
  match lst1, lst2 with
  | [], [] -> []
  | [], x2 :: lst2' -> (None, Some x2) :: zip2 [] lst2'
  | x1 :: lst1', [] -> (Some x1, None) :: zip2 lst1' []
  | x1 :: lst1', x2 :: lst2' -> (Some x1, Some x2) :: zip2 lst1' lst2'
