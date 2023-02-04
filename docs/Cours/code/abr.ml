type 'a abr = Nil | ABR of 'a abr * 'a * 'a abr

let rec insertion x a = match a with
  | Nil -> ABR(Nil, x, Nil)
  | ABR(_, y, _) when y = x -> a
  | ABR(g, y, d) -> if x < y then ABR (insertion x g, y, d)
                    else ABR (g, y, insertion x d)
                            
let rec creation = function
  | [] -> Nil
  | x :: xs -> insertion x (creation xs)

                 
let rec min = function
  | Nil -> None
  | ABR (Nil, x, _) -> Some x
  | ABR (g, _, _) -> min g

let rec max = function
  | Nil -> None
  | ABR (_, x, Nil) -> Some x
  | ABR (_, _, d) -> max d

let denoyauter o = match o with
   | None -> failwith "None"
   | Some v -> v
                   
let rec contient x = function
  | Nil -> false
  | ABR (_, y, _) when x = y -> true
  | ABR (g, y, d) -> contient x (if x<y then g else d)

let rec suppression x = function
  | Nil -> Nil
  | ABR (g, y, d) when x = y ->
     begin match g, d with
     | Nil, Nil -> Nil
     | e, Nil | Nil, e -> e
     | _, _ -> let s = denoyauter (min d) in
            ABR (g, s, suppression s d)
     end
  | ABR (g, y, d) -> if x<y then ABR (suppression x g, y, d)
                     else ABR (g, y, suppression x d)
