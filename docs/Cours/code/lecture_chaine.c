#include <stdio.h>

int main(void){
  char str[10];
  char c;
  
  //scanf(" %s", str); // dangereux si l'utilisateur entre plus de 9 caractères
  scanf(" %9s", str); // plus prudent: seuls 9 caractères sont lus

  scanf(" %c", &c);
  printf("c = %c\n", c); // c contiendra le 10e caractère écrit
  
  return 0;
}
