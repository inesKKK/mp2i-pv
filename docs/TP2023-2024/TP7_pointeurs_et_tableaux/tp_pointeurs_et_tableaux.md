# TP6 : pointeurs et tableaux
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


## Flocon -- pour ceux qui n'ont jamais programmé
### Exercice 1 : 
Échange d'entiers
La fonction suivante en `C` ne fonctionne pas :
```C
void echange_errone(int a, int b){
    int c = a;
    a = b;
    b = c;
}
```
Proposer une fonction `echange` qui permette d'échanger les valeurs de deux variables entières.

C'est à vous d'écrire une fonction `main`, dans un fichier
`echange.c`.

### Exercice 2 : Plagiat
Écrire et documenter une fonction `copie` qui prend en argument un tableau d'entiers et sa taille et renvoie une copie de ce tableau.

[plagiat.c](tests/plagiat.c)


### Exercice 3 : Suite récurrente
On considère une suite numérique $(u_n)_{n>= 0}$ donnée par son premier terme $(u_0)$ et la relation de récurrence $u_{n+1}=au_n+b$, où $u_0$, $a$ et $b$ sont des réels. Le but de cet exercice est de calculer les premiers termes de cette suite.

Écrire et documenter une fonction `premiers_termes` dont les paramètres sont, dans l'ordre, le terme initial de la suite, les coefficients $a$ et $b$, et le nombre de termes à calculer $n$ et renvoie un tableau qui contient les $n$ premiers termes de la suite.


[premiers_termes.c](tests/premiers_termes.c)

### Exercice 4 : Tri par dénombrement
Le tri par dénombrement peut être utilisé dans le cas où on doit trier des entiers positifs pas nécessairement distincts dont on connaît un majorant. Il est efficace si ce majorant n'est pas trop grand par rapport au nombre d'entiers à trier.
Son principe est le suivant : on parcourt les données et pour chaque valeur qui apparaît, on maintient à jour un compteur qui nous permet de savoir combien de fois chaque valeur a été vue. Avec ces nombres d'occurences, on peut à la fin reconstruire les données dans l'ordre croissant.

1. Écrire et documenter une fonction `tri_denombrement` qui prend dans l'ordre un tableau d'entiers supposés positifs ou nuls, sa taille et un majorant (sans faire de vérification), et renvoie un nouveau tableau avec les données dans l'ordre croissant.

[tri_denombrement.c](tests/tri_denombrement.c)

2. Quelle est la complexité du tri par dénombrement ?


### Exercice 5 : Crible d'Eratosthene
Le crible d'Eratosthene est un algorithme pour trouver les nombres premiers parmi les $n$ premiers entiers. Son principe est le suivant : on considère un tableau représentant les entiers de 2 à $n$. Le plus petit entier non entouré et non barré est premier, on l'entoure et on barre tous ses multiples, puis on recommence, comme illustré dans l'animation ci-dessous :

