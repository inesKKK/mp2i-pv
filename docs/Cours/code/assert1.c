#include <assert.h>

/** n : entier positif ou nul
 */
int factorielle(int n){
  assert( n >= 0 );
  
  if(n==0){
    return 1;
  }
  return n*factorielle(n-1);
}

int main(){
  factorielle(4);
}
