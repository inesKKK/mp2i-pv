#include <stdlib.h>
#include "stack_list.h"

struct stack *new_stack(){
  struct stack *st = (struct stack *)malloc(sizeof(struct stack));

  st->len = 0;
  st->elt = NULL;

  return st;
}

int top(struct stack *st){
  return st->elt->val;;
}

int pop(struct stack *st){
  struct cell *old = st->elt;
  int res = old->val;

  st->elt = st->elt->next;
  st->len -= 1;
  free(old);
  
  return res;
}

void push(struct stack *st, int val){
  struct cell *c = (struct cell *)malloc(sizeof(struct cell));

  c->val = val;
  c->next = st->elt;
  st->elt = c;
  st->len += 1;
}

bool empty(struct stack *st){
  return (st == NULL || st->len == 0);
}

int height(struct stack *st){
  if(st == NULL){
    return 0;
  }
  return st->len;
}

void delete_cell(struct cell *c){
  if(c != NULL){
    delete_cell(c->next);
    free(c);
  }
}

void delete(struct stack *st){
  if(st != NULL){
    delete_cell(st->elt);
  }
  free(st);
}
