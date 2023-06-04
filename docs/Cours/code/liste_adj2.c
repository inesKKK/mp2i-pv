#include <stdlib.h>

const int n = 10;
const int d = 3;
typedef int graphe[10][4];

void predecesseurs(graphe g, int s, int pred[n+1]){
  int p = 1; // case pour écrire le prochain prédécesseur
  for(int r=0; r<n; r=r+1){ // teste l'existence de l'arc r->s
    for(int i=1; i<g[r][0]; i=i+1){
      if(g[r][i] == s){
        pred[p] = r;
        p = p+1;
        break;
      }
    }
  }
  pred[0] = p-1;
}


int main(void){
  graphe g = {{2,1,3}, {3,1,2,7}, {1,0}, {1, 4}, {1, 1}, {1, 6},
              {1, 5}, {1, 8}, {0}, {1, 0}};

  return 0;
}
