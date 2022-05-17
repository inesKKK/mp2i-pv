#include <stdlib.h>
#include <stdio.h>

/* dans la vraie vie il faudrait faire un tableau avec toutes les
adresses et une fonction intermédiaire, mais le but de ce TP étant
de mieux comprendre les tableaux 2D, je m'abstiens.
*/
int main(void){
  int *t0 = (int *)malloc(3*sizeof(int));
  int t1[] = {1,2,3};
  int t2[3];
  int *t3 = (int *)malloc(3*sizeof(int));

  printf("t0 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t0[i]);
  }
  printf("\n\n");

  printf("t1 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t1[i]);
  }
  printf("\n\n");

  printf("t2 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t2[i]);
  }
  printf("\n\n");

  printf("t3 :  ");
  for(int i=0; i<3; i=i+1){
    printf("%p  ", (void *)&t3[i]);
  }
  printf("\n\n");

  return 0;
}
