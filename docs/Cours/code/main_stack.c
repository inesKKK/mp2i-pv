#include <stdio.h>
#include "stack_array.h"
//#include "stack_list.h"  //au choix


int main(void){
  stack_tt *st = new_stack();
  int n;
  
  for(int i=0; i<5; i++){
    printf("un entier : ");
    scanf("%d", &n);
    push(st, n);
  }

  while(!empty(st)){
    printf("%d\n", pop(st));
  }
  
  delete(st);

  return 0;
}
