#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

/** initialisation d'une pile vide */
stack_tt *new_stack();

/** consultation du sommet de la pile */
int top(stack_tt *st);

/** recuperation du sommet de la pile (dépile) */
int pop(stack_tt *st);

/** ajout d'un élément dans la pile (empile) */
void push(stack_tt *st, int val);

/** test pile vide */
bool empty(stack_tt *st);

/** hauteur de pile */
int height(stack_tt *st);

/** détruit la pile */
void delete(stack_tt *st);

#endif
