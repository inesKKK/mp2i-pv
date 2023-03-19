#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* exemple en C */
int64_t fibonacci(int n){
  if (n==0 || n==1){
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char **argv){
  int n = 4;
  if(argc > 1){
    n = atoi(argv[1]);
  }
  printf("%ld\n", fibonacci(n));
  return 0;
}
