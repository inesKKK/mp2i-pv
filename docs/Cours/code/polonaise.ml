type operation = Plus | Moins | Fois | Divise
type item = Int of int | Op of operation

let polonaise lst =
  let calcul op x y = match op with
    | Plus -> x + y
    | Moins -> x - y
    | Fois -> x * y
    | Divise -> x / y in
  let rec chopin xs acc = match xs with
    | [] -> acc
    | x :: xs' -> match x with
                  | Int n -> chopin xs' (n::acc)
                  | Op op -> let y :: x :: acc' = acc in
                             chopin xs' (calcul op x y :: acc') in
  chopin lst []


let _ = let [ x ] = polonaise [ Int 15; Int 6; Int 7; Op Plus; Int 4; Op Moins; Op Fois ] in
        print_int x 
          
