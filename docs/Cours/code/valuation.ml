type formule = Proposition of string
             | Non of formule
             | Et of formule * formule
             | Ou of formule * formule

exception Pas_de_valuation of string
                   
let rec evaluation valuations = function
  | Proposition p -> begin
      try List.assoc p valuations with Not_found -> raise (Pas_de_valuation p)
    end
  | Non f -> not (evaluation valuations f)
  | Et (f, g) -> (evaluation valuations f) && (evaluation valuations g)
  | Ou (f, g) -> (evaluation valuations f) || (evaluation valuations g)

let _ = let formule = Ou ( Et ( Proposition "p", Proposition "q"),
                           Non ( Proposition "r" ) ) in
        let valuations = [ ("p", true); ("q", true); ("r", false) ] in
        evaluation valuations formule
