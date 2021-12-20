#ifndef _STACK_LIST_H
#define _STACK_LIST_H

typedef struct stack stack_tt;

#include "stack.h"

struct cell {
  int val;
  struct cell *next;
};

struct stack {
  int len;
  struct cell* elt;
};

#endif
