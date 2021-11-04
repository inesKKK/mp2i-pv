#include <stdio.h>

int main(int argc, char **argv){
  printf("argc = %d\n", argc);
  for(int i=0; i<argc; i = i+1){
    printf("argc[%d] : %s\n", i, argv[i]);
  }
  
  return 0;
}
