(* représentation d'un graphe par liste d'adjacence, les sommets sont supposés
être les premiers entiers naturels *)
type graphe = {
    entree : int;
    sortie : int;
    adj : int list array
  }


let graphe0 = {
    entree = 4;
    sortie = 1;
    adj = [| []; [2;4]; [3;2;8]; [1]; [5]; [2]; [7]; [6]; [9]; []; [1] |]
  }

let graphe1 = {graphe0 with sortie=9};;
