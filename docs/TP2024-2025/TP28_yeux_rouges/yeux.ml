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
   
let rouge pixel =
  let h, s, _ = hsv_of_rgb (pixel.(0), pixel.(1), pixel.(2)) in
   30.<s && s<325. && ( h < 40. || h > 320. ) 

  
let composante_connexe img x y =
  let haut = Array.length img.pix in
  let larg = Array.length img.pix.(0) in
  let file = Queue.create () in
  Queue.add (x, y) file;
  let cc = Array.make (haut * larg) false in
  cc.(x*larg + y) <- true;
  while not (Queue.is_empty file) do
    let x, y = Queue.take file in
    for d = -1 to 1 do
      let x' = x+d in
      if x'>=0 && x'<haut
         && not cc.(x'*larg+y) && rouge img.pix.(x').(y) then
        ( cc.(x'*larg+y) <- true;
          Queue.add (x', y) file );
      let y' = y+d in
      if y'>=0 && y'<larg
         && not cc.(x*larg+y') && rouge img.pix.(x).(y') then
        ( cc.(x*larg+y') <- true;
          Queue.add (x, y') file )
    done;
  done;
  cc
  

let modif_coul img x y =
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
      modif_coul img x y
  done
  
let _ =
(*  let img = charger_image "photos/photo1.ppm" in
  let cc = composante_connexe img 672 427 in *)
  let img = charger_image "photos/photo2.ppm" in
  let cc = composante_connexe img 389 217 in
  print_endline "fin calcul composante connexe";
  enlever_yeux_rouges img cc;
  let cc = composante_connexe img 380 364 in
  print_endline "fin calcul composante connexe";
  enlever_yeux_rouges img cc;
  sauvegarder_image img "test.ppm"
          
