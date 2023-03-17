# TP8 : Encore des pointeurs
Toutes les semaines, les TP sont à rendre pour le mercredi soir
suivant au plus tard, sur cahier-de-prepa. 

Chaque TP est composé de deux parties:
* flocon : partie dédiée à ceux parmi vous qui n'ont jamais programmé
  ou se sentent en difficulté;
* première étoile : partie dédiée à ceux qui sont à l'aise en programmation et à
  ceux qui ont réussi la partie flocon rapidement.
  
Le but de **ceux qui choisissent la partie flocon** doit être
d'arriver petit à petit de plus en plus loin dans la partie première
étoile.

**Ceux qui choisissent la partie première étoile** n'ont pas besoin de
faire la partie flocon, et dans l'idéal doivent terminer la partie
première étoile.


> Les réponses sont à rendre dans un ou plusieurs fichiers sources
(éventuellement dans une archive), en
ajoutant en commentaire vos nom et prénom sur la première ligne, la
ligne de compilation à utiliser sur la deuxième ligne, et en
identifiant de manière claire les numéros d'exercices et de
questions.

Pour certains exercices, je fournis un fichier qui contient un
`main` avec des tests. À vous de compléter ce fichier en écrivant la
fonction demandée (avant le `main`), de le compiler et de
l'exécuter. Pour les exercices pour lesquels je ne fournis pas de
`main`, je vous donne le nom du fichier qui doit contenir votre
programme, merci de respecter ce nom.


## Plus sur la compilation

La compilation d'un programme `C` se fait en plusieurs étapes (et
ces étapes peuvent dépendre du compilateur). Au moment où le
compilateur passe dans un morceau de code où une variable, une valeur
ou une fonction est utilisée, il vérifie si les types qui apparaissent
sont cohérents, par exemple pour une affectation si le type de la
rvalue est compatible avec le type de la lvalue.

Le compilateur a donc, entre autres, besoin de connaître les types de
retour des fonctions ainsi que les types de leurs paramètres. Si la
fonction est définie (=en-tête+corps) _avant_ son utilisation, il les
connaît et peut procéder à des vérifications. Sinon ce n'est pas le
cas, et la compilation produit une erreur.

