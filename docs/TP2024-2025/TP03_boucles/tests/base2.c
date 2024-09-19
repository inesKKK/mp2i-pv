#include <stdio.h>

int main(void){
  int n = 1 << 31;

  printf("La ligne suivante doit être 1");
  for(int i=0; i<31; i=i+1){
    printf("0");
  }
  printf(" :\n");
  ecriture_binaire_positif(n);
  
  return 0;
}
