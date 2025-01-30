#ifndef _FILES_H
#define _FILES_H

#include <stdbool.h>
#include "arbres.h"

#define TAILLE_MAX 512

struct file {
  int d, f;
  struct arbre *val[TAILLE_MAX];
};

typedef struct file *file;

/** renvoie une file vide */
file file_vide();
/** teste si une file est vide */
bool est_file_vide(file f);
/** enfile une valeur */
bool enfile(file f, struct arbre *v);
/** f : file non vide, renvoie le bout */
struct arbre *bout(file f);
/** f : file non vide, defile */
struct arbre *defile(file f);
#endif
