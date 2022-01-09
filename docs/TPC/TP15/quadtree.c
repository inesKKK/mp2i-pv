#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "quadtree.h"
#include "image.h"
#include "ppm.h"


/*************************/
/* Les fonctions à écrire */
/*************************/

quadtree *image2quadtree(image *img, int debi, int debj, int taille){
  //TODO
  return NULL;
}

void simplifier(quadtree *q){
  //TODO
}

void quadtree2image(quadtree *q, image *img, int debi, int debj, int taille){
  //TODO
}


void liberer_quadtree(quadtree *q){
  //TODO
}


quadtree *reduire(quadtree *q, int taille){
  //TODO
  return NULL;
}


/*************************/
/* Les fonctions fournies */
/*************************/

bool est_feuille(quadtree *q){
  return q == NULL || (q->se == NULL && q->so == NULL && q->ne == NULL && q->no == NULL);
}

int taillei(quadtree *q){
  if(q == NULL || est_feuille(q)){
    return 0;
  }
  return 1 + taillei(q->se) + taillei(q->so) + taillei(q->ne) + taillei(q->no);
}

quadtree *img2qt(image *img){
  if(img == NULL || img->haut != img->larg){
    return NULL;
  }
  return  image2quadtree(img, 0, 0, img->haut);
}


image *qt2img(quadtree *q){
  image *img;
  if(q == NULL){
    return NULL;
  }

  img = (image *)malloc(sizeof(image));
  img->larg = q->taille;
  img->haut = q->taille;
  img->c = (couleur **)malloc(img->haut * sizeof(couleur *));
  for(int j=0; j<img->haut; j=j+1){
    img->c[j] = (couleur *)malloc(img->larg * sizeof(couleur));
  }
  quadtree2image(q, img, 0, 0, q->taille);

  return img;
}




int main(void){
  // TODO tests
  //affiche(qt2img(img2qt(lecture("img.ppm"))));
  //affiche(qt2img(reduire(img2qt(lecture("img.ppm")), 64)));
}
