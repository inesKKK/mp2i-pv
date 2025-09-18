#include <assert.h>

int main(void){
  assert(max3(-1,-1,-1) == -1);
  assert(max3(1,2,3) == 3);
  assert(max3(1,3,2) == 3);
  assert(max3(2,1,3) == 3);
  assert(max3(2,3,1) == 3);
  assert(max3(3,1,2) == 3);
  assert(max3(3,2,1) == 3);
  assert(max3(-1,-2,-3) == -1);
  assert(max3(-2,7,-5) == 7);
  
  return 0;
}
