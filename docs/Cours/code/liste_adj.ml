type graphe = int list array

let degre_sortant lst s =
  List.length lst.(s)

(** pre-condition : l'arc s->t n'est pas présent *)
let ajout_arc lst s t =
  lst.(s) <- t :: lst.(s);
  lst

let suppression_arc lst s t =
  let rec supprimer t = function
    | [] -> []
    | x :: xs -> if x = t then xs else x :: (supprimer t xs) in
  lst.(s) <- supprimer t lst.(s);
  lst
  
let _ =
  let g : graphe = [| [1;2]; [0]; [0]; [] |] in
  degre_sortant g 0
