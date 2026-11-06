#ifndef _SERPENT_H
#define _SERPENT_H

struct ecaille {
  int y; // ordonnée de l'écaille courante
  struct ecaille *queue; // écailles suivantes
};

struct serpent {
  int x; // abscisse de la tête du serpent
  int y; // ordonnée de la tête du serpent
  struct ecaille *e; // écailles suivantes
};

//////////////// code a ecrire
// new_serpent
// free_serpent
// avance_queue
// avance
// image
// trajet


#endif
