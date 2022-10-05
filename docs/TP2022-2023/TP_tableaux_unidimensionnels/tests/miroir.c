#include <assert.h>

int main(void){
  bool xxx[] = {true, false, false, true, false, true, true, true, false, false, false, false, false, false, false, true, true, true, true, true, false, false, true, true, true, true, false, true, true, false, true, false, false, true, true, false, false, false, true, true, false, true, true, false, true, false, true, true, true, false, false, true, false, true, false, true, true, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, false, true, true, true, false, true, false, false, false, false, false, true, false, false, true, false, false, true, true, true, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, false, false, false, true, true, false, true, false, false, true, false, false, true, true, false, false};

  int *yyy = miroir(xxx);
  
  assert(! yyy[0]);
  assert(yyy[32]);
  assert(! yyy[86]);
  assert(! yyy[117]);

  
  return 0;
}
