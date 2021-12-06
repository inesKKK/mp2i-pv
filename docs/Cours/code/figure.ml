type point = float * float

type figure =
  | Point of point
  | Cercle of {centre : point; rayon : float}
  | Rectangle of {bas_gauche : point; haut_droite : point}

let aire fig = match fig with
  | Point _ -> 0.
  | Cercle {rayon} -> Float.pi *. (rayon ** 2.)
  | Rectangle {bas_gauche; haut_droite} ->
     let x1, y1 = bas_gauche in
     let x2, y2 = haut_droite in
     (x2 -. x1) *. (y2 -. y1)
                 
let aire2 fig = match fig with
  | Point _ -> 0.
  | Cercle {rayon} -> Float.pi *. (rayon ** 2.)
  | Rectangle {bas_gauche = (x1, y1); haut_droite = (x2, y2)} -> (x2 -. x1) *. (y2 -. y1)


