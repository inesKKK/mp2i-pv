#include <stdlib.h>

int main(void){
  int *bad_pt = NULL,
    *good_pt = malloc(sizeof(int));
  int n;

  while(1){
    n = rand()%10;
    if(n==0){
      *bad_pt = 5;
    } else {
      *good_pt = 5;
    }
  }
  
  return 0;
}
