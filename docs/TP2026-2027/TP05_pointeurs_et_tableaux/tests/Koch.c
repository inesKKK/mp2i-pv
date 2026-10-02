#include <stdlib.h>
#include <assert.h>
#include <math.h>

void tests_question1(){
  double epsilon = 0.00001;
  double *test = init_x();

  assert(fabs(test[0])<epsilon);
  assert(fabs(test[1]-1)<epsilon);
  free(test);
}

void tests_question2(){
  double epsilon = 0.00001;
  double *test = init_y();

  assert(fabs(test[0])<epsilon);
  assert(fabs(test[1])<epsilon);
  free(test);
}

int main(void){
  tests_question1();
  //tests_question2(); //a decommenter
  //affichage(3); //a decommenter (en commentant les tests precedents)
  return 0;
}
