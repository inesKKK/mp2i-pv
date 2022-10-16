#include <stdlib.h>

void f_pointeur_pointeur(int **p){
  p[0][0] = 1;
}

void f_tab_pointeur1(int *p[]){
  p[0][0] = 1;
}

void f_tab_pointeur2(int *p[3]){
  p[0][0] = 1;
}

/* void f_tab_tab1(int p[][]){ // interdit */
/*   p[0][0] = 1; */
/* } */

void f_tab_tab2(int p[][3]){
  p[0][0] = 1;
}

void f_tab_tab3(int p[2][3]){
  p[0][0] = 1;
}


int main(void){
  int **p1 = malloc(2*sizeof(int *));
  int *p2[2];
  int p3[2][3];
  
  p1[0] = malloc(3*sizeof(int));
  p1[1] = malloc(3*sizeof(int));
  p2[0] = malloc(3*sizeof(int));
  p2[1] = malloc(3*sizeof(int));

  f_pointeur_pointeur(p1);
  f_pointeur_pointeur(p2);
  /* f_pointeur_pointeur(p3);  // interdit */

  f_tab_pointeur1(p1);
  f_tab_pointeur1(p2);
  /* f_tab_pointeur1(p3); //interdit */
  
  f_tab_pointeur2(p1);
  f_tab_pointeur2(p2);
  /* f_tab_pointeur2(p3); // interdit */

  /* f_tab_tab2(p1); // interdit */
  /* f_tab_tab2(p2); // interdit */
  f_tab_tab2(p3);
  
  /* f_tab_tab3(p1); // interdit */
  /* f_tab_tab3(p2); // interdit */
  f_tab_tab3(p3);
  
  return 0;
}
