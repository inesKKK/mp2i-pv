# TP4 : tableaux unidimensionnels
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

**Comme on n'a pas vu comment fournir un tableau en argument à une
fonction, je vous donne les en-têtes de fonctions. Vous ne pouvez pas
les comprendre, mais avec la documentation vous pouvez quand même
utiliser les paramètres.**

## Flocon -- pour ceux qui n'ont jamais programmé
### Exercice 1 : Nombre d'éléments positifs

Écrire une fonction `nombres_positifs` qui prend en argument un
tableau d'entiers et un entier représentant la taille de ce tableau et
renvoie le nombre de cases du tableau dont la valeur est positive ou
nulle.

[nombres_positifs.c](tests/nombres_positifs.c)

### Exercice 2 : Somme des éléments d'un tableau

Écrire une fonction `somme` qui prend en argument un
tableau de double et un entier représentant la taille de ce tableau et
renvoie la somme des valeurs des cases de ce tableau.


[somme.c](tests/somme.c)

### Exercice 3 : Recherche d'un élément

1. Écrire une fonction `trouve` qui prend en argument une valeur
entière, un tableau d'entiers et un entier représentant la taille de
ce tableau et renvoie `true` si et seulement si la valeur apparaît
dans au moins une case du tableau.

[trouve.c](tests/trouve.c)

L'instruction `break` permet de sortir de la boucle dans laquelle elle
est exécutée. Par exemple la suite d'instructions:

```C
int i;
for(i = 0; i<53; i = i+1){
    if(i == 27){
        break;
    }
}
printf("valeur de i à la sortie de la boucle : %d\n", i);
```

provoque l'affichage suivant:

```C
valeur de i à la sortie de la boucle : 27
```

2. Reprenez le code de la fonction `trouve` écrit à la question
   précédente et faites en sorte de minimiser le nombre d'itérations
   dans votre boucle.

### Exercice 4 : Produit scalaire
Écrire une fonction `produit_scalaire` qui prend en argument deux
vecteurs de même dimension donnés sous la forme d'un tableau d'entiers
et leur dimension, et renvoie leur produit scalaire.

[produit_scalaire.c](tests/produit_scalaire.c)

### Exercice 5 : Plagiat
Écrire et documenter une fonction `copie` qui prend en argument deux
tableaux d'entiers de même taille et leur taille, et copie le contenu
du premier tableau dans le deuxième.

[copie.c](tests/copie.c)

### Exercice 6 : Inversion d'éléments
Écrire une fonction `miroir` qui prend en argument deux
tableaux de booléens de même taille et leur taille, et teste si le
contenu du deuxième tableau est 'egal au contenu du premier mais dans
l'autre sens.

[miroir.c](tests/miroir.c)

## Première étoile -- pour ceux qui sont à l'aise en programmation et ceux qui ont facilement fini le flocon

### Exercice 7 : Plus petite distance
Écrire une fonction `plus_petite_distance` qui prend en argument un tableau de `double` supposé trié dans l'ordre croissant (sans avoir à le vérifier) et sa longueur et renvoie la plus petite distance entre deux nombres de ce tableau, sinon la constante `INFINITY` définie dans le fichier d'en-tête `math.h`.

[plus_petite_distance.c](tests/plus_petite_distance.c)

### Exercice 8 : Périodicité
Écrire une fonction qui prend en argument un tableau d'entiers, sa
taille et un entier `p`, et teste si un tableau est `p`-périodique
(c'est-à-dire si ses valeurs se répètent toutes les `p` cases, on ne
cherche pas à ce que `p` soit la plus petite période).

[periodique.c](tests/periodique.c)

### Exercice 9 : Maxima locaux
Si je considère un tableaux de valeurs comparables (par exemple des nombres), je peux définir une case comme un _maximum local_ si ses deux voisines ont des valeurs strictement inférieures à elle (une case avec une seule voisine n'est pas un maximum local).

1. Écrire une fonction `maximum_local` qui prend en argument un tableau d'entiers, sa taille et un indice et teste si la valeur à cet indice est un maximum local.

[maximum_local.c](tests/maximum_local.c)


L'instruction `break` permet de sortir de la boucle dans laquelle elle
est exécutée. Par exemple la suite d'instructions:

```C
int i;
for(i = 0; i<53; i = i+1){
    if(i == 27){
        break;
    }
}
printf("valeur de i à la sortie de la boucle : %d\n", i);
```

provoque l'affichage suivant:

```C
valeur de i à la sortie de la boucle : 27
```

2. Parfois on a des plateaux (plusieurs cases de suite qui ont la même valeur), et il faut donc aller chercher plus loin si la valeur descend ou pas. Écrire une fonction `vrai_maximum_local` en adaptant `maximum_local` pour que cela tienne compte de cette situation possible : une case est maintenant un maximum local si elle appartient à un plateau qui est encadré de valeurs strictement inférieures.

### Exercice 10 : complément à 2
Écrire une fonction `complement_a_deux` qui prend en argument un entier supposé compris
entre $-2^7$ et $2^7-1$ (sans avoir à le vérifier) et un tableau
de booléens supposé de taille 8 correspondant et modifie le contenu de ce
tableau de sorte qu'il contienne la représentation en
complément à 2 de l'entier, avec `false` représentant un bit à
0 et `true` un bit à 1.

[complement_a_deux.c](tests/complement_a_deux.c)

## Deuxième étoile -- pour ceux qui ont facilement fini la première étoile

Si vous en êtes là, écrivez vos propres tests dans la fonction `main`
et vos en-têtes de fonction (en vous inspirant des en-têtes dans les
autres exercices).


### Exercice 11 : Périodicité exacte
Écrire une fonction qui prend en argument un tableau d'entiers, sa
taille et renvoie le plus petit entier `p`tel que le tableau est
`p`-périodique.


### Exercice 12 : Permutation
Si $n$ est un entier, on peut donner une application $\{ 0,\dots,
n\} \to \{ 0, \dots,n\}$ sous la forme d'un tableau
à $n+1$ cases dont la case $i$ contient l'image de l'entier $i$.

Écrire une fonction `inverse` qui prend en argument un tableau
représentant une fonction $f : \{ 0, \dots, n\} \to \{ 0,\dots
n\}$, un entier donnant $n$ et un tableau $t$ de taille $n+1$ dont
le comportement est le suivant:
* si $f$ est une bijection, alors le contenu de $t$ est modifié pour
  que $t$ représente l'inverse de la fonction $f$, et la valeur `true`
  est renvoyée,
* sinon la valeur `false` est renvoyée.

### Exercice 13 : Compter des chiffres
Écrire une fonction `nb_de_chiffres` qui prend en argument deux
entiers, `n` et `b`, où on suppose que `b` appartient à $[0,9]$, et
renvoie le chiffre le plus fréquent dans l'écriture de `n` en base `b`.

### Exercice 14 : Tri par sélection
Le tri par sélection des éléments d'un tableau peut être fait en place
de la manière suivante : on sélectionne le maximum, qu'on met à sa
place, on l'oublie et on recommence jusqu'à avoir tout
placé. Implémenter un tel tri sur un tableau d'entiers.

### Exercice 15 : IEEE 754
Écrire une fonction qui affiche l'encodage d'un décimal en flottant
double précision selon la norme IEEE 754.
