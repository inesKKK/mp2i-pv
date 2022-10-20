#include <assert.h>
#include <math.h>

int main(void){
  double epsilon = 0.0001;
  double *u = premiers_termes(2, 3, 0, 35);
  double *v = premiers_termes(-1, 1, 1.7, 28);
  double *w = premiers_termes(3.14, 0, 1.4142, 53);

  assert(fabs(u[0] - 2) < epsilon);
  assert(fabs(u[10] - 2*pow(3, 10)) < epsilon);
  assert(fabs(u[34] - 2*pow(3, 34)) < epsilon);

  assert(fabs(v[0] + 1) < epsilon);
  assert(fabs(v[21] - (-1+1.7*21)) < epsilon);
  assert(fabs(v[27] - (-1+1.7*27)) < epsilon);

  assert(fabs(w[0] - 3.14) < epsilon);
  assert(fabs(w[52] - 1.4142) < epsilon);

  
  return 0;
}
