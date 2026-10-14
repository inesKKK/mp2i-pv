TP7 : jeu du drapeau
---


Il s'agit d'implémenter des fonctionnalités manquantes pour le jeu du
drapeau. Ce jeu consiste à essayer de deviner un drapeau en proposant
des noms de pays, on a alors la partie commune qui apparaît entre ce
qu'on propose et le drapeau d'origine, le tout s'enrichissant au fur
et à mesure des propositions.

Les sources pour le TP sont dans l'archive
[tp_drapeaux.zip](tp_drapeaux.zip). Il faut dézipper et vous obtenez:

* un fichier `jeu_du_drapeau.c` qu'il va falloir compléter tout au
  long du TP;
* un fichier `drapeaux.h` qui contient la définition des types et des
  constantes à utiliser;
* un répertoire `Drapeaux` qui contient des images de drapeaux.


Les constantes et types à utiliser sont imposés :

```C
#define LARGEUR 600
#define HAUTEUR 400
#define COULEUR_MAX 256

struct couleur {
  bool existe; //false si pas de couleur
  int r, g, b; //rouge, vert, bleu
};

struct image {
  int largeur, hauteur;
  int max;
  struct couleur **pixel;
};

typedef struct couleur **drapeau;
```

Le type `struct couleur` représente une couleur (si le champ `existe`
vaut `true`) ou une non-couleur (si le champ `existe` vaut `false`).

Le type `struct image` correspond à une image en mémoire de dimensions
`largeur*hauteur`, avec des couleurs allant de 0 à `max`.

L'instruction `typedef` sert à définir des synonymes de types.
Le type `drapeau` correspond à un drapeau, c'est-à-dire un tableau
bidimensionnel de couleurs de dimension `LARGEUR*HAUTEUR` et des
couleurs allant de 0 à `COULEUR_MAX`. Le premier indice dans un
drapeau correspond à la hauteur, il varie donc entre 0 et `HAUTEUR -
1`.

On vous fournit un certain nombre de fonctions pré-implémentées dans
le fichier `jeu_du_drapeau.c`. Voici celles que vous serez amenés à
lire ou à utiliser pour tout le début du TP :

```C
bool couleurs_semblables(struct couleur c1, struct couleur c2);
struct image *load_image(const char *fichier);
void save_image(const char *fichier, drapeau d);
```

**Question 1.** En regardant les allocations de mémoire faites dans la
fonction `load_image`, écrivez une fonction

```C
void free_image(struct image *img);
```

qui libère la mémoire allouée par `load_image`.
Testez votre fonction en décommentant le test associé, en compilant
avec les options `-g -fsanitize=address` (sans oublier `-lm` en fin de
ligne pour la librairie de math), puis en exécutant.

**Question 2.** Écrire les fonctions

```C
drapeau init_drapeau(); //allocation de la mémoire liée à un drapeau
void free_drapeau(drapeau d); //libération de la mémoire liée à un drapeau
```

qui respectivement initialise et libère la mémoire liée à un
drapeau. Pour rappel, le premier indice dans un
drapeau correspond à la hauteur, il varie donc entre 0 et `HAUTEUR -
1`.

Tester la fonction en décommentant le test associé, en compilant
avec les options `-g -fsanitize=address` (sans oublier `-lm` en fin de
ligne pour la librairie de math), puis en exécutant.

**Question 3.** Écrire la fonction

```C
drapeau drapeau_noir(); //revoie un drapeau avec uniquement des non-couleurs
```

qui respectivement initialise un drapeau dont tous les pixels sont des non-couleurs.

**Question 4.** Écrire la fonction

```C
drapeau image_to_drapeau(struct image *img);
```

qui renvoie le drapeau associé à une image (il s'agit essentiellement
d'une mise à l'échelle).

Vous pouvez tester votre fonction en affichant le drapeau français
avec `display Drapeaux/france.ppm`, puis en affichant le résultat pour
le fichier `test_france.ppm`.

**Question 5.** Écrire la fonction

```C
struct couleur intersect_couleurs(struct couleur c1, struct couleur c2);
```

qui prend en paramètre deux couleurs, et renvoie l'une d'elle si elles
sont considérées comme semblables par la fonction
`couleurs_semblables` et une absence de couleur sinon (en utilisant le
champ `existe` du type `struct couleur`).

Vous pouvez faire un test avec la fonction `test_intersect_couleurs`.

**Question 6.** Écrire la fonction

```C
drapeau intersection_drapeaux(drapeau d1, drapeau d2);
```
qui crée un nouveau drapeau avec l'intersection des couleurs des deux
drapeaux fournis en argument.

Vous pouvez tester en faisant l'intersection de deux drapeaux et en
regardant le résultat.

**Question 7.** Écrire la fonction

```C
struct couleur union_couleurs(struct couleur c1, struct couleur c2);
```

qui renvoie une non-couleur si ses deux paramètres sont des
non-couleurs, la vraie couleur si un de ses paramètre est une couleur
et l'autre une non-couleur, et une des deux couleurs passées en
paramètre sinon.

**Question 8.** Écrire la fonction

```C
drapeau union_drapeaux(drapeau d1, drapeau d2);
```
qui crée un nouveau drapeau avec l'union des couleurs des deux
drapeaux fournis en argument.


Pour mettre en place le jeu, on a besoin des fonctions auxiliaires
suivantes, qui se trouvent dans le fichier `auxiliaire.c` :

```C
void affiche_image(const char *fichier);
void ferme_image();
void attendre();
drapeau drapeau_pays_mystere(const char *rep);
drapeau drapeau_pays_propose(const char *rep);
```

Pour compiler du code écrit sur deux fichiers, il suffit de mettre les
noms des deux fichiers après `gcc`. Attention : les fonctions
d'affichage ne fonctionneront que sur un système de type unix/linux.

**Question 9.** Écrire une fonction

```C
void jeu();
```
qui permet de jouer au jeu du drapeau.
