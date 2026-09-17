#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void){
  int n = 1 << 30;

  char *msg = "La ligne suivante doit être";
  printf("%s 1", msg);
  for(unsigned int i=0; i<30; i=i+1){
    printf("0");
  }
  printf(" :\n");
  for(unsigned int i=0; i<strlen(msg); i=i+1){
    printf(" ");
  }
  ecriture_binaire_positif(n);


  printf("\n\n");
  printf("%s ", msg);
  for(unsigned int i=0; i<8*sizeof(int)-1; i=i+1){
    printf("1");
  }
  printf(" :\n");
  for(unsigned int i=0; i<strlen(msg); i=i+1){
    printf(" ");
  }
  ecriture_binaire_positif(INT_MAX);
  printf("\n");
  
  return 0;
}
