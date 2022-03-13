#include <stdio.h>
#include <stdlib.h>


int main(void){
  FILE *f = fopen("big", "w");

  for(int i=0; i<10000; i++){
    fseek(f, 1<<30, SEEK_CUR);
  }
  fwrite("a", sizeof(char), 1, f);
  
  fclose(f);
  return 0;
}
