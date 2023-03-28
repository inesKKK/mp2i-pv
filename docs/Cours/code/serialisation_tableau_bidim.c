#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tab {
  int haut, larg;
  int **val;
};

/** t : tableau bidimensionnel (pointeur non nul)
 * effet: sauvegarde dans le fichier dont le nom est passé en argument
 */
int sauvegarde(struct tab *t, const char *fichier){
  FILE *f;

  assert(t != NULL);
  f = fopen(fichier, "w");
  if (f == NULL){
    fprintf(stderr, "fichier %s: chemin inexistant ou droits insuffisants\n", fichier);
    return 1;
  }

  fprintf(f, "%d\n%d\n", t->haut, t->larg);
  for(int i=0; i<t->haut; i=i+1){
    for(int j=0; j<t->larg; j=j+1){
      fprintf(f, "%d;", t->val[i][j]);
    }
    fprintf(f, "\n");
  }
  
  fclose(f);

  return 0;
}

/** fichier : un fichier avec un tableau bidimensionnel sauvegardé
 * sortie : un tableau bidimensionnel avec les données correspondantes
 */
struct tab *chargement(const char *fichier){
  FILE *f;
  struct tab *t;

  f = fopen(fichier, "r");
  if (f == NULL){
    fprintf(stderr, "fichier %s: fichier inexistant ou droits insuffisants\n", fichier);
    return NULL;
  }

  t = (struct tab *)malloc(sizeof(struct tab));
  fscanf(f, " %d %d", &t->haut, &t->larg);
  t->val = (int **)malloc(t->haut * sizeof(int *));
  for(int i=0; i<t->haut; i=i+1){
    t->val[i] = (int *)malloc(t->larg * sizeof(int));
    for(int j=0; j<t->larg; j=j+1){
      fscanf(f, " %d;", &t->val[i][j]);
    }
  }
  
  fclose(f);
  return t;
}



int main(void){
  struct tab t = { .haut = 3, .larg = 2,
                   .val = NULL };

  t.val = (int **) malloc(3 * sizeof(int *));
  for(int i=0; i<3; i=i+1){
    t.val[i] = (int *)malloc(2*sizeof(int));
    t.val[i][0] = 2*i;
    t.val[i][1] = 2*i+1;
  }    
  sauvegarde(&t, "toto");

  sauvegarde(chargement("toto"), "titi");
  
  return 0;
}
