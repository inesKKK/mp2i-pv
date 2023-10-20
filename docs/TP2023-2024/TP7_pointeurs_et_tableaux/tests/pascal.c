#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void tests_question1(){
  uint8_t p0[] = {1};
  uint8_t *p1, *p2, *p3, *p4, *p5;

  p1 = ligne_suivante(p0, 1);
  assert(p1[0] == 1);
  assert(p1[1] == 1);

  p2 = ligne_suivante(p1, 2);
  free(p1);
  assert(p2[0] == 1);
  assert(p2[1] == 2);
  assert(p2[2] == 1);

  p3 = ligne_suivante(p2, 3);
  free(p2);
  assert(p3[0] == 1);
  assert(p3[1] == 3);
  assert(p3[2] == 3);
  assert(p3[3] == 1); 

  p4 = ligne_suivante(p3, 4);
  free(p3);
  p5 = ligne_suivante(p4, 5);
  free(p4);
  assert(p5[1] == 5);
  assert(p5[3] == 10);
  free(p5);
}


void tests_question2(){
  printf("triangle de Pascal de hauteur 1:\n");
  triangle_de_Pascal(1);
  printf("\n\ntriangle de Pascal de hauteur 10:\n");
  triangle_de_Pascal(10);
}


int main(void){
  tests_question1();
  //tests_question2(); // a decommenter

  return0;
}
