let rec nieme n a b u0 = match n with
  | 0 -> u0
  | _ -> nieme (n - 1) a b (a *. u0 +. b)
let u5 = nieme 5 2. 1. 1.
  and u10 = nieme 10 2. 1. 1.
