(** affiche texte espaces affiche le texte en insérant des espaces aux emplacements donnés *)
let rec affiche texte espaces fin =
  match espaces with
  | [] -> print_string (String.sub texte 0 fin ^ " ") 
  | debut :: suite ->
     affiche texte suite debut;
     print_string (String.sub texte debut (fin-debut) ^ " ")


let decoupage texte dico =
  let rec decoupe texte dico debut espaces =
    if debut = String.length texte
    then
      begin
        affiche texte espaces (String.length texte);
        print_endline "***"
      end
    else
      begin
        for fin = debut to String.length texte - 1 do
          let prefixe = String.sub texte debut (fin - debut + 1) in
          if Array.exists (fun x -> x = prefixe) dico
          then
            begin
              decoupe texte dico (fin+1) ((fin+1) :: espaces)
            end
        done;
      end
  in decoupe texte dico 0 []

    
let _ =
  let texte = "celama" in
  let dico = [| "ce"; "cela"; "lama"; "m"; "a" |] in
  decoupage texte dico
 


             (* let _ = let texte = "abcdefg" in affiche texte [5;2;1] (String.length texte) *)
  
