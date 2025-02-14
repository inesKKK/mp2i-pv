#ifndef _STEGANOGRAPHIE_H_
#define _STEGANOGRAPHIE_H_

#include <stdint.h>
#include <stdio.h>

struct image {
  int haut, larg;
  int max_couleur;
  uint16_t **pix;
};

typedef struct image image;

/** fabrique une image à partir du contenu d'un fichier supposé au format PGM ascii */
image *charger_image(char *fichier);

/** renvoie le caractère caché dans les 8 premières cases du tableau */
char caractere(uint16_t *tab);

/** écrit dans le flux le message caché dans l'image (on suppose f non NULL) */
void message(image *img, FILE *f);

/** insere le caractère dans les 8 premières cases du tableau */
void inserer_caractere(uint16_t *tab, char c);

/** cache le message dans l'image */
image *cacher(image *img, char *msg);

/** sauvegarde l'image dans le fichier au format PGM ascii */
int sauvegarder_image(char *fichier, image *img);

#endif
