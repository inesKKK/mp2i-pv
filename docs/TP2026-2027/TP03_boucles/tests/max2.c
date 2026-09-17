#include <assert.h>

int main(void){
  assert(max2(0,0) == 0);
  assert(max2(1,2) == 2);
  assert(max2(2,1) == 2);
  assert(max2(1,1) == 1);
  assert(max2(-1,-2) == -1);
  assert(max2(-2,-1) == -1);
  assert(max2(-1,-1) == -1);
  assert(max2(-1,2) == 2);
  assert(max2(2,-1) == 2);
  
  return 0;
}
