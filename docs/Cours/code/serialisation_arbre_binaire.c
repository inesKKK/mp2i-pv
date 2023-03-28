#include <stdlib.h>
#include <stdio.h>

struct node {
  int val; //entiers positifs
  struct node *g, *d;
};

typedef struct node *tree;

tree init(int val, tree g, tree d){
  tree t = (struct node *)malloc(sizeof(struct node));

  t->val = val;
  t->g = g;
  t->d = d;

  return t;
}


int sauvegarde_noeud(FILE *f, tree t, int indice){
  fseek(f, indice*sizeof(int), SEEK_SET);
  if (t == NULL){
    int n = -1;
    fwrite(&n, sizeof(int), 1, f);
    return indice;
  } else {
    int ng, nd;
    fwrite(&t->val, sizeof(int), 1, f);
    ng = sauvegarde_noeud(f, t->g, 2*indice);
    nd = sauvegarde_noeud(f, t->d, 2*indice+1);
    return (ng < nd) ? nd : ng;  // max des deux
  }
}

void sauvegarde(char *fichier, tree t){
  FILE *f = fopen(fichier, "w");
  int max_noeud = 0;

  if(f == NULL){
    return;
  }
  max_noeud = sauvegarde_noeud(f, t, 1);
  fseek(f, 0, SEEK_SET);
  fwrite(&max_noeud, sizeof(int), 1, f);
  
  fclose(f);
}


tree chargement_noeud(FILE *f, int indice, int max_noeud){
  tree t;
  int n;

  if(indice > max_noeud){
    return NULL;
  }
  
  fseek(f, indice*sizeof(int), SEEK_SET);
  fread(&n, sizeof(int), 1, f);
  if(n == -1){
    return NULL;
  } else {
    t = (struct node *)malloc(sizeof(struct node));
    t->val = n;
    t->g = chargement_noeud(f, 2*indice, max_noeud);
    t->d = chargement_noeud(f, 2*indice+1, max_noeud);
    return t;
  }
}

tree chargement(char *fichier){
  FILE *f = fopen(fichier, "r");
  tree t;
  int max_noeud;

  if(f == NULL){
    return NULL;
  }

  fread(&max_noeud, sizeof(int), 1, f);
  t = chargement_noeud(f, 1, max_noeud);
  
  fclose(f);
  return t;
}

int main(void){
  tree t = init(5, init(3, NULL, NULL), init(12, init(17, NULL, init(666, NULL, NULL)), NULL));
  sauvegarde("serialisation_arbre", t);

//  t = chargement("serialisation_arbre");
}
