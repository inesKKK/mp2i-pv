(* Les 2 lignes suivantes sont à décommenter pour les versions
   récentes de OCaml. *)
(* #use "topfind";;
#require "graphics";; *)

(* La ligne suivante est à décommenter pour les anciennes 
   versions de WinCaml *)
(* #load "graphics.cma";; *)

(* Le code suivant permet d'afficher une image : la fonction prend
   en argument une image (au sens du type défini précédemment) et un
   entier (correspondant à une taille de pixel) et affiche l'image
   dans une fenêtre graphique. *)

open Graphics;;

let afficher im pixel =
    let h, l = Array.length im, Array.length im.(0) in
    open_graph "";
    for lgn = 0 to h - 1 do
        for col = 0 to l - 1 do
            let c = im.(lgn).(col) in
            set_color (rgb c c c);
            fill_rect (pixel * col) (pixel * (h - lgn - 1)) pixel pixel;
        done
    done;;

(* Le code suivant permet de lire une image PNG et de la transformer
   en matrice correspondant à cette image en niveaux de gris. On pourra
   l'utiliser pour tester de nouvelles images 28 × 28 si on le souhaite
   (attention, il faut que camlimages soit installé, donc ça risque de ne
   pas marcher avec WinCaml) *)

(*
#use "topfind";;
#require "camlimages.png";; *)

let niveau_de_gris r g b = 
    (2126*r + 7152*g + 722*b)/10000;;

let lire_image fichier =
    (* fichier est une chaîne de caractères correspondant au nom de l'image
       à lire (au format png) *)
    let Images.Rgb24 im = Png.load_as_rgb24 (chemin^fichier) [] in
    let h = im.height and l = im.width in
    let s = Rgb24.dump im in
    let image = Array.make_matrix h l 0 in
    for lgn = 0 to h - 1 do
        for col = 0 to l - 1 do
            let i = 3 * (lgn * l + col) in
            let r = Bytes.get_uint8 s i 
            and g = Bytes.get_uint8 s (i + 1) 
            and b = Bytes.get_uint8 s (i + 2) in
            image.(lgn).(col) <-  niveau_de_gris r g b
        done
    done;
    image;;
