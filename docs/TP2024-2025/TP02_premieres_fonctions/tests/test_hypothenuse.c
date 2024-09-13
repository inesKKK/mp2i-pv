#include <math.h>
#include <assert.h>

int main(void){
  double epsilon = 0.0001;

  assert(fabs(hypothenuse(3,4) - 5) < epsilon);
  assert(fabs(hypothenuse(7,9) - 11.401754) < epsilon);

  return 0;
}
