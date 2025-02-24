## Chronologie du cours

[page d'accueil](https://ineskkk.github.io/mp2i-pv/)

### septembre

#### 2 septembre 2024

* présentation rapide de ce qu'est l'informatique;
* introduction à la ligne de commande
* introduction au SGF
* commandes liées au SGF : `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `cp`,
  `mv`, `rm`

#### 4 septembre 2024

* i-nœuds, commande `ls -i`
* répertoires comme entité structurante pour le passage du tableau
  d'i-nœuds à l'arborescence du SGF
* liens physiques et liens symboliques; commandes `ln` et `ln -s`
* exemple de création d'un faux gros fichier; code: [bigfile.c](code/bigfile.c)
* espace d'adressage
* droits sur les fichiers : consultation, signification et modification

#### 5 septembre 2024

* caractérisation d'un langage de programmation: paradigmes
  (POO/impératif/fonctionnel)
* graphe de flot de contrôle d'un programme
* compilation vs. interprétation
* types: définition, taille, conversions explicite et implicite, typage fort vs. typage faible
* typage statique vs. typage dynamique
* identifiants dans les langages de programmation
* bases de `C` : compilation

#### 9 septembre 2024

* bases de `C` : flot d'un programme `C` et rôle de la fonction `main`
* identifiants en `C` : règles
* variables en `C` : déclaration, affectation
* variables en `C` : portée

#### 10 septembre 2024

* variables en `C` : portée; code :
  [reutilisation_identifiant.c](code/reutilisation_identifiant.c)
* constantes en `C` (littérales et symboliques)
* fonctions en `C`: invocation/appel, syntaxe

#### 11 septembre 2024

* fonctions en `C`: passage par valeurs, variables locales, valeur de
  retour; code : [passage_par_valeurs.c](code/passage_par_valeurs.c)
* types en `C`: `int`, `unsigned int`, `int8_t`, `int32_t`, `int64_t`,
  `uint8_t`, `uint32_t`, `uint64_t`
* bit de poids fort / bit de poids faible
* complément à 2

#### 16 septembre 2024

* opérations sur les entiers
* norme IEEE 754 pour les nombres à virgule flottante en double
  précision
* opérations sur les doubles, problèmes de précision et erreurs d'arrondi
* opérations entre doubles et entiers
* booléens
* structures de contrôle de `C`: conditionnelles, boucles
  conditionnelles, boucles inconditionnelles

#### 18 septembre 2024

* introduction à l'algorithmique
* conception d'un algorithme: entrée, sortie, problème de décision
* correction: terminaison, correction partielle et totale; code :
  [plus_grande_puissance_de_2.c](code/plus_grande_puissance_de_2.c) /
  [plus_grande_puissance_de_2.ml](code/plus_grande_puissance_de_2.ml)
* efficacité: complexité temporelle, complexité spatiale

#### 23 septembre 2024

* indécidabilité du problème de l'arrêt
* terminaison : définition des variants de boucle et des variants
  d'appels
* preuve de terminaison par variant de boucle et par variant d'appel; 
  code : [factorielle.c](code/factorielle.c) /
  [factorielle.ml](code/factorielle.ml) /
  [nb_chiffres_base10.c](code/nb_chiffres_base10.c) /
  [nb_chiffres_base10.ml](nb_chiffres_base10.ml) / [dichotomie.c](code/dichotomie.c)
* correction : définition des invariants de boucle
* preuve de correction par invariant de boucle

#### 25 septembre 2024

* gestion de la mémoire en `C`: tableaux (déclaration, initialisation)

#### 30 septembre 2024

* preuve de correction par récurrence
* compter des opérations en itératif et en récursif
* ordres de grandeurs : grand O, $\Theta$, $\Omega$


### octobre
#### 2 octobre 2024

* définition des pointeurs
* valeur, contenu et déréférencement d'un pointeur
* obtenir une valeur de type pointeur: `NULL`, adresse d'une variable,
  allocation mémoire avec `malloc`

#### 7 octobre 2024

* comparaisons et calculs des ordres de grandeurs habituels
* comment définir les tailles des entrées; code : [tri_bulle.c](code/tri_bulle.c)
* complexités dans le pire et le meilleur des cas (définition)
* Schéma général de calcul d'une complexité
* étude de la complexité temporelle du tri bulle: meilleur des cas et
  pire des cas; code : [tri_bulle.c](code/tri_bulle.c)

#### 9 octobre 2024

* libération mémoire avec `free`
* pile d'appel d'un processus; code :
  [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) [pile_tas3.c](code/pile_tas3.c)
* bloc d'activation d'un appel

#### 14 octobre 2024

* tas d'un processus; code : [pile_tas4.c](code/pile_tas4.c)
* passage d'un pointeur en paramètre; code :
  [mise_a_42.c](code/mise_a_42.c)
* tableaux et fonctions; code :
  [parametre_tableau.c](parametre_tableau.c) / [retour_tableau.c](retour_tableau.c)
* tableaux et pointeurs (unidimensionnels et multidimensionnels) comme
  paramètres d'une fonction; code :
  [pb_tableaux_pointeurs.c](code/pb_tableaux_pointeurs.c)
* arguments du `main`; code :
  [arguments_du_main.c](code/arguments_du_main.c)

#### 16 octobre 2024

* étude de la complexité temporelle de la recherche dichotomique: meilleur des
  cas et pire des cas; code : [dichotomie.c](code/dichotomie.c)

### novembre
#### 4 novembre 2024
* types structurés en `C` : définition (`struct`), déclaration,
  initialisateur; accès aux champs
* types structurés et fonctions; code :
  [quadrilatere.c](code/quadrilatere.c)
* types structurés et tableaux, types structurés et pointeurs
* structures auto-référencées : listes chaînées; code :
  [liste_chainee1.h](code/liste_chainee1.h) / [liste_chainee1.c](code/liste_chainee1.c)
* listes chaînées en `C` avec une tête; code :
  [liste_chainee2.h](code/liste_chainee2.h) / [liste_chainee2.c](code/liste_chainee2.c)

#### 6 novembre 2024
* étude de la complexité temporelle du tri fusion; code : [tri_fusion.c](code/tri_fusion.c)

#### 13 novembre 2024
* introduction à `OCaml` : immuabilité, expressions
* compilation et exécution `OCaml` : `OCamlc`, `OCamlopt`, REPL
* types primitifs `OCaml`
* définitions de variables
* expressions conditionnelles, expressions `let` et portée
* annotation de types
* fonctions anonymes
* définition d'une fonction

#### 18 novembre 2024
* sémantiques dynamique et statique des fonctions
* curryfication

#### 20 novembre 2024
* fonctions récursives; code : [factorielle.ml](code/factorielle.ml) /
  [pair_impair.ml](code/pair_impair.ml) / [compte.ml](code/compte.ml)
  / [compte_rt.ml](code/compte_rt.ml)

#### 25 novembre 2024
* polymorphisme
* listes littérales, sémantiques des listes, constructeur de liste (`::`); code : [longue_liste.ml](code/longue_liste.ml)
* filtrage par motifs de listes
* fonctionnement du filtrage

#### 27 novembre 2024
* filtrage profond, disjonction de motifs
* exemples filtrage par motifs de listes; code :
  [pattern_matching.ml](code/pattern_matching.ml)

### décembre

#### 2 décembre 2024
* types algébriques: types énumérés sans valeur; code : [mois.ml](code/mois.ml)
* portée des constructeurs des types énumérés
* motifs de filtrage pour les types énumérés
* enregistrements et leurs motifs
* $n$-uplets et leurs motifs

#### 4 décembre 2024
* types énumérés embarquant des données
* motifs de filtrage des types énumérés embarquant des données;
  code : [figure.ml](code/figure.ml) / [liste_entiers_flottants.ml](code/liste_entiers_flottants.ml)

#### 9 décembre 2024
* début des structures de données
* mot-clef `typedef` en `C`
* interface des tableaux de taille variable; code :
  [vartab.h](code/vartab.h) /
  [main_tableaux_de_taille_variable.c](code/main_tableaux_de_taille_variable.c)
  /
  [tableaux_de_taille_variable.h](code/tableaux_de_taille_variable.h)
  / [tableaux_de_taille_variable.c](code/tableaux_de_taille_variable.c)
* interface des piles; code : [stack.h](code/stack.h) / [main_stack.c](code/main_stack.c) / [stack_array.h](code/stack_array.h) / [stack_array.c](code/stack_array.c) / [stack_list.h](code/stack_list.h) / [stack_list.c](code/stack_list.c)
* exemple d'utilisation de pile : calculatrice en polonaise inverse;
  code : [polonaise.ml](code/polonaise.ml)
* interface d'une file; code : [queue.h](code/queue.h) /
  [main_queue.c](code/main_queue.c) /
  [queue_list.h](code/queue_list.h) /
  [queue_list.c](code/queue_list.c)

#### 11 décembre 2024
* types récursifs et polymorphes; code : [liste.ml](code/liset.ml) /
  [liste_parametree.ml](code/liste_parametree.ml)
* mot-clef `and` en `OCaml` pour définir des types mutuellement
  récursifs
* options
* parenthésage `(`/`)` et `begin`/`end`
* files en `OCaml`; code : [queue.ml](code/queue.ml)

#### 16 décembre 2024
* arbres binaires : définitions de base (père, frère, sous-arbre,
  feuille, nœud interne, branche, arbre binaire strict, arbre binaire
  complet)
* lien taille / hauteur dans les divers types d'arbres binaires
* implémentation des arbres binaires en `C` avec des pointeurs et en `OCaml` avec un type somme
* implémentation des arbres binaires complets sous forme de tableau
* files de priorité

#### 18 décembre 2024
* implémentation des files par tas max : percolation vers le bas (correction et
  complexité)

### janvier

#### 6 janvier 2025
* implémentation des files par tas max (suite) : percolation vers le
  haut, modification de valeur, insertion de valeur, extraction du
  maximum, construction d'un tas (avec les complexités)

#### 7 janvier 2025
* complexité en moyenne
* étude de la complexité en moyenne du tri bulle; code :
  [tri_bulle.c](code/tri_bulle.c)
* complexité amortie : méthode du banquier, exemple des tableaux de
  taille variable

#### 8 janvier 2025
* complexité amortie (suite) : méthode du banquier, exemples des 
  tableaux de taille variable et des files implémentées par deux
  piles; méthode des potentiels, exemple des tableaux de taille
  variable

#### 13 janvier 2025
* complexité amortie (fin) : exemple des files implémentées par deux
  piles avec la méthode des potentiels
* applications des arbres binaires :
  * minoration de la complexité dans le pire des cas d'un tri par
    comparaisons
  * tri par tas
  * principe du codage de Huffman
  * tri rapide : déroulement sur un exemple

#### 15 janvier 2025
* mutabilité en `OCaml`: enregistrements avec champs mutables, types référence
  (y compris les tests d'égalité et de différence, `==` et `!=`)
* `unit` comme type de retour d'une fonction
* opérateur `;`

#### 20 janvier 2025
* tri rapide : correction totale, analyse
  de complexité dans le pire des cas, dans le meilleur des cas et en
  moyenne sous l'hypothèse de l'absence de doublons; code :
  [tri_rapide.c](code/tri_rapide.c)
* tri rapide : sensibilisation au cas des doublons
  
#### 22 janvier 2025
* type `unit` : type de retour, expressions conditionnelles, fonctions
  sans argument; code : [pile.ml](code/pile.ml)
* tableaux en `OCaml`
* boucles `for` en `OCaml`

#### 27 janvier 2025
* tri rapide : variante pour tenir compte des doublons; code :
  [tri_rapide_3.c](code/tri_rapide_3.c)
* parcours d'arbres binaires: en profondeur (préfixe, postfixe,
  suffixe), en largeur
* boucles `while` en `OCaml`

#### 28 janvier 2025
* exceptions en `OCaml`
* type caractère en `C` et en `OCaml`
* chaînes de caractères en `C` et en `OCaml`
* Rappels sur les flux standards des processus

### février

#### 3 février 2025
* représentation d'un ensemble de données
* arbres binaires de recherche:
  * construction naïve; code : [abr.ml](code/abr.ml)
  * recherche d'élément
  * parcours infixe
  * ajout d'un élément
  * suppression d'un élément
* arbres rouge et noir: définition, lien entre taille et hauteur


#### 4 février 2025
* entrées / sorties : flux standard, shell, `C` et `ocaml`; code :
  [bufferisation.c](code/bufferisation.c) /
  [bufferisation2.c](code/bufferisation2.c) /
  [lecture_entree_standard.c](code/lecture_entree_standard.c) / [lecture_chaine.c](code/lecture_chaine.c)
* arbres rouge et noir: rotations

#### 10 février 2025
* arbres rouge et noir : insertion et suppression d'un élément; code :
  [arbresRN.ml](code/arbresRN.ml)
* tables de hachage: définition

#### 11 février 2025
* tables de hachage: résolution des collisions par sondage et par
  chaînage; module `Hashtbl` en `OCaml`
* tests fonctionnels ou "boîtes noires"
