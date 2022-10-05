#include <assert.h>
#include <math.h>

int main(void){
  double tab[] = {-4.3, -3.1, 0, 1.2, 5.6, 6.3};
  assert(fabs(plus_petite_distance(tab, 6) - .7) < 0.00001);
  
  return 0;
}
