#include <assert.h>

int main(void){
  assert(parfait(6));
  assert(!parfait(15));
  assert(parfait(8128));
  assert(parfait(33550336));
  assert(!parfait(64726437));
  
  return 0;
}
