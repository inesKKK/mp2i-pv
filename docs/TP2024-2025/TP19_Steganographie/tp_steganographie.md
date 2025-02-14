TP19 : Stéganographie
==

La _stéganographie_ est l'art de cacher un objet dans un autre. On
peut par exemple cacher un message dans une image.

Il s'agit dans un premier temps de découvrir le message caché dans
l'image [mystere.pgm](mystere.pgm), puis de fabriquer soit-même des
messages cachés.

![](mystere.png)

Le format d'image que nous allons utiliser est le format PGM ascii. Vous
pouvez regarder la description du format sur la [page
wikipedia](https://fr.wikipedia.org/wiki/Portable_pixmap#Fichier_ASCII_2).

On supposera dans la suite que les fichiers images ne contiennent pas
de ligne de commentaire.


Le TP est à faire en `C`. Pour qu'il n'y ait pas d'ambiguïté sur ce
que je demande, voici le fichier d'en-tête correspondant à votre
programme: [steganographie.h](steganographie.h).

## Exercice 1 : Mettre une image en mémoire.
Écrire une fonction `charger_image` qui prend en argument le nom d'un
fichier et renvoie un pointeur sur image qui pointe sur une zone mémoire
contenant les données de l'image.



## Exercice 2 : Lire une lettre cachée.
L'image fournie contient un message caché de la manière suivante :
* chaque ligne de l'image permet de cacher un caractère,
* dans une ligne donnée, chacun des 8 premiers pixels permet de
  cacher un bit qui est donné par le bit de poids faible du pixel,
* ces bits sont rangés du bit de poids fort au bit de poids faible du
  caractère caché.

Ainsi une image qui contiendrait dans la première colonne les niveaux
de gris suivant pour ses pixels:


| niveau de gris | bit de poids faible |
|-----|-----|
| 80 | 0 |
| 81 | 1 |
| 81 | 1 |
| 89 | 1 |
| 89 | 1 |
| 90 | 0 |
| 89 | 1 |
| 80 | 0 |

cacherait sur cette colonne le caractère `'z'` qui est le caractère de
code ascii 122 qui s'écrit `01111010` en binaire.

1. Comment obtient-on le bit de poids faible d'un entier?

2. Écrire une fonction `caractere` qui prend en argument un tableau
   d'au moins 8 entiers et renvoie le caractère caché (avec la méthode
   décrite précédemment).
   
## Exercice 3 : Lire le message secret.
Écrire une fonction `message` qui prend en argument une
image en mémoire et un nom de fichier et écrit le message caché dans
l'image dans le fichier correspondant. Le message se termine quand on
rencontre le caractère `'\0'` de code ascii 0.


## Exercice 4 : Cacher un caractère.
Écrire une fonction `inserer_caractere` qui prend en argument un
tableau d'entiers d'au moins 8 cases et un caractère, et insère le
caractère dans le tableau en suivant les règles décrites ci-dessus.

## Exercice 5 : Coder ses propres messages.
Écrire une fonction `cacher` qui prend en argument une image en
mémoire et une chaîne de caractères, cache le message dans l'image
(sans oublier le caractère `'\0'` final) et
renvoie l'adresse de l'image si l'image était assez grande pour
contenir le message ou `NULL` si ce n'est pas le cas.


## Exercice 6 : Sauvegarder une image.
Écrire une fonction `sauvegarder_image` qui prend en argument un nom
de fichier (qui n'existe pas forcément) et une image en mémoire et
sauvegarde l'image au format PGM ascii dans ce fichier.

## Exercice 7 : Fabriquer ses commandes.
Écrire un programme qui prend en argument un nom de fichier et une
chaîne de caractères et fabrique un fichier `secret.pgm` contenant
l'image avec le message caché. Si l'image n'est pas assez grande pour
cacher le message (avec la méthode décrite; il est clair qu'on peut
faire mieux), alors le programme doit afficher un message d'erreur.

Écrire un programme qui prend en argument un nom de fichier et affiche
le message secret contenu dans le fichier.
