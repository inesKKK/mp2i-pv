#include <stdio.h>
//#include "stack_array.h"
#include "queue_list.h"  //au choix

int main(void){
  queue_tt q = new_queue();
  int n;
  
  for(int i=0; i<5; i++){
    printf("un entier : ");
    scanf("%d", &n);
    enqueue(q, n);
  }

  while(!empty(q)){
    printf("%d\n", dequeue(q));
  }
  
  delete(q);

  return 0;
}
