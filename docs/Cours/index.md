### Chronologie du cours

**4 septembre 2023**:

* présentation rapide de ce qu'est l'informatique;
* introduction à la ligne de commande


**6 septembre 2023**:
* introduction au SGF
* commandes liées au SGF : `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `cp`,
  `mv`, `rm`
* notion d'i-nœud et de numéro d'i-nœud
* contenu d'un répertoire
* liens physiques et symboliques, commande `ls`

**8 septembre 2023**
* droits sur les fichiers : consultation, signification et modification

**11 septembre 2023**
* espace d'adressage: description de System V
* exemple de création d'un faux gros fichier; code:
  [bigfile.c](code/bigfile.c)
* caractérisation d'un langage de programmation: paradigmes
  (POO/impératif/fonctionnel)
* graphe de flot de contrôle d'un programme
* compilation vs. interprétation
* types: définition, taille, conversions explicite et implicite, typage fort vs. typage faible
* typage statique vs. typage dynamique

**13 septembre 2023**
* identifiants dans les langages de programmation
* bases de `C` : compilation, flot d'un programme `C` et rôle de la
  fonction `main`
* types en `C`: `int`, `unsigned int`, `int8_t`, `int32_t`, `int64_t`,
  `uint8_t`, `uint32_t`, `uint64_t`
* bit de poids fort / bit de poids faible
* complément à 2

**18 septembre 2023**
* fin représentation des entiers
* norme IEEE 754 pour les nombres à virgule flottante en double
  précision [détails vus en TD]
* opérations sur les doubles, problèmes de précision et erreurs d'arrondi
* opérations entre doubles et entiers
* booléens
* identifiants en `C` : règles
* variables en `C` : déclaration, affectation
  
**20 septembre 2023**
* variables en `C` : portée; code :
  [reutilisation_identifiant.c](code/reutilisation_identifiant.c)
* constantes en `C` (littérales et symboliques)
* fonctions en `C`: invocation/appel, syntaxe

**22 septembre 2023** [en TP]
* fonctions en `C`: passage par valeurs, variables locales, valeur de
  retour; code : [passage_par_valeurs.c](code/passage_par_valeurs.c)
* structures de contrôle de `C`: conditionnelles, boucles conditionnelles

**25 septembre 2023**
* structures de contrôle de `C`: boucles inconditionnelles
* introduction à l'algorithmique
* conception d'un algorithme: entrée, sortie, problème de décision
* correction: terminaison, correction partielle et totale; code :
  [plus_grande_puissance_de_2.c](code/plus_grande_puissance_de_2.c) /
  [plus_grande_puissance_de_2.ml](code/plus_grande_puissance_de_2.ml)
* efficacité: complexité temporelle, complexité spatiale
* indécidabilité du problème de l'arrêt
* terminaison : définition des variants de boucle

**27 septembre 2023**
* terminaison :  définition des variants d'appels
* preuve de terminaison par variant de boucle
  code : [fibonacci.c](code/fibonacci.c) /
  [fibonacci.ml](code/fibonacci.ml) /
  [note_sous_la_moyenne.c](code/note_sous_la_moyenne.c) /
  [note_sous_la_moyenne.ml](code/note_sous_la_moyenne.ml) / [dichotomie.c](code/dichotomie.c)

**2 octobre 2023**
* preuve de terminaison par récurrence;
* correction : définition des invariants de boucle
* preuve de correction par invariant de boucle et par récurrence
* compter des opérations en itératif et en récursif
* ordres de grandeurs : grand O

**4 octobre 2023**
* gestion de la mémoire en `C`: tableau (déclaration, initialisation)

**9 octobre 2023**
* ordres de grandeurs : $\Theta$, $\Omega$
* comparaisons et calculs des ordres de grandeurs habituels
* comment définir les tailles des entrées; code : [tri_bulle.c](code/tri_bulle.c)
* complexités dans le pire et le meilleur des cas (définition)

**11 octobre 2023**
* définition des pointeurs
* obtenir une valeur de type pointeur: `NULL`, adresse d'une variable
* valeur, contenu et déréférencement d'un pointeur

**16 octobre 2023**
* Schéma général de calcul d'une complexité
* étude de la complexité temporelle du tri bulle: meilleur des cas et
  pire des cas; code : [tri_bulle.c](code/tri_bulle.c)
* étude de la complexité temporelle de la recherche dichotomique: meilleur des
  cas et pire des cas; code : [dichotomie.c](code/dichotomie.c)

**18 octobre 2023**
* obtenir une valeur de type pointeur: 
  allocation mémoire avec `malloc`, libération avec `free`
* pile d'appel d'un processus; code :
  [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) [pile_tas3.c](code/pile_tas3.c)
* bloc d'activation d'un appel


**20 octobre 2023** [en TP]
* tas d'un processus; code : [pile_tas4.c](code/pile_tas4.c)
* passage d'un pointeur en paramètre; code :
  [mise_a_42.c](code/mise_a_42.c)
* tableaux et fonctions; code :
  [parametre_tableau.c](parametre_tableau.c) / [retour_tableau.c](retour_tableau.c)

**6 novembre 2023**
* étude de la complexité temporelle du tri fusion; code : [tri_fusion.c](code/tri_fusion.c)


**8 novembre 2023**
* tableaux et pointeurs (unidimensionnels et multidimensionnels) comme
  paramètres d'une fonction; code :
  [pb_tableaux_pointeurs.c](code/pb_tableaux_pointeurs.c)
* arguments du `main`; code :
  [arguments_du_main.c](code/arguments_du_main.c)

**13 novembre 2023**
* types structurés en `C` : définition (`struct`), déclaration,
  initialisateur; accès aux champs
* types structurés et fonctions; code :
  [quadrilatere.c](code/quadrilatere.c)
* types structurés et tableaux, types structurés et pointeurs
* structures auto-référencées : listes chaînées; code :
  [liste_chainee1.h](code/liste_chainee1.h) / [liste_chainee1.c](code/liste_chainee1.c)


**15 novembre 2023**
* listes chaînées en `C` avec une tête; code :
  [liste_chainee2.h](code/liste_chainee2.h) / [liste_chainee2.c](code/liste_chainee2.c)
* introduction à `ocaml` : immuabilité, expressions
* compilation et exécution `ocaml` : `ocamlc`, `ocamlopt`, REPL
* types primitifs `ocaml` (début)
* définitions de variables

**20 novembre 2023**
* types primitifs `ocaml` (fin)
* définitions de variables
* expressions conditionnelles, expressions `let` et portée

**22 novembre 2023**
* annotation des de types
* fonctions anonymes
* définition d'une fonction
* sémantiques dynamique et statique des fonctions
* curryfication

**27 novembre 2023**
* fonctions récursives; code : [factorielle.ml](code/factorielle.ml) /
  [pair_impair.ml](code/pair_impair.ml) / [compte.ml](code/compte.ml)
  / [compte_rt.ml](code/compte_rt.ml)
* polymorphisme
* listes littérales, sémantiques des listes, constructeur de liste (`::`); code : [longue_liste.ml](code/longue_liste.ml)

**29 novembre 2023**
* filtrage par motifs
* filtrage par motifs de listes; code :
  [pattern_matching.ml](code/pattern_matching.ml)
* opérateur `@` vs. constructeur `::`
* fonctionnement du filtrage, filtrage profond, disjonction de motifs

**4 décembre 2023**
* compléments sur le filtrage : disjonctions de cas, motifs gardés;
  code : [que_pairs.ml](code/que_pairs.ml)
* exemple du tri par insertion
* types algébriques: types énumérés sans valeur; code : [mois.ml](code/mois.ml)
* portée des constructeurs des types énumérés
* motifs de filtrage pour les types énumérés
* enregistrements et leurs motifs
* $n$-uplets et leurs motifs
* types énumérés embarquant des données

**6 décembre 2023**
* motifs de filtrage des types énumérés embarquant des données;
  code : [figure.ml](code/figure.ml) / [liste_entiers_flottants.ml](code/liste_entiers_flottants.ml)
* syntaxe et sémantique des types
* types récursifs et polymorphes; code : [liste.ml](code/liset.ml) /
  [liste_parametree.ml](code/liste_parametree.ml)

**11 décembre 2023**
* début des structures de données
* mot-clef `typedef` en `C`
* interface des tableaux de taille variable; code :
  [vartab.h](code/vartab.h) /
  [main_tableaux_de_taille_variable.c](code/main_tableaux_de_taille_variable.c)
  /
  [tableaux_de_taille_variable.h](code/tableaux_de_taille_variable.h)
  / [tableaux_de_taille_variable.c](code/tableaux_de_taille_variable.c)
* interface des piles; code : [stack.h](code/stack.h) / [main_stack.c](code/main_stack.c) / [stack_array.h](code/stack_array.h) / [stack_array.c](code/stack_array.c) / [stack_list.h](code/stack_list.h) / [stack_list.c](code/stack_list.c)

**13 décembre 2023**
* mot-clef `and` en `ocaml` pour définir des types mutuellement
  récursifs
* options; code : [xip2.ml](code/zip2.ml)
* parenthésage `(`/`)` et `begin`/`end`

**18 décembre 2023**
* exemple d'utilisation de pile : calculatrice en polonaise inverse;
  code : [polonaise.ml](code/polonaise.ml)
* interface d'une file; code : [queue.h](code/queue.h) /
  [main_queue.c](code/main_queue.c) /
  [queue_list.h](code/queue_list.h) /
  [queue_list.c](code/queue_list.c) / [queue.ml](code/queue.ml)
* arbres binaires : définitions de base (père, frère, sous-arbre,
  feuille, nœud interne, branche, arbre binaire strict)

**20 décembre 2023**
* arbres binaires parfaits, lien taille / hauteur
* arbres binaires complets, lien taille / hauteur
* implémentation des arbres binaires en `C` avec des pointeurs et en `ocaml` avec un type somme
* implémentation des arbres binaires complets sous forme de tableau
* files de priorité
* implémentation par tas max : percolation vers le bas (correction et
  complexité), percolation vers le haut, modification de valeur,
  insertion de valeur, extraction du maximum, construction d'un tas
  (avec les complexités)

**8 janvier 2024**
* complexité en moyenne
* étude de la complexité en moyenne du tri bulle; code :
  [tri_bulle.c](code/tri_bulle.c)
* complexité amortie : méthode du banquier

**10 janvier 2024**
* complexité amortie : suite méthode du banquier, méthode du potentiel

**15 janvier 2024**
* applications des arbres binaires :
  * minoration de la complexité dans le pire des cas d'un tri par
    comparaisons
  * tri par tas

**17 janvier 2024**
* tests fonctionnels
* tests structurels: couverture des sommets, couverture des arcs,

  
**22 janvier 2024**
* tests structurels: tests exhaustifs de condition
* documentation et programmation défensive; code :
  [assert1.c](code/assert1.c) / [assert2.c](code/assert2.c)
* applications des arbres binaires (suite) :
  * principe du codage de Huffman

**24 janvier 2024**
* mutabilité en `ocaml`: enregistrements avec champs mutables, types référence

**29 janvier 2024**
* tri rapide : déroulement sur un exemple, correction totale, analyse
  de complexité dans le pire des cas, dans le meilleur des cas et en
  moyenne sous l'hypothèse de l'absence de doublons; code : [tri_rapide.c](code/tri_rapide.c)

**30 janvier 2024**
* tri rapide : cas des doublons; code :
  [tri_rapide_3.c](tri_rapide_3.c)
* parcours d'arbres binaires: en profondeur (préfixe, postfixe,
  suffixe), en largeur (dont l'algorithme de Cheney en applicaction)

**31 janvier 2024**
* type `unit` : type de retour, expressions conditionnelles, fonctions
  sans argument; code : [pile.ml](code/pile.ml)
* tableaux et boucles en `ocaml`
* exceptions en `ocaml`
