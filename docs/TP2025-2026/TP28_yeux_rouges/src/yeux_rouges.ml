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
