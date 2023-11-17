# TP9 : tableaux, pointeurs et structures

Toutes les semaines, les TP sont à rendre pour le mercredi soir
suivant au plus tard, sur cahier-de-prepa. Comme c'est à la maison je
mets un seul énoncé pas trop compliqué (à condition que vous soyez
méthodiques).

> Les réponses sont à rendre dans un  fichier source, en
ajoutant en commentaire vos nom et prénom sur la première ligne, la
ligne de compilation à utiliser sur la deuxième ligne, et en
identifiant de manière claire les numéros de questions.


### Exercice : Serpent
Dans cet exercice, nous allons modéliser de façon simplifiée les mouvements erratiques d'un serpent. Seule règle : il avance vers les abscisses croissantes.

Je vous fournis les fichiers suivants :
* [fichiers.h](tests/fichiers.h) et [fichiers.c](tests/fichiers.c) qui
  permettent de transformer des tableaux représentant des images en
  fichiers contenant des images au format `ppm`;
* [tests_serpent.c](tests/tests_serpent.c) qui contient des tests
  pour votre code (certaines parties sont commentées, il faudra
  décommenter au fur et à mesure de votre implémentation);
* [serpent.h](tests/serpent.h) qui contient la définition de `struct
  serpent` et qu'il faudra compléter avec les signatures des fonctions
  à écrire.

Vous devez écrire votre code dans un fichier `serpent.c` (à créer).

Le type serpent est donné de la façon suivante :


```C
struct serpent {
    int taille; // nombre d'écailles, y compris la tête
    int tete; // abscisse de la tête
    int *ecailles; // ordonnées des écailles
    // l'écaille 0 est la tête
};
```

Question 1. Écrire et documenter un initialisateur `new_serpent` qui prend en
   argument une taille et renvoie un pointeur sur un serpent de cette taille-là dont la tête est à l'abscisse 0 et toutes les écailles sont à l'ordonnée 0. Prévoyez le cas où l'utilisateur donnerait une taille négative.


Question 2. En fin de vie le serpent disparaît et il faut libérer la mémoire qui lui est associée. Écrire une fonction `free_serpent` qui prend en argument un pointeur sur serpent et libère toute la mémoire associée.


Question 3. À chaque étape de sa vie, le serpent avance d'une case vers la droite, c'est-à-dire que l'abscisse de sa tête augmente de 1. L'ordonnée de sa tête peut rester identique, augmenter de 1 ou diminuer de 1. La fonction `rand` déclarée dans `stdlib.h` renvoie un entier pseudo aléatoire entre 0 et `RAND_MAX` (constante définie dans `stdlib.h`).

