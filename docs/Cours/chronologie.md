## Chronologie du cours



#### vendredi 3 septembre 2021


* [P] caractériser un langage de programmation
<br />bases du `C`
<br />> divers critères : paradigmes, compilation/interprétation, typage statique/dynamique faible/fort; code: [SuiteRec.java](code/SuiteRec.java), [suite_rec.c](code/suite_rec.c), [suite_rec.ml](code/suite_rec.ml)
<br />> comment compiler un programme `C`; code: [bonjour.c](code/bonjour.c)
<br />

#### lundi 6 septembre 2021


* [A] tour d'horizon
<br />terminaison
<br />> conception / correction / efficacité; code : [plus_grande_puissance_de_2.py](code/plus_grande_puissance_de_2.py), [plus_grande_puissance_de_2.c](code/plus_grande_puissance_de_2.c), [plus_grande_puissance_de_2.ml](code/plus_grande_puissance_de_2.ml)
<br />> variants de boucles<br />

#### jeudi 9 septembre 2021


* [P] types numériques
<br />> fonction `main`
<br />> représentation des entiers et des flottants en machine
<br />

#### vendredi 10 septembre 2021


* [P] fin types numériques
<br />variables en `C`
<br />début fonctions
<br />> représentation des booléens en machine
<br />> les identifiants en `C`
<br />> variables et constantes en `C`
<br />> fonctions : syntaxe
<br />

#### lundi 13 septembre 2021


* [A] terminaison et correction
<br />début complexité
<br />> terminaison : variants de boucles et preuves par récurrence; code : [fibonacci.py](code/fibonacci.py) / [fibonacci.c](code/fibonacci.c) / [fibonacci.ml](code/fibonacci.ml) / [note_sous_la_moyenne.py](code/note_sous_la_moyenne.py) / [note_sous_la_moyenne.c](code/note_sous_la_moyenne.c) / [note_sous_la_moyenne.ml](code/note_sous_la_moyenne.ml) / [dichotomie.py](code/dichotomie.py) / [dichotomie.c](code/dichotomie.c)
<br />> correction : invariants de boucles et preuves par récurrence
<br />> complexité : notation grand O
<br />

#### jeudi 16 septembre 2021


* [P] suite fonctions
<br />> passage par valeur des paramètres
<br />> variables locales
<br />> valeur de retour
<br />

#### vendredi 17 septembre 2021


* [P] structures de contrôle
<br />> conditionnelles, boucles conditionnelles et inconditionnelles
<br />

#### lundi 20 septembre 2021


* [A] ordres de grandeur
<br />> notations grand Omega et grand Theta
<br />> lien avec les limites
<br />> comparaison des fonctions usuelles
<br />

#### jeudi 23 septembre 2021


* [P] tableaux unidimensionnels
<br />> types tableaux
<br />> déclaration
<br />> initialisateurs
<br />

#### lundi 27 septembre 2021


* [A] complexité des algorithmes
<br />> étude de cas : tri bulle (meilleur des cas, pire des cas et en moyenne)
<br />

#### jeudi 30 septembre 2021


* [P] pointeurs
<br />> adresse d'une variable
<br />> NULL
<br />> allocation mémoire
<br />

#### lundi 4 octobre 2021


* [A] complexité des algorithmes récursifs
<br />> étude de cas : recherche dichotomique, tri fusion; code : [tri_fusion.c](code/tri_fusion.c)
<br />

#### jeudi 7 octobre 2021


* [P] mémoire d'un processus
<br />tableaux multidimensionnels
<br />début types structurés
<br />> pile/tas, différence entre pointeurs et tableaux; code : [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) / [pile_tas3.c](code/pile_tas3.c) / [pile_tas4.c](code/pile_tas4.c)
<br />> pointeurs, tableaux et fonctions; code : [mise_a_42.c](code/mise_a_42.c) / [parametre_tableau.c](code/parametre_tableau.c) / [retour_tableau.c](code/retour_tableau.c)
<br />> tableaux multidimensionnels, arguments du main; code : [arguments_du_main.c](code/arguments_du_main.c)
<br />> syntaxe pour `struct`
<br />

