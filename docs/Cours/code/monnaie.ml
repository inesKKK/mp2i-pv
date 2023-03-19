let rendu montant caisse =
  let unwrap = function
    | None -> failwith "impossible"
    | Some x -> x in
  let rendus = Array.make_matrix (montant+1) (Array.length caisse) None in
  let rec rend somme k pieces =
    match somme, k with
    | s, -1 when s > 0 -> 666
    | 0, _ -> 0
    | s, _ when s < 0 -> 666
    | _, _ -> if rendus.(somme).(k) = None
              then rendus.(somme).(k) <- Some (min
                                         (rend somme (k-1) pieces)
                                         (1 + rend (somme - pieces.(k)) k pieces) );
              unwrap rendus.(somme).(k)
  in (Array.sort (fun x y -> y - x) caisse);
     rend montant (Array.length caisse - 1) caisse

let _ = print_int (rendu 25 [|10;5;2;1|])
