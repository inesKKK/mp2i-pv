#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "oiseaux.h"

void test_hasard(){
  /*
  int n = rand()%30;
  for(int i=0; i<50; i=i+1){
    assert(hasard(30, n) != n);
  }
  */
}

void test_deplacement_oiseau(){
  /*
  struct nuee nu = { 3, NULL };
  struct oiseau oi;

  nu.cui = (struct oiseau *)malloc(3*sizeof(struct oiseau));
  for(int i=0; i<3; i=i+1){
    nu.cui[i].x = .2*i+.1;
    nu.cui[i].y = .3*i+.1;
    nu.cui[i].ami = (i+2)%3;
    nu.cui[i].ennemi = (i+1)%3;
  }
  deplacement_oiseau(&nu, &nu.cui[0], &oi);

  assert(fabs(oi.x-0.11816507) < 0.00001);
  assert(fabs(oi.y-0.12371207) < 0.00001);
  */
}


void test_nuee(){
  /*
  struct nuee *nu = alloue_nuee(10);
  assert(nu->taille == 10);
  free(nu->cui);
  free(nu);
  */
}

void test_init_nuee(){
  /*
  struct nuee *nu = init_nuee(10);
  assert(nu->cui[0].x>=0 && nu->cui[0].x<=1);
  assert(nu->cui[9].ami>=0 && nu->cui[9].ami<=8);
  */
}

void test_deplacement(){
  /*
  struct nuee nu = { 3, NULL }, *future;

  nu.cui = (struct oiseau *)malloc(3*sizeof(struct oiseau));
  for(int i=0; i<3; i=i+1){
    nu.cui[i].x = .2*i+.1;
    nu.cui[i].y = .3*i+.1;
    nu.cui[i].ami = (i+2)%3;
    nu.cui[i].ennemi = (i+1)%3;
  }

  future = alloue_nuee(3);

  deplacement(&nu, future);

  assert(fabs(future->cui[0].x-0.11816507) < 0.00001);
  assert(fabs(future->cui[0].y-0.12371207) < 0.00001);
  assert(fabs(future->cui[2].x-0.48890600) < 0.00001);
  assert(fabs(future->cui[2].y-0.67335899) < 0.00001);
  free(future);
  */
}

void test_change_amitie(){
  /*
  struct nuee nu = { 10, NULL };
  bool id = true;
  nu.cui = (struct oiseau *)malloc(10*sizeof(struct oiseau));
  for(int i=0; i<10; i=i+1){
    nu.cui[i].x = .2*i+.1;
    nu.cui[i].y = .3*i+.1;
    nu.cui[i].ami = (i+2)%10;
    nu.cui[i].ennemi = (i+1)%10;
  }
  change_amities(&nu);
  for(int i=0; i<nu.taille; i=i+1){
    id = id && nu.cui[i].ami==(i+2)%3 && nu.cui[i].ennemi==(i+1)%3;
  }
  assert(!id);
  */
}



void test_image(){
  /*
  struct nuee nu = { 10, NULL };
  bool **img;

  nu.cui = (struct oiseau *)malloc(10*sizeof(struct oiseau));
  for(int i=0; i<10; i=i+1){
    nu.cui[i].x = .05*i+.1;
    nu.cui[i].y = .03*i+.1;
    nu.cui[i].ami = (i+2)%10;
    nu.cui[i].ennemi = (i+1)%10;
  }
  img = image(&nu);

  assert(img[50][100]);
  assert(!img[120][84]);
  */
}


int main(void){
  test_hasard();
  test_deplacement_oiseau();
  test_nuee();
  test_init_nuee();
  test_deplacement();
  test_change_amitie();
  test_image();

  return 0;
}