#### lundi 11 octobre 2021


* [A] complexité spatiale
<br />> compromis entre complexité temporelle et complexité spatiale, exemple de la mémoïsation; code : [fibonacci_memoisation.c](code/fibonacci_memoisation.c)
<br />

#### mercredi 13 octobre 2021


* [P] types structurés
<br />structures auto-référencées
<br />assert
<br />> syntaxe
<br />> utilisation avec les fonctions, tableaux et pointeurs
<br />> listes chaînées; code : [liste_chainee1.h](code/liste_chainee1.h) / [liste_chainee1.c](code/liste_chainee1.c) / [liste_chainee2.h](code/liste_chainee2.h) / [liste_chainee2.c](code/liste_chainee2.c)
<br />> parenthèse sur la documentation et la programmation défensive; code : [assert1.c](code/assert1.c) / [assert2.c](code/assert2.c)
<br />

#### jeudi 14 octobre 2021


* [S] SGF
<br />> répertoires / fichiers réguliers
<br />> chemins absolus / chemins relatifs
<br />> lancer une commande dans un shell
<br />> répertoire courant
<br />> quelques commandes : `man`, `pwd`, `cd`, `ls`, `mkdir`
<br />

#### lundi 8 novembre 2021


* [P] méthodes de tests
<br />> tests fonctionnels "boîte noire"
<br />> début tests structurels "boîte blanche" : couverture des sommets / couverture des arcs
<br />

#### lundi 15 novembre 2021


* [P] méthodes de tests
<br />début ocaml
<br />> fin tests structurels "boîte blanche": tests exhaustifs de conditions / MDMC / couverture des chemins
<br />> ocaml : intro; mutabilité vs immuabilité; compilation / utop; types primitifs
<br />

#### mercredi 17 novembre 2021


* [P] ocaml : variables et expressions
<br />> définitions de variables
<br />> expressions : expressions conditionnelles, expressions let et portée, annotations de types
<br />

#### jeudi 18 novembre 2021


* [P] ocaml : fonctions (non récursives)
<br />> fonctions anonymes
<br />> définition, syntaxe et sémantique des fonctions
<br />> curryfication
<br />

#### lundi 22 novembre 2021


* [P] ocaml : fonctions récursives, récursivité terminale, listes, filtrage par motifs
<br />> `let rec` et exemples de fonctions récursives; code : [factorielle.ml](code/factorielle.ml) / [pair_impair.ml](code/pair_impair.ml)
<br />> récursivité terminale (hors programme) pour éviter un débordement de pile; code : [compte.ml](code/compte.ml) / [compte_rt.ml](code/compte_rt.ml)
<br />> polymorphisme
<br />> listes : immuabilité, syntaxes `x :: xs` et `[e1;e2;e3]`, sémantiques statique et dynamique; code : [longue_liste.ml](code/longue_liste.ml)
<br />> filtrage : syntaxe `match ... with`, variables de motif, variable joker `_`, motifs associés aux listes
<br />

#### jeudi 25 novembre 2021


* [P] ocaml : filtrage par motifs, opérateur `@`
<br />> rôle du compilateur : exhaustivité, cas non atteints
<br />> importance de l'ordre des cas
<br />> des exemples de fonctions utilisant le filtrage sur les listes; code : [pattern_matching.ml](code/pattern_matching.ml)
<br />> opérateur `@` et sa complexité
<br />

#### lundi 29 novembre 2021


* [P] ocaml : types algébriques
<br />> types énumérés : constructeurs constants
<br />> enregistrements
<br />> n-uplets
<br />> motifs de filtrage associées; code : [zip.ml](code/zip.ml)
<br />> types énumérés qui transportent des données (constructeurs non constants); code : [figure.ml](code/figure.ml); [liste_entiers_flottants.ml](code/liste_entiers_flottants.ml)
<br />

