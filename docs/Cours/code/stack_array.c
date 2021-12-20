#include <stdlib.h>
#include "stack_array.h"

int *new_stack(){
  int *st = (int *)malloc((STACK_LENGTH+1) * sizeof(int));

  st[0] = 0;
  return st;
}

int top(int *st){
  return st[st[0]];
}

int pop(int *st){
  st[0] = st[0] - 1;
  return st[st[0]+1];
}

void push(int *st, int val){
  if(st[0] < STACK_LENGTH){
    st[0] = st[0] + 1;
    st[st[0]] = val;
  }
}

bool empty(int *st){
  return st[0] == 0;
}

int height(int *st){
  if(st == NULL){
    return 0;
  }
  return st[0];
}

void delete(int *st){
  free(st);
}
