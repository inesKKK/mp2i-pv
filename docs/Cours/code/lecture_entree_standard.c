#include <stdio.h>
#include <stdlib.h>

int main(void){
  char c, d;
  int n;

  printf("c = ");
  scanf(" %c", &c);
  printf("d = ");
  scanf(" %c", &d);
  printf("n = ");
  scanf(" %d", &n);

  printf("c lu : %c\n", c);
  printf("d lu : %c\n", d);
  printf("n lu : %d\n", n);
  
  return 0;
}
