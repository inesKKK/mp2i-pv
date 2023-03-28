#include <stdio.h>
#include <stdlib.h>
#include "arbres.h"

void sauve(arbre a, FILE *file){
  if (a == NULL){
    fprintf(file, "-1 ");
  }  else {
    fprintf(file, "%d ", a->v);
    sauve(a->g, file);
    sauve(a->d, file);
  }
}

void sauvegarde(arbre a, char *f){
  FILE *file = fopen(f, "w");
  sauve(a, file);
  fclose(file);
}


arbre charge(FILE *file){
  arbre a;
  int n;
  fscanf(file, " %d", &n);
  if (n == -1){
    return NULL;
  }

  a = (arbre)malloc(sizeof(struct noeud));
  a->v = n;
  a->g = charge(file);
  a->d = charge(file);

  return a;
}

arbre chargement(char *f){
  arbre a;
  FILE *file = fopen(f, "r");
  a = charge(file);
  fclose(file);

  return a;
}

int main(void){
//  arbre a = chargement("toto");
  struct noeud a = {.v = 5, .g = NULL, .d = NULL},
	b = {.v = 13, .g = &a, .d = NULL},
	c = {.v = 17, .g = NULL, .d = NULL},
	d = {.v = 25, .g = &b, .d = &c};
  sauvegarde(&d, "titi");
  return 0;
}