Cette étape de vérification se fait lors
de la compilation avant l'_édition de liens_ qui est l'étape où le
lien est effectivement fait entre un appel de fonction et la
définition de cette fonction (c'est-à-dire son code).

Si une fonction `g(...)` appelle une fonction `f(...)` du même
fichier, pour que le compilateur connaisse les types de `f(...)` avant
cet appel, on peut par exemple définir `f(...)` avant `g(...)`. Une
autre méthode consiste à _déclarer_ `f(...)` avant `g(...)` (en
général avant de commencer à définir des fonctions), en écrivant sa
signature (c'est-à-dire son en-tête) suivi d'un `;`:

```C
int f(int n);      // déclaration de f

void g(){
    int p = f(3);  // pas de problème car f a été déclarée avant
}

int f(int n){      // définition de f
    return n;
}
```

### Fichiers d'en-tête
Quand on écrit un petit programme qui ne sera utilisé que par nous,
cette solution de déclarer les fonctions en tête de fichier `.c` est
parfaitement suffisante. Mais quand on écrit un programme dans le but
qu'il soit réutilisé, elle est peu satisfaisante : on n'a pas
forcément envie que l'utilisateur accède au code qu'on a écrit (ne
serait-ce que parce qu'il peut le modifier par mégarde), mais on doit
quand même lui fournir les en-têtes des fonctions et les définitions de
types.

On a vu qu'il existe des fichiers d'en-tête (_headers_ en anglais) qui
permettent de déclarer des types et des fonctions. Ces fichiers
portent l'extension `.h`. **Un fichier d'en-tête ne sert pas à définir
des fonctions**, seulement à les déclarer (donc pas de corps de
fonctions, que des en-têtes).

On ne peut pas définir plusieurs fois la même entité en `C`, il est
donc important qu'un fichier d'en-tête ne soit inclus qu'une seule
fois. Pour ne pas avoir à gérer à la main des inclusions multiples, on
utilise des macro-définitions: des valeurs pour le précompilateur qui
lui permettent de savoir si le fichier a déjà été lu ou pas lors de la
compilation (voir les fichiers d'en-tête fournis plus bas).

Assez vite, on arrive à des fichiers sources trop
longs, ou dont on voudrait pouvoir réutiliser une partie et pas
l'autre par exemple. Pour structurer un programme, on peut bien
entendu le séparer en plusieurs fichiers. Pour compiler un programme
éparpillé sur plusieurs fichiers, il suffit de tous les donner en
argument à `gcc`<sup>[1](#myfootnote2)</sup>.


---------------------------

Dans ce TP, je vous fournis systématiquement:

* pour les tests:
  * un fichier d'en-tête avec des déclarations;
  * un fichier source avec des tests : les corps des fonctions sont
    commentés, à vous de les décommenter au fur et à mesure de
    l'avancée de votre travail;
* pour votre propre travail:
  * un fichier d'en-tête avec les types : vous devrez le compléter
    avec les signatures des fonctions que vous écrivez au fur et à mesure;
  * un fichier dans lequel vous devez travailler, avec éventuellement
    quelques fonctions écrites (par exemple les fonctions liées aux fichiers).

## Flocon -- pour ceux qui n'ont jamais programmé


### Exercice 1 : Ensemble de Mandelbrot
Pour cette partie, les fichiers utiles:
[tests_mandelbrot.h](tests/tests_mandelbrot.h)
[tests_mandelbrot.c](tests/tests_mandelbrot.c)
[mandelbrot.h](tests/mandelbrot.h) 
[mandelbrot.c](tests/mandelbrot.c) 

On considère un point $C$ du plan de coordonnées $(x_c,y_c)$ et une suite de points $(P_n)_{n\geq 0}$ du plan. On note $(x_n, y_n)$ les coordonnées de $P_n$. Les coordonnées de $(P_n)_n$ sont obtenues par la relation de récurrence suivante :

$$\begin{array}{lcl}
(x_0, y_0) &= & (0, 0)\\
(x_{n+1}, y_{n+1}) &=& (x_n^2-y_n^2+x_c, 2x_ny_n+y_c)
\end{array}$$

L'_ensemble de Mandelbrot_ est l'ensemble des points $C$ du plan pour lesquels la suite des points $(P_n)_n$ est bornée. On se propose d'obtenir une représentation graphique de cet ensemble.

Tous les points du plan seront considérés à coordonnées réelles (car $(1,1)$ n'est déjà plus dans l'ensemble de Mandelbrot). Il faudra donc mettre à la bonne échelle pour faire la représentation graphique.

1. Écrire une fonction `point_suivant` qui possède 6 paramètres (dans cet ordre pour les tests, abscisse puis ordonnée à chaque fois):

* 2 paramètres pour les coordonnées d'un point de la suite
* 2 paramètres pour les coordonnées de $C$
* 2 paramètres pour les coordonnées du point suivant dans la suite

et calcule les coordonnées du point suivant de la suite.


On donne la fonction `norme_carre` qui permet de calculer la norme au carré d'un point.

2. En considérant que la suite des normes des $P_n$ est non bornée si au plus tard au bout de de 100 itérations, le point obtenu a atteint ou dépassé 2 en norme, écrire une fonction `suite_bornee` qui prend en argument l'abscisse et l'ordonnée du point $C$ et teste si la suite des normes est bornée.

3. Écrire une fonction `mandelbrot` qui prend en argument deux entiers
   représentant la hauteur et la largeur d'une fenêtre et renvoyant un
   double pointeur sur booléen. Une case de ce tableau vaut `true` si
   et seulement si le point qu'elle représente est dans l'ensemble de
   Mandelbrot (attention à l'échelle : les points de l'ensemble de
   Mandelbrot ont des coordonnées de valeur absolue inférieure à
   1). Je fournis une fonction `sauvegarder` qui permet de regarder le
   résultat visuel de votre fonction.
   
   Avec les paramètre `h=500` et `l=500`, j'obtiens l'image suivante:
   
   ![](img/mandel_modele.png)

## Première étoile -- pour ceux qui sont à l'aise en programmation et ceux qui ont facilement fini le flocon


### Exercice 2 : Hasard
Pour cette partie, les fichiers utiles:
[tests_oiseaux.h](tests/tests_oiseaux.h) 
[tests_oiseaux.c](tests/tests_oiseaux.c) 
[oiseaux.h](tests/oiseaux.h) 
[oiseaux.c](tests/oiseaux.c) 

Écrire et documenter une fonction `hasard` qui tire un entier positif ou nul au hasard, majoré par une borne donnée en premier paramètre, et ayant comme deuxième paramètre une valeur à éviter.  

Pour rappel, la fonction `random()` (déclaré dans le fichier d'en-tête `stdlib.h`) renvoie un entier entre 0 et une constante `RAND_MAX` (également définie dans le fichier d'en-tête `stdlib.h`).

### Exercice 3 : Vol d'oiseaux (version simplifiée)
On désire modéliser le vol d'une nuée d'oiseaux. Pour cela, on modélise chaque oiseau comme un point, et on lui attribue un ami et un ennemi:


```C
struct oiseau {
    double x, y; // entre 0 et 1 pour être visible
    int ami;     // indice de l'ami dans la nuee (voir ci-dessous)
    int ennemi;  // indice de l'ennemi dans la nuee
};
```

Une nuée d'oiseaux est un ensemble d'oiseaux. On définit le type structuré:


```C
struct nuee {
    int taille; // nombre d'oiseaux
    struct oiseau *cui;
}
```

À chaque étape de vol, chaque oiseau se déplace selon le vecteur
$$0.01 * \vec{u} + 0.05*\vec{v} -0.03*\vec{w}\:,$$ où $\vec{u}$ est le vecteur unitaire de l'oiseau vers le point $(0.5, 0.5)$, $\vec{v}$ est le vecteur unitaire de l'oiseau vers son ami et $\vec{w}$ est le vecteur unitaire de l'oiseau vers son ennemi.

1. Écrire et documenter une fonction `deplacement_oiseau` qui prend en paramètre (dans cet ordre) un pointeur sur nuée et deux pointeurs sur oiseau : le premier donne l'oiseau au temps $t$, le deuxième l'oiseau au temps $t+1$ (même ami et même ennemi, mais coordonnées mises à jour selon les règles établies ci-dessus ---si elles dépassent les limites pour être visible ce n'est pas grave).

2. Écrire un documenter une fonction `alloue_nuee` qui prend en argument un entier qui est la taille de la nuée et alloue la mémoire nécessaire pour une nouvelle nuee (et renvoie l'adresse de cette nouvelle nuée).

3. Écrire une fonction `init_nuee` qui prend en argument un entier qui est la taille de la nuéeet crée la nuée en tirant au hasard les abscisse, ordonnée, ami et ennemi de chaque oiseau (abscisse et ordonnée entre 0 et 1).

4. Pour éviter d'effectuer sans arrêt des copies de données, les données liées à une nuée d'oiseau vont en fait alterner entre deux emplacements mémoire de type `struct nuee`. En permanence, l'un correspondra à l'étape qu'on est en train de calculer, tandis que l'autre correspondra à l'étape précédente (et bien sûr ils inverseront leur rôle à chaque changement d'étape). Écrire et documenter une fonction `deplacement` qui prend en argument un pointeur sur une nuée correspondant à l'état actuelle de la nuée, et un second pointeur sur une nuée qui permettra d'écrire les nouvelles coordonnées des oiseaux de la nuée. 

5. De temps en temps, pour relancer la dynamique de la nuée, il faut modifier les ami et ennemi de chaque oiseau. Écrire et documenter une fonction `change_amities` qui a comme paramètre un pointeur sur nuee et retire au hasard les ami et ennemi de chaque oiseau.

6. Pour les affichages, il faut transformer une nuée en image. Écrire et documenter une fonction `image` qui prend en argument un pointeur sur nuee et renvoie un tableau bidimensionnel de booléens de taille 300x300 où une case vaut `false` si et seulement s'il y a un oiseau dedans (n'oubliez pas que les coordonnées visibles des oiseaux sont entre 0 et 1, il faut donc appliquer un coefficient multiplicatif pour se ramener à 0-300).

7. Je vous fournis la fonction `ecrire_image` qui permet de créer un fichier image au format `ppm` à partir d'un tableau bidimensionnel de booléens.

Écrire un programme avec plusieurs étapes de déplacement de la nuée
qui produit un fichier à chaque fois (en numérotant les fichiers dans l'ordre). Vous pouvez prendre les paramètres suivants:
* nombre d'oiseaux : 300
* nombre de pas : 200
* changement d'ami/ennemi : tous les 30 pas


Pour créer un gif animé puis supprimer les fichiers inutiles, vous
pouvez utiliser les commandes suivantes dans votre shell:

```bash
convert -delay .1 -loop 0 oiseaux-*.ppm oiseaux.gif  # pour fabriquer le gif animé
rm -f oiseaux-*.ppm  # pour supprimer les images ppm
```

De mon côté, j'obtiens l'animation suivante:

![](img/oiseaux_modele.gif)

### Exercice 4 : Vol d'oiseaux (version plus réaliste)
Modifier le programme (les deux versions sont à rendre quand même) en
faisant en sorte qu'à l'étape de changement d'amitié, seulement 10%
des oiseaux changent d'ami (de façon probabiliste: un
oiseau à une chance sur dix de changer) et que l'ennemi d'un oiseau
soit en fait l'oiseau le plus proche de lui.


----
<a name="myfootnote2">1</a>: Dans la vrai vie, il existe des outils
pour gérer la compilation des gros projets et notamment spécifier les
dépendances entre tous les fichiers qui interviennent, ce qui évite de
tout recompiler quand on ne modifie qu'un seul fichier par exemple,
mais permet aussi de recompiler tout ce qu'il est nécessaire de
recompiler sans se poser de questions à chaque fois. Ces outils sont
hors programme, mais les plus curieux pourron jeter un œil à [gnu
make](https://www.gnu.org/software/make/) qui est sans doute l'outil
de base le plus classique à cet effet pour le `C`.
