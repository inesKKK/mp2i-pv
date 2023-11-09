#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include "mandelbrot.h"
#include "tests_mandelbrot.h"

void test_point_suivant(){
  /*
  double x, y;
  double epsilon = 0.00001;

  point_suivant(0, 0, 0, 0, &x, &y);
  assert(fabs(x)<epsilon && fabs(y)<epsilon);

  point_suivant(1, 1, 2, 3, &x, &y);
  assert(fabs(x-2)<epsilon && fabs(y-5)<epsilon);

  point_suivant(1.5, -2.3, -2, .5, &x, &y);
  assert(fabs(x+5.04)<epsilon && fabs(y+6.4)<epsilon);
  */
}


void test_suite_bornee(){
  /*
  assert(suite_bornee(0,0));
  assert(!suite_bornee(1,1));
  assert(suite_bornee(.01,.01));
  assert(!suite_bornee(1,0));
  */
}

int main(void){
  test_point_suivant();
  test_suite_bornee();
  return 0;
}
