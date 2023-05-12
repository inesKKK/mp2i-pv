TP25 : tableaux bidimensionnels en `C` et détection de contours
==

Rappel: compilez avec le plus d'options possibles, par exemple `-Wall
-Wno-unused -pedantic -Werror -Wextra`.


## Révisions sur les tableaux et les pointeurs
On sait qu'en `C` les tableaux statiques et les pointeurs alloués par `malloc`
ne se trouvent pas dans la même zone mémoire. Ainsi l'exécution du
programme [dim1a.c](dim1a.c) suivant:

```C
int main(void){
  int *t0 = (int *)malloc(3*sizeof(int));
  int t1[] = {1,2,3};
  int t2[3];
  int *t3 = (int *)malloc(3*sizeof(int));

  t0[0] = 4;
  t1[0] = 5;
  t2[0] = 6;
  t3[0] = 7;

  printf("t0 : %p\nt1 : %p\nt2 : %p\nt3 : %p\n", (void *)t0, (void *)t1, (void *)t2, (void *)t3);
  
  return 0;
}
```

permet de constater ce phénomène. Vous pouvez aussi exécuter le
programme sur [C tutor](https://pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Aint%20main%28void%29%7B%0A%20%20int%20*t0%20%3D%20%28int%20*%29malloc%283*sizeof%28int%29%29%3B%0A%20%20int%20t1%5B%5D%20%3D%20%7B1,2,3%7D%3B%0A%20%20int%20t2%5B3%5D%3B%0A%20%20int%20*t3%20%3D%20%28int%20*%29malloc%283*sizeof%28int%29%29%3B%0A%0A%20%20t0%5B0%5D%20%3D%204%3B%0A%20%20t1%5B0%5D%20%3D%205%3B%0A%20%20t2%5B0%5D%20%3D%206%3B%0A%20%20t3%5B0%5D%20%3D%207%3B%0A%0A%20%20printf%28%22t0%20%3A%20%25p%5Cnt1%20%3A%20%25p%5Cnt2%20%3A%20%25p%5Cnt3%20%3A%20%25p%5Cn%22,%20%28void%20*%29t0,%20%28void%20*%29t1,%20%28void%20*%29t2,%20%28void%20*%29t3%29%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D).

On a vu que les en-têtes suivantes de fonctions sont complètement
équivalentes:

```C
void fp(int *t);
void ft(int t[]);
```
et qu'on peut donner `t0`, `t1`, `t2` ou `t3` en argument à ces deux
fonctions sans problème.

On a aussi évoqué le fait que les adresses des cases d'un tableau
(statique ou alloué avec `malloc`) sont consécutives (en laissant la
place pour les données bien sûr), ce qu'on peut constater avec le
programme [dim1b.c](dim1b.c):

```C
/* dans la vraie vie il faudrait faire un tableau avec toutes les
adresses et une fonction intermédiaire, mais le but de ce TP étant
de mieux comprendre les tableaux 2D, je m'abstiens.
*/
int main(void){
  int *t0 = (int *)malloc(3*sizeof(int));
  int t1[] = {1,2,3};
  int t2[3];
  int *t3 = (int *)malloc(3*sizeof(int));

  printf("t0 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t0[i]);
  }
  printf("\n\n");

  printf("t1 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t1[i]);
  }
  printf("\n\n");

  printf("t2 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t2[i]);
  }
  printf("\n\n");

  printf("t3 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t3[i]);
  }
  printf("\n\n");

  return 0;
}
```

Que se passe-t-il en dimension 2 ? Les effets en mémoire des
déclarations suivantes sont-elles fondamentatement différentes ?

```C
  int **tt0 = (int **)malloc(3*sizeof(int *));
  int *tt1[3];
  int tt2[3][2];
  int tt3[][2] = {{1,2},{3,4},{5,6}};

  for(int i=0; i<3; i=i+1){
    tt0[i] = (int *)malloc(2*sizeof(int));
    tt1[i] = (int *)malloc(2*sizeof(int));
  }
```


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
