#include <assert.h>

int main(void){
  assert(suivant_syracuse(1) == 4);
  assert(suivant_syracuse(6) == 3);
  assert(suivant_syracuse(13) == 40);

  return 0;
}
