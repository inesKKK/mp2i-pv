# TP7 : tableaux, pointeurs et structures
## [à la maison pour cause de 11 novembre]


### Exercice : Serpent
Dans cet exercice, nous allons modéliser de façon simplifiée les mouvements erratiques d'un serpent. Seule règle : il avance vers les abscisses croissantes.

Votre base de travail est le fichier [serpent.c](tests/serpent.c). À
vous de le compléter et de décommenter les tests correspondants au fur
et à mesure des questions.

Le type serpent est donné de la façon suivante :


```C
struct serpent {
    int taille; // nombre d'écailles, y compris la tête
    int tete; // abscisse de la tête
    int *ecailles; // ordonnées des écailles
    // l'écaille 0 est la tête
};
```

1. Écrire et documenter un initialisateur `new_serpent` qui prend en
   argument une taille et renvoie un pointeur sur un serpent de cette taille-là dont la tête est à l'abscisse 0 et toutes les écailles sont à l'ordonnée 0. Prévoyez le cas où l'utilisateur donnerait une taille négative.


2. En fin de vie le serpent disparaît et il faut libérer la mémoire qui lui est associée. Écrire une fonction `free_serpent` qui prend en argument un pointeur sur serpent et libère toute la mémoire associée.


3. À chaque étape de sa vie, le serpent avance d'une case vers la droite, c'est-à-dire que l'abscisse de sa tête augmente de 1. L'ordonnée de sa tête peut rester identique, augmenter de 1 ou diminuer de 1. La fonction `rand` déclarée dans `stdlib.h` renvoie un entier pseudo aléatoire entre 0 et `RAND_MAX` (constante définie dans `stdlib.h`).

Écrire et documenter une fonction `avance` qui prend en argument un pointeur sur serpent et fait avancer le serpent (évidemment, c'est le même serpent, donc il ne s'agit pas d'en créer un nouveau).


4. En vue de pouvoir faire un affichage, on a besoin de transformer des données sous forme de type structuré serpent en un tableau bidimensionnel de booléens (l'affichage se fera sur deux couleurs).

Écrire et documenter une fonction `image` qui prend en argument un pointeur sur serpent, un entier pour la largeur et un entier pour la hauteur et renvoie un tableau bidimensionnel aux bonnes dimensions avec des `false` dans toutes les cases où le serpent ne se trouve pas et des `true` là où il se trouve. On considèrera que le point de coordonnées $(0,0)$ se trouve sur le bord de gauche au milieu.

Pour obtenir un gif animé du mouvement du serpent, nous allons fabriquer un certain nombre de fichiers images au format `ppm`, et nous demanderons ensuite à `Imagemagick` de fabriquer le gif animé.

La fonction `ecrire_image` fournie dans le fichier `serpent.c` permet
d'écrire un fichier au format `ppm` à partir d'un tableau
bidimensionnel comme celui renvoyé par la fonction `image`.

5. Écrire et documenter une fonction `trajet` qui prend en argument la longueur d'un serpent, la largeur et la hauteur d'une fenêtre, et permet de créer tous les fichiers d'images correspondant à chaque étape de l'avancée du serpent. 


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
![](serpent_modele.gif)
