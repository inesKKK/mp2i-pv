#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include "mandelbrot.h"
#include "tests_mandelbrot.h"

void test_point_suivant(){
  struct point p;
  struct point origine = {.x=0, .y=0}, p1 = {.x=1, .y=1}, c1 = {.x=2, .y=3},
    p2 = {.x=1.5, .y=-2.3}, c2 = {.x=-2, .y=.5};
  double epsilon = 0.00001;

  point_suivant(origine, origine, &p);
  assert(fabs(p.x)<epsilon && fabs(p.y)<epsilon);

  point_suivant(p1, c1, &p);
  assert(fabs(p.x-2)<epsilon && fabs(p.y-5)<epsilon);

  point_suivant(p2, c2, &p);
  assert(fabs(p.x+5.04)<epsilon && fabs(p.y+6.4)<epsilon);
}


void test_suite_bornee(){
  struct point p1 = {.x=0, .y=0}, p2 = {.x=1, .y=1},
    p3 = {.x=.01, .y=.01}, p4 = {.x=1, .y=0};
  assert(suite_bornee(p1));
  assert(!suite_bornee(p2));
  assert(suite_bornee(p3));
  assert(!suite_bornee(p4));
}

int main(void){
  test_point_suivant();
  test_suite_bornee();
  return 0;
}
