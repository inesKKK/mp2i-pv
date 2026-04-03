open Base

type carre = bool array jeu (* case i à true si i deja placé *)

exception Incorrect

(* tous les entiers de 1 à n² sont présents une et une seule fois *)
let tous_presents carre =
  let p = carre.plateau in
  let n = Array.length p in
  let t = Array.make (n*n) false in
  try
    for i = 0 to Array.length p - 1 do
      for j = 0 to Array.length p.(i) - 1 do
        if t.(i+j*n) = false then t.(i+j*n) <- true else raise Incorrect
      done
    done; true
  with Incorrect -> false

(* les lignes pleines somment à ce qu'il faut *)
let lignes_pleines_correctes carre =
  let p = carre.plateau in
  let n = Array.length p in
  let s = (n*(n*n+1))/2 in
  let li, _ = carre.premiere_case_libre in
  try
    for i = 0 to li - 1 do
      if Array.fold_left (+) 0 p.(i) <> s then raise Incorrect
    done; true
  with Incorrect -> false
                  

(* les colonnes pleines somment à ce qu'il faut *)
let colonnes_pleines_correctes carre =
  let li, lj = carre.premiere_case_libre in
  let p = carre.plateau in
  let n = Array.length p in
  if li < n - 1 then true else
    let s = (n*(n*n+1))/2 in
    try
      for i = 0 to lj - 1 do
        let t = Array.init n (fun k -> p.(k).(i)) in
        if Array.fold_left (+) 0 t <> s then raise Incorrect
      done; true
    with Incorrect -> false
                  

(* les diagonales somment à ce qu'il faut *)
let diagonales_correctes carre =
  let p = carre.plateau in
  let n = Array.length p in
  let s = (n*(n*n+1))/2 in
  let d1 = Array.init n (fun k -> p.(k).(k)) in
  let d2 = Array.init n (fun k -> p.(k).(n-1-k)) in
  Array.fold_left (+) 0 d1 = s && Array.fold_left (+) 0 d2 = s
                  
(* rempli correctement *)     
let gagne carre =
  tous_presents carre && lignes_pleines_correctes carre
  && colonnes_pleines_correctes carre && diagonales_correctes carre

(* on ne peut plus jouer *)
let fini_carre_magique carre =
  let p = carre.plateau in
  let c = carre.premiere_case_libre in
  if c <> (Array.length p, 0) (* il reste des cases à remplir *)
  then if (lignes_pleines_correctes carre && colonnes_pleines_correctes carre)
       then PasFini
       else Perdu
  else if (gagne carre) then Gagne else Perdu


(** p : état actuel du plateau
c : dernière case jouée *)
let prochains_carre_magique carre =
  let p = carre.plateau in
  let n = Array.length p in
  let s = (n*(n*n+1))/2 in
  let i, j = carre.premiere_case_libre in
  if (i, j) = (n-1, n) then raise Incorrect
  else
    let debut_ligne = Array.init j (fun k -> p.(i).(k))
                    |> Array.fold_left (+) 0 in
    let t = carre.complement in
       Array.init (Array.length t) (fun k -> k) |> Array.to_list
       |> List.filter (fun k -> not t.(k) && debut_ligne + k <= s)
       |> List.map (fun k -> ((i, j), k))
  
let affiche_carre_magique carre =
  carre.plateau
  |> Array.iter (fun t -> Array.iter (fun x -> print_int x; print_char ' ') t;
                          print_newline ());
  print_newline ()

let place_carre_magique carre ((i, j), v) =
  let n = Array.length carre.plateau in
  let carre' =
    { plateau = Array.init n (fun i -> Array.copy carre.plateau.(i));
      prochains = carre.prochains;
      fini = carre.fini;
      complement = Array.copy carre.complement;
      premiere_case_libre = if j+1 = n then (i+1, 0) else (i, j+1);
      affiche = carre.affiche;
      place = carre.place;
    } in
  carre'.plateau.(i).(j) <- v;
  carre'.complement.(v) <- true;
  carre'

let init_carre n : carre =
  let carre = {
      plateau = Array.make_matrix n n (-1);
      prochains = prochains_carre_magique;
      fini = fini_carre_magique;
      complement = Array.make (n*n+1) false;
      premiere_case_libre = (0, 0);
      affiche = affiche_carre_magique;
      place = place_carre_magique;
    } in
  carre.complement.(0) <- true;
  carre
