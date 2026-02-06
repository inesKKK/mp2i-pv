open Tp18

let test_longueur () =
  assert ( longueur "" = 0 );
  assert ( longueur("a") = 1 );
  assert ( longueur("anticonstitutionnellement") = 25)

let test_nombre_occurences () =
  assert ( nombre_occurences 'a' "" = 0 );
  assert ( nombre_occurences 'a' "123456" = 0 );
  assert ( nombre_occurences 'a' "a123456" = 1 );
  assert ( nombre_occurences 'a' "a12a34a56" = 3 );
  assert ( nombre_occurences 'a' "123456a" = 1 );
  assert ( nombre_occurences 'a' "12aaa3456a" = 4 )

let test_derniere_occurence () =
  assert( derniere_occurence 'a' "" = None );
  assert( derniere_occurence '1' "23456" = None );
  assert( derniere_occurence 'A' "Atout" = Some 0);
  assert( derniere_occurence 'a' "carreau" = Some 5);
  assert( derniere_occurence 'a' "abracadabra" = Some 10)

let test_split () =
  let s = "ceci est un essai pour un exemple" in
  let t1 = split ' ' s in
  let t2 = split 'e' s in
  let t3 = split 'z' s in
  assert ( t1.(0) = "ceci" );
  assert ( t1.(2) = "un" );
  assert ( t1.(6) = "exemple" );
  assert ( t2.(1) = "ci " );
  assert ( t2.(6) = "" );
  assert ( t3.(0) = s )
  
  
let _ = test_longueur ();
        test_nombre_occurences ();
        test_derniere_occurence ();
        test_split ()

