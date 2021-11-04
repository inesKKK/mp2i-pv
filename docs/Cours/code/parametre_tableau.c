#include<stdlib.h>

void f(int n[]){
  n[0] = 5;
}

int main(){
  int *p = (int *)malloc(sizeof(int));
  int tab[3];

  f(tab);
}
