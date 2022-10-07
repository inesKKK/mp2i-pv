# TP5 : tableaux unidimensionnels
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
l'exécuter. Pour les exercices consistant à faire des affichages, à
vous d'écrire le `main` avec un ou deux exemples pour voir si ce qui
s'affiche est ce qui est attendu.


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


Dans ce qui suit, un tableau de `double` de taille 25 est déclaré et initialisé. Déclarez une variable `somme` et faites en sorte que sa valeur soit la somme des éléments du tableau.

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

### Exercice 4 : Plagiat
Écrire et documenter une fonction `copie` qui prend en argument un tableau d'entiers et sa taille et renvoie une copie de ce tableau.

[copie.c](tests/copie.c)

### Exercice 5 : Inversion d'éléments
Écrire une fonction `miroir` qui prend en argument un tableau de
booléen et sa taille et renvoie un tableau de la même taille qui
contient les mêmes éléments mais dans l'ordre inverse.

[miroir.c](tests/miroir.c)

## Première étoile -- pour ceux qui sont à l'aise en programmation et ceux qui ont facilement fini le flocon

### Exercice 6 : Plus petite distance
Écrire une fonction `plus_petite_distance` qui prend en argument un tableau de `double` supposé trié dans l'ordre croissant (sans avoir à le vérifier) et sa longueur et renvoie la plus petite distance entre deux nombres de ce tableau, sinon la constante `INFINITY` définie dans le fichier d'en-tête `math.h`.

[plus_petite_distance.c](tests/plus_petite_distance.c)

### Exercice 7 : Périodicité
Écrire une fonction qui prend en argument un tableau d'entiers, sa
taille et un entier `p`, et teste si un tableau est `p`-périodique
(c'est-à-dire si ses valeurs se répètent toutes les `p` cases, on ne
cherche pas à ce que `p` soit la plus petite période).

[periodique.c](tests/periodique.c)

### Exercice 8 : Maxima locaux
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

### Exercice 9 : complément à 2
Écrire une fonction `complement_a_deux` qui prend en argument un entier supposé compris
entre $-2^7$ et $2^7-1$ (sans avoir à le vérifier) et qui renvoie un
tableau de booléens de taille 8 correspondant à la représentation en
complément à 2 de cet entier, de sorte que `false` représente un bit à
0 et `true` un bit à 1.

[complement_a_deux.c](tests/complement_a_deux.c)
