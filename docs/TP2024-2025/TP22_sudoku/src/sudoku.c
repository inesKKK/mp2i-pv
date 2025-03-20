#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sudoku.h"


int nb_de_lignes(FILE *f){
  int n = 0;

  rewind(f);
  while(fscanf(f, "%*s\n") != EOF){
    n++;
  }

  rewind(f);
  return n;
}

void recopie(FILE *src, FILE *dest){
  char c;
  while(fscanf(src, "%c", &c) != EOF){
    fprintf(dest, "%c", c);
  }
}
