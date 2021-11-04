#include <stdlib.h>

// fonction particulierement peu efficace pour obtenir 0
int zero(int n){
  if (n<=0) return 0;
  else return zero(n-1);
}

int main(){
  int a = zero(6);

  return 0;
}
