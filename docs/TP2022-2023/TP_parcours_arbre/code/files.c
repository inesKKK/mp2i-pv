#include <stdbool.h>
#include <stdlib.h>
#include "files.h"
#include "arbres.h"

file file_vide(){
  file f = (struct file *)malloc(sizeof(struct file));
  f->d = 0;
  f->f = 0;
  return f;
}

bool est_file_vide(file f){
  return f->d == f->f;
}

bool enfile(file f, struct arbre *v){
  if((f->f - f->d + 1) % TAILLE_MAX == 0){
    return false;
  }
  f->val[f->d] = v;
  f->d = (f->d-1+TAILLE_MAX) % TAILLE_MAX;
  return true;
}

struct arbre *bout(file f){
  return f->val[f->f];
}

struct arbre *defile(file f){
  struct arbre *a = f->val[f->f];
  f->f = (f->f-1+TAILLE_MAX) % TAILLE_MAX;
  return a;
}

