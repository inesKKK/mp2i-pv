### Chronologie du cours

**2 septembre 2022**:

* présentation rapide de ce qu'est l'informatique;
* introduction à la ligne de commande et au SGF

**5 septembre 2022**:

* commandes liées au SGF : `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `cp`,
  `mv`, `rm`
* notion d'i-nœud et de numéro d'i-nœud
* droits sur les fichiers : consultation, signification et modification
* contenu d'un répertoire

**8 septembre 2022**:

* liens physiques et symboliques, commande `ls`
* espace d'adressage: description de System V
* exemple de création d'un faux gros fichier; code:
  [bigfile.c](code/bigfile.c)
* caractérisation d'un langage de programmation: paradigmes
  (POO/impératif/fonctionnel)
* graphe de flot de contrôle d'un programme
* compilation vs. interprétation
* types: définition, taille, conversions explicite et implicite, typage fort vs. typage faible

**12 septembre 2022**:
* typage statique vs. typage dynamique
* bases de `C` : compilation, flot d'un programme `C` et rôle de la
  fonction `main`
* types en `C`: `int`, `unsigned int`, `int8_t`, `int32_t`, `int64_t`,
  `uint8_t`, `uint32_t`, `uint64_t`
* bit de poids fort / bit de poids faible
* complément à 2

**15 septembre 2022**:
* norme IEEE 754 pour les nombres à virgule flottante en double
  précision
* opérations sur les doubles, problèmes de précision et erreurs d'arrondi
* opérations entre doubles et entiers
* booléens
* identifiants en C: règles

**16 septembre 2022** (complément en TP):
* variables en `C`: déclaration, affectation, portée; code : [reutilisation_identifiant.c](code/reutilisation_identifiant.c)

**19 septembre 2022**
* constantes en `C` (littérales et symboliques)
* fonctions en `C`: invocation/appel, passage par valeurs, variables
  locales, valeur de retour; code :
  [passage_par_valeurs.c](code/passage_par_valeurs.c)
* structures de contrôle de `C`: conditionnelles, boucles
  (conditionnelles et inconditionnelles)
* introduction à l'algorithmique

**22 septembre 2022**
* conception d'un algorithme: entrée, sortie, problème de décision
* correction: terminaison, correction partielle et totale; code :
  [plus_grande_puissance_de_2.c](code/plus_grande_puissance_de_2.c) /
  [plus_grande_puissance_de_2.ml](code/plus_grande_puissance_de_2.ml)
* efficacité: complexité temporelle, complexité spatiale
* indécidabilité du problème de l'arrêt

**26 septembre 2022**
* preuve de terminaison par variant de boucle et par récurrence;
  code : [fibonacci.c](code/fibonacci.c) /
  [fibonacci.ml](code/fibonacci.ml) /
  [note_sous_la_moyenne.c](code/note_sous_la_moyenne.c) /
  [note_sous_la_moyenne.ml](code/note_sous_la_moyenne.ml) / [dichotomie.c](code/dichotomie.c)
* preuve de correction par invariant de boucle et par récurrence

**29 septembre 2022**
* gestion de la mémoire en `C`: tableau (déclaration, initialisation),
  pointeur (déclaration)

**3 octobre 2022**
* obtenir une valeur de type pointeur: `NULL`, adresse d'une variable,
  allocation mémoire avec `malloc`, libération avec `free`
* valeur, contenu et déréférencement d'un pointeur
* pile d'appel d'un processus, bloc d'activation d'un appel; code :
  [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) [pile_tas3.c](code/pile_tas3.c)

**6 octobre 2022**
* tas d'un processus; code : [pile_tas4.c](code/pile_tas4.c)
* passage d'un pointeur en paramètre; code :
  [mise_a_42.c](code/mise_a_42.c)
* tableaux multi-dimensionnels, syntaxe et place occupée en mémoire;
  code : [tableaux_multidim.c](code/tableaux_multidim.c)

**10 octobre 2022**
* tableaux et pointeurs (unidimensionnels et multidimensionnels) comme
  paramètres d'une fonction; code :
  [pb_tableaux_pointeurs.c](code/pb_tableaux_pointeurs.c)
* arguments du `main`; code :
  [arguments_du_main.c](code/arguments_du_main.c)
* ordres de grandeurs : grand O, $\Theta$, $\Omega$
* comparaisons et calculs des ordres de grandeurs habituels
* complexité dans le pire des cas (définition)

**13 octobre 2022**
cours annulé

**17 octobre 2022**
* complexité dans le meilleur des cas et en moyenne (définitions)
* point de vue expérimental sur la complexité
* étude de la complexité temporelle du tri bulle: meilleur des cas et
  pire des cas dans le cas général, en moyenne en ajoutant l'hypothèse
  que les données sont deux à deux distinctes
* étude de la complexité temporelle du tri dichotomique: meilleur des
  cas et pire des cas
  
**20 octobre 2022**
* fin du pire des cas pour le tri dichotomique
* étude de la complexité temporelle du tri fusion
* étude de la complexité spatiale de diverses implémentation du calcul
  de la suite de Fibonacci

**7 novembre 2022**
* tests fonctionnels
* tests structurels: couverture des sommets, couverture des arcs,
  tessts exhaustifs de condition, MC/DC

**10 novembre 2022**
* documentation et programmation défensive; code :
  [assert1.c](code/assert1.c) / [assert2.c](code/assert2.c)
* types structurés en `C` : définition (`struct`), déclaration,
  initialisateur; accès aux champs
* types structurés et fonctions; code :
  [quadrilatere.c](code/quadrilatere.c)
* types structurés et tableaux, types structurés et pointeurs
* structures auto-référencées : listes chaînées; code :
  [liste_chainee1.h](code/liste_chainee1.h) / [liste_chainee1.c](code/liste_chainee1.c)

**14 novembre 2022**
* listes chaînées en `C` avec une tête; code :
  [liste_chainee2.h](code/liste_chainee2.h) / [liste_chainee2.c](code/liste_chainee2.c)
* introduction à `ocaml` : immuabilité, expressions
* compilation et exécution `ocaml` : `ocamlc`, `ocamlopt`, REPL
* types primitifs `ocaml`
* définitions de variables


**17 novembre 2022**
* expressions conditionnelles, expressions `let` et portée

**21 novembre 2022**
* annotation des de types
* fonctions anonymes
* définition d'une fonction
* sémantiques dynamique et statique des fonctions
* curryfication
* fonctions récursives; code : [factorielle.ml](code/factorielle.ml) /
  [pair_impair.ml](code/pair_impair.ml) / [compte.ml](code/compte.ml)
  / [compte_rt.ml](code/compte_rt.ml)
* polymorphisme

**24 novembre 2022**
* listes littérales, sémantiques des listes, constructeur de liste (`::`); code : [longue_liste.ml](code/longue_liste.ml)
* début du filtrage par motifs

**28 novembre 2022**
* filtrage par motifs de listes; code :
  [pattern_matching.ml](code/pattern_matching.ml)
* opérateur `@` vs. constructeur `::`
* fonctionnement du filtrage, filtrage profond, disjonction de motifs
* sucre syntaxique `function`
* types algébriques: types énumérés sans valeur; code : [mois.ml](code/mois.ml)

**1er décembre 2022**
* portée des constructeurs des types énumérés
* motifs de filtrage pour les types énumérés
* enregistrements et leurs motifs
* $n$-uplets et leurs motifs
* types énumérés embarquant des données et leurs motifs de filtrage;
  code : [figure.ml](code/figure.ml) / [liste_entiers_flottants.ml](code/liste_entiers_flottants.ml)

**5 décembre 2022**
* syntaxe et sémantique des types
* types récursifs et polymorphes; code : [liste.ml](code/liset.ml) /
  [liste_parametree.ml](code/liste_parametree.ml)
* mot-clef `and` en `ocaml` pour définir des types mutuellement
  récursifs
* option
* parenthésage `(`/`)` et `begin`/`end`

**7 décembre 2022**
* début des structures de données
* mot-clef `typedef` en `C`
* interface des tableaux de taille variable; code :
  [vartab.h](code/vartab.h) /
  [main_tableaux_de_taille_variable.c](code/main_tableaux_de_taille_variable.c)
  /
  [tableaux_de_taille_variable.h](code/tableaux_de_taille_variable.h)
  / [tableaux_de_taille_variable.c](code/tableaux_de_taille_variable.c)
* interface des piles; code : [stack.h](code/stack.h) / [main_stack.c](code/main_stack.c) / [stack_array.h](code/stack_array.h) / [stack_array.c](code/stack_array.c) / [stack_list.h](code/stack_list.h) / [stack_list.c](code/stack_list.c)

**12 décembre 2022**
* exemple d'utilisation de pile : calculatrice en polonaise inverse;
  code : [polonaise.ml](code/polonaise.ml)
* interface d'une file; code : [queue.h](code/queue.h) /
  [main_queue.c](code/main_queue.c) /
  [queue_list.h](code/queue_list.h) /
  [queue_list.c](code/queue_list.c) / [queue.ml](code/queue.ml)
* arbres binaires : définitions de base (père, frère, sous-arbre,
  feuille, nœud interne, branche, arbre binaire strict)

**15 décembre 2022**
* arbres binaires parfaits, lien taille / hauteur
* arbres binaires complets, lien taille / hauteur
* implémentation des arbres binaires en `C` avec des pointeurs et en `ocaml` avec un type somme
* implémentation des arbres binaires complets sous forme de tableau

**5 janvier 2023**
* files de priorité
* implémenation par tas max : percolation vers le bas (correction et complexité)

**9 janvier 2023**
* tas max : percolation vers le haut, modification de valeur,
  insertion de valeur, extraction du maximum, construction d'un tas
  (avec les complexités)
* applications des arbres binaires:
  * minoration de la complexité dans le pire des cas d'un tri par
    comparaisons
  * tri par tas
  * principe du codage de Huffman
  

**12 janvier 2023**
* applications des arbres binaires - suite:
  * tri rapide (correction); code : [tri_rapide.c](code/tri_rapide.c)
  

**16 janvier 2023**
* tri rapide - suite : complexité dans le pire des cas, le
    meilleur des cas et en moyenne, cas des doublons; code : [tri_rapide_3.c](tri_rapide_3.c)
* parcours d'arbres binaires: en profondeur (préfixe, postfixe,
  suffixe), en largeur

**19 janvier 2023**
* complexité amortie : méthode du banquier

**23 janvier 2023**
* complexité amortie : suite méthode du banquier, méthode du potentiel
* arbres d'arité quelconque: implémentation et applications; code :
  [tableaux_arbres.h](code/tableaux_arbres.h) /
  [tableaux_arbres.c](code/tableaux_arbres.c) / 
* mutabilité en `ocaml`: enregistrements avec champs mutables, types référence

**25 janvier 2023**
* mutabilité en `ocaml`: suite types référence
* type `unit` : type de retour, expressions conditionnelles, fonctions
  sans argument; code : [pile.ml](code/pile.ml)
* tableaux et boucles en `ocaml`

**30 janvier 2023**
* exceptions en `ocaml`
* représenter une collections de données: ABR; code : [abr.ml](code/abr.ml)

**1er février 2023**
* arbres rouge-noir (sauf suppression d'une valeur); code : [arbresRN.ml](code/arbresRN.ml)
* dictionnaires

**6 février 2023**
* retour sur la suppression d'une valeur dans un arbre rouge-noir
* tables de hachage: définition, résolution des collisions par
  sondage, début résolution des collisions par chaînage
  
**7 février 2023**
* tables de hachage: fin résolution des collisions par chaînage
* récursivité et induction: ensembles ordonnés, ordre bien fondé,
  définition des ensembles inductifs par intersection

**8 février 2023**
* suite ensembles inductifs
* preuves par induction
* caractérisation des ensembles inductifs par union
* principe d'induction structurelle
* principe d'induction bien fondée
* lien avec la correction des fonctions récursives
* début logique propositionnelle : syntaxe, tables de vérité

**13 février 2023**
* suite logique propositionnelle
* valuation; code : [valuation.ml](code/valuation.ml)
* (au passage: exploration de quelques fonctions des modules `List` et
  `Array` en `ocaml`)
* satisfiabilité d'une formule, tautologie, antilogie, équivalence de
  formules, lois de De Morgan, conséquence logique
* formes normales négatives

**15 février 2023**
* équivalence logique entre une formule et sa forme normale négative
* formes normales conjonctives
* problème SAT
* équivalence logique entre une formule et sa forme normale
  conjonctive
* formules équi-satisfiables

**6 mars 2023**
* substitution de formules
* algorithme de Quine
* formes normales disjonctives
* type caractère en `C` et en `ocaml`
* chaînes de caractères en `C`; code :
  [chaines_memoire.c](code/chaines_memoire.c) / [erreur_caractere.c](code/erreur_caractere.c)

**8 mars 2023**
* chaînes de caractères en `ocaml`
* début stratégies algorithmiques
* force brut; code : [cherche.c](code/cherche.c) /
  [cherche.ml](code/cherche.ml)
* backtracking (retour sur trace); code : [reines.c](code/reines.c) /
  [espaces.ml](code/espaces.ml)
* début algorithmes gloutons

**13 mars 2023**
* suite algorithmes gloutons; code : [egypte.ml](code/egypte.ml)
* début programmation dynamique; code : [fibonacci.c](code/fibonacci2.c) /
  [fibonacci_dynamique.c](code/fibonacci_dynamique.c) /
  [fibonacci_dynamique2.c](code/fibonacci_dynamique2.c) /
  [monnaie_naive.ml](code/monnaie_naive.ml) / [monnaie.ml](code/monnaie.ml)

**15 mars 2023**
* fin programmation dynamique; code :
  [levenshtein_naif.c](code/levenshtein_naif.c) /
  [levenshtein.c](code/levenshtein.c) /
  [typographie.c](code/typographie.c)
* début diviser pour régner : couvertures de *n* points de la droite
  par *k* segments de plus petite longueur

**20 mars 2023**
* fin diviser pour régner : ligne d'horizon
* rencontre au milieu; code : [subsum.c](code/subsum.c)
* entrées / sorties : flux standard, shell et `C`; code :
  [bufferisation.c](code/bufferisation.c) /
  [bufferisation2.c](code/bufferisation2.c) /
  [lecture_entree_standard.c](code/lecture_entree_standard.c) / [lecture_chaine.c](code/lecture_chaine.c)

**22 mars 2023**
* entrées / sorties : flux standard, `ocaml`
* fichiers textuels; code :
  [trop_d_ouvertures.c](code/trop_d_ouvertures.c) /
  [pas_d_ecriture.c](code/pas_d_ecriture.c) / [cat.ml](code/cat.ml)
* Algorithmique du texte : recherche de motifs (algorithmes de
  Rabin-Karp et de Boyer-Moore_Horspool); compression de données
  (algorithmes de Huffman, et Lempel-Ziv-Welsh)

**27 mars 2023**
* fin algorithme Lempel-Ziv-Welsh
* sérialisation; code :
  [serialisation_tableau_bidim.c](code/serialisation_tableau_bidim.c)
  /
  [serialisation_tableau_bidim.ml](code/serialisation_tableau_bidim.ml)
  / [arbres.h](code/arbres.h) / [arbres.c](code/arbres.c) /
  [arbres.ml](code/arbres.ml) / [serialisation_arbre_binaire.c](code/serialisation_arbre_binaire.c)
* `fwrite` / `fread` / `fseek`; code :
  [exemple_fwrite.c](code/exemple_fwrite.c) / [exemple_fread.c](code/exemple_fread.c)
* introduction bases de données
