TP24 : Sudoku
==

Ce TP est à faire au choix en `C` ou en `OCaml` (conseil : prenez le
langage dans lequel vous êtes le moins à l'aise). C'est à vous
d'introduire les structures de données à utiliser. C'est un TD/TP :
les formules de logique sont à trouver sur papier *avant* de se lancer
dans la programmation.


Si vous ne connaissez pas le jeu du sudoku, allez regarder le premier
paragraphe de la page
[wikipedia](https://fr.wikipedia.org/wiki/Sudoku) qui y est consacré
pour comprendre de quoi il s'agit.

On numérote les cases d'une grille de sudoku horizontalement et de bas
en haut: 11 à 19 pour la première ligne, 21 à 29 pour la suivante,
etc. jusqu'à 91 à 99 pour la dernière.

Le but de ce TP est de fabriquer un fichier dimacs contenant toutes
les contraintes sur une grille donnée pour que minisat puisse résoudre
la grille. Pour rappel, le format dimacs est décrit dans le [tp23](https://ineskkk.github.io/mp2i-pv/TP2023-2024/TP23_Logique/tp_logique_et_serialisation.html).

Les variables propositionnelles utilisées sont des entiers positifs
composés de la manière suivante:
* chacun de ces entiers s'écrit sur 3 chiffres;
* l'entier ijk signifie que le prédicat "La case ij contient
  l'entier k" est vrai.


On peut imaginer que l'utilisateur donnera l'état initiale de la
grille grâce à fichier contenant une ligne par case initialement
remplie, cette ligne contenant la variable propositionnelle
concernée. 

**Question 0.** Écrire une fonction qui prend en argument un nom de
fichier au format décrit ci-dessus et affiche la grille ainsi décrite
(par exemple avec 0 pour les cases non encore remplies).

## Des formules générales

**Question 1.** Écrire une fonction qui prend en argument un flux en
lecture sur un tel fichier et renvoie son nombre de lignes.

**Question 2.** Écrire une fonction qui prend en argument un flux en
lecture et un flux en écriture et recopie le contenu du flux en
lecture sur le flux en écriture.

**Question 3.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque case contient au moins une fois l'un des chiffres 1 à 9

**Question 4.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque case contient au plus une fois l'un des chiffres 1 à 9

**Question 5.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque ligne contient au moins une fois l'un des chiffres 1 à 9

**Question 6.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque ligne contient au plus une fois l'un des chiffres 1 à 9

**Question 7.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque colonne contient au moins une fois l'un des chiffres 1 à 9

**Question 8.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque colonne contient au plus une fois l'un des chiffres 1 à 9

**Question 9.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque bloc contient au moins une fois l'un des chiffres 1 à 9

**Question 10.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque bloc contient au plus une fois l'un des chiffres 1 à 9

**Question 11.** Écrire une fonction qui prend en argument un nom de
fichier contenant une grille initiale comme décrite avant la Question
1, et produit un fichier `conditions.dimacs` contenant les conditions
pour que `minisat` résolve la grille.

Faites des tests en cherchant des grilles sur internet.

## Des formules adaptées à la grille initiale

**Question 12.** Si une case contient une valeur initiale, on est sûr
qu'elle n'est remplie par aucune autre valeur. Écrire une fonction
qui permettra d'écrire dans un flux de sortie cet ensemble de conditions.

**Question 13.** Si une case contient une valeur initiale, on est sûr qu'aucune
case sur la même ligne ne contient cette valeur. Écrire une fonction
qui permettra d'écrire dans un flux de sortie cet ensemble de conditions.

**Question 14.** Faites de même pour les colonnes.

**Question 15.** Faites de même pour les blocs.

**Question 16.** Écrire une nouvelle fonction qui prend en argument un
nom de fichier contenant une grille initiale comme décrite avant la Question
1, et produit un fichier `conditions.dimacs` contenant les conditions
pour que `minisat` résolve la grille.

**Question 17.** Comparer les temps d'exécution de `minisat` avec les
fichiers obtenus grâce à la fonction de la question 11 et ceux obtenus
grâce à la fonction de la question 16.
