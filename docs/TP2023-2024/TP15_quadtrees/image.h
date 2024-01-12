#ifndef _IMAGE_H
#define _IMAGE_H

#include <stdint.h>
#include <stdbool.h>

struct couleur {
  uint8_t r, g, b;
};
typedef struct couleur couleur;


struct image {
  int larg, haut; // dimensions de l'image
  couleur **c; // c[ligne][colonne]
};
typedef struct image image;

/*************************/
/* Les fonctions fournies */
/*************************/

/** largeur, hauteur : dimension de l'image (entiers >0)
 * fond : couleur pour le fond
 * sortie : image d'une seule couleur
 */
image *canevas(int largeur, int hauteur, couleur fond);

/****************************************/
/* Les fonctions à écrire et documenter */
/****************************************/
bool meme_couleur(couleur c1, couleur c2);
couleur melange2(couleur c1, couleur c2);
couleur melange4(couleur c1, couleur c2, couleur c3, couleur c4);


#endif
