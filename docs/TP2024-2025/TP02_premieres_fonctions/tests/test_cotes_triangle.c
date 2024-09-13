#include <assert.h>

int main(void){
  assert(cotes_triangle(3,4,5));
  assert(!cotes_triangle(0,4,5));
  assert(!cotes_triangle(5,7,13));

  return 0;
}
