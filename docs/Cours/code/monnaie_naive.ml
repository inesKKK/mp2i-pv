let rendu montant caisse =
  let rec rend somme k pieces =
    match somme, k with
    | s, -1 when s > 0 -> 666
    | 0, _ -> 0
    | s, _ when s < 0 -> 666
    | _, _ -> min (rend somme (k-1) pieces) (1 + rend (somme - pieces.(k)) k pieces)
  in (Array.sort (fun x y -> y - x) caisse);
     rend montant (Array.length caisse - 1) caisse

let _ = rendu 25 [|10;5;2;1|]
