type note =
  | Do
  | Re
  | Mi
  | Fa
  | Sol
  | La
  | Si

val note_vers_chaine : note -> string

type partition = note array

val afficher_partition : partition -> unit

val mus1 : partition
val mus2 : partition
val mus3 : partition
val mus4 : partition
val mus5 : partition
val mus6 : partition
