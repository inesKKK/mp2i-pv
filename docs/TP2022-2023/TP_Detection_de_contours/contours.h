#ifndef _CONTOURS_H
#define _CONTOURS_H


extern const int haut;
extern const int larg;

void derive(int src[haut][larg], int dest[haut][larg]);
void seuil(int img[haut][larg], int s);


void lire_image_pgm(char *fic, int img[haut][larg], int *max);
void ecrire_image_pgm(char *fic, int img[haut][larg], int max);

#endif
