TP27 : Génération et résolution de labyrinthes
===


Le but de ce TP est de générer des labyrinthes et de les résoudre.

# Parcours de graphes [en `OCaml`]

On se place pour l'instant dans un cadre plus général : on dispose d'un
graphe non orienté et d'un sommet d'entrée dans ce graphe et on cherche un chemin
de cette entrée vers un sommet particulier qu'on nommera sortie.



Un graphe non orienté est représenté par le type

```Caml
type graphe = {
    entree : int;
    sortie : int;
    adj : int list array
  }
```

où `entree` est le point de départ de l'exploration du graphe,
`sortie` le point d'arrivée et `adj` une représentation par listes
d'adjacence. Le but est donc de trouver un chemin de l'entrée vers la
sortie. On trouvera ce type ainsi que deux instances de graphes dans
le fichier [graphes.ml](src/graphes.ml).

**Question 1.** Écrire une fonction `parcours : graphe -> int option
array` qui à un graphe associe un tableau contenant en case `s` le
prédécesseur du sommet `s` dans un parcours en largeur à partir de
l'entrée du graphe (`None` si pas de prédécesseur).

**Question 2.** Écrire une fonction `sortir : graphe -> int Stack.t`
qui à un graphe associe une pile donnant la liste des sommets à
parcourir pour aller de l'entrée à la sortie du graphe (entrée au
sommet de la pile, sortie en fond de pile). On supposera que l'entrée
et la sortie appartiennent à la même composante connexe, sans avoir à
le vérifier.


# Résolution d'un labyrinthe [en `OCaml`]

Les labyrinthes considérés ici sont des labyrinthes
rectangulaires. Ils sont composés de pièces et de murs. Avant qu'on
enlève des murs pour permettre le passage, une base de labyrinthe 7x3
ressemble à ça :

```
+-------------+
| | | | | | | |
+-------------+
| | | | | | | |
+-------------+
| | | | | | | |
+-------------+
```

Quand un mur (`-` ou `|`) n'existe pas, il est remplacé par du vide,
voici un exemple de labyrinthe sur la base précédente, où il faut
trouver un chemin allant de la case `E` à la case `S` :

```
+-------------+
|     | | |  S|
+ --- ----- --+
|E| | | | | | |
+ --- ----- --+
|           | |
+-------------+
```

Un tel labyrinthe est encodé par un fichier contenant sa largeur
en première ligne, sa hauteur en deuxième ligne et la description du
labyrinthe sous le format précédent ensuite. Le fichier associé au
labyrinthe précédent est fournit dans le fichier [laby0](src/laby0).

Le but de cette partie est de trouver une solution pour sortir du
labyrinthe.

Pour cela, on représente un labyrinthe par un graphe, en 
numérotant les cases du labyrinthe par des entiers naturels, de
gauche à droite et de haut en bas (je ne mets que le début de la
numérotation ci-dessous pour conserver des cases de largeur constante) :

```
+-------------+
|0|1|2|3|4|5|6|
+-------------+
|7|8|9| | | | |
+-------------+
| | | | | | | |
+-------------+
```

**Question 3.** Écrire une fonction `lecture_labyrinthe : string ->
int * int * graphe` qui, à un nom de fichier représentant un graphe et supposé bien
formé, associe un triplet contenant la largeur du labyrinthe, sa
hauteur et une instance de `graphe` qui le représente.

Après avoir lu les dimensions, on pourra:

* lire une ligne en l'ignorant, puis
* lire les lignes 2 à 2 : la première ligne permet de décider
  s'il existe des arêtes entre une case et ses voisines de gauche et
  droite (ne pas oublier la symétrie), la deuxième ligne permet de décider
  s'il existe des arêtes entre une case et ses voisines du dessus et
  du dessous (là encore, ne pas oublier la symétrie)
* attention aux retours à la ligne.

