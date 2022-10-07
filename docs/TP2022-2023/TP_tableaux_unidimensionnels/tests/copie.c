#include <assert.h>

int main(void){
  int a[] = {9};
  int *a2 = copie(a, 1);
  int b[] = {6, 10, -3, 4, 5};
  int *b2 = copie(b, 5);

  assert(a[0] == a2[0]);

  assert(b[0] == b2[0]);
  assert(b[4] == b2[4]);

  return 0;
}

