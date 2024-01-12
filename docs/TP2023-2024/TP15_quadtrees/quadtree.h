#ifndef _QUADTREE_H
#define _QUADTREE_H

#include "image.h"

struct quadtree {
  int taille; // l'image représentée est carrée, de côté taille
  struct quadtree *se, *so, *ne, *no;
  couleur c;
};

typedef struct quadtree quadtree;

/*************************/
/* Les fonctions fournies */
/*************************/
/** renvoie un quadtree représentant l'image */
quadtree *img2qt(image *img);
/** renvoie une image représentant le quadtree */
image *qt2img(quadtree *q);
/** teste si le quadtree est réduit à une feuille */
bool est_feuille(quadtree *q);
/** renvoie le nombre de noeuds internes du quadtree */
int taillei(quadtree *q);

/****************************************/
/* Les fonctions à écrire et documenter */
/****************************************/
quadtree *image2quadtree(image *img, int debi, int debj, int taille);
void quadtree2image(quadtree *q, image *img, int debi, int debj, int taille);
void liberer_quadtree(quadtree *q);
void simplifier(quadtree *q);
quadtree *reduire(quadtree *q, int taille);
void tourner(quadtree *q);

#endif
