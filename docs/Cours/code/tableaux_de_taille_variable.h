#ifndef _TABLEAUX_DE_TAILLE_VARIABLE_H_
#define _TABLEAUX_DE_TAILLE_VARIABLE_H_

typedef struct vartab vartab_tt;

#include "vartab.h"

struct vartab {
  int size; // nombre de cases allouées
  int len;  // nombre d'éléments
  int *val;
};


#endif
