(** le maillon d'un liste : valeur + éventuel maillon suivant *)
type 'a maillon = { valeur : 'a; mutable suivant : 'a maillon option }

(** une pile éventuellement vide donnée par son sommet *)
type 'a pile = { mutable sommet : 'a maillon option }

(** vide p est vrai si et seulement si p est vide *)
let vide p = p.sommet = None

(** empile e p est une pile obtenue en empilant l'élément e sur la pile p *)            
let empile e p = p.sommet <- Some { valeur = e; suivant = p.sommet }

(** sommet p renvoie le sommet de la pile s'il existe *)
let sommet p = match p.sommet with
  | None -> failwith "pile vide"
  | Some { valeur } -> valeur

(** depile p depile le sommet de la pile p *)
let depile p = match p.sommet with
  | None -> failwith "pile vide"
  | Some { suivant } -> p.sommet <- suivant

(** vide' () est une pile vide *)
let vide' () = { sommet = None }
            
(** depile' p depile le sommet de la pile p et renvoie la valeur du sommet s'il y a lieu *)
let depile' p = match p.sommet with
  | None -> failwith "pile vide"
  | Some { valeur; suivant } -> p.sommet <- suivant; valeur
