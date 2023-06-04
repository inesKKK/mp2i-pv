type mat_adj = (bool array) array

let rec chemin (adj : mat_adj) i j len =
  if len = 0 then
       i = j
  else let adj_i = adj.(i) in
       Array.exists (fun k -> adj_i.(k) && chemin adj k j (len-1))
         (Array.init (Array.length adj_i) (fun x -> x) )
