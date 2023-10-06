#include <assert.h>

/** u, v : 2 vecteurs de meme dimension
 * n : leur dimension */
int produit_scalaire(int *u, int *v, int n){
  // TODO
}

int main(void){
  int u[] = {1, 2, 3, 4}, v[] = {-1, 0, 2, 5};

  assert(produit_scalaire(u, v, 4) == 25);
  
  return 0;
}
