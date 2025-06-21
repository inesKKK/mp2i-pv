(* ligne de compilation : ocamlopt graphics.cmxa souris.ml *)
(* #use "topfind";;
 * #require "graphics";; *)

open Graphics;;

let test () =
    open_graph " 1500x800";
    set_color cyan;
    fill_rect 300 200 30 30;
    set_color green;
    let rec attendre () =      
      let s = wait_next_event [Button_down] in
      let sx = s.mouse_x and sy = s.mouse_y in
      if sx >= 300 && sx <= 330 && sy >= 200 && sy <= 230 then
        close_graph ()
      else (fill_rect sx sy 30 30; attendre ()) in
    attendre ();;
       
let () = test ()