![](https://upload.wikimedia.org/wikipedia/commons/8/8c/New_Animation_Sieve_of_Eratosthenes.gif)

Écrire et documenter une fonction `eratosthene` qui prend en argument un entier $n$. Si cet entier est positif ou nul, elle doit renvoyer un tableau de booléens de taille $n+1$ tel que la case $i$ du tableau vaut `true` si et seulement si $i$ est un nombre premier.

[Eratosthene.c](tests/Eratosthene.c)

## Première étoile -- pour ceux qui sont à l'aise en programmation et ceux qui ont facilement fini le flocon
### Exercice 6 :  Triangle de Pascal
Le triangle de pascal est une technique qui permet d'obtenir une généralisation de l'identité remarquable $(a+b)^2 = a^2 + 2ab + b^2$, en donnant les coefficients de $(a+b)^n$. Pour rappel, ces coefficients sont les coefficients binomiaux :

```math
(a+b)^n = \sum\limits_{k=0}^{n} \begin{pmatrix}n\\k\end{pmatrix} a^kb^{n-k}\:.
```

Le principe est le suivant : on part du tableau 
$t_0=$ |1| et on crée un nouveau tableau $t_1$ contenant une case de plus que $t_0$ tel que la première et la dernière case de ce tableau valent toutes les deux 1, et la $i^e$ case de $t_1$ , pour toute autre valeur de $i$, vaut $t_0[i-1]+t_0[i]$. Et ainsi de suite.

On obtient ainsi : 

$t_1 =$

|1|1|

$t_2=$

|1|2|1|

et

$t_3 =$

|1|3|3|1|.

1. Écrire une fonction `ligne_suivante` qui prend en argument un tableau d'entiers `uint8_t` supposé être une ligne dans le triangle de Pascal et sa longueur (sans avoir à le vérifier) et renvoie la ligne suivante sous la forme d'un tableau.

[pascal.c](tests/pascal.c)

2. Écrire et documenter une fonction `triangle_de_Pascal` qui prend en argument un entier $n$ et affiche les $n+1$ premiers niveaux du triangle de Pascal. Si $n$ vaut 4, on s'attend à l'affichage
```bash
1
1 1
1 2 1
1 3 3 1
```

### Exercice 7 : Circulation automobile
Dans cet exercice nous allons simuler (de façon très simplifiée) la circulation automobile sur une route à une seule voie (et dans un seul sens! qui sera de droite à gauche pour des raisons esthétiques). L'idée est la suivante : on discrétise la route qui est donc assimilée à un tableau de petits entiers à $n$ cases (0 : la case est libre, sinon elle est occupée); si au temps $t$, un véhicule $v$ se trouve en case $i$, alors :

* si la case $i-1$ est libre au temps $t$, le véhicule $v$ se retrouvera en case $i-1$ au temps $t+1$,
* si la case $i-1$ est occupée au temps $t$, le véhicule $v$ reste en case $i$ au temps $t+1$.

Pour les cases extrêmales, on impose le comportement suivant :

* le véhicule en position 0 sort du champ de notre vue systématiquement,
* si la case $n-1$ est libre au temps $t$, alors un véhicule arrive de façon aléatoire dans cette case au temps $t+1$,
* si la case $n-1$ est occupée au temps $t$, alors aucun véhicule n'arrive dans cette case au temps $t+1$.


Nous allons fabriquer un modèle où il y a 4 types de véhicules (1, 2, 3 et 4; pour rappel 0 signifie que la portion de route est libre). La fonction suivante permet de fabriquer aléatoirement un véhicule (ou une portion de route vide) :


```C
/** frequence : la route est libre avec frequence 1/frequence
 * sortie : un entier entre 0 et 4 qui représente soit une portion de route libre, soit un type de véhicule
 */
uint8_t vehicule(int frequence){
    if(random()%frequence==0){
        return 0;
    } else {
        return (random()%4) + 1;
    }
}
```

1. Écrire et documenter une fonction `init` qui prend en argument deux entiers : la longueur visible de la route (=son nombre de cases) et la fréquence d'occupation au sens de la fonction `vehicule`, et renvoie un tableau de `uint8_t` de la bonne taille, dont chaque case contient 0 ou un entier représentant un type de véhicule (en utilisant la fonction `vehicule` fournie ci-dessus).

[circulation.c](tests/circulation.c)


2. Écrire et documenter une fonction `next` qui prend en argument l'état de la route (=le tableau qui décrit son occupation), sa longueur et la frequence, et calcule l'état suivant de la route.


3. La fonction ci-dessous permet d'afficher la route à un moment donné. Notez la composition entre tableaux `voiture[route[i]]`.


```C
#include <stdio.h>
#include <wchar.h>

/** route : état de la route
 * n : longueur de la route
 * sortie : affichage de la route
 */
void affiche(uint8_t *route, int n){
    //le type wint_t est hors programme
    wint_t voiture[] = {' ',(wint_t)128663, (wint_t)128665, (wint_t)128661, (wint_t)127949};
    //cette instruction est hors programme et permet l'affichage des caractères bizarres au-dessus;
    setlocale(LC_ALL, "");
    for(int i=0; i<n; i++){
        printf("%lc", voiture[route[i]]);
    }
    printf("\n");
}
```

Compléter la fonction la fonction `affichage` du code qui permet d'afficher l'état de la route en fonction du temps (une ligne par clic d'horloge).

### Exercice 8 : Courbe de von Koch
La courbe de Koch est obtenue par un procédé itératif illustré par la figure ci-dessous : on part d'un segment, on supprime son tiers du milieu et on le remplace par les deux autres côtés pour former un triangle équilatéral, toujours vers l'extérieur de la figure (définition pas très mathématique, j'en conviens, mais l'animation doit être claire, même si elle ne fait pas apparaître le segment initial).

![](https://upload.wikimedia.org/wikipedia/commons/b/bf/Koch_anime.gif)

Dans cet exercice, on se propose de construire deux tableaux contenant respectivement les abscisses et les ordonnées des sommets de la courbe, en supposant que le segment de départ relie l'origine du repère $(0,0)$ au point $(1,0)$.

Si on considère un segment $[A, B]$ de la courbe pour une itération donnée, il est assez simple de trouver les coordonnées des tiers du segment en fonction des coordonnées de $A$ et de $B$, et je vous laisse le faire. Supposons que ces coordonnées soient $(x_1, y_1)$ et $(x_2, y_2)$ dans l'ordre de parcours de la courbe de gauche à droite.

Comme tout le monde n'a pas fait Maths Expertes, je vous donne les coordonnées $(x_3, y_3)$ du 3e point du triangle équilatéral (mais il suffit d'exprimer une rotation en complexes pour les trouver) :

$$x_3  = x_1 + (x_2-x_1)\cos\alpha - (y_2-y_1)\sin\alpha$$

$$y_3 = y_1 + (x_2-x_1)\sin\alpha + (y_2-y_1)\cos\alpha$$

où $\alpha=\pi/3$.

1. Écrire une fonction `init_x` qui renvoie un tableau avec les abscisses des deux extrêmités du segment initial.

[Koch.c](tests/Koch.c)

2. Écrire une fonction `init_y` qui renvoie un tableau avec les ordonnées des deux extrêmités du segment initial.

3. Écrire une fonction `suivante_x` qui prend en argument deux tableaux représentants respectivement les abscisses et les ordonnées des sommets à une étape donnée dans la construction de la courbe de Koch, et le nombre de sommets en question (sans avoir à le vérifier) et renvoie un tableau avec les abscisses des somments à l'étape suivante.

4. Écrire une fonction `suivante_y` qui prend en argument deux tableaux représentants respectivement les abscisses et les ordonnées des sommets à une étape donnée dans la construction de la courbe de Koch, et le nombre de sommets en question (sans avoir à le vérifier) et renvoie un tableau avec les ordonnées des somments à l'étape suivante.


5. Écrire une fonction `affichage` qui prend en argument un entier `n` et affiche les coordonnées des points de la `n`$^e$ courbe de Koch (le segment de départ ayant le numéro 0), un point par ligne, l'abscisse suivie de l'ordonnée. Par exemple pour la courbe 2, j'ai l'affichage suivant :

```bash
0.000000 0.000000
0.111111 0.000000
0.166667 0.096225
0.222222 0.000000
0.333333 0.000000
0.388889 0.096225
0.333333 0.192450
0.444444 0.192450
0.500000 0.288675
0.555556 0.192450
0.666667 0.192450
0.611111 0.096225
0.666667 0.000000
0.777778 0.000000
0.833333 0.096225
0.888889 0.000000
1.000000 0.000000
```

Pour voir le résultat graphique, faites en sorte que le fichier
`data.txt` contienne l'affichage des coordonnées comme décrit
ci-dessus. Lancez `gnuplot` en ligne de commande (m'appeler si ce
n'est pas installé) et taper les lignes suivantes:

```bash
gnuplot> set xrange [-0.2:1.2]
gnuplot> set yrange [-0.1:0.8]
gnuplot> plot "data.txt" with lines
```

## Deuxième étoile -- pour ceux qui ont facilement fini la première étoile

Si vous en êtes là, écrivez vos propres tests dans la fonction `main`.

### Exercice 9 : Pile d'entiers
On représente une pile d'entiers par un tableau dont la première case
contient la hauteur de la pile. Implémenter les fonctions suivantes:

```C
/** renvoie une pile vide dont la capacite est spécifiée en argument */
int *init(int capacite);
/** empile l'élément n sur la pile si celle-ci n'est pas pleine,
 * renvoie true si c'est fait, false sinon */
bool empile(int n, int *pile, int capacite);
/** teste si la pile est vide */
bool est_vide(int *pile);
/** depile si la pile n'est pas vide, sinon ne fait rien et renvoie -1 */
int depile(int *pile);
```

(Quand on aura fait les structures, on pourra recommencer plus proprement.)

### Exercice 10 : Tri base
Implémenter une fonction
```C
void tri_base(int n, int lg, int *entiers, int b)
```
où `n` est le nombre de cases auxquelles on a accès à l'adresse
`entiers`, on suppose (sans avoir à le vérifier) que toutes les cases
d'`entiers` contiennent des entiers dont l'écriture en base `b`
contient `lg` chiffres. La fonction doit trier les éléments
d'`entiers` en utilisant le tri base en base `b`.

*Rappel* : le tri base consiste à placer les éléments par paquets
selon leur dernier chiffre, puis selon leur avant-dernier chiffre,
etc. Pensez à utiliser l'exercice précédent pour manipuler vos
données.
