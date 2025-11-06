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
  assert(s->y == 0);
  struct ecaille *e = s->e;
  for(int i=0; i<14; i=i+1){
    assert(e->y == 0);
    assert(e->queue != NULL);
    e = e->queue;
  }
  assert(e->y == 0);
  assert(e->queue == NULL);
  
  free_serpent(s);  // à commenter si pas encore implémenté
}


void test_avance(){
  struct serpent *s = new_serpent(10);
  s->y = -1;
  s->e->queue->queue->queue->y = 1;
  s->x = 32;

  avance(s);
  assert(s->x == 33);
  assert(s->e->y == -1);
  assert(s->e->queue->queue->queue->queue->y == 1);
  assert(s->e->queue->queue->queue->queue->queue->y == 0);
  assert(s->y >= -2 && s->y <= 0);

  free_serpent(s);  // à commenter si pas encore implémenté
}


int main(void){
  // à décommenter au fur et à mesure de vos implémentations
  //  test_new_serpent();
  //  test_avance();
  //  trajet(15, 100, 80);  // pour générer les images ppm
}
