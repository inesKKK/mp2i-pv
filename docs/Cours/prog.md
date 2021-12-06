## Programmation



* vendredi 3 septembre 2021 : caractériser un langage de programmation
<br />bases du `C`
<br />> divers critères : paradigmes, compilation/interprétation, typage statique/dynamique faible/fort; code: [SuiteRec.java](code/SuiteRec.java), [suite_rec.c](code/suite_rec.c), [suite_rec.ml](code/suite_rec.ml)
<br />> comment compiler un programme `C`; code: [bonjour.c](code/bonjour.c)
<br />

* jeudi 9 septembre 2021 : types numériques
<br />> fonction `main`
<br />> représentation des entiers et des flottants en machine
<br />

* vendredi 10 septembre 2021 : fin types numériques
<br />variables en `C`
<br />début fonctions
<br />> représentation des booléens en machine
<br />> les identifiants en `C`
<br />> variables et constantes en `C`
<br />> fonctions : syntaxe
<br />

* jeudi 16 septembre 2021 : suite fonctions
<br />> passage par valeur des paramètres
<br />> variables locales
<br />> valeur de retour
<br />

* vendredi 17 septembre 2021 : structures de contrôle
<br />> conditionnelles, boucles conditionnelles et inconditionnelles
<br />

* jeudi 23 septembre 2021 : tableaux unidimensionnels
<br />> types tableaux
<br />> déclaration
<br />> initialisateurs
<br />

* jeudi 30 septembre 2021 : pointeurs
<br />> adresse d'une variable
<br />> NULL
<br />> allocation mémoire
<br />

* jeudi 7 octobre 2021 : mémoire d'un processus
<br />tableaux multidimensionnels
<br />début types structurés
<br />> pile/tas, différence entre pointeurs et tableaux; code : [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) / [pile_tas3.c](code/pile_tas3.c) / [pile_tas4.c](code/pile_tas4.c)
<br />> pointeurs, tableaux et fonctions; code : [mise_a_42.c](code/mise_a_42.c) / [parametre_tableau.c](code/parametre_tableau.c) / [retour_tableau.c](code/retour_tableau.c)
<br />> tableaux multidimensionnels, arguments du main; code : [arguments_du_main.c](code/arguments_du_main.c)
<br />> syntaxe pour `struct`
<br />

* mercredi 13 octobre 2021 : types structurés
<br />structures auto-référencées
<br />assert
<br />> syntaxe
<br />> utilisation avec les fonctions, tableaux et pointeurs
<br />> listes chaînées; code : [liste_chainee1.h](code/liste_chainee1.h) / [liste_chainee1.c](code/liste_chainee1.c) / [liste_chainee2.h](code/liste_chainee2.h) / [liste_chainee2.c](code/liste_chainee2.c)
<br />> parenthèse sur la documentation et la programmation défensive; code : [assert1.c](code/assert1.c) / [assert2.c](code/assert2.c)
<br />

* lundi 8 novembre 2021 : méthodes de tests
<br />> tests fonctionnels "boîte noire"
<br />> début tests structurels "boîte blanche" : couverture des sommets / couverture des arcs
<br />

* lundi 15 novembre 2021 : méthodes de tests
<br />début ocaml
<br />> fin tests structurels "boîte blanche": tests exhaustifs de conditions / MDMC / couverture des chemins
<br />> ocaml : intro; mutabilité vs immuabilité; compilation / utop; types primitifs
<br />

* mercredi 17 novembre 2021 : ocaml : variables et expressions
<br />> définitions de variables
<br />> expressions : expressions conditionnelles, expressions let et portée, annotations de types
<br />

* jeudi 18 novembre 2021 : ocaml : fonctions (non récursives)
<br />> fonctions anonymes
<br />> définition, syntaxe et sémantique des fonctions
<br />> curryfication
<br />

* lundi 22 novembre 2021 : ocaml : fonctions récursives, récursivité terminale, listes, filtrage par motifs
<br />> `let rec` et exemples de fonctions récursives; code : [factorielle.ml](code/factorielle.ml) / [pair_impair.ml](code/pair_impair.ml)
<br />> récursivité terminale (hors programme) pour éviter un débordement de pile; code : [compte.ml](code/compte.ml) / [compte_rt.ml](code/compte_rt.ml)
<br />> polymorphisme
<br />> listes : immuabilité, syntaxes `x :: xs` et `[e1;e2;e3]`, sémantiques statique et dynamique; code : [longue_liste.ml](code/longue_liste.ml)
<br />> filtrage : syntaxe `match ... with`, variables de motif, variable joker `_`, motifs associés aux listes
<br />

* jeudi 25 novembre 2021 : ocaml : filtrage par motifs, opérateur `@`
<br />> rôle du compilateur : exhaustivité, cas non atteints
<br />> importance de l'ordre des cas
<br />> des exemples de fonctions utilisant le filtrage sur les listes; code : [pattern_matching.ml](code/pattern_matching.ml)
<br />> opérateur `@` et sa complexité
<br />

* lundi 29 novembre 2021 : ocaml : types algébriques
<br />> types énumérés : constructeurs constants
<br />> enregistrements
<br />> n-uplets
<br />> motifs de filtrage associées; code : [zip.ml](code/zip.ml)
<br />> types énumérés qui transportent des données (constructeurs non constants); code : [figure.ml](code/figure.ml); [liste_entiers_flottants.ml](code/liste_entiers_flottants.ml)
<br />

* jeudi 2 décembre 2021 : ocaml : types algébriques, options
<br />> retour sur la syntaxe et la sémantique
<br />> récursivité et polymorphisme; code : [liste.ml](code/liste.ml); [liste_parametree.ml](code/liste_parametree.ml)
<br />> options
<br />> bloc `begin ... end`
<br />


[Synthèse](synthese.md) /  [Chronologie](chronologie.md) / [Algorithmique](algorithmique.md) / [Bases de données](bd.md) / [Programmation](prog.md) / [Systèmes](systemes.md) 


[Page principale du cours](https://ineskkk.github.io/mp2i-pv)

