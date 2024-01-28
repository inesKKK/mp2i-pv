let rec que_pairs lst = match lst with
  | [] -> []
  | x :: lst' when x mod 2 = 0 -> x :: que_pairs lst'
  | _ :: lst' -> que_pairs lst'
