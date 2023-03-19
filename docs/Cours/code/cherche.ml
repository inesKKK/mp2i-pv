exception Solution of int

(** cherche tab val vaut Some i où i est l'indice de première
occurence de v dans tab, ou None si v n'apparaît pas dans tab *)
let cherche tab v =
  try for i = 0 to Array.length tab - 1 do
        if tab.(i) = v then raise (Solution i)
      done;
      raise Not_found
  with
  | Solution i -> Some i
  | Not_found -> None
