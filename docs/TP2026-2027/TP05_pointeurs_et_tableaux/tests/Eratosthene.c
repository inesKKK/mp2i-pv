#include <assert.h>
#include <stdlib.h>

int main(void){
  bool *premier = eratosthene(200);

  assert(eratosthene(-1) == NULL);
  assert(!premier[0]);
  assert(!premier[1]);
  assert(premier[2]);
  assert(premier[3]);
  assert(premier[137]);
  assert(!premier[169]);

  free(premier);

  return 0;
}
