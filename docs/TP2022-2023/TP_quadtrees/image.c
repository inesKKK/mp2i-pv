#include <stdlib.h>
#include <stdio.h>

#include "image.h"
#include "ppm.h"

couleur blanc = { .r = 255, .g = 255, .b = 255 };

/*************************/
/* Les fonctions à écrire */
/*************************/

couleur melange2(couleur c1, couleur c2){
  //TODO
  return blanc;
}

couleur melange4(couleur c1, couleur c2, couleur c3, couleur c4){
  //TODO
  return blanc;
}

bool meme_couleur(couleur c1, couleur c2){
  //TODO
  return true;
}


/*************************/
/* Les fonctions fournies */
/*************************/

image *canevas(int largeur, int hauteur, couleur fond){
  image *res = (image *)malloc(sizeof(image));
  res->larg = largeur;
  res->haut = hauteur;
  res->c = (couleur **)malloc(hauteur*sizeof(couleur *));
  for(int j=0; j < res->haut; j=j+1){
    res->c[j] = (couleur *)malloc(largeur*sizeof(couleur));
    for(int i=0; i < res->larg; i=i+1){
      res->c[j][i] = fond;
    }
  }

  return res;
}

