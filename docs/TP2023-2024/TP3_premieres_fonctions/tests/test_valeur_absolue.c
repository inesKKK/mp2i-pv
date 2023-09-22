#include <math.h>
#include <assert.h>

int main(void){
  double epsilon = 0.0000001;

  assert(fabs(valeur_absolue(0)) < epsilon);
  assert(fabs(valeur_absolue(1.) - 1) < epsilon);
  assert(fabs(valeur_absolue(-1.7) - 1.7) < epsilon);

  return 0;
}
