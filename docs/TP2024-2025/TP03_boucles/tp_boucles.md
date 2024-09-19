# TP3 : Boucles

Toutes les semaines, les TP seront à rendre pour le mercredi soir
suivant au plus tard, sur cahier-de-prepa. 

Chaque TP sera composé de deux parties:
* flocon : partie dédiée à ceux parmi vous qui n'ont jamais programmé
  ou se sentent en difficulté;
* première étoile : partie dédiée à ceux qui ont déjà programmé et à
  ceux qui ont réussi la partie flocon rapidement.
  
Le but de **ceux qui choisissent la partie flocon** doit être
d'arriver petit à petit de plus en plus loin dans la partie première
étoile.

**Ceux qui choisissent la partie première étoile** n'ont pas besoin de
faire la partie flocon, et dans l'idéal doivent terminer la partie
première étoile.


> Les réponses sont à rendre dans un ou plusieurs fichiers sources, en
ajoutant en commentaire vos nom et prénom sur la première ligne, la
ligne de compilation à utiliser sur la deuxième ligne, et en
identifiant de manière claire les numéros d'exercices et de
questions.

Pour certains exercices, je fournis un fichier qui contient un
`main` avec des tests. À vous de compléter ce fichier en écrivant la
fonction demandée (avant le `main`), de le compiler et de
l'exécuter. Pour les exercices consistant à faire des affichages, à
vous d'écrire le `main` avec un ou deux exemples pour voir si ce qui
s'affiche est ce qui est attendu.


## Flocon -- pour ceux qui n'ont jamais programmé

**Exercice 1**
Écrire une fonction `max2` qui prend en argument deux entiers et renvoie leur max.

[max2.c](tests/max2.c)

**Exercice 2**
Écrire une fonction `max3` qui prend en argument trois entiers et utilise `max2` pour calculer le max de ses trois arguments.


[max3.c](tests/max3.c)


Dans la suite, vous aurez besoin de faire quelques affichages. Pour afficher une étoile, il suffit d'utiliser l'instruction
```C
printf("*");
```

À noter que pour utiliser la fonction `printf`, il faut au début du programme signaler qu'on utilise les fonctions d'entrée/sortie de la librairie standard, grâce à la ligne
```C
#include <stdio.h>
```

**Exercice 3**
Écrire une fonction `ligne` qui prend en argument un entier et affiche une ligne d'étoiles de longueur cet entier.

Par exemple l'appel à `ligne(15)` doit produire l'affichage
```
***************
```


**Exercice 4**
Pour effectuer un retour à la ligne, il suffit d'utiliser l'instruction
```C
printf("\n");
```

Écrire une fonction `colonne` qui prend en argument un entier et affiche une colonne d'étoiles de hauteur cet entier, suivie d'un retour à la ligne.

Par exemple l'appel à `colonne(15)` doit produire l'affichage
```
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
```

**Exercice 5**
Écrire une fonction `triangle` qui prend en argument un entier et affiche un triangle rectangle d'étoiles de hauteur et largeur cet entier, suivi d'un retour à la ligne.

Par exemple l'appel à `triangle(5)` doit produire l'affichage
```
*
**
***
****
*****
```

**Exercice 6**
Écrire une fonction `alternance` qui prend en argument trois entiers et affiche alternativement une ligne d'étoiles de longueur chacun des deux premiers entiers, le nombre total de ligne étant spécifié par le 3e entier.

Par exemple l'appel à `alternance(5,3,8)` affiche
```
*****
***
*****
***
*****
***
*****
***
```

**Exercice 7**
Pour afficher un espace, il faut utiliser l'instruction
```C
printf(" ");
```

Écrire une fonction `croix_negative` qui prend en argument un entier et affiche une croix blanche sur fond étoilé dont la diagonale est de longueur cet entier s'il est impair et le suivant s'il est pair.

Par exemple les appels à `croix_negative(8)` et `croix_negative(9)` affichent tous les deux
```
 ******** 
* ****** *
** **** **
*** ** ***
****  ****
*** ** ***
** **** **
* ****** *
 ******** 
 ```

**Exercice 8**
Faites l'exercice 10 de la partie première étoile.


## Première étoile -- pour ceux qui ont déjà programmé et ceux qui ont facilement fini le flocon

**Exercice 9**
Si vous n'avez pas fait la partie flocon, faites les exercices 6 et 7 ci-dessus.


