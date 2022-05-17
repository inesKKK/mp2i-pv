#include "contours.h"

const int haut = 400;
const int larg = 600;

void test_derive_premiere(int img[haut][larg], int transforme[haut][larg], int s){
  derive(img, transforme);
  seuil(transforme, s);
}  

int main(void){
  int img[haut][larg], transforme[haut][larg];
  int max;

  lire_image_pgm("paul_valery.pgm", img, &max);
  test_derive_premiere(img, transforme, 4000);
  ecrire_image_pgm("contours_paul_valery.pgm", transforme, 1);
  
  return 0;
}