#### jeudi 2 décembre 2021


* [P] ocaml : types algébriques, options
<br />> retour sur la syntaxe et la sémantique
<br />> récursivité et polymorphisme; code : [liste.ml](code/liste.ml); [liste_parametree.ml](code/liste_parametree.ml)
<br />> options
<br />> bloc `begin ... end`
<br />

#### lundi 6 décembre 2021


* [A] structures de données séquentielles
<br />> `typedef` en `C`
<br />> différence implémentation / interface
<br />> tableaux de taille variable; code : [vartab.h](code/vartab.h), [main_tableaux_de_taille_variable.c](code/main_tableaux_de_taille_variable.c), [tableaux_de_taille_variable.h](code/tableaux_de_taille_variable.h), [tableaux_de_taille_variable.c](code/tableaux_de_taille_variable.c)
<br />> piles; code : [stack.h](code/stack.h). [main_stack.c](code/main_stack.c), [stack_array.h](code/stack_array.h), [stack_array.c](code/stack_array.c), [stack_list.h](code/stack_list.h), [stack_list.c](code/stack_list.c)
<br />> calculatrice en polonaise inverse; code : [polonaise.ml](code/polonaise/ml)
<br />> calculatrice avec des parenthèses
<br />> files; code : [queue.h](code/queue.h), [main_queue.c](code/main_queue.c), [queue_list.h](code/queue_list.h), [queue_list.c](code/queue_list.c), [queue.ml](code/queue.ml)
<br />

#### jeudi 9 décembre 2021


* [A] structures de données hiérarchiques
<br />> arbres binaires, vocabulaire dans un arbre
<br />> arbres binaires stricts, parfaits
<br />> liens entre hauteur et taille dans un arbre binaire parfait
<br />

#### lundi 13 décembre 2021


* [A] structures de données hiérarchiques
<br />> arbres binaires complets
<br />> liens entre hauteur et taille dans un arbre binaire complet
<br />> exemples d'implémentation d'arbres binaires en `ocaml` et en `C`
<br />> implémenation des arbres binaires complets par tableau
<br />> files de priorité
<br />> tas : percolation (+complexité), construction
<br />

#### jeudi 16 décembre 2021


* [A] fin tas
<br />des applications des arbres
<br />> tas : complexité de l'algorithme de construction
<br />> applications : minimisation de la complexité dans le pire des cas d'un tri par comparaisons; tri par tas
<br />

#### lundi 3 janvier 2022


* [A] applications des arbres, suite
<br />> codage de Huffman : construction de l'arbre d'encodage
<br />> tri rapide : correction, complexité dans le meilleur et dans le pire des cas; code : [tri_rapide.c](code/tri_rapide.c)
<br />

#### jeudi 6 janvier 2022


* [A] applications des arbres, suite
<br />> tri rapide : complexité en moyenne
<br />

#### dimanche 9 janvier 2022


* [A] applications des arbres, fin
<br />parcours d'arbres binaires
<br />arbres d'arité quelconque
<br />> tri rapide : cas des doublons ; code : [tri_rapide_3.c](code/tri_rapide_3.c)
<br />> parcours : profondeur (préfixe, infixe, postfixe) et largeur (application : garbage collector)
<br />> représentation fils gauche/frère droit
<br />

#### jeudi 13 janvier 2022


* [A] arbres d'arité quelconque, suite
<br />complexité amortie
<br />> tableaux dynamiques implémentés par des arbres; code : [tableaux_arbres.h](code/tableaux_arbres.h) / [tableaux_arbres.c](code/tableaux_arbres.c)
<br />> complexité amortie pour les tableaux dynamique implémentés à la python
<br />


[Synthèse](synthese.md) /  [Chronologie](chronologie.md) / [Algorithmique](algorithmique.md) / [Bases de données](bd.md) / [Programmation](prog.md) / [Systèmes](systemes.md) 


[Page principale du cours](https://ineskkk.github.io/mp2i-pv)

