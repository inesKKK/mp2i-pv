# TP de révisions, partie `C` -- vacances de Noël


* Commencez par vérifier que vous avez fait les TP du semestre en
  entier. Si ce n'est pas le cas, terminez-les.
* Je ne corrigerai pas ces exercices : je vous propose des valeurs
  tests (souvent en vous fournissant un fichier à compléter contenant
  le `main`, et pour les exercices graphiques vous pouvez regarder si
  ça a l'air bien).

Voici la ligne de compilation la plus complète que vous puissiez
utiliser et qui repère pas mal d'erreurs (mais bien sûr pas toutes
puisque certaines erreurs ne peuvent apparaître qu'à l'exécution):

```bash
gcc -O -Wall -Wextra -Wpedantic -std=c11 -o toto toto.c -fsanitize=address,undefined
```

(Dans l'hypothèse où votre fichier source s'appelle `toto.c` et que
vous souhaitez que votre exécutable s'appelle `toto`.)

Pour certains exercices, je vous fournis un bout de programme à
compléter, ce qui vous permet de faire des tests.

## Fonctions simples

Écrire une fonction `surface` qui prend en argument un double supposé
être le rayon d'un disque et renvoie l'aire de ce disque.

----

Écrire une fonction sapin qui prend en argument un entier et affiche un sapin sous la forme suivante :

sapin(4) :
```
   **
  *  *
 *    *
*      *
********
   ||
```

sapin(3) :
```
  **
 *  *
*    *
******
  ||
```

## Adresses

Fichier à compléter pour les deux fonctions suivantes :
[main_racines.c](main_racines.c).

Écrire une fonction `discriminant` qui prend en argument trois nombres
flottants `a`, `b` et `c` supposés représenter les coefficients dans
l'équation du second degré $ax^2 + bx + c = 0$, `a` étant supposé non
nul, et renvoie la valeur du disciminant de cette équation.

Écrire une fonction `racines` qui prend en argument:
*  trois nombres flottants `a`, `b` et `c` supposés représenter les
coefficients dans l'équation $ax^2 + bx + c = 0$ (`a` pas
nécessairement nul ici),
* les adresses de deux nombres flottants qui serviront à stocker la ou
  les éventuelles solution(s) de l'équation (si une seule solution:
  dans le premier entier, si une infinité, pas de solution stockée).
* et renvoie un entier contenant le nombre de solutions
  de l'équation (convention : -1 en cas de nombre infini de solutions),
  
---

Soit le type `image` défini comme suit :

```C
struct image {
    int larg, haut; //largeur et hauteur
    bool **p; // false pour blanc, true pour noir
};

typedef struct image image;
```

Je vous donne une fonction d'affichage d'image : [affichage_images.c](affichage_images.c).

Écrire les fonctions suivantes :

* `image *intersection(image *im1, image *im2)` qui prend en argument
  deux adresses d'images; si ces images ont des tailles différentes,
  la fonction renvoie un pointeur `NULL`, si elles ont la même taille,
  elle renvoie l'adresse d'une nouvelle image qui correspond à
  l'intersection des deux images, c'est-à-dire qu'un pixel est noir si
  et seulement s'il l'était dans les deux images,
* `image *union(image *im1, image *im2)` : de même mais avec l'union
  (un pixel est noir si et seulement s'il l'était dans au moins une des deux images).

---

[Difficile] Après avoir lu la page wikipedia sur l'[algorithme de
Bresenham](https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham),
implémenter une fonction qui permet de tracer un segment sur un plan
discret en suivant cet algorithme. Vous utiliserez le type `image`
introduit à l'exercice précédent et ferez l'affichage avec la fonction
fournie pour.

## Types structurés

On considère le type `complexe` défini comme suit :

```C
struct complexe {
    double re; // partie réelle
    double im; // partie imaginaire
};

typedef struct complexe complexe;
```

Écrire les fonctions suivantes (dont la signification est donnée par
le nom) :

* `complexe somme(complexe c1, complexe c2)`
* `complexe produit(complexe c1, complexe c2)`
* `complexe différence(complexe c1, complexe c2)`
* `complexe norme(complexe c1, complexe c2)`
* `complexe quotient(complexe c1, complexe c2)`

Je vous donne une fonction d'affichage et à vous de trouver des tests:
[affichage_complexes.c](affichage_complexes.c).
