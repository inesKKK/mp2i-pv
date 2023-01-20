#include <stdio.h>
#include <stdlib.h>
#include "arbres.h"
#include "exemple.h"
#include "files.h"

void parcours_largeur(struct arbre *a){
  file f = file_vide(); 
  if(a == NULL){
    return;
  }
  enfile(f, a);
  while(!est_file_vide(f)){
    struct arbre *t = defile(f);
    printf("%c ", t->nom);
    if(t->g != NULL){
      enfile(f, t->g);
    }
    if(t->d != NULL){
      enfile(f, t->d);
    }
  }
  printf("\n");
}

void affichage_naif(struct arbre *a){
  file f;
  if(a == NULL){
    return;
  }
  f = file_vide(); 
  enfile(f, a);
  enfile(f, NULL);
  while(!est_file_vide(f)){
    struct arbre *t = defile(f);
    if(t == NULL){
      printf("\n");
      if(!est_file_vide(f)){
        enfile(f, NULL);
      }
    } else {
      printf("%c ", t->nom);
      if(t->g != NULL){
        enfile(f, t->g);
      }
      if(t->d != NULL){
        enfile(f, t->d);
      }
    }
  }
  printf("\n");
}

int max(int a, int b){
  if (a>b){
    return a;
  } else {
    return b;
  }
}

int hauteur(struct arbre *a){
  if(a == NULL){
    return -1;
  }
  if (a->g == NULL && a->d == NULL){
    return 0;
  }
  return 1 + max( hauteur(a->g), hauteur(a->d) );
}

int remplir_espaces(struct arbre *a, int h){
  int e;
  if(a == NULL){
    return 0;
  }
  if(h == 0){
    a->espace = 0;
    return 0;
  }
  e = remplir_espaces(a->g, h-1);
  e = max(e, remplir_espaces(a->d, h-1));
  a->espace = 2*e+1;
  return a->espace;
}

void affiche_espaces(int n, char c){
  for(int i=0; i<n; i=i+1){
    printf("%c", c);
  }
}



void joli_affichage_arbre_parfait(struct arbre *a){
  if(a == NULL){
    return;
  }
  int h = hauteur(a);
  remplir_espaces(a, h);
  file f = file_vide(); 
  
  enfile(f, a);
  enfile(f, NULL);
  while(!est_file_vide(f)){
    struct arbre *t = defile(f);
    if(t == NULL){
      printf("\n");
      if(!est_file_vide(f)){
        enfile(f, NULL);
      }
    } else {
      affiche_espaces(t->espace, ' ');
      printf("%c ", t->nom);
      affiche_espaces(t->espace, ' ');
      if(t->g != NULL){
        enfile(f, t->g);
      }
      if(t->d != NULL){
        enfile(f, t->d);
      }
    }
  }
  printf("\n");
  
}


void parcours_prefixe(struct arbre *a){
  if(a == NULL){
    return;
  }
  printf("%c\n", a->nom);
  parcours_prefixe(a->g);
  parcours_prefixe(a->d);
}


void parcours_decale(struct arbre *a, int n){
  if(a == NULL){
    return;
  }
  affiche_espaces(n, '-');
  printf("%c\n", a->nom);
  parcours_decale(a->g, n+2);
  parcours_decale(a->d, n+2);
}

void joli_parcours_decale(struct arbre *a, int n){
  if(a == NULL){
    return;
  }
  affiche_espaces(n, '-');
  printf("%c", a->nom);
  joli_parcours_decale(a->g, n+1);
  if(a->g != NULL && a->d != NULL){
    printf("\n");
    affiche_espaces(((n+1)*(n+2))/2, ' ');
  }
  joli_parcours_decale(a->d, n+1);
}



int main(void){
  struct arbre *e = exemple();
  joli_parcours_decale(e, 0);
  /* parcours_largeur(e); */
  printf("\n");
  /* affichage_naif(e); */

  //  e = exemple_parfait(5);
  //  joli_affichage_arbre_parfait(e);
  //  parcours_largeur(e);
}
