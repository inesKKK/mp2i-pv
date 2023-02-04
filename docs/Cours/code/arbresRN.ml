type color = Red | Black

(** arbre rouge-noir : ABR + conditions sur les arbres rouge-noir *)
type 'a rbtree = Leaf | Node of ( color * 'a * 'a rbtree * 'a rbtree )

let ex1 = Node (Black, 3, Leaf, Leaf)

let string_of_color = function
  | Red -> "fill=red!50"
  | Black -> "white,fill=black!70"
        
let string_of_rbtree t =
  let rec forest = function
    | Leaf -> " [] "
    | Node (c, x, l, r) -> " [ " ^ (string_of_int x) ^ "," ^ (string_of_color c)
                           ^ (forest l) ^ (forest r) ^ "] "
  in "\\begin{forest}\n" ^ (forest t) ^ "\n\\end{forest}\n"

let empty = Leaf
                       
(** mem x t est vrai si et seulement si la valeur x apparaît dans t *)
let rec mem x = function
  | Leaf -> false
  | Node (_, y, l, r) -> x = y || mem x (if x<y then l else r)

(** fait les rotations nécessaires après la phase d'insertion correspondant à un ABR *)
let balance = function
  | (Black, z, Node (Red, y, Node (Red, x, a, b), c), d)
  | (Black, z, Node (Red, x, a, Node (Red, y, b, c)), d)
  | (Black, x, a, Node (Red, z, Node (Red, y, b, c), d))
  | (Black, x, a, Node (Red, y, b, Node (Red, z, c, d)))
    -> Node (Red, y, Node (Black, x, a, b), Node (Black, z, c, d))
  | t -> Node t

(** insert x t effectue l'insertion de x dans l'arbre rouge-noir t, en respectant les
conditions pour conserver un arbre rouge-noir *)       
let rec insert_aux x t = match t with
  | Leaf -> Node (Red, x, Leaf, Leaf)
  | Node (_, y, _, _) when y = x -> t
  | Node (c, y, l, r) -> if x < y then balance (c, y, insert_aux x l, r)
                         else balance (c, y, l, insert_aux x r)

let insert x t =
  match insert_aux x t with
  | Leaf -> failwith "impossible"
  | Node (_, y, l, r) -> Node (Black, y, l, r)
(* au cas où ce serait nécessaire, si ça ne l'est pas ça reste possible *)
                       
let rbtree_of_list lst =
  let rec of_list acc = function
    | [] -> acc
    | hd :: tl -> of_list (insert hd acc) tl
  in of_list empty lst
      
let _ = let ex2 = rbtree_of_list [1;2;3;4;5;6;8;9;10;11] in
        print_string (string_of_rbtree ex2)
