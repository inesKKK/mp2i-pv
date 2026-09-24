#include <assert.h>

/** t1 : tableau a recopier
 * t2 : tableau dans lequel recopier (suppose de meme taille que t1)
 * n : taille des tableaux */
void copie(int *t1, int *t2, int n){
  // TODO
}

int main(void){
  int a1[] = {9}, a2[1];
  copie(a1, a2, 1);
  int b1[] = {6, 10, -3, 4, 5}, b2[5];
  copie(b1, b2, 5);

  assert(a1[0] == a2[0]);

  assert(b1[0] == b2[0]);
  assert(b1[4] == b2[4]);

  return 0;
}

