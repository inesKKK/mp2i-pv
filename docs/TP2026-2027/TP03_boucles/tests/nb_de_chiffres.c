#include <assert.h>

int main(void){
  assert(nb_de_chiffres(0) == 0);
  assert(nb_de_chiffres(1) == 1);
  assert(nb_de_chiffres(9) == 1);
  assert(nb_de_chiffres(10) == 2);
  assert(nb_de_chiffres(99) == 2);
  assert(nb_de_chiffres(100) == 3);
  assert(nb_de_chiffres(865462) == 6);
  
  return 0;
}
