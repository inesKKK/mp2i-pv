#include <stdio.h>
#include <stdlib.h>

int main(void){
  for(int i=0; i<1024; i=i+1){
    if(fopen("toto", "r") == NULL){
      printf("i = %d\n", i);
    }
  }

  return 0;
}
