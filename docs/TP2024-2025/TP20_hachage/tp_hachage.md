TP20 : Tables de hachage
==

Il s'agit dans ce TP de constater expérimentalement l'efficacité des
tables de hachage pour stocker des ensembles (d'entiers pour
simplifier).

# Gestion des collisions par chaînage

Nous nous intéressons à la gestion des collisions par chaînage et nous
voulons déterminer expérimentalement la bonne taille de table de
hachage en fonction du nombre de données à stocker.

Les fichiers d'en-tête qui spécifient les types et les fonctions à
implémenter: [hachage.h](code/hachage.h) / [liste.h](code/liste.h).

## Exercice 1 : implémenter les fonctions liées aux listes chaînées

Tout est dans le titre... la liste des fonctions se trouvent dans le
fichier d'en-tête.

## Exercice 2 : implémenter la table de hachage

Le champ `hacher` un peu bizarre qu'on voit dans le fichier d'en-tête
et le paramètre assez similaire de la fonction `init`
permettent de manipuler des fonctions comme des valeurs (comme dans le
cas des tableaux, le nom d'une fonction est converti implicitement en
son adresse). Il s'agit ici de conserver l'adresse de la fonction de
hachage dans la table de hachage.

Par exemple on pourrait écrire:

```C
int zero(int n, int p){  // les paramètres sont là pour le type de la fonction
    return 0;
} // très peu intéressant comme fonction de hachage

int main(void){
    hachage h;
    
    h.hacher = zero;
}
```

(Les types comme celui du champ `hacher` sont hors programme et je ne
vous demande pas de savoir les manipuler, mais là il s'agit juste
d'utiliser une fonction comme paramètre d'une autre.)

Varier les fonctions de hachage:
* identité modulo la taille de la table,
* produit par un entier premier avec la taille de la table, puis
  modulo la taille de la table,
* première valeur renvoyée par `random` quand on fait un `srandom` sur
  la valeur à stocker,
* choix d'un double non entier `a` et partie entière inférieure de
  `n*(k*a % 1)` où `n` est la taille de la table et `k` la clef considérée.

## Exercice 3 : statistiques
Je vous fournis les fichiers [temps.h](code/temps.h) / [temps.c](code/temps.c)
qui permettent de mesurer le temps d'exécution d'une partie d'un
programme.

Il s'agit de faire des statistiques sur les temps d'insertion, de
consultation et de suppression d'élément dans votre table de hachage.

Pour les tracés, on utilisera `gnuplot` (essayez de le lancer en ligne
de commande dans un terminal, si ce n'est pas installé, appelez-moi).

Un tutoriel pour utiliser gnuplot avec des données dans un fichier:
[https://riptutorial.com/gnuplot/example/12382/plot-a-single-data-file](https://sodocumentation.net/gnuplot/topic/3591/basic-plotting-of-data-files).

On suppose qu'on a une table de hachage de `N` alvéoles. On veut
 connaître le temps mis pour `M` insertions prises au hasard, le temps
 de consultation pour `M/2` consultations au hasard et le temps de
 suppression pour `M/2` suppressions au hasard.
 
 Faites des graphiques où `N` est fixé et `M` varie, et des graphiques
 où `N/M` est fixé et `N` et `M` varient.

# Gestion des collisions par sondage
 
 Faites les mêmes expériences en gérant les collisions par sondage.

# Pour ceux qui ont fini
Je vous propose d'essayer de commencer un [sujet de TP
d'ENS](https://informatique.ens-lyon.fr/concours-info/2019/sujet-ancetre_commun.pdf),
en `C` ou en `OCaml`, au choix.
