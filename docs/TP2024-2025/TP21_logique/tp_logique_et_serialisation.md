TP 21 : Logique et sérialisation
==

Dans ce TP, on va manipuler des formules de logique propositionnelle
dans le but de les sérialiser pour répondre au problème SAT en
utilisant `minisat`.

Les variables propositionnelles sont représentées par des entiers
strictement positifs.

On considère les types suivants :

```Caml
type litteral = Pos of int | Neg of int (* entiers > 0 *)
type clause = litteral list (* clause *)
type cnf = clause list (* formule sous forme normale conjonctive *)
type valuation = bool array
(* La case i contient la valuation de la variable propositionnelle i+1 *)
```

**Question 1.** Écrire une fonction `eval_clause : valuation -> clause
-> bool` qui donne la valeur de vérité associée à une clause.

**Question 2.** Écrire une fonction `eval_cnf : valuation -> cnf ->
bool` qui donne la valeur de vérité associée à une formule de logique
propositionnelle sous forme normale conjonctive.


On s'intéresse maintenant au problème SAT, et on souhaite déléguer la
résolution de ce problème au programme `minisat` qui prend en argument
un fichier au format dimacs.

Le format dimacs (sans commentaires) suit le schéma suivant:
* sur la première ligne `p cnf NOMBRE_DE_VARIABLES NOMBRE_DE_CLAUSES`
* une clause représentée sur chaque ligne, avec les entiers correspondants
  aux littéraux positifs de la clause, et les opposés des entiers
  correspondants aux littéraux négatifs de la clause, séparés par des
  espaces, la ligne se terminant par `0`
  
exemple : 

```
p cnf 5 3
1 -5 4 0
-1 5 3 4 0
-3 -4 0
```

**Question 3.** Écrire une fonction `max_var : cnf -> int` qui renvoie
l'entier maximal correspondant à une variable propositionnelle dans la
formule fournie en argument. Ne pas hésiter à écrire une fonction
intermédiaire pour avoir la réponse sur une clause.


**Question 4.** Écrire une fonction `dimacs_of_cnf : string -> cnf ->
unit` qui permet de sérialiser une formule sous forme normale
conjonctive au format dimacs.

**Question 5.** Tester la fonction précédente avec la formule
`[[Pos 3; Pos 4; Neg 2]; [Neg 1; Pos 7; Pos 4]]` et lancer `minisat`
sur le fichier obtenu : `minisat fichier` pour savoir si la formule
est satisfiable, `minisat fichier reponse` pour obtenir un modèle dans
le fichier `reponse` si la formule est satisfiable.

On va maintenant vérifier que le modèle donné par `minisat` en est
vraiment un.

**Question 6.** Écrire une fonction `valuation_of_dimacs : string ->
valuation` qui récupère une valuation dans un fichier généré par
`minisat`. Tester la réponse donnée par `minisat` à la question 5.


**Question 7.**
Voici le curieux règlement d'un club britannique :

* tout membre non écossais porte des chaussures rouges ;
* tout membre porte un kilt ou ne porte pas de chaussures rouges ;
* les membres mariés ne sortent pas le dimanche ;
* un membre sort le dimanche si et seulement s'il est écossais ;
* tout membre qui porte un kilt est écossais et marié ;
* tout membre écossais porte un kilt.

1. Exprimer ce règlement à l'aide d'une formule de logique
   propositionnelle.
2. Grâce à votre programme, créer un fichier dimacs exprimant ce
   problème.
3. Utiliser minisat pour répondre à la question suivante : ce
   règlement permet-il d'accueillir des membres ? 

**Question 8.** Fabriquer son propre solveur sur [learn-ocaml](http://vps-ff29e1ab.vps.ovh.net:49300/).

**Question 9.** Passer une formule sous forme normale conjonctive sur [learn-ocaml](http://vps-ff29e1ab.vps.ovh.net:49300/).
