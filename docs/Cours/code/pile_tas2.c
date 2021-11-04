#include <stdlib.h>

void f(double x){
  int tab[] = {4,5,6,7};
  double *q = (double *)malloc(3*sizeof(double));

  free(q);
}

int main(){
  int n = 2;
  int tab[] = {1,2,3};
  int *p = (int *)malloc(5*sizeof(int));

  f(3.14);
  
  free(p);
  return 0;
}