Écrire et documenter une fonction `avance` qui prend en argument un pointeur sur serpent et fait avancer le serpent (évidemment, c'est le même serpent, donc il ne s'agit pas d'en créer un nouveau).


Question 4. En vue de pouvoir faire un affichage, on a besoin de transformer des données sous forme de type structuré serpent en un tableau bidimensionnel de booléens (l'affichage se fera sur deux couleurs).

Écrire et documenter une fonction `image` qui prend en argument un pointeur sur serpent, un entier pour la largeur et un entier pour la hauteur et renvoie un tableau bidimensionnel aux bonnes dimensions avec des `false` dans toutes les cases où le serpent ne se trouve pas et des `true` là où il se trouve. On considèrera que le point de coordonnées $(0,0)$ se trouve sur le bord de gauche au milieu.

Pour obtenir un gif animé du mouvement du serpent, nous allons fabriquer un certain nombre de fichiers images au format `ppm`, et nous demanderons ensuite à `Imagemagick` de fabriquer le gif animé.

La fonction `ecrire_image` fournie dans le fichier `serpent.c` permet
d'écrire un fichier au format `ppm` à partir d'un tableau
bidimensionnel comme celui renvoyé par la fonction `image`.

Question 5. Écrire et documenter une fonction `trajet` qui prend en argument la longueur d'un serpent, la largeur et la hauteur d'une fenêtre, et permet de créer tous les fichiers d'images correspondant à chaque étape de l'avancée du serpent. 


Une fois que vous avez obtenu toutes les images de serpent, vous
pouvez obtenir le gif animé avec la ligne de commande

```bash
convert -delay 1 -loop 0 serpent-*.ppm serpent.gif  # pour fabriquer le gif animé
```

et effacer les fichiers images fabriqués avec la ligne de commande

```bash
rm -f serpent-*.ppm  # pour supprimer les images ppm
```

Vous pouvez voir votre animation en ouvrant le fichier généré
`serpent.gif` par exemple avec votre navigateur.

Je vous mets ce que j'obtiens de mon côté pour comparaison:

![](img/serpent_modele.gif)


## Exercice : Oiseaux

Pour cette partie, les fichiers utiles:
* [fichiers.h](tests/fichiers.h) et [fichiers.c](tests/fichiers.c) qui
  permettent de transformer des tableaux représentant des images en
  fichiers contenant des images au format `ppm`;
* [tests_oiseaux.c](tests/tests_oiseaux.c) qui contient des tests
  pour votre code (certaines parties sont commentées, il faudra
  décommenter au fur et à mesure de votre implémentation);
* [oiseaux.h](tests/oiseaux.h) qui contient les types définis et qu'il
  faudra compléter avec les signatures des fonctions.
  à écrire.

Vous devez écrire votre code dans un fichier `oiseaux.c` (à créer).

Question 1. Écrire et documenter une fonction `hasard` qui tire un entier positif ou nul au hasard, majoré par une borne donnée en premier paramètre, et ayant comme deuxième paramètre une valeur à éviter.  

Pour rappel, la fonction `random()` (déclaré dans le fichier d'en-tête `stdlib.h`) renvoie un entier entre 0 et une constante `RAND_MAX` (également définie dans le fichier d'en-tête `stdlib.h`).

Question 2. On désire modéliser le vol d'une nuée d'oiseaux. Pour cela, on modélise chaque oiseau comme un point, et on lui attribue un ami et un ennemi:


```C
struct oiseau {
    double x, y; // entre 0 et 1 pour être visible
    int ami;     // indice de l'ami dans la nuee (voir ci-dessous)
    int ennemi;  // indice de l'ennemi dans la nuee
};
```

Une nuée d'oiseaux est un ensemble d'oiseaux. On définit le type structuré:


```C
struct nuee {
    int taille; // nombre d'oiseaux
    struct oiseau *cui;
}
```

À chaque étape de vol, chaque oiseau se déplace selon le vecteur
<br />
$0.01 * \vec{u} + 0.05*\vec{v} -0.03*\vec{w}\:,$
<br />
où $\vec{u}$ est le vecteur unitaire de l'oiseau vers le point $(0.5, 0.5)$, $\vec{v}$ est le vecteur unitaire de l'oiseau vers son ami et $\vec{w}$ est le vecteur unitaire de l'oiseau vers son ennemi.

Question 3. Écrire et documenter une fonction `deplacement_oiseau` qui prend en paramètre (dans cet ordre) un pointeur sur nuée et deux pointeurs sur oiseau : le premier donne l'oiseau au temps $t$, le deuxième l'oiseau au temps $t+1$ (même ami et même ennemi, mais coordonnées mises à jour selon les règles établies ci-dessus ---si elles dépassent les limites pour être visible ce n'est pas grave).

Question 4. Écrire un documenter une fonction `alloue_nuee` qui prend en argument un entier qui est la taille de la nuée et alloue la mémoire nécessaire pour une nouvelle nuee (et renvoie l'adresse de cette nouvelle nuée).

Question 5. Écrire une fonction `init_nuee` qui prend en argument un
entier qui est la taille de la nuée et crée la nuée en tirant au hasard les abscisse, ordonnée, ami et ennemi de chaque oiseau (abscisse et ordonnée entre 0 et 1).

Question 6. Pour éviter d'effectuer sans arrêt des copies de données, les données liées à une nuée d'oiseau vont en fait alterner entre deux emplacements mémoire de type `struct nuee`. En permanence, l'un correspondra à l'étape qu'on est en train de calculer, tandis que l'autre correspondra à l'étape précédente (et bien sûr ils inverseront leur rôle à chaque changement d'étape). Écrire et documenter une fonction `deplacement` qui prend en argument un pointeur sur une nuée correspondant à l'état actuelle de la nuée, et un second pointeur sur une nuée qui permettra d'écrire les nouvelles coordonnées des oiseaux de la nuée. 

Question 7. De temps en temps, pour relancer la dynamique de la nuée, il faut modifier les ami et ennemi de chaque oiseau. Écrire et documenter une fonction `change_amities` qui a comme paramètre un pointeur sur nuee et retire au hasard les ami et ennemi de chaque oiseau.

Question 8. Pour les affichages, il faut transformer une nuée en image. Écrire et documenter une fonction `image` qui prend en argument un pointeur sur nuee et renvoie un tableau bidimensionnel de booléens de taille 300x300 où une case vaut `false` si et seulement s'il y a un oiseau dedans (n'oubliez pas que les coordonnées visibles des oiseaux sont entre 0 et 1, il faut donc appliquer un coefficient multiplicatif pour se ramener à 0-300).

Question 9. Je vous fournis la fonction `ecrire_image` qui permet de créer un fichier image au format `ppm` à partir d'un tableau bidimensionnel de booléens.

Écrire un programme avec plusieurs étapes de déplacement de la nuée
qui produit un fichier à chaque fois (en numérotant les fichiers dans l'ordre). Vous pouvez prendre les paramètres suivants:
* nombre d'oiseaux : 300
* nombre de pas : 200
* changement d'ami/ennemi : tous les 30 pas


Pour créer un gif animé puis supprimer les fichiers inutiles, vous
pouvez utiliser les commandes suivantes dans votre shell:

```bash
convert -delay .1 -loop 0 oiseaux-*.ppm oiseaux.gif  # pour fabriquer le gif animé
rm -f oiseaux-*.ppm  # pour supprimer les images ppm
```

De mon côté, j'obtiens l'animation suivante:

![](img/oiseaux_modele.gif)

Question 10.
Modifier le programme (les deux versions sont à rendre quand même) en
faisant en sorte qu'à l'étape de changement d'amitié, seulement 10%
des oiseaux changent d'ami (de façon probabiliste: un
oiseau à une chance sur dix de changer) et que l'ennemi d'un oiseau
soit en fait l'oiseau le plus proche de lui.
