#include <stdio.h>
#include "couleur.h"

const struct couleur blanc = { .r=255, .g = 255, .b = 255 };

void affiche_couleur(struct couleur c){
      printf("%d %d %d ", c.r, c.g, c.b);
}