Rappel: la lecture d'une ligne se fait avec `input_line : in_channel
-> string` et la lecture d'un caractère avec `input_char : in_channel
-> char`.

**Question 4.** En combinant les fonctions précédentes, donner un
chemin de sortie pour [laby0](src/laby0) et [laby1](src/laby1).

Vous pouvez regarder votre chemin avec la fonction `affichage_sortie :
string -> unit` qui prend le nom du fichier où se trouve le labyrinthe
et affiche le chemin trouvé (si vous avez bien respecté les types
demandés dans l'énoncé) et [qui est fournie](src/labyrinthe.ml).

Pour info, voici :
* mon chemin pour laby0 :

```
+-------------+
|     | | |* *|
+ --- ----- --+
|*| | | | |*| |
+ --- ----- --+
|* * * * * *| |
+-------------+
```
* mon chemin pour laby1 :

```
+---------------------------------------------------------------------+
|                 |   |           |               |                   |
+ --------- --- - - - ----- - --- - --------- --- - --------------- - +
| |   |   |   | | | |     | | |   |   |     | |   | |             | | |
+ --- - - - --- - - ----- - - - ----- - ----- --- - - ----- --- --- - +
|     | | | |   | | |   | | | | |       |   |   | | |     | |   |   | |
+---- - - --- --- - - - - --- - ------- - - --- --- --- --- - --- --- +
|   | | |   | | |   | |     | |       | | |   |   |   | |   |   | |   |
+ - --- --- - - --- ------- - ------- --- --- --- --- --- ----- - - --+
| |     |   | |     |     |   |     |     | |   |   |   | |   | | |   |
+ ------- --- - ----- --- --------- ------- --- - ----- - - - - - --- +
| |     |   | |     |   |         | |         | |         | | | | |   |
+ --- ----- - ----- --- --------- - - ------- - - ------- - - --- --- +
|   |         |       | |   |     | | |     |   | |   |   | |   |   | |
+ - ----------------- - - - - ----- - - --- ----- - - ----- --- --- --+
| |     |         |   | | | |   |     | | |     | | |   |   |     |   |
+------ - ------- ----- - - --- - ----- - --- - --- --- - ------- --- +
|     |         |     |   | | | | |   |   |   |     | | |       |   | |
+ --- --------- ----- ----- - - - - ----- - --------- - --- --- --- - +
| | |   |   |   |   | |       | | |       |         | |   |   | |   | |
+ - --- - - --- - - - - ------- - ------- ------- - - --- ----- --- - +
| |   |   |   | | |   |   | |   |       | |     | | |   |     |   |   |
+ --- ------- - - - ----- - - --------- --- --- --- - ------- - - --- +
|   | |     | | | | |   |   |       | |     | |   | |     | | | |   | |
+ - - - - --- - - --- - --- ------- - ------- --- - --- - - - --- - - +
| | | | | |   | |     |         | | |           |   |   |   |   | | | |
+ - - - - - --- --------------- - - --------- - ----- ----- --- - - - +
| | |   |   |           |     |   | |   |   | | |       |   |   | | | |
+ - ----- ------- ----- - --- ----- - - - - - - - ----- - --- --- - --+
| |     |       | |   | | | |       | |   |   | |   | | |   |   | |   |
+ ----- ------- --- - --- - --------- ------------- - - ------- ----- +
|     |   |     |   |     |             |         |   | |     |     | |
+---- --- --- --- ----- ----- --------- - ----- ----- - - --- ----- - +
| |     |   |     |   | |   |   |     |   |   |   |   | |   |         |
+ - ------- --- --- - --- - --- --- - ------- --- - --- --- --------- +
| | | |   | |   |   |     | |     | |           | |   |     |   |   | |
+ - - - - - --- - ----- --- ----- - - ----- ----- --- ----- --- - - --+
|     | | |   | | |   | |   |* *| | | |     |   | |   |   |   | | |   |
+ ----- - --- --- - - - - --- - - --- - ----- - - - --- - --- - - --- +
| |   | |   | |   | | | | |* *|*|   | | |   | |   |   | |   | | |   | |
+ - - - --- - - --- - --- - --- --- - - --- - - ----- - --- - - --- - +
| | | | |   |   | | |     |*| |* *|   |   | | | |   | | |   |     | | |
+-- - - - ----- - - ----- - - --- ------- - - --- - - - - --------- - +
|   |   |     |   |     | |*|   |* *|       |     |   | |           | |
+ - --------- - ------- - - - - --- - ----- ----- ----- ------------- +
| | |     | | | |     | | |*| | | |*| |* *| |* *|   | | |             |
+ - - --- - - --- --- - --- - - - - --- - --- - --- - - - ------------+
| | |   | | | |   |   |   |*| |   |* * *|* *|*|* *|   | | |           |
+ ----- - - - - ----- --- - - --- --------- - --- ----- - --- ------- +
|       | | | |     |   | |*|   | |     | |* *| |* *|   |   | |     | |
+ ------- - - - --- --- - - --- - - --- - ----- --- - ----- --- --- - +
|   | |   | | |   |   | | |* *| |   |     |* * * * *  |   |     |   | |
+-- - - --- - --- --- - - --- - ----------- ----------- --------- --- +
|     |   | |   |   | |   |* *|  * * *|* *|*| |* * * *|         |     |
+------ - - --- ----- --- - ----- --- - - - - - ----- - - ----- ----- +
|     | | |   |     | |   |* * *|   |* *|* *  |* *  |*| | |     |     |
+ --- --- - - ----- - --- ----- --- ------------- --- - - ------- ----+
| | |   | | |       |   | |   |*|       |* * * * *|* *| | |       |   |
+ - --- - - ------- --- - --- - --------- --------- ----- - --------- +
| |       |   |   | |   |   | |* * * * * *        |*|* *| | |   |   | |
+ ------------- - - - ----- - ------------------- - - - - - - - - - - +
|               | |   |   |     |     |* * * *|   |* *|*|   | |   | | |
+ --------------- ----- - ----- - ----- ----- --------- - --- ----- - +
|     |   |     | |     | |       |* * *|   |* *|* *|* *| |   |     | |
+---- - - - - --- - - ----- ------- ----- ----- - - - --- - --- ----- +
|   |   | | | |   | | |       |* *|*|* * * * * *|*|*|* *| |   |     | |
+ - ----- --- - ----- - ------- - - - ----------- - --- - - - ----- - +
| |     |   | | |     | | |* * *|* *|*|  * *|* *|*|* * *| | | |   |   |
+ ----- --- - - - ----- - - --------- --- - - - - ------- - - --- --- +
| |       |   | | |   |   |* * * * *|* * *|* *|* *|     | | |   |   | |
+ ------- ----- - - - --- --------- ----------- ------- - --- - - - - +
| |   |       | |   |   |   |     |* * * *|* *| |* *|   |   | | | |   |
+ - - ------- - - --- - --- - - --------- - - ----- - - --- --- - ----+
|   |     | |   | | | |   | | |   |     |* *|* * * *| |   |   | | |   |
+ ------- - ----- - - --- - --- - - --- ------------- - ----- - --- - +
|   |   | |   |     | | | |   | |     |   |   |       | |     |     | |
+-- --- - - - - ----- - - --- ------- - - - --- ----- --- ----------- +
| |   | | | | |   |   |     | |     | | | | |   |   |     |         | |
+ --- - - - ----- - --------- - --- - - - - - --- - ------- ------- - +
|   |   | |       |       |   | | | | | |   |   | |     |     |       |
+ - --- - --- ------- --- - --- - - - - --- --- ------- - --- ------- +
| | |   |   |   |   | |   |     |   | |   |   |       |   | |     |   |
+-- - ----- ----- - --- --------- --- --- --- ------- --- - ----- - --+
|   | |   |       |   |         |   | |   |         |   |   |   | |   |
+ - - --- ----------- --- - ------- --- --------------- --- - - - --- +
| | |   |           |   | |       |   | |           |   | |   | |   | |
+ ----- - ----- - ----- ------- ----- - - --------- - --- --- ----- --+
|     | |     | | |   |       | |   |   |   |     | | |       |   |   |
+ - - - ----- - --- - ------- - - - --- --- - - --- - - ------- - --- +
| | | |     | |   | |   |   | |   |     | | | | |   | | |     | |   | |
+ - ------- ----- - --- - - - - ------- - - - - - --- - - --- - --- - +
| |       |       | |     |   |   |   |   |   | |     |   |   |   | | |
+ --- ----------- - --------- ----- - --- ----- ----------- ----- - - +
|   | |   |       |         | |     | |       | |       |       | | | |
+-- - - - - --------------- - - ----- - ------- - ----- ------- - - - +
|   |   |   |     |       | | |     | |   |     | |   |     |   | |   |
+ ------------- - ------- - - ----- - --- - ----- - - ----- - --- --- +
|   |     |     | |     | | |   |   |   | |   |   | |     | | |   |   |
+-- - --- --- --- - --- - - ----- ----- ----- --- - - ----- --- --- --+
|     |       |     |     |           |           | |           |     |
+---------------------------------------------------------------------+
```

# Génération d'un labyrinthe [en `C`]

Dans cette partie, nous nous attaquons au problème de génération de
labyrinthe.

Le type `struct labyrinthe` donné dans le fichier
[labyrinthe.h](src/labyrinthe.h) est le suivant :

```C
struct labyrinthe {
  int largeur, hauteur;
  int entree, sortie;
  bool *mur_sous; // cases numerotees de 0 à largeur * hauteur - 1
  bool *mur_droite;
};
```

Les attributs `mur_sous` et `mur_droite` permettent de savoir s'il y a
un mur sous une case ou à droite d'une case.

**Question 5.** Écrire une fonction
```C
struct labyrinthe initialisation_labyrinthe(int largeur, int hauteur);
```
qui permet d'allouer la mémoire pour un labyrinthe dont les dimensions
sont fournies en argument, en plaçant par défaut tous les murs et
l'entrée et la sortie en case 0.

**Question 6.** 
Pour obtenir un entier aléatoire, on peut utiliser la fonction
```C
long int random(void);
```

et on peut initialiser la graine de l'aléa avec
```C
#include <time.h>

srandom((unsigned int)time(NULL));
```

Écrire une fonction récursive
```C
bool generation_labyrinthe(struct labyrinthe laby, bool *vus, int courant)
```
qui permet de générer un labyrinthe en suivant l'algorithme
d'[exploration exhaustive](https://fr.wikipedia.org/wiki/Mod%C3%A9lisation_math%C3%A9matique_d%27un_labyrinthe#Exploration_exhaustive).

**Question 7.** Écrire une fonction
```C
struct labyrinthe nouveau_labyrinthe(int largeur, int hauteur);
```
qui combine les deux fonctions précédentes pour obtenir un labyrinthe
dont on a donné les dimensions.

**Question 8.** Écrire une fonction
```C
void sauvegarder_labyrinthe(struct labyrinthe laby, char *fic);
```
permettant de sauvegarder un labyrinthe dans un fichier dont on
spécifie le nom, au format décrit dans la partie de résolution d'un
labyrinthe. 

**Question 9.**
Écrire la fonction principale de votre programme pour qu'on puisse
lancer en ligne de commande la génération d'un labyrinthe de la
manière suivante :
```
./a.out 35 50 laby
```

**Question 10.** Faites s'affronter votre programme de génération et
votre programme de résolution.
