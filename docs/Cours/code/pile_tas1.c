#include <stdlib.h>

int main(){
  int tab1[5];
  int tab2[] = {1,2,3};
  int tab3[10] = {4,5,6};

  int *p1, *p2, *p3;

  tab1[0] = 2; /* pour eviter l'optimisation du compilateur si tab1
                          n'est pas utilise */
  
  p1 = malloc(7*sizeof(int));
  p2 = tab1;
  p3 = malloc(2*sizeof(int));

  free(p1);
  free(p3);
}
