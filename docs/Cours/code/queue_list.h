#ifndef _QUEUE_LIST_H_
#define _QUEUE_LIST_H_

typedef struct queue *queue_tt;

#include "queue.h"

struct cell {
  int val;
  struct cell *next;
};

struct queue {
  int len;
  struct cell *nouveau, *ancien;
  //ancien : element le plus ancien, debut de la liste chainee
  //nouveau : element le plus recent, fin de la liste chainee
};

#endif
