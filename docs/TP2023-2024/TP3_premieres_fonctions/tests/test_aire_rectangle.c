#include <math.h>
#include <assert.h>

int main(void){
  double epsilon = 0.0001;

  assert(fabs(aire_rectangle(0,7)) < epsilon);
  assert(fabs(aire_rectangle(3.4,5.2) - 17.68) < epsilon);

  return 0;
}
