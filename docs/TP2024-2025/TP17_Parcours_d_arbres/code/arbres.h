#ifndef _ARBRES_H
#define _ARBRES_H

struct arbre {
  char nom;
  struct arbre *g, *d;
  int espace; // pour l'exercice 3
};

#endif
