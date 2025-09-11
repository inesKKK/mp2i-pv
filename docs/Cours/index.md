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
