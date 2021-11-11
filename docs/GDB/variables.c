#include <string.h>
#include <stdlib.h>

int *int_tab(int n){
  int *res = (int *)malloc(n*sizeof(int));
  int i;

  for(i=0; i<n; i++)
    res[i] = 2*i;
  return res;
}

int main(void){
  int i, len;
  int *t = int_tab(6);
  char *p = "qwerty";

  len = strlen(p);
  for(i=0; i<len; i++){
    p++;
    t++;
  }
}
