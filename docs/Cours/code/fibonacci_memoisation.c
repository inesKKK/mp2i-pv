/* exemple en C */
#include <stdlib.h>

int fibo(int *val, int n){
  int f1, f2;

  if(val[n] != -1){
    return val[n];
  }

  val[n] = fibo(val, n-1) + fibo(val, n-2); 

  return val[n];
}


int fibonacci(int n){
  int *fib;
  int res;

  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  
  fib = (int *)malloc((n+1)*sizeof(int));

  fib[0] = 0;
  fib[1] = 1;
  for(int i=2; i<=n; i = i+1){
    fib[i] = -1;
  }

  fibo(fib, n);
  
  res = fib[n];
  free(fib);
  return res;
}

int main(){
  fibonacci(60);
  return 0;
}
