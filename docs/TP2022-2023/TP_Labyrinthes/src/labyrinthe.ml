let affichage_sortie fichier =
  let largeur, hauteur, g = lecture_labyrinthe fichier in
  let chemin = List.of_seq (Stack.to_seq (sortir g)) in
  print_char '+';
  for i = 1 to 2*largeur-1 do
    print_char '-'
  done;
  print_endline "+";
  for i = 0 to hauteur - 1 do
    (* murs verticaux *)
    print_char '|';
    for j = 0 to largeur - 1 do
      let k = i * largeur + j in
      if List.mem k chemin then print_char '*' else print_char ' ';
      if k mod largeur = largeur - 1 then print_endline "|"  (* bord droit *)
      else if not (List.mem (k+1) g.adj.(k))
      then print_char '|' else print_char ' ';
    done;
    (* murs horizontaux *)
    print_char '+';
    for j = 0 to largeur - 1 do
      let k = i * largeur + j in
      if List.mem (k+largeur) g.adj.(k) then print_char ' ' else print_char '-';
      if k mod largeur = largeur - 1 then print_endline "+"  (* bord droit *)
      else print_char '-';
    done;
  done
