TP Backtracking
====


Le but de ce TP est d'écrire un algorithme de backtracking pour
trouver les solutions de deux jeux :
* un carré magique
* un sudoku

## Carré magique
Si vous ne savez pas ce qu'est un carré magique, allez regarder sur
[wikipedia](https://fr.wikipedia.org/wiki/Carr%C3%A9_magique_(math%C3%A9matiques)).

On suppose qu'on dispose dans le fichier [base.ml](base.ml) des types

```Caml
type plateau = int array array
type case = int * int
type coup = case * int  (* ((i, j), k) : on joue k en case (i, j) *)
type final = Gagne | Perdu | PasFini
          
type 'a jeu = {
    plateau : plateau;
    prochains : 'a jeu -> coup list;
    premiere_case_libre : int * int;
    fini : 'a jeu -> final; (* teste si on est dans un position finale *)
    affiche : 'a jeu -> unit; (* affiche le plateau *)
    place : 'a jeu -> coup -> 'a jeu; (* renvoie un nouveau joue en simulant le coup *)
    complement : 'a; (* si jamais on a besoin d'autre chose *)
  }
```

Par ailleurs on fournit un fichier [carre.ml](carre.ml) qui fournit
le type

```Caml
type carre = bool array jeu (* case i à true si i deja placé *)
```

et la fonction `init_carre : int -> carre` qui fournit un carre
initialement vide de la bonne taille avec tous les champs bien
remplis.

**Question 1.** Dans un fichier `solution.ml`, écrire une fonction
`cherche_solution : 'a Base.jeu -> unit` qui affiche toutes les
solutions d'un jeu en faisant une recherche par backtracking. Vous
pouvez le tester avec un carré magique. Attention : votre fonction ne
doit pas dépendre du fait que c'est un carré magique qu'on cherche à résoudre !

**Rappel** : l'ordre de compilation n'est pas anodin en
`OCaml`. Pensez à écrire:
```
ocamlopt base.ml carre.ml solution.ml
```

En ayant mis `open Base` dans `carre.ml` et `solution.ml`, et `open
Carre` dans `solution.ml`.

## Sudoku

Il s'agit maintenant d'utiliser la fonction précédente pour résoudre
un sudoku.

Pour cela il va falloir écrire toutes les fonctions intermédiaires :
```Caml
type sudoku = unit Base.jeu
val toutes_les_cases_remplies : sudoku -> bool = <fun>
val deux_a_deux_distincts : int array -> bool = <fun>
val toutes_les_lignes_correctes : sudoku -> bool = <fun>
val toutes_les_colonnes_correctes : sudoku -> bool = <fun>
val toutes_les_zones_correctes : sudoku -> bool = <fun>
val fini_sudoku : sudoku -> Base.final = <fun>
val prochains_sudoku : sudoku -> ((int * int) * int) list = <fun>
val affiche_sudoku : sudoku -> unit = <fun>
val case_suivante : sudoku -> int * int -> int * int = <fun>
val place_sudoku : sudoku -> (int * int) * int -> sudoku = <fun>
val creer_sudoku : Base.plateau -> sudoku = <fun>
val s1 : int array array =
  [|[|6; 3; -1; -1; 2; -1; -1; -1; 9|]; [|-1; 4; -1; 5; 3; 1; -1; -1; 2|];
    [|-1; 7; 5; -1; 4; 9; -1; 3; 1|]; [|8; -1; -1; 4; -1; 6; 1; -1; -1|];
    [|-1; -1; -1; 2; 1; -1; 3; 9; 6|]; [|-1; -1; -1; 7; -1; 3; 2; -1; 4|];
    [|3; 8; 7; -1; -1; -1; 4; -1; -1|]; [|4; -1; 2; 1; -1; -1; -1; 6; 3|];
    [|-1; -1; -1; -1; 7; -1; -1; -1; -1|]|]
```

Il ne reste plus qu'à tester en ajoutant un appel à `cherche_solution`
déjà écrit.
