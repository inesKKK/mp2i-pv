#include <stdbool.h>

struct mat_adj {
  int n;
  bool **adj;
};

/** M : matrice d'adjacence d'un graphe
 * i, j : indices sommets du graphe
 * len : entier >= 0
 * sortie : vrai si et seulement s'il existe un chemin de i à j
 * de longueur len dans le graphe */
bool chemin(mat_adj M, int i, int j, int len){
  if (len == 0){
    return i == j;
  }
  for(int k=0; k<M.n; k=k+1){
    if (M.adj[i][k] && chemin(M, k, j, len-1)){
      return true;
    }
  }
  return false;
}
