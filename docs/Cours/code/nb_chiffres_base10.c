#include <stdio.h>

int nb(int n){
  if(n == 0){
    return 0;
  }
  return 1 + nb(n / 10);
}

int nombre_de_chiffres_en_base_10(int n){
  if(n == 0){
    return 1;
  }
  return nb(n);
}

int main(void){
  for(int i=-157; i<157; i++){
    printf("%d : %d chiffres\n", i, nombre_de_chiffres_en_base_10(i));
  }

  return 0;
}
