type arbre =
  | Leaf of Musique.note
  | Node of arbre * arbre

let creer_feuille note =
  Leaf (note)

let fusion_arbres a1 a2 =
  Node (a1, a2)
