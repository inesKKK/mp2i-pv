open Images


let hsv_of_rgb (r, g, b) =
  let rf = float_of_int r /. 255. in
  let gf = float_of_int g /. 255. in
  let bf = float_of_int b /. 255. in
  let cmax = max (max rf gf) bf in
  let cmin = min (min rf gf) bf in
  let diff = cmax -. cmin in
  let h = if cmax = cmin then 0.
          else if cmax = rf then mod_float (60. *. ((gf -. bf) /. diff) +. 360.) 360.
          else if cmax = gf then mod_float (60. *. ((bf -. rf) /. diff) +. 120.) 360.
          else mod_float (60. *. ((rf -. gf) /. diff) +. 240.) 360. in
  let s = if cmax = 0. then 0. else (diff /. cmax) *. 100. in
  let v = cmax *. 100. in
  (h, s, v)
   
let voisin img (x,y) (x',y') =
  let rouge pixel =
    (* pixel.(0) > (pixel.(1)+pixel.(2))/2 *)
    let h, _, _ = hsv_of_rgb (pixel.(0), pixel.(1), pixel.(2)) in
    print_float h; print_string " ";
    h < 100. || h > 260. in
(*  let rouge pixel =
    pixel.(0) > (pixel.(1)+pixel.(2))/2 in *)
  rouge img.pix.(x).(y) && rouge img.pix.(x').(y')

let voisins img (x,y) =
  let a_cote = List.filter (fun (x',y') -> (x'>=0 && x'<Array.length img.pix &&
              y'>=0 && y'<Array.length img.pix.(0))) [(x+1, y); (x-1, y); (x, y+1); (x, y-1)] in
  List.filter (voisin img (x,y)) a_cote
  
let rec ajoute_sommets file = function
  | (x,y) :: suite -> Queue.add (x, y) file; ajoute_sommets file suite
  | [] -> ()
  
let composante_connexe img (x0,y0) =
  let haut = Array.length img.pix in
  let larg = Array.length img.pix.(0) in
  let cc = Array.make (haut * larg) false in
  let file = Queue.create () in
  Queue.add (x0,y0) file;
  while not (Queue.is_empty file) do
    let (x, y) = Queue.take file in
    if not cc.(x*larg + y) then
      ( cc.(x*larg + y) <- true;
        ajoute_sommets file (voisins img (x,y)) )
  done;
  cc


let modif_coul img (x, y) =
  let couleurs = img.pix.(x).(y) in
  let vert = couleurs.(1) in
  let bleu = couleurs.(2) in
  img.pix.(x).(y).(0) <- (vert + bleu) / 2
  
let enlever_yeux_rouges img cc =
  let larg = Array.length img.pix.(0) in 
  for k = 0 to (Array.length cc - 1) do
    if cc.(k) then
      let x = k / larg in
      let y = k mod larg in
      modif_coul img (x,y)
  done
  
let _ =
  let img = charger_image "photos/photo2.ppm" in
  (*  let cc = composante_connexe img (672, 427) in *)
  let cc = composante_connexe img (389, 217) in
  enlever_yeux_rouges img cc;
  let cc = composante_connexe img (380, 364) in
  (*  let cc = composante_connexe img (648, 1548) in *)
  enlever_yeux_rouges img cc;
  sauvegarder_image img "test.ppm"
