type 'a liste = Vide | Maillon of 'a * 'a liste

let lst1 = Maillon(2, Vide) (* similaire à à 2 :: [] *)
let lst2 = Maillon(4, Maillon(1, Vide)) (* similaire à [4; 1] *)

let lst3 = Maillon(2.3, Vide)
let lst4 = Maillon("toto", Maillon("titi", Vide))
         
let vide lst = lst = Vide
        
let rec somme lst = match lst with
  | Vide -> 0
  | Maillon(hd, tl) -> hd + somme tl
