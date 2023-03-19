let fraction_egyptienne p q =
  let rec egypt p q lst =
    if q mod p = 0 then (q/p) :: lst
    else let k = q / p + 1 in
         let p' = p*k - q in
         let q' = k*q in
         egypt p' q' (k :: lst) 
  in egypt p q []


   
let _ = List.iter (fun x -> print_string "1/"; print_int x; print_string " + ")
          (fraction_egyptienne 12 13)
