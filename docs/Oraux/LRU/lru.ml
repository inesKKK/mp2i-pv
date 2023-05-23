type lru = {
    liste : liste_chainee;
    hachage : (int, string * maillon option) Hashtbl.t;
    mmu : int -> string;
    mutable longueur : int;
    capacite : int;
  }

(* exemple de fonction pour le champ mmu du type lru *)
let chiffre = function
  | 0 -> "zero"
  | 1 -> "un"
  | 2 -> "deux"
  | 3 -> "trois"
  | 4 -> "quatre"
  | 5 -> "cinq"
  | 6 -> "six"
  | 7 -> "sept"
  | 8 -> "huit"
  | 9 -> "neuf"
  | _ -> failwith "pas un chiffre"
