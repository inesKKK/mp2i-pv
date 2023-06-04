#include <stdlib.h>

struct adj {
  int s;
  struct adj *suiv;
};

typedef struct adj **graphe;

unsigned int degre_sortant(graphe g, int s){
  unsigned int n = 0;
  struct adj *succ;
  if(g[s] == NULL){
    return 0;
  }
  succ = g[s];
  while(succ != NULL){
    n = n+1;
    succ = succ->suiv;
  }
  return n;
}

/** pré-condition : l'arc s->t n'est pas présent */
void ajout_arc(graphe g, int s, int t){
  struct adj *succ = (struct adj *)malloc(sizeof(struct adj));
  succ->s = t;
  succ->suiv = g[s];
  g[s] = succ;
}

struct adj *supprimer(struct adj *succ, int t){
  if (succ == NULL){
    return NULL;
  }

  if (succ->s == t){
    struct adj *succ2 = succ->suiv;
    free(succ);
    return succ2;
  } else {
    succ->suiv = supprimer(succ->suiv, t);
    return succ;
  }
}

void suppression_arc(graphe g, int s, int t){
  if(g[s] != NULL){
    g[s] = supprimer(g[s], t);
  }
}

graphe cree_graphe(int n){
  graphe g = (struct adj **)malloc(n*sizeof(struct adj *));

  for(int s=0; s<n; s=s+1){
    g[s] = NULL;
  }
  return g;
}


void detruit_adj(struct adj *adj){
  if(adj != NULL){
    detruit_adj(adj->suiv);
    free(adj);
  }
}

void detruit_graphe(graphe g, int n){
  for(int s=0; s<n; s=s+1){
    detruit_adj(g[s]);
  }
  free(g);
}

int main(void){
  graphe g = cree_graphe(3);
  ajout_arc(g, 0, 1);
  ajout_arc(g, 0, 2);
  ajout_arc(g, 1, 0);
  ajout_arc(g, 2, 0);
    
  int n = degre_sortant(g, 1);

  suppression_arc(g, 1, 0);
  n = degre_sortant(g, 1);

  ajout_arc(g, 1, 2);
  n = degre_sortant(g, 1);

  detruit_graphe(g, 3);
  
  return 0;
}
