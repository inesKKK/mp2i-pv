(** est_vide lst teste si lst est une liste vide *)
let est_vide lst = match lst with
  | [] -> true
  | _ -> false

(** est_vide2 lst teste si lst est une liste vide, sans pattern matching, mais mieux *)
let est_vide2 lst = lst = [] 
       
(** premier lst est le premier element de lst si lst est non vide, et lève une exception sinon *)
let premier liste = match liste with
  | [] -> failwith "liste non vide"
  | hd :: tl -> hd


(** dernier lst est le dernier element de lst si lst est non vide, et lève une exception sinon *)
let rec dernier lst = match lst with
  | [] -> failwith "liste vide"
  | [ x ] -> x
  | _ :: tl -> dernier tl


(** somme lst est la somme des elements de lst, 0 si lst est vide *)
let rec somme lst = match lst with
  | [] -> 0
  | hd :: tl -> hd + somme tl

(** longueur lst est la longueur de lst *)
let rec longueur lst = match lst with
  | [] -> 0
  | _ :: tl -> 1 + longueur tl

(** longueur2 lst est la longueur de lst *)
let longueur2 lst =
  let rec long2 lst2 n =
    match lst2 with
    | [] -> n
    | _ :: tl -> long2 tl (n+1)
  in long2 lst 0


(** append lst x est la liste qui commence par les les éléments de lst et se termine par x *)
let rec append lst x = match lst with
  | [] -> [ x ]
  | hd :: tl -> hd :: append tl x
  
(** extend lst1 lst2 est la liste dont les premiers éléments sont ceux de lst1 et les derniers ceux de lst2 *)
let rec extend lst1 lst2 = match lst1 with
  | [] -> lst2
  | hd :: tl -> hd :: extend tl lst2


(** que_pairs lst est une liste formée des éléments pairs de lst *)
let rec que_pairs xs = match xs with
  | [] -> []
  | x :: xs' -> if x mod 2 = 0 then x :: que_pairs xs' else que_pairs xs'
