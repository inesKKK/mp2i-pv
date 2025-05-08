open Graphics

type instruction = AV of int | TD of int | TG of int | RP of int * programme
and programme = instruction list

exception Fin_bloc

(** applique x y alpha prog applique le programme prog
à partir de la position (x, y) avec l'angle courant alpha,
et met à jour les contenus de x, y et alpha *)
let rec applique x y alpha = function
  | [] -> ()
  | AV n :: suite ->
     x := !x +. (float_of_int n) *. (cos (!alpha *. 3.14 /. 180.));
     y := !y +. (float_of_int n) *. (sin (!alpha *. 3.14 /. 180.));
     (* translation de n pas dans  la direction alpha *)
     lineto (int_of_float !x) (int_of_float !y);
     applique x y alpha suite
  | TD n :: suite ->
     (* rotation de n degrés à droite *)
     alpha := !alpha -. (float_of_int n);
     applique x y alpha suite
  | TG n :: suite ->
     (* rotation de n degrés à gauche *)
     alpha := !alpha +. (float_of_int n);
     applique x y alpha suite
  | RP (n, bloc) :: suite ->
     begin
       (* exécution d'une boucle *)
       for i = 1 to n do
         applique x y alpha bloc 
       done;
       applique x y alpha suite
     end
         
(** dessin prog ouvre la fenêtre graphique si elle n'est pas ouverte, et
 y représente le dessin décrit par prog *)
let dessin prog =
  open_graph "";
  resize_window 900 600;
  moveto (size_x () / 2) (size_y () / 2);
  let x = ref (float_of_int (current_x ())) in
  let y = ref (float_of_int (current_y ())) in
  let alpha = ref 0. in
  applique x y alpha prog

(* pour que l'affichage ne se ferme pas tout seul en mode interactif
pris sur https://stackoverflow.com/questions/36263152/simple-ocaml-graphics-progam-that-close-before-its-window-is-displayed *)
let rec interactive () =
  let event = wait_next_event [Key_pressed] in
  if event.key == 'q' then exit 0
  else print_char event.key; print_newline (); interactive ()

(** l'exemple de l'énoncé *)
let exemple = [AV 57; TG 90; RP (5, [ AV 100; RP (360, [AV 1; TD 1]); TD 300]) ]

let _ = dessin exemple; interactive ()
                                                 
