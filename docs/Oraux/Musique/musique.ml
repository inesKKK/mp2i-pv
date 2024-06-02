type note =
  | Do
  | Re
  | Mi
  | Fa
  | Sol
  | La
  | Si

let note_vers_chaine = function
  | Do -> "Do"
  | Re -> "Re"
  | Mi -> "Mi"
  | Fa -> "Fa"
  | Sol -> "Sol"
  | La -> "La"
  | Si -> "Si"

type partition = note array

let afficher_partition part =
  let rec parcours cpt =
    if cpt < Array.length part then
      (Printf.printf "%s " (note_vers_chaine part.(cpt)) ;
       parcours (cpt+1))
  in
  parcours 0

let mus1 = [| Do ; Mi ; Fa ; Si ; La ; Re ; Sol |]

let mus2 = [| Do ; Re ; Fa ; Sol ; Do ; Mi ; Fa ; La ; Si ; Fa ; Re ; Re |]

let mus3 = [| Mi ; Sol ; Fa ; La ; Sol ; Mi ; Do |]

let mus4 = [| Sol ; La ; Do ; Si ; Sol ; Fa ; La ; Si ; Sol ; La ; Mi ; Do |]

(* Menuet en G major, Bach *)
let mus5 = [| Re ; Re ; Sol ; Fa ; Sol ; Mi ; Sol ; Fa ; Sol ;
              Re ; Do ; Si ; La ; Sol ; Fa ; Sol ; La ;
              Re ; Mi ; Fa ; Sol ; La ; Si ; Do ; Si ; La ;
              Si ; Re ; Sol ; Fa |]

(* Scarborough Fair *)
let mus6 = [| Re ; Re ; La ; La ; Mi ; Fa ; Mi ; Re ; La ; Do ; Re ; Do ;
              La ; Si ; Sol ; La ; Re ; Re ; Re ; Do ; La ; La ; Sol ; Fa ;
              Mi ; Do ; Re ; La ; Sol ; Fa ; Mi ; Re ; Do ; Re ; Re |]
