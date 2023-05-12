TP25 : tableaux bidimensionnels en `C` et détection de contours
==

Rappel: compilez avec le plus d'options possibles, par exemple `-Wall
-Wno-unused -pedantic -Werror -Wextra`.




En adaptant `dim1a.c`, affichez les adresses de `tt0`, `tt1`, `tt2`, puis
les adresses des trois sous-tableaux de chacun.

Exécutez votre programme sur [C tutor](https://pythontutor.com/c.html#mode=edit) pour comprendre comment sont réparties les données.

Affichez les adresses des deux cases de chacun des trois sous-tableaux
de `tt0`, puis de ceux de `tt1`, puis de ceux de `tt2`.

Regardez de plus près les adresses de `t[0][1]` et `t[1][0]` (pour `t`
prenant les valeurs `tt0`, `tt1`, `tt2`et `tt3`). Que remarquez-vous ? Que
pouvez-vous conclure sur la façon dont les tableaux `tt2` et `tt3`
sont rangés en mémoire ?

Regardons maintenant ce qui se passe avec les fonctions.

On considère les quatre fonctions suivantes disponibles dans le fichier
[dim2b.c](dim2b.c):

```C
void fpp(int **t){
  printf("fpp\n");
}

void fpt(int *t[]){
  printf("fpt\n");
}

void ftt1(int t[3][2]){
  printf("ftt1\n");
}

void ftt2(int t[][2]){
  printf("ftt2\n");
}
```

Essayez d'invoquer ces fonctions avec `tt0`, `tt1`, `tt2` et `tt3`
comme argument. Faites le bilan de ce qui est possible et de ce qui ne
l'est pas.


Bien sûr, il faut garder en tête qu'une fonction ne ne peut pas
renvoyer une adresse dans sa pile d'appel, puisqu' à la sortie de
l'appel cet adresse n'a plus de sens. En revanche, rien n'interdit de
transmettre à un appel de fonction une adresse locale, l'appel ayant
alors la possibilité de modifier le contenu à cette adresse.

## Contour d'image

Dans ce qui suit, je vais utiliser des variables déclarées `const`
comme longueurs de tableaux statiques au lieu de macro définies avec
`#define`. En fait ce sont du coup des VLA - *variable length array*,
qui sont donc explicitement hors programme. Mais un
des concours a utilisé ça dans un énoncé. Au moins vous l'aurez vu une fois.

### Par dérivée

Le but ici est de partir d'une image au format pgm ascii de taille
400x600 et d'en extraire le contour (sous forme d'une image de
même dimension et au même format, ne contenant que du noir et du
blanc).

Par exemple l'image

![](img/paul_valery.png)

permet d'obtenir le contour

![](img/contours_paul_valery.png)

Le principe pour trouver le contour d'une image, est de repérer les
points dont la couleur varie particulièrement par rapport aux couleurs
des voisins.

