#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

/** initialisation d'une file vide */
queue_tt new_queue();

/** récuperation d'un élément dans la file (défile) */
int dequeue(queue_tt q);

/** ajout d'un élément dans la file (enfile) */
void enqueue(queue_tt q, int val);

/** consulter l'élément en tête */
int peek(queue_tt q);

/** test file vide */
bool empty(queue_tt q);

/** détruit la file */
void delete(queue_tt q);

#endif