Rappel: quand on utilise l'opérateur '/' entre deux entiers, on obtient le quotient de la division euclidienne. Le reste lui est obtenu grâce à l'opérateur `%`.

Pour afficher la valeur d'un entier `n`, on utilise l'appel de fonction
```C
printf("%d", n);
```
et pour effectuer un retour à la ligne, l'appel
```C
printf("\n");
```

**Exercice 10**
Écrire une fonction `ecriture_binaire_positif` qui prend en argument un entier supposé strictement positif et écrit sa représentation en base 2.

[base2.c](tests/base2.c)


**Exercice 11**
Écrire maintenant une fonction `representation_32_bits_positifs` qui prend en argument un entier positif supposé dans le bon ensemble pour pouvoir être représenté par un `int32_t` et affiche sa représentation en tant que `int32_t`.


**Exercice 12**
Un nombre _parfait_ est un nombre égal à la somme de ses diviseurs stricts. Écrire une fonction `parfait` qui prend en argument un entier supposé strictement positif et teste s'il est parfait. (Détail amusant: on ne connaît aucun nombre parfait impair.)

[parfait.c](tests/parfait.c)


**Exercice 13**
Écrire une fonction `nb_de_chiffres` qui prend en argument un entier supposé positif et renvoie le nombre de chiffres de cet entier en base 10.

[nb_de_chiffres.c](tests/nb_de_chiffres.c)


**Exercice 14**
D'après wikipedia, un [_nombre de Kaprekar_](https://fr.wikipedia.org/wiki/Nombre_de_Kaprekar) est un entier naturel qui, dans une base donnée, lorsqu'il est élevé au carré, peut être séparé en une partie gauche et une partie droite (non nulle) telles que la somme donne le nombre initial.

Écrire une fonction `Kaprekar` qui teste si un nombre est de Kaprekar.

[kaprekar.c](tests/kaprekar.c)


## Deuxième étoile -- pour ceux qui ont facilement fini la première étoile

Si vous en êtes là, écrivez vos propres tests dans la fonction `main`.

**Exercice 15**
On ne peut pas fabriquer une suite aléatoire d'entiers avec des
méthodes arithmétiques. Néanmoins, on peut fabriquer une suite
d'entiers qui semble aléatoire. Von Neumann a proposé la méthode
suivante en 1946 :

* on part d'un entier $n$
* on répète l'opération :
   * $n$ est une sortie du générateur
   * $m=n^2$
   * $n$ prend la valeur du nombre formé par les 4 chiffres au centre
     de $m$ si $m$ comporte 8 chiffres et les 4 chiffres au centre de
     $10m$ si $m$ en comporte 7 (tout ça en base 10).
 
 Ainsi, si au départ $n=1111$, alors le début de cette suite est
 
 * $1111$
 * $3432$ (car $1111^2=12\underline{3432}1$)
 * $7786$ (car $3432^2=11\underline{7786}24$)
 
 Écrire une fonction `int entier_suivant(int n)` qui prend en argument
 un terme de cette suite et fournit le suivant (en supposant que `n`
 s'écrit sur 4 chiffres, sans avoir à le vérifier).
 
 Écrire une fonction `int apparition_de_n(int n)` qui affiche tous les
 rangs de la suite où l'entier est `n` (on suppose qu'on commence par
 `n` et qu'il s'agit du rang 0) parmi les 10000 premiers rangs, et
 renvoie le nombre d'occurences de `n` dans ce début de suite.
 
 Quels sont les entiers qui se répètent plusieurs fois si on commence
 par eux ? (Écrire un programme qui permet de répondre à la question.)
 

**Exercice 16**
Écrire une fonction `unsigned int miroir(unsigned int n)`
qui renvoie le nombre miroir de `n` en base 10, c'est-à-dire celui
composé avec les chiffres de `n` en base 10 lus de droite à gauche.

On appelle *palindrome* un nombre qu'on peut lire indifféremment de
gauche à droite ou de droite à gauche (ex : 121, 1221). Écrire une
fonction `bool est_palindrome(unsigned int n)` qui détermine si
l'écriture de `n` en base 10 est un palindrome ou pas.


**Exercice 17**
Écrire maintenant une fonction `representation_32_bits` qui prend en argument un entier supposé dans le bon ensemble pour pouvoir être représenté par un `int32_t` et affiche sa représentation en tant que `int32_t`.
