#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "serpent.h"


void test_new_serpent(){
  struct serpent *s = new_serpent(-1);
  assert(s == NULL);

  s = new_serpent(0);
  assert(s == NULL);

  s = new_serpent(15);
  assert(s != NULL);
  assert(s->taille == 15);
  assert(s->tete == 0);
  assert(s->ecailles[0] == 0);
  assert(s->ecailles[14] == 0);

  //free_serpent(s);  // a decommenter quand ce sera implemente
}


void test_avance(){
  struct serpent *s = new_serpent(10);
  s->ecailles[0] = -1;
  s->ecailles[5] = 1;
  s->tete = 32;

  avance(s);
  assert(s->ecailles[1] == -1);
  assert(s->ecailles[6] == 1);
  assert(s->ecailles[9] == 0);
  assert(s->ecailles[0]>=-2 && s->ecailles[0]<=0);
  assert(s->tete == 33);

  free_serpent(s);
}


int main(void){
  //  test_new_serpent();
  //  test_avance();
  //  trajet(15, 100, 80);  // pour générer les images ppm
}
