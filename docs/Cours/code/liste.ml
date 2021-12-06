type liste = Vide | Maillon of int * liste

let lst1 = Maillon (2, Vide) (* similaire à 2 :: [] *)
let lst2 = Maillon (4, Maillon(1, Vide)) (* similaire à [4; 1] *)

let vide lst = lst = Vide
        
let rec somme lst = match lst with
  | Vide -> 0
  | Maillon (hd, tl) -> hd + somme tl
