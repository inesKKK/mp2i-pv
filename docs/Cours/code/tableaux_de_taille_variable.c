#include <stdlib.h>
#include "tableaux_de_taille_variable.h"

struct vartab *new_vartab(int *tab, int n){
  struct vartab *vt = (struct vartab *)malloc(sizeof(struct vartab));
  
  vt->size = 2*n;
  vt->len = n;
  vt->val = (int *)malloc(vt->size*sizeof(int));
  for(int i=0; i<vt->len; i++){
    vt->val[i] = tab[i];
  }

  return vt;
}

int get(struct vartab *t, int i){
  return t->val[i];
}

void set(struct vartab *t, int i, int val){
  t->val[i] = val;
}

int len(struct vartab *t){
  return t->len;
}

struct vartab *append(struct vartab *t, int val){
  int *newval;
  
  if(t->len<t->size){
    t->val[t->len] = val;
    t->len = t->len+1;
    return t;
  }
  //pour ce qui suit, il existe realloc aussi (hors programme)
  t->size = 2*t->size;
  newval = (int *)malloc(t->size*sizeof(int));
  for(int i=0; i<t->len; i=i+1){
    newval[i] = t->val[i];
  }
  newval[t->len] = val;
  t->len = t->len+1;
  free(t->val);
  t->val = newval;

  return t;
}


void delete_vartab(struct vartab *t){
  if (t){
    free(t->val);
  }
}

int pop(struct vartab *t){
  int res = t->val[t->len-1];
  int *newval;

  t->len = t->len - 1;

  if (t->len > t->size/2){
    return res;
  }
  //pour ce qui suit, il existe realloc aussi (hors programme)
  t->size = t->size/2;
  newval = (int *)malloc(t->size*sizeof(int));
  for(int i=0; i<t->len; i=i+1){
    newval[i] = t->val[i];
  }
  free(t->val);
  t->val = newval;

  return res;
}
