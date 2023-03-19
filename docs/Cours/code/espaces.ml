exception Decoupable
            
let decoupable texte dico =
  let rec decoupe texte dico debut =
    if debut = String.length texte then true
    else
      begin
        try
          for fin = debut to String.length texte - 1 do
            let prefixe = String.sub texte debut (fin - debut + 1) in
            if Array.exists (fun x -> x = prefixe) dico
            then
              begin
                if decoupe texte dico (fin+1)
                then raise Decoupable
              end
          done;
          false
        with
        | Decoupable -> true
      end
  in decoupe texte dico 0

  
let dico = [| "ce"; "cela"; "lama"; "m"; "a" |]
  
let _ = let a = decoupable "celada" dico in
        if a then print_endline "decoupable" else print_endline "non"
