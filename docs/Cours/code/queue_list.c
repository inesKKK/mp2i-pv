#include <stdlib.h>
#include "queue_list.h"

/** initialisation d'une file vide */
struct queue *new_queue(){
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  q->len = 0;
  q->nouveau = NULL;
  q->ancien = NULL;
  return q;
}

/** récuperation d'un élément dans la file (défile) */
int dequeue(struct queue *q){
  int res = q->ancien->val;
  struct cell *old = q->ancien;
  q->len = q->len - 1;

  q->ancien = q->ancien->next;
  free(old);
  if(q->ancien == NULL){
    q->nouveau = NULL;
  }
  return res;
}

/** ajout d'un élément dans la file (enfile) */
void enqueue(struct queue *q, int val){
  struct cell *maillon = (struct cell *)malloc(sizeof(struct cell));
  q->len = q->len + 1;

  maillon->val = val;
  maillon->next = NULL;
  if(q->nouveau != NULL){
    q->nouveau->next = maillon;
  }
  q->nouveau = maillon;
  if(q->ancien == NULL){
    q->ancien = q->nouveau;
  }
}

/** consulter l'élément en tête */
int peek(struct queue *q){
  return q->ancien->val;
}

/** test file vide */
bool empty(struct queue *q){
  return q->len == 0;
}

void delete_cell(struct cell *c){
  if(c != NULL){
    delete_cell(c->next);
    free(c);
  }
}

/** détruit la file */
void delete(struct queue *q){
  delete_cell(q->ancien);
  free(q);
}
