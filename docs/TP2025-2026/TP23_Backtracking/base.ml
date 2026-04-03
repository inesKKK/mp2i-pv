type plateau = int array array
type case = int * int
type coup = case * int  (* ((i, j), k) : on joue k en case (i, j) *)
type final = Gagne | Perdu | PasFini
          
type 'a jeu = {
    plateau : plateau;
    prochains : 'a jeu -> coup list;
    premiere_case_libre : int * int;
    fini : 'a jeu -> final; (* teste si on est dans un position finale *)
    affiche : 'a jeu -> unit; (* affiche le plateau *)
    place : 'a jeu -> coup -> 'a jeu; (* renvoie un nouveau joue en simulant le coup *)
    complement : 'a; (* si jamais on a besoin d'autre chose *)
  }