Pour cela, on regarde la variation par rapport au voisin du dessous
et au voisin de droite (en fait par rapport au voisin obtenu en
décrémentant l'abscisse et au voisin obtenu en décrémentant
l'ordonnée, peu importe l'orientation de l'image).

Le but est d'écrire les fonctions `derive` et `seuil` déclarées dans
le fichier [contours.h](contours.h) de façon à pouvoir exécuter la
fonction principale contenue dans [main.c](main.c).

Pour `derive`: la valeur obtenue pour le pixel
 ![](https://latex.codecogs.com/svg.image?(x,y)&space;) est
 ![](https://latex.codecogs.com/svg.image?\sqrt{\bigl(I(x,y)-I(x-1,y)\bigr)^2&plus;\bigl(I(x,y)-I(x,y-1)\bigr)^2}&space;)
 (quand cela a un sens).

La fonction `seuil` permet ensuite de modifier l'image transmise en
mettant 0 pour les valeurs inférieures au seuil et 1 pour les autres
(dans l'exemple j'ai pris un seuil de 4000).


### Par filtres plus perfectionnés

Il existe des opérateurs permettant de détecter les contours de façon
un peu plus fine, en variant les directions considérées. Ils s'écrivent tous sous forme de matrice 3x3
noté  ![](https://latex.codecogs.com/svg.image?f) et
s'appliquent sous forme de produit de convolution:

![](https://latex.codecogs.com/svg.image?\sum_{u=-1}^{1}&space;\sum_{v=-1}^{1}&space;f(u,v)\times&space;I\bigl(x-u,y-v\bigr)&space;)

(Il faut bien entendu faire attention aux bords.)

Écrire une fonction qui prend pour paramètre une image source sous la
forme d'un tableau d'entiers de taille `haut`x`larg`, un filtre de
taille 3x3, et une image destination sous la
forme d'un tableau d'entiers de taille `haut`x`larg` et remplit
l'image destination avec le produit de convolution.

Vous pouvez faire des tentatives avec les filtres suivants:

* opérateurs de Prewitt:

![](https://latex.codecogs.com/svg.image?\frac{1}{3}\begin{pmatrix}-1&space;&&space;0&space;&&space;1%5C%5C-1&space;&&space;0&space;&&space;1%5C%5C-1&space;&&space;0&space;&&space;1\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{3}\begin{pmatrix}-1&space;&&space;-1&space;&&space;-1%5C%5C0&space;&&space;0&space;&&space;0%5C%5C1&space;&&space;1&space;&&space;1\end{pmatrix}&space;)

* opérateurs de Sobel:

![](https://latex.codecogs.com/svg.image?\frac{1}{4}\begin{pmatrix}-1&space;&&space;0&space;&&space;1%5C%5C-2&space;&&space;0&space;&&space;2%5C%5C-1&space;&&space;0&space;&&space;1\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{4}\begin{pmatrix}-1&space;&&space;-2&space;&&space;-1%5C%5C0&space;&&space;0&space;&&space;0%5C%5C-1&space;&&space;-2&space;&&space;-1\end{pmatrix}&space;)

* opérateurs de Kirch

![](https://latex.codecogs.com/svg.image?\frac{1}{15}\begin{pmatrix}-3&space;&&space;-3&space;&&space;-5%5C%5C-3&space;&&space;0&space;&&space;5%5C%5C-3&space;&&space;-3&space;&&space;5\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{15}\begin{pmatrix}-3&space;&&space;-3&space;&&space;-3%5C%5C-3&space;&&space;0&space;&&space;-3%5C%5C5&space;&&space;5&space;&&space;5\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{15}\begin{pmatrix}-3&space;&&space;-3&space;&&space;-3%5C%5C5&space;&&space;0&space;&&space;-3%5C%5C5&space;&&space;5&space;&&space;-3\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{15}\begin{pmatrix}5&space;&&space;5&space;&&space;-3%5C%5C5&space;&&space;0&space;&&space;-3%5C%5C-3&space;&&space;-3&space;&&space;-3\end{pmatrix}&space;)

* opérateurs de Robinson

![](https://latex.codecogs.com/svg.image?\frac{1}{5}\begin{pmatrix}-1&space;&&space;1&space;&&space;1%5C%5C-1&space;&&space;-2&space;&&space;1%5C%5C-1&space;&&space;1&space;&&space;1\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{5}\begin{pmatrix}-1&space;&&space;-1&space;&&space;-1%5C%5C1&space;&&space;-2&space;&&space;1%5C%5C1&space;&&space;1&space;&&space;1\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{5}\begin{pmatrix}-1&space;&&space;1&space;&&space;1%5C%5C-1&space;&&space;-2&space;&&space;1%5C%5C-1&space;&&space;11&space;&&space;1\end{pmatrix}&space;)

![](https://latex.codecogs.com/svg.image?\frac{1}{5}\begin{pmatrix}-1&space;&&space;-1&space;&&space;1%5C%5C-1&space;&&space;-2&space;&&space;1%5C%5C1&space;&&space;1&space;&&space;1\end{pmatrix}&space;)

* laplacien

![](https://latex.codecogs.com/svg.image?\begin{pmatrix}0&space;&&space;-1&space;&&space;0%5C%5C-1&space;&&space;4&space;&&space;-1%5C%5C0&space;&&space;-1&space;&&space;0\end{pmatrix}&space;)
