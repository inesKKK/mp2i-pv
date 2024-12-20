(* (abscisse, ordonnee) *)
type point = int * int

(* maximum lst est le plus grand élément de lst
maximum [] vaut 0
pré-condition: les éléments de lst sont positifs *)
val maximum : int list -> int

(* liste_points abs ords est la liste des points dont la première abscisse est abs et
les ordonnees sont donnees par ords, dans l'ordre decroissant des ordonnées *)
val liste_points : int -> int list -> point list

(* affiche les points en ascii art, avec espace pour les pixel blancs et x pour les pixels noirs *)
val affiche : int -> int list -> unit
