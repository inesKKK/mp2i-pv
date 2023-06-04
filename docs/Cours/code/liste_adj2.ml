type graphe = int array array

let predecesseurs (g : graphe) s =
  let pred = List.filter (fun r -> Array.mem s g.(r))
               (List.init (Array.length g) (fun x->x)) in
  Array.of_list pred

let g = [| [|1;3|]; [|1;2;7|];  [|0|];  [|4|];  [|1|];  [|6|];
           [|5|];  [|8|];  [||];  [|0|] |]
    in predecesseurs g 1
