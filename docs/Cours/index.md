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
* introduction à `ocaml` : immuabilité, expressions
* compilation et exécution `ocaml` : `ocamlc`, `ocamlopt`, REPL
* types primitifs `ocaml`
* définitions de variables
* expressions conditionnelles, expressions `let` et portée
* annotation de types
* fonctions anonymes
* définition d'une fonction
