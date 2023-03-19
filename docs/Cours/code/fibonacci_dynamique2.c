/* exemple en C */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int64_t fibonacci(int n){
  int64_t fibn2, fibn1, fib;
    
  if(n==0 || n==1) return 1;

  fibn2 = 1;
  fibn1 = 1;
    for(int i=2; i<=n; i++){
      fib = fibn1 + fibn2;
      fibn2 = fibn1;
      fibn1 = fib;
    }
  return fib;
}

int main(int argc, char **argv){
  int n = 4;
  if(argc > 1){
    n = atoi(argv[1]);
  }
  printf("%ld\n", fibonacci(n));
  return 0;
}
