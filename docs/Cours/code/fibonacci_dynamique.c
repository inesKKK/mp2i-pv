/* exemple en C */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int64_t fibonacci(int n){//solution avec tableau (mais on peut s'en passer)
  int64_t *fib;
  int64_t res;
  
  if(n==0 || n==1) return 1;
  
  fib=malloc((n+1)*sizeof(int64_t));
  
  fib[0] = 1;
  fib[1] = 1;
  for(int i=2; i<=n; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  res = fib[n];
  free(fib);
  return res;
}

int main(int argc, char **argv){
  int n = 4;
  if(argc > 1){
    n = atoi(argv[1]);
  }
  printf("%ld\n", fibonacci(n));
  return 0;
}
