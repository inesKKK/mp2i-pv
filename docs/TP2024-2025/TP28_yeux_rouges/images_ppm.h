#ifndef _IMAGES_PPM_
#define _IMAGES_PPM_


struct couleur {
  unsigned int r, g, b;
};

typedef struct couleur couleur;

extern const int larg;
extern const int haut

typedef couleur image[haut][larg];

image *charger_image(char *fichier);
void sauvegarder_image(char *fichier, image *img);

#endif
