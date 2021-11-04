#include<stdlib.h>

int *f(){
  int tab[] = {1,2,3};
  return tab;  // incorrect : on ne renvoie pas l'adresse d'une variable locale
}

int main(){
  int *p = f();
}
