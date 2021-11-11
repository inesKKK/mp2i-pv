#ifndef _LISTE_H
#define _LISTE_H

struct maillon {
  int profondeur;
  struct rectangle *rect;
  struct maillon *suiv;
};

void perspective(struct toile *tableau, struct maillon *liste);

#endif
