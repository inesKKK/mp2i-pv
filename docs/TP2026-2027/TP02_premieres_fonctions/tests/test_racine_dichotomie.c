#include <math.h>
#include <assert.h>

int main(void){
  double epsilon = 0.001;
  double precisiontest = 0.0000001;
  double xtest = 43643285.43;

  assert(fabs(racine_par_dichotomie(0, precisiontest)) < epsilon);
  assert(fabs(racine_par_dichotomie(.5, precisiontest) - sqrt(.5)) < epsilon);
  assert(fabs(racine_par_dichotomie(xtest, precisiontest) - sqrt(xtest)) < epsilon);

  return 0;
}
