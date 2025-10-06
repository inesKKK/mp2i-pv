## Chronologie du cours

[page d'accueil](https://ineskkk.github.io/mp2i-pv/)

### septembre
#### 1er septembre 2025

* présentation rapide de ce qu'est l'informatique;
* introduction à la ligne de commande

#### 3 septembre 2025

* introduction au SGF
* commandes liées au SGF : `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `cp`,
  `mv`, `rm`
* i-nœuds, commande `ls -i`
* répertoires comme entité structurante pour le passage du tableau
  d'i-nœuds à l'arborescence du SGF
* liens physiques et liens symboliques; commandes `ln` et `ln -s`
* exemple de création d'un faux gros fichier; code: [bigfile.c](code/bigfile.c)
* espace d'adressage
* droits sur les fichiers : consultation, signification et modification

#### 6 septembre 2025

* caractérisation d'un langage de programmation: paradigmes
  (POO/impératif/fonctionnel)
* graphe de flot de contrôle d'un programme
* compilation vs. interprétation
* types: définition, taille, conversions explicite et implicite, typage fort vs. typage faible
* typage statique vs. typage dynamique
* identifiants dans les langages de programmation
* bases de `C` : compilation

#### 8 septembre 2025

* bases de `C` : flot d'un programme `C` et rôle de la fonction `main`
* identifiants en `C` : règles
* variables en `C` : déclaration, affectation
* variables en `C` : portée
* variables en `C` : portée; code :
  [reutilisation_identifiant.c](code/reutilisation_identifiant.c)
* constantes en `C` (littérales et symboliques)

#### 9 septembre 2025
* fonctions en `C`: invocation/appel, syntaxe
* fonctions en `C`: passage par valeurs, variables locales, valeur de
  retour; code : [passage_par_valeurs.c](code/passage_par_valeurs.c)
* types en `C`: `int`, `unsigned int`, `int8_t`, `int32_t`, `int64_t`,
  `uint8_t`, `uint32_t`, `uint64_t`
* bit de poids fort / bit de poids faible
* complément à 2
* opérations sur les entiers
* norme IEEE 754 pour les nombres à virgule flottante en double
  précision (début)

#### 10 septembre 2025

* norme IEEE 754 pour les nombres à virgule flottante en double
  précision (fin)
* opérations sur les doubles, problèmes de précision et erreurs d'arrondi
* opérations entre doubles et entiers
* booléens
* structures de contrôle de `C`: conditionnelles, boucles
  conditionnelles, boucles inconditionnelles

#### 15 septembre 2025

* introduction à l'algorithmique
* conception d'un algorithme: entrée, sortie, problème de décision
* correction: terminaison, correction partielle et totale; code :
  [plus_grande_puissance_de_2.c](code/plus_grande_puissance_de_2.c) /
  [plus_grande_puissance_de_2.ml](code/plus_grande_puissance_de_2.ml)
* efficacité: complexité temporelle, complexité spatiale
* indécidabilité du problème de l'arrêt
* terminaison : définition des variants de boucle

#### 17 septembre 2025

* preuve de terminaison par variant de boucle et par variant d'appel; 
  code : [factorielle.c](code/factorielle.c) /
  [factorielle.ml](code/factorielle.ml) /
  [nb_chiffres_base10.c](code/nb_chiffres_base10.c) /
  [nb_chiffres_base10.ml](nb_chiffres_base10.ml) / [dichotomie.c](code/dichotomie.c)
* correction : définition des invariants de boucle

#### 22 septembre 2025

* preuve de correction par invariant de boucle
* preuve de correction par récurrence
* définition des pointeurs
* valeur, contenu et déréférencement d'un pointeur

#### 24 septembre 2025

* obtenir une valeur de type pointeur: `NULL`, adresse d'une variable,
  allocation mémoire avec `malloc`
* libération mémoire avec `free`

#### 29 septembre 2025

* pile d'appel d'un processus; code :
  [pile_tas1.c](code/pile_tas1.c) / [pile_tas2.c](code/pile_tas2.c) [pile_tas3.c](code/pile_tas3.c)
* bloc d'activation d'un appel
* tas d'un processus; code : [pile_tas4.c](code/pile_tas4.c)
* passage d'un pointeur en paramètre; code :
  [mise_a_42.c](code/mise_a_42.c)
* tableaux et fonctions; code :
  [parametre_tableau.c](parametre_tableau.c) / [retour_tableau.c](retour_tableau.c)

### octobre

#### 1er octobre 2025

* compter des opérations en itératif et en récursif
* ordres de grandeurs : grand O, $\Theta$, $\Omega$
* comparaisons et calculs des ordres de grandeurs habituels
(début)
