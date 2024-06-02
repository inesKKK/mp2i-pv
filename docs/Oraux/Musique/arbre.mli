type arbre =
  | Leaf of Musique.note
  | Node of arbre * arbre

val creer_feuille : Musique.note -> arbre

val fusion_arbres : arbre -> arbre -> arbre
