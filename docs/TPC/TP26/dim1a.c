#include <stdlib.h>
#include <stdio.h>

int main(void){
  int *t0 = (int *)malloc(3*sizeof(int));
  int t1[] = {1,2,3};
  int t2[3];
  int *t3 = (int *)malloc(3*sizeof(int));

  t0[0] = 4;
  t1[0] = 5;
  t2[0] = 6;
  t3[0] = 7;

  printf("t0 : %p\nt1 : %p\nt2 : %p\nt3 : %p\n", (void *)t0, (void *)t1, (void *)t2, (void *)t3);
  
  return 0;
}
