#include <assert.h>

int main(void){
  assert(Kaprekar(703));
  assert(Kaprekar(4879));
  assert(!Kaprekar(4329));
  
  return 0;
}
