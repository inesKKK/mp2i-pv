#include "tableaux_de_taille_variable.h"

int main(){
  int tab[] = {1,2,3,4,-1,7};
  vartab_tt *t;

  t = new_vartab(tab, 6);
  for(int i=0; i<10; i++){
    append(t, i);
  }
  delete_vartab(t);
}
