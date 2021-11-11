#ifndef _PEINTRE_H
#define _PEINTRE_H

#include "couleur.h"

extern const struct couleur blanc;

struct rectangle {
  int x, y; // coordonnées du point en haut à gauche
  int larg, haut; // largeur et hauteur
  struct couleur c;
};

struct toile {
  int larg, haut; // dimensions de la toile
  struct couleur **c;
};

struct toile *canevas(int largeur, int hauteur);
void detruit_toile(struct toile *tableau);
void trace(struct rectangle *rect, struct toile *tableau);
void affiche(struct toile *tableau);
struct toile *enonce();
struct toile *suprematism1915();

#endif
