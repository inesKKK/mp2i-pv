#include <assert.h>

/** t1 : tableau
 * t2 : tableau de même taille
 * n : taille commune */
bool miroir(bool *t1, bool *t2, int n){
  //TODO
}

int main(void){
  bool xxx[] = {true, false, false, true, false, true, true, true, false, false, false, false, false, false, false, true, true, true, true, true, false, false, true, true, true, true, false, true, true, false, true, false, false, true, true, false, false, false, true, true, false, true, true, false, true, false, true, true, true, false, false, true, false, true, false, true, true, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, false, true, true, true, false, true, false, false, false, false, false, true, false, false, true, false, false, true, true, true, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, false, false, false, true, true, false, true, false, false, true, false, false, true, true, false, false};
  bool yyy[] = {false, false, true, true, false, false, true, false, false, true, false, true, true, false, false, false, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, true, false, false, false, false, false, true, false, true, true, true, false, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, true, true, false, true, false, true, false, false, true, true, true, false, true, false, true, true, false, true, true, false, false, false, true, true, false, false, true, false, true, true, false, true, true, true, true, false, false, true, true, true, true, true, false, false, false, false, false, false, false, true, true, true, false, true, false, false, true};
  bool zzz1[] = {false, false, true, true, false, false, true, false, false, true, false, true, true, false, false, false, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, true, false, false, false, false, false, true, false, true, true, true, false, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, true, true, false, true, false, true, false, false, true, true, true, false, true, false, true, true, false, true, true, false, false, false, true, true, false, false, true, false, true, true, false, true, true, true, true, false, false, true, true, true, true, true, false, false, false, false, false, false, false, true, true, true, false, true, false, false, false};
  bool zzz2[] = {true, false, true, true, false, false, true, false, false, true, false, true, true, false, false, false, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, true, false, false, false, false, false, true, false, true, true, true, false, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, true, true, false, true, false, true, false, false, true, true, true, false, true, false, true, true, false, true, true, false, false, false, true, true, false, false, true, false, true, true, false, true, true, true, true, false, false, true, true, true, true, true, false, false, false, false, false, false, false, true, true, true, false, true, false, false, true};
  bool zzz3[] = {false, false, true, true, false, false, true, false, false, true, false, true, true, false, false, false, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, true, false, false, false, false, false, true, false, true, true, true, false, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, true, true, false, true, false, true, false, false, true, true, true, false, true, false, true, true, false, true, true, false, false, false, true, true, false, false, true, false, true, true, false, true, true, true, true, false, true, true, true, true, true, true, false, false, false, false, false, false, false, true, true, true, false, true, false, false, true};

  assert(miroir(xxx, yyy, 127));
  assert(!miroir(xxx, zzz1, 127));
  assert(!miroir(xxx, zzz2, 127));
  assert(!miroir(xxx, zzz3, 127));
  
  return 0;
}
