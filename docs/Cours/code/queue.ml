type queue = int list * int list

let new_queue = ([], [])
           
let enqueue x (st1, st2) = (x :: st1, st2)
    
let rec dequeue (st1, st2) = match st2 with
  | [] -> if st1 = [] then failwith "file vide"
          else dequeue ([], List.rev st1)
  | hd :: tl -> (hd, (st1, tl))

let rec peek (st1, st2) = match st2 with
  | [] -> if st1 = [] then failwith "file vide"
          else peek ([], List.rev st1)
  | hd :: _ -> (hd, (st1, st2)) 
