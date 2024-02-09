#include <stdlib.h>
#include "arbres.h"

struct arbre *exemple(){
  struct arbre *a = (struct arbre *)malloc(10*sizeof(struct arbre));
  a[0].nom = 'a';
  a[0].g = &a[1];
  a[0].d = &a[2];
  a[1].nom = 'b';
  a[1].g = &a[3];
  a[1].d = &a[4];
  a[2].nom = 'c';
  a[2].g = NULL;
  a[2].d = &a[5];
  a[3].nom = 'd';
  a[3].g = NULL;
  a[3].d = NULL;
  a[4].nom = 'e';
  a[4].g = &a[6];
  a[4].d = NULL;
  a[5].nom = 'f';
  a[5].g = &a[7];
  a[5].d = &a[8];
  a[6].nom = 'g';
  a[6].g = NULL;
  a[6].d = &a[9];
  a[7].nom = 'h';
  a[7].g = NULL;
  a[7].d = NULL;
  a[8].nom = 'i';
  a[8].g = NULL;
  a[8].d = NULL;
  a[9].nom = 'j';
  a[9].g = NULL;
  a[9].d = NULL;
  
  return a;
}


int puissance(int a, int n){
  int p = 1;
  while (n > 0) {
    if (n%2 == 1){
      p = p * a;
    }
    a = a * a;
    n = n / 2;
  }

  return p;
}

struct arbre *exemple_parfait(int h){
  int taille = puissance(2, h+1) - 1;
  struct arbre *a = (struct arbre *)malloc(taille*sizeof(struct arbre));
  char etiq = 'a';

  for(int i=0; i<taille; i=i+1){
    a[i].nom = etiq;
    etiq = (char) ((etiq+1-'a')%26 + 'a'); //pour la lettre suivante de facon cyclique
    if(i < taille/2){
      a[i].g = &a[2*i+1];
      a[i].d = &a[2*i+2];
    } else {
      a[i].g = NULL;
      a[i].d = NULL;
    }
  }
  
  return a;
}
