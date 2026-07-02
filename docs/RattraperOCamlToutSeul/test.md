# OCaml MPSI/MP — Correspondance programme officiel × CS3110

## Sommaire

- [Traits généraux](#traits-généraux)
- [Définitions et types de base](#définitions-et-types-de-base)
- [Types structurés](#types-structurés)
- [Programmation impérative](#programmation-impérative)
- [Divers](#divers)
- [Éléments après rappel](#éléments-techniques-devant-être-reconnus-et-utilisables-après-rappel)
  - [Types de base](#types-de-base-après-rappel)
  - [Listes](#listes-et-fonctions-associées)
  - [Tableaux](#tableaux)
  - [Structures de données](#structures-de-données-après-rappel)
  - [Piles et files](#piles-et-files)
  - [Dictionnaires](#dictionnaires)

---

# Traits et éléments techniques à connaitre

## Traits généraux

* Typage statique, inférence des types par le compilateur. Idée naïve du polymorphisme.
* Passage par valeur.
* [Portée lexicale](https://cs3110.github.io/textbook/chapters/basics/expressions.html#scope)
  : la valeur utilisée est celle de la définition.
* [Curryfication des fonctions et fonctions d'ordre supérieur](https://cs3110.github.io/textbook/chapters/hop/higher_order.html#currying)
* Gestion automatique de la mémoire.
* Lisibilité du code : indentation non significative.

---

## Définitions et types de base

* [`let`, `let rec`, `let rec ... and ...`, `fun`](https://cs3110.github.io/textbook/chapters/basics/functions.html)

* `let v = e in e'`, `let rec f x = e in e'`
  - https://cs3110.github.io/textbook/chapters/basics/expressions.html#let-expressions
  - https://cs3110.github.io/textbook/chapters/basics/expressions.html#scope

* [`if e then e1 else e2`](https://cs3110.github.io/textbook/chapters/basics/expressions.html#more-operators)

* Types de base :
  - `int`, `float`, `bool`
  - opérateurs usuels
  - dépassements possibles

* Comparaisons :
  `=`, `<>`, `<`, `>`, `<=`, `>=`

---

## Types structurés

### Listes

* `'a list`, `[]`, `::`, `[x; y; z]`
* opérateur `@`
* `List.length`
* filtrage

https://cs3110.github.io/textbook/chapters/data/lists.html

---

### Options

* `'a option`

https://cs3110.github.io/textbook/chapters/data/options.html

---

### Types et synonymes

* `type t = ...`

https://cs3110.github.io/textbook/chapters/data/type_synonym.html#type-synonyms

---

### Types sommes

* sans transport :
  https://cs3110.github.io/textbook/chapters/data/variants.html

* avec transport :
  https://cs3110.github.io/textbook/chapters/data/algebraic_data_types.html

---

### Filtrage

* `match ... with`
* exhaustivité
* `_`
* unicité des variables
* ordre des motifs

https://cs3110.github.io/textbook/chapters/data/pattern_matching_advanced.html

---

## Programmation impérative

* expressions impures, `unit`, `()`

### Références

https://cs3110.github.io/textbook/chapters/mut/refs.html

* `ref`, `!`, `:=`

### Séquences et boucles

* `;`
* `while`
* `for`

---

## Divers

* `begin ... end`
* Exceptions (`failwith`)
  https://cs3110.github.io/textbook/chapters/data/exceptions.html

* Modules (`M.f`)
  https://cs3110.github.io/textbook/chapters/modules/modules.html#using-modules

* commentaires

---

# Éléments techniques devant être reconnus après rappel

---

## Types de base (après rappel)

* `mod`, `**`

### Char et string

https://cs3110.github.io/textbook/chapters/data/strings.html

* `'x'`, `"..."`

* `String.length`, `s.[i]`, `^`

* ordre sur `char`

* immuabilité des chaînes

---

### Affichage

https://cs3110.github.io/textbook/chapters/basics/printing.html

* `print_int`
* `print_string`
* `print_float`

---

## Listes et fonctions associées

* `List.mem`
  https://cs3110.github.io/textbook/chapters/data/lists.html

* `List.exists`, `List.for_all`, `List.filter`
  https://cs3110.github.io/textbook/chapters/hop/filter.html

* `List.map`
  https://cs3110.github.io/textbook/chapters/hop/map.html

* `List.iter`
  https://cs3110.github.io/textbook/chapters/hop/beyond_lists.html

---

## Tableaux

https://cs3110.github.io/textbook/chapters/mut/arrays.html

* `'a array`
* `[| ... |]`
* `t.(i)`, `t.(i) <- v`

Fonctions :

* `Array.length`
* `Array.make`
* `Array.make_matrix`
* `Array.init`
* `Array.copy`
* `Array.mem`
* `Array.exists`
* `Array.for_all`
* `Array.map`
* `Array.iter`

---

## Structures de données (après rappel)

* enregistrements :
  https://cs3110.github.io/textbook/chapters/data/records_tuples.html

* mutabilité :
  https://cs3110.github.io/textbook/chapters/mut/mutable_fields.html

* types récursifs :
  https://cs3110.github.io/textbook/chapters/data/algebraic_data_types.html#recursive-variants

---

## Piles et files

### Stack

https://cs3110.github.io/textbook/chapters/modules/functional_data_structures.html#stacks

* `create`
* `is_empty`
* `push`
* `pop`

### Queue

* même API attendue
* aucune section dédiée dans CS3110

---

## Dictionnaires

### Hashtbl

https://cs3110.github.io/textbook/chapters/ds/hash_tables.html

* `create`
* `add`
* `remove`
* `mem`
* `find`
* `find_opt`
* `iter`
