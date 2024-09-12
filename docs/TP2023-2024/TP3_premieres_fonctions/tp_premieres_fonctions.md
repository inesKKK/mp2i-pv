# TP3 : Premières fonctions

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

Pour chaque exercice, je fournis un fichier qui contient un
`main` avec des tests. À vous de compléter ce fichier en écrivant la
fonction demandée (avant le `main`), de le compiler et de l'exécuter.

## Flocon -- pour ceux qui n'ont jamais programmé

**Exercice 1**:
Écrire une fonction `aire_rectangle` qui prend en argument deux nombres à virgule flottante représentant la largeur et la longueur d'un rectangle et renvoie l'air de ce rectangle.

[aire_rectangle.c](tests/test_aire_rectangle.c) (ce test est à compiler
avec l'option `-lm` à cause de l'utilisation de la bibliothèque de math)

**Exercice 2**:
Écrire une fonction `hypothenuse` qui prend en argument deux entiers
représentant les longueurs des deux côtés les plus courts d'un
triangle rectangle et renvoie la longueur approchée du troisième
côté. Vous pouvez utiliser la fonction `sqrt` pour le calcul de la
racine carrée, en incluant le fichier d'en-tête `math.h`.

[hypothenuse.c](tests/test_hypothenuse.c)

**Exercice 3**:
Écrire une fonction `cotes_triangle` qui prend en argument trois nombres à virgule flottante et teste s'ils peuvent représenter les longueurs des côtés d'un triangle. (Rappel : cela revient à tester si chaque longueur est inférieure à la somme des deux autres longueurs.)

[cotes_triangle.c](tests/test_cotes_triangle.c)


**Exercice 4**:
La célèbre conjecture de Syracuse énonce que, quel que soit l'entier strictement positif $N$, la suite définie par $u_0=N$ et
```math
u_ {n+1} = \begin{cases}
\frac{u_n}{2} & \text{ si }u_n\text{ est pair}\\
3u_n+1 & \text{ si }u_n\text{ est impair}
\end{cases}
```
est stationnaire.

Écrire une fonction `suivant_syracuse` qui prend en argument un entier
supposé apparaître dans la suite de Syracuse et renvoie l'entier
suivant dans cette suite.

[Syracuse.c](tests/test_Syracuse.c)




## Première étoile -- pour ceux qui ont déjà programmé et ceux qui ont facilement fini le flocon

**Exercice 5**:
Écrire et commenter un fonction `valeur_absolue` qui prend un double en arguments et renvoie sa valeur absolue.

[valeur_absolue.c](tests/test_valeur_absolue.c) (ce test est à compiler
avec l'option `-lm` à cause de l'utilisation de la bibliothèque de math)

## Algorithme dichotomique
Dans cette partie, nous allons aborder le problème du calcul de la racine carrée d'un nombre supposé positif (sans vérifier pour l'instant ce point), par une stratégie algorithmique classique, la _dichotomie_. Le principe de la dichotomie est le suivant :
* on cherche la réponse dans un intervalle,
* si la réponse est au milieu de l'intervalle, on a trouvé la solution,
* sinon
  * soit elle est inférieure à ce milieu et on regarde dans la moitié de gauche en suivant la même méthode,
  * soit elle est supérieure et on regarde dans la moitié de droite en suivant la même méthode.
C'est le principe que vous utilisez quand vous cherchez un mot dans un dictionnaire.


### Application au calcul de la racine
Ici, si on note $x$ le nombre dont on cherche la racine carrée, on sait que celle-ci appartient à l'intervalle
$[1,x]$ si $x\geq 1$ et $[x,1]$ sinon (rappel : on suppose que $x\geq 0$.) On peut alors comparer le carré de la valeur candidate (ici $(x+1)/2$) à $x$ : s'ils sont suffisamment proches, on considère qu'on a trouvé $\sqrt{x}$, sinon on continue dans la bonne moitié de l'intervalle.

**Exercice 6**:
Documenter et écrire la fonction `racine_par_dichotomie` qui prend en premier argument le flottant dont on chreche la racine, et en deuxième argument la précision qui permet de détecter si le carré de la valeur candidate est suffisamment proche de ce nombre.

[racine_dichotomie.c](tests/test_racine_dichotomie.c)

## Algorithme de Héron
Chez les Grecs anciens, trouver la racine carrée de $x$ était un problème de gémétrie : cela revenait à trouver un carré de côté $c$ dont l'aire valait $x$. L'algorithme de Héron repose sur cette vision :
* on part d'un rectangle dont on sait que l'aire est $x$ : le rectangle $1\times x$,
* tant que le rectangle ne peut pas être considéré comme un carré (c'est-à-dire tant que ses côtés sont suffisamment différents)
  * on considère un nouveau rectangle dont un des côtés vaut la moyenne arithmétique des côtés de l'ancien rectangle, et l'autre ce qu'il faut pour que l'aire de ce rectangle soit encore $x$
* on retourne $x$.

**Exercice 7**:
Documenter et écrire la fonction `racine_Heron` qui prend les mêmes arguments que fonction `racine_par_dichotomie`.

[racine_Heron.c](tests/test_racine_Heron.c)

**Exercice 8**:
On peut obtenir le temps nécessaire à l'exécution d'un programme en
faisant précéder la ligne de commande pour le lancer par la commande
`time`. 

* Écrivez un programme qui calcule les racines des entiers de
43561 à 143560 avec la méthode dichotomique et chronométrez son temps
d'exécution.
* Faites de même pour la méthode de Héron.
* Enfin recommencez en faisant appel à la fonction `sqrt` de la
  bibliothèque de math.
