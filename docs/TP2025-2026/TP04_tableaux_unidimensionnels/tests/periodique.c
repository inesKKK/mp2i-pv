#include <assert.h>

/** t : tableau
 * n : taille de t
 * p : un entier */
bool periodique(int *t, int n, int p){
  // TODO
}

int main(void){
  int t[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2};
  int t2[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1};

  assert(periodique(t, 11, 3));
  assert(! periodique(t, 11, 2));
  assert(! periodique(t2, 11, 3));

  
  return 0;
}
