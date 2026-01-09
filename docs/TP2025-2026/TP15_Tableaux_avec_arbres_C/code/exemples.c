#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "exemples.h"
#include "tableaux_arbres.h"

arbre *ax(int h, int n, int *taille){
  arbre *a = malloc(sizeof(arbre));

  if(h == -1){//valeur
    a->hauteur = -1;
    a->val = n*n;
    a->fils_courant = NO_VALUE;
    a->fils = NULL;
    *taille = 1;
  } else {//arbre
    a->hauteur = h;
    a->val = NO_VALUE;
    a->fils_courant = NODE_SIZE;
    a->fils = malloc(NODE_SIZE*sizeof(arbre *));
    int indice = n;
    *taille = 0;
    for(int i=0; i<NODE_SIZE; i=i+1){
      int taillesa;
      a->fils[i] = ax(h-1, indice, &taillesa);
      indice = indice + taillesa;
    }
    *taille = indice - n;
  }
  return a;
}




tableau ex(int h){
  tableau t;
  t.echelle = 1;
  for(int i=0; i<h; i=i+1){
    t.echelle = t.echelle*NODE_SIZE;
  }
  t.racine = ax(h, 0, &t.len);
  return t;
}


int main(){
  tableau t;


  for(int k=0; k<5; k=k+1){
    t = ex(k);
    for(int i=0; i<t.len; i=i+1){
      assert(get(t, i) == i*i);
    }
  }

  return 0;
}
