// doit être compilé avec le lien vers la librairie math : ajouter -lm à la fin de la ligne de compilation
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

const double epsilon = 0.000001;

bool egal(double x, double y){
  return fabs(x - y) < epsilon;
}

//écrire ici la fonction discriminant

//écrire ici la fonction racines

int main(void){
  int n;
  double x1, x2;

  n = racines(0, 1, 2, &x1, &x2);
  assert(n == 1 && egal(x1, -2));

  n = racines(0, 0, 2, &x1, &x2);
  assert(n == 0);

  n = racines(0, 0, 0, &x1, &x2);
  assert(n == -1);

  n = racines(2, 4, 2, &x1, &x2);
  assert(n == 1 && egal(x1, -1));

  n = racines(1, -3, 2, &x1, &x2);
  assert(n == 2 && ( ( egal(x1, 1) && egal(x2, 2) )
                     || ( egal(x1, 2) && egal(x2, 1) ) ) );

  n = racines(1, 3, 3.2, &x1, &x2);
  assert(n == 0);

  return 0;
}
