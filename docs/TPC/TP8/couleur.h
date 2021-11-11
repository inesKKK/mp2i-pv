#ifndef _COULEUR_H
#define _COULEUR_H

#include <stdint.h>

struct couleur {
  uint8_t r, g, b;
};

const struct couleur blanc;

void affiche_couleur(struct couleur c);

#endif
