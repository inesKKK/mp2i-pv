# À retenir absolument

[page d'accueil](https://ineskkk.github.io/mp2i-pv/)

(Le reste du cours est aussi à connaître, mais ces indications doivent
vous permettre de prioriser vos apprentissages.)

Des [conseils pour apprendre un cours](https://www.youtube.com/watch?v=RVB3PBPxMWg).

### SGF

* différence entre chemins relatifs et absolus, et savoir former de
    tels chemins
* savoir utiliser les commandes de base : `pwd`, `cd`, `ls`,
  `mkdir`, `rmdir`, `cp`, `mv`, `rm`
* ce qu'est un lien physique, ce qu'est un lien symbolique, comment
  les créer
* connaître les droits : groupes d'utilisateurs, types de droits,
  savoir les lire, les interpréter et les modifier
* savoir rediriger l'entrée standard, la sortie standard et la sortie
  erreur

### Processus

* connaître différence entre premier plan et arrière plan
* savoir utiliser `&`, `Ctrl-z` et `bg`
* savoir arrêter un processus en premier plan avec `Ctrl-c`
* savoir faire des redirections d'entrée, de sortie et de sortie
  erreur sur la ligne de commande

### Langages de programmation

* être capable de dessiner un graphe de flot de contrôle d
un programme qu'on comprend
* connaître la différence entre typage fort et typage faible, et entre
  typage statique et typage dynamique
* savoir écrire des tests fonctionnels et des tests structurels
* documenter son code à bon escient

### Langage C

* savoir compiler un programme en langage `C`
* savoir que l'exécution d'un programme `C` est l'exécution de son
  `main`
* connaître les règles de construction des identifiants en `C`
* savoir déclarer et affecter des variables et des constantes
* savoir déterminer la portée d'une variable
* connaître la syntaxe d'une fonction
* savoir que les passages de paramètres se font **par valeur** en `C`
* connaître les divers types d'entiers qui sont au programme, leur
  taille et leurs valeurs extrêmes
* connaître les opérations sur les valeurs numériques et les booléens
  en `C`
* connaître la syntaxe des structures de contrôle en `C`
* savoir déclarer un tableau et l'initialiser
* savoir accéder aux cases d'un tableau
* savoir déclarer un pointeur, et le déréférencer
* connaître la valeur `NULL`
* savoir récupérer l'adresse d'une variable
* savoir utiliser `malloc` et `free`
* savoir que ce qu'est un bloc d'activation d'appel
* savoir que les blocs d'activation d'appel se trouvent sur la pile
* savoir que les emplacements mémoire alloués avec `malloc` se
  trouvent dans le tas
* savoir qu'on ne peut pas renvoyer une adresse qui se trouve dans le
  bloc d'activation de l'appel courant
* comprendre la différence de forme en mémoire entre les tableaux
  statiques et les tableaux alloués avec `malloc` en
  multi-dimensionnel
* savoir utiliser les arguments du `main` (y compris avec `atoi`)
* savoir déclarer et utiliser un type structuré, y compris pour les
  types auto-référencés
* savoir utiliser `->`
* savoir manipuler des chaînes de caractères
* utilisation de `printf`, `fprintf` et `scanf`
* lecture et écriture dans un fichier

### Représentation des nombres en machine

* savoir représenter un entier en complément à 2
* connaître la représentation des flottants normalisés et des
  flottants dénormalisés

### Algorithmique
* savoir ce qu'est une entrée et une sortie d'un algorithme
* savoir ce que signifie terminaison, correction partielle et
  correction totale d'un algorithme
* savoir ce que signifie complexité temporelle et complexité spatiale
  d'un algorithme
* savoir définir un variant de boucle et un variant d'appel et savoir
  ce que leur existence permet de conclure
* savoir définir un invariant de boucle
* savoir prouver une correction par récurrence pour une fonction
  récursive
* connaître le tri par tas (en particulier pouvoit l'appliquer sur un
  exemple) et pouvoir prouver sa complexité
* connaître le tri rapide (en particulier pouvoit l'appliquer sur un
  exemple) et pouvoir prouver sa terminaison, sa vorrection, sa
  complexité dans le pire des cas et en moyenne
* connaître les stratégies suivantes et savoir les mettre en œuvre :
  diviser pour régner, force brute, backtracking, glouton,
  programmation dynamique (de bas en haut et mémoïsation), diviser
  pour  régner, meet in the middle
* savoir identifier la propriété des sous-problèmes optimaux et le
  chevauchement de sous-problèmes (en vue d'appliquer une stratégie de
  programmation dynamique)
* algorithmique du texte : connaître les algorithmes de Rabin-Karp, de
  Boyer-Moore, de Huffman

### Complexité
* savoir compter un nombre d'opérations en itératif et en récursif
* connaître les définitions de grand O, $\Theta$, $\Omega$
* savoir comparer rapidement des ordres de grandeur de fonctions
  correspondant à des complexités classiques
* savoir définir complexité dans le meilleur des cas et complexité
  dans le pire des cas
* connaître les schémas généraux de calcul de complexité
* savoir résoudre une relation de récurrence par somme télescopique
* savoir définir complexité en moyenne et complexité amortie
* connaître la méthode du banquier et la méthode du potentiel pour la
  complexité amortie

### `OCaml`
* savoir utiliser `utop`
* savoir compiler un programme en `OCaml`
* connaître les types primitifs et les opérations associées
* savoir définir une variable
* être capable d'écrire une expression conditionnelle et une
  expression let
* savoir définir une fonction
* savoir définir une fonction récursive
* savoir utiliser des fonctions partielles
* savoir manipuler des listes
* savoir utiliser un filtrage par motifs
* savoir fabriquer de nouveaux typee algébriques et les utiliser
  (union sans ou avec données, enregistrements, $n$-uplets, types
  paramétrés, types récursifs)
* connaître l'existence du type `option` et savoir l'utiliser
* connaître le type `unit` et son unique valeur `()`
* savoir utiliser l'opérateur `;`
* savoir créer un tableau in extenso et accéder à une de ses cases
  (lecture et écriture)
* savoir écrire une fonction sans argument
* savoir écrire des boucles `for` et while
* savoir manipuler une chaîne de caractères
* savoir manipuler des exceptions : créer, lever, attraper 
* lecture et écriture dans un fichier
* savoir utiliser `Hashtbl` pour implémenter une table de hachage

### Structures de données
* connaître l'interface et savoir implémenter en `C` et en `OCaml` :
  des tableaux de taille variable (seulement en `C` pour l'instant),
  des piles et des files
* savoir définir des arbres binaires et connaître le vocabulaire
  associé
* connaître les implémentations des arbres binaires (y compris
  l'implémentation par tableau des arbres binaires complets)
* savoir ce que sont une file de priorité et un tas max
* connaître les algorithmes de manipulation des tas max
* connaître les divers parcours d'arbres (savoir les appliquer et
  savoir écrire les algorithmes)
* ABR : définition, opérations de base
* arbres rouge-noir : définition, lien entre taille et hauteur,
  algorithme d'ajout d'un nouvel élément
* tables de hachage : définition, résolution des collisions par sondage et par
  chaînage

### Induction
* savoir ce qu'est un ordre bien fondé
* savoir définir inductivement un ensemble
* connaître et savoir appliquer le théorème d'induction structurelle
* connaître et savoir prouver la caractérisation d'un ensemble défini
  par induction comme union infinie

### Logique
* savoir construire inductivement les formules de la logique
  propositionnelle
* savoir ce qu'est une valuation, pouvoir l'étendre à des formules
* savoir ce qu'est un modèle et ce que signifie la satisfiabilité
* connaître les connecteurs classiques et leurs tables de vérité
* savoir écrire la table de vérité d'une formule
* savoir ce que sont des tautologies et des antilogies
* savoir ce que sont une équivalence logique et une conséquence
  logique
* connaître la contraposée, les lois de De Morgan et le principe du
  tiers exclu
* savoir ce que sont des littéraux et des clause
* savoir énoncer les problèmes SAT et n-SAT
* savoir mettre une formule sous forme normale négative, sous forme
  normale conjonctive et sous forme normale disjonctive
* connaître un exemple de formule pour laquelle la mise sous FNC donne
  une formule exponentiellement plus grande, et une formule pour
  laquelle la mise sous FND donne une formule exponentiellement plus
  grande
* savoir substituer une formule à une variable
* connaître l'algorithme de Quine et savoir l'appliquer

### Bases de données
* connaître le vocabulaire de base
