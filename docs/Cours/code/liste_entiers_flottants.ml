type donnee = Int of int | Float of float

let rec somme lst =
  match lst with
  | [] -> 0.
  | Int n :: lst' -> float_of_int n +. somme lst'
  | Float x :: lst' -> x +. somme lst'

let _ = somme [Int 3; Float 5.2; Int (-1); Float 3.14];;
