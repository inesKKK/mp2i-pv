TP22 : Sudoku
==

Ce TP est à faire en `C`. C'est un TD/TP :
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
les contraintes sur une grille donnée pour que `minisat` puisse résoudre
la grille. Pour rappel, le format dimacs est décrit dans le [tp21](https://ineskkk.github.io/mp2i-pv/TP2024-2025/TP21_logique/tp_logique_et_serialisation.html).

C'est une adaptation libre du sujet de l'épreuve d'option informatique MP
du concours CentraleSupelec 2014.

Les variables propositionnelles utilisées sont des entiers positifs
composés de la manière suivante:
* chacun de ces entiers s'écrit sur 3 chiffres;
* l'entier $ijk$ signifie que le prédicat "La case $ij$ contient
  l'entier $k$" est vrai. On note indifféremment $ijk$ ou $p_{ijk}$ la
  variable propositionnelle associée.

Le type `sudoku` représentant une grille de sudoku est fourni dans le
fichier d'en-tête [sudoku.h](src/sudoku.h). Attention au décalages
d'indices : pour les raisonnements et l'écriture des variables
propositionnelles, les cases commencent à 1, mais ce n'est pas le cas
en `C`. Ainsi pour connaître le chiffre associé à la case 11 sur la
grille, il faut regarder la case `[0][0]` quand on programme.


On peut imaginer que l'utilisateur donnera l'état initial de la
grille grâce à fichier contenant une ligne par case initialement
remplie, cette ligne contenant la variable propositionnelle
concernée. 

Dans la suite, on aura à un moment donné besoin de compter le nombre
de lignes d'un fichier et de recopier un fichier dans un autre. On
vous fournit les fonctions `nb_de_lignes` et `recopie` à cette fin
dans le fichier [sudoku.c](src/sudoku.c) que vous pouvez compléter.

**Question 1.** Écrire une fonction `void affiche_grille(char
*fichier)` qui prend en argument un nom de fichier au format décrit
ci-dessus et affiche la grille ainsi décrite (par exemple avec 0 pour
les cases non encore remplies).


## Des formules générales

**Question 2.** 
La contrainte
> Chaque case contient au moins une fois l'un des chiffres 1 à 9

peut s'écrire $\bigwedge\limits_{1\leq i, j\leq 9}
\bigvee\limits_{1\leq k\leq 9}p_{ijk}$.
Écrire une fonction `void case_au_moins(FILE *f)` qui prend en
argument un flux en écriture et y écrit les lignes (au format dimacs)
correspondants à cette contrainte.

**Question 3.** 
La contrainte
> Chaque case contient au plus une fois l'un des chiffres 1 à 9

peut s'écrire $\bigwedge\limits_{1\leq i, j\leq 9}
\bigwedge\limits_{1\leq k < k'\leq 9} (\neg p_{ijk}\vee \neg
p_{ijk'})$.
Écrire une fonction `void case_au_plus(FILE *f)` qui prend en argument
un flux en écriture et y écrit les lignes (au format dimacs)
correspondants à cette contrainte.

**Question 4.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque ligne contient au moins une fois l'un des chiffres 1 à 9

**Question 5.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque ligne contient au plus une fois l'un des chiffres 1 à 9

**Question 6.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque colonne contient au moins une fois l'un des chiffres 1 à 9

**Question 7.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque colonne contient au plus une fois l'un des chiffres 1 à 9

**Question 8.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque bloc contient au moins une fois l'un des chiffres 1 à 9

**Question 9.** Écrire une fonction qui prend en argument un flux en
écriture et y écrit les lignes (au format dimacs) correspondants à la
contrainte:
> Chaque bloc contient au plus une fois l'un des chiffres 1 à 9

**Question 10.** Écrire une fonction qui prend en argument un nom de
fichier contenant une grille initiale comme décrite avant la Question
1, et produit un fichier `conditions.dimacs` contenant les conditions
pour que `minisat` résolve la grille.

Faites des tests en utilisant des grilles de [grilles](grilles). (Pour
certaines ce sera trop long.) (Ces grilles sont empruntées à mon
collègue JB Bianquis et réadaptées au format de ce sujet.)

## Des formules adaptées à la grille initiale
Dans la partie précédente, les contraintes sont les même pour toutes
les grilles, auxquelles on ajoute simplement le fait que certaines
cases sont remplies. On peut en fait ajouter d'autres contraintes
adaptées à la grille de départ et qui vont permettre d'accélérer les
calculs.

**Question 11.** Si une case contient une valeur initiale, on est sûr
qu'elle n'est remplie par aucune autre valeur. Écrire une fonction
qui permettra d'écrire dans un flux de sortie cet ensemble de conditions.

**Question 12.** Si une case contient une valeur initiale, on est sûr qu'aucune
case sur la même ligne ne contient cette valeur. Écrire une fonction
qui permettra d'écrire dans un flux de sortie cet ensemble de conditions.

**Question 13.** Faites de même pour les colonnes.

**Question 14.** Faites de même pour les blocs.

**Question 15.** Écrire une nouvelle fonction qui prend en argument un
nom de fichier contenant une grille initiale comme décrite avant la Question
1, et produit un fichier `conditions.dimacs` contenant les conditions
pour que `minisat` résolve la grille.

**Question 16.** Comparer les temps d'exécution de `minisat` avec les
fichiers obtenus grâce à la fonction de la question 11 et ceux obtenus
grâce à la fonction de la question 16.
