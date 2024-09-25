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
