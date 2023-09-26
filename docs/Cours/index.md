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
* correction : définition des variants de boucle
