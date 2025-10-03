#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

double *init_x(){
    double *x = (double *)malloc(2*sizeof(double));
    x[0] = 0;
    x[1] = 1;
    return x;
}

double *init_y(){
    double *x = (double *)malloc(2*sizeof(double));
    x[0] = 0;
    x[1] = 0;
    return x;
}


double *suivante_x(double *abs, double *ord, int n){
    int n2 = 4*(n-1)+1;
    double *abs2 = (double *)malloc(n2*sizeof(double));
    double y1, y3;
    double alpha = M_PI/3;
    for(int i=0; i<n-1; i++){
        abs2[4*i] = abs[i];
        abs2[4*i+1] = 2./3*abs[i] + 1./3*abs[i+1];
        y1 = 2./3*ord[i] + 1./3*ord[i+1];
        abs2[4*i+3] = 1./3*abs[i] + 2./3*abs[i+1];
        y3 = 1./3*ord[i] + 2./3*ord[i+1];
        abs2[4*i+2] = abs2[4*i+1] + (abs2[4*i+3] - abs2[4*i+1])*cos(alpha) - (y3-y1)*sin(alpha);
    }
    abs2[n2-1] = abs[n-1];
    return abs2;
}

double *suivante_y(double *abs, double *ord, int n){
    int n2 = 4*(n-1)+1;
    double *ord2 = (double *)malloc(n2*sizeof(double));
    double x1, x3;
    double alpha = M_PI/3;
    for(int i=0; i<n-1; i++){
        ord2[4*i] = ord[i];
        ord2[4*i+1] = 2./3*ord[i] + 1./3*ord[i+1];
        x1 = 2./3*abs[i] + 1./3*abs[i+1];
        ord2[4*i+3] = 1./3*ord[i] + 2./3*ord[i+1];
        x3 = 1./3*abs[i] + 2./3*abs[i+1];
        ord2[4*i+2] = ord2[4*i+1] + (ord2[4*i+3] - ord2[4*i+1])*cos(alpha) + (x3-x1)*sin(alpha);
    }
    ord2[n2-1] = ord[n-1];
    return ord2;
}


void affichage(int k){
    if(k<0){
        return ;
    }
    double *x = init_x(), *x2;
    double *y = init_y(), *y2;
    int n=2;
    for(int i=0; i<k; i++){
        x2 = suivante_x(x, y, n);
        y2 = suivante_y(x, y, n);
        free(x);
        x = x2;
        free(y);
        y = y2;
        n = 4*(n-1) + 1;
    }
    for(int i=0; i<n; i++){
        printf("%f %f\n", x[i], y[i]);
    }
}


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
  tests_question2(); //a decommenter
  affichage(3);
  return 0;
}
