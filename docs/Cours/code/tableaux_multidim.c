#include <stdlib.h>
#include <stdio.h>


int main(void){
  int tab1[2][5]; //tableau de 2 cases, chacune de type un tableau de 5 entiers.
  int *tab2[3];//tableau de 3 cases, chacune de type un pointeur sur entier
  int tab3[][2] = {{1,2},{3,4},{5,6}};
  /* int tab4[][]; // interdit */
  /* int tab5[4][]; //interdit */
  int **p;//pointeur sur pointeur sur entier

  tab1[0][4] = 3;
    
  tab2[0] = NULL;
  tab2[1] = malloc(7*sizeof(int));
  tab2[2] = malloc(sizeof(int));

  p = (int **)malloc(4*sizeof(int *));
  for(int i=0; i<4; i++){
    p[i] = (int *)malloc((i+1)*sizeof(int));
  }

  //adresses des cases de tab1
  printf("tab1 :\n");
  for(int i=0; i<2; i=i+1){
    printf("\t&tab1[%d] = %p\n", i, (void *)&tab1[i]);
    for(int j=0; j<5; j=j+1){
      printf("\t\t&tab1[%d][%d] = %p \n", i, j, (void *)&tab1[i][j]);
    }
  }
  printf("\n");

  //adresses des cases de tab2
  printf("tab2 :\n");
  printf("\t&tab2[0] = %p\n", (void *)&tab2[0]);
  printf("\t&tab2[1] = %p\n", (void *)&tab2[1]);
  for(int j=0; j<7; j=j+1){
    printf("\t\t&tab2[1][%d] = %p \n", j, (void *)&tab2[1][j]);
  }
  printf("\t&tab2[2] = %p\n", (void *)&tab2[2]);
  printf("\t\t&tab2[2][0] = %p \n", (void *)&tab2[2][0]);
  printf("\n");

  //adresses des cases de tab3
  printf("tab3 :\n");
  for(int i=0; i<3; i=i+1){
    printf("\t&tab3[%d] = %p\n", i, (void *)&tab3[i]);
    for(int j=0; j<2; j=j+1){
      printf("\t\t&tab3[%d][%d] = %p \n", i, j, (void *)&tab3[i][j]);
    }
  }
  printf("\n");

  //adresses des cases de p
  printf("p :\n");
  for(int i=0; i<4; i=i+1){
    printf("\t&p[%d] = %p\n", i, (void *)&p[i]);
    for(int j=0; j<i+1; j=j+1){
      printf("\t\t&p[%d][%d] = %p \n", i, j, (void *)&p[i][j]);
    }
  }
  printf("\n");

  return 0;
}
