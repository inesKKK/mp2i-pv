#include <stdio.h>
#include "histogramme.h"

void affiche_histogramme(struct histogramme *h){
  printf("set style data histogram\nplot '-'\n");
  for(int i=0; i<h->n; i=i+1){
    printf("%d\n", h->valeurs[i]);
  }
}

int main(){
  int val[] = {5, 15, 30, 26, 20, 25, 2};
  struct histogramme h = { .n = 7, .valeurs =  val};
  affiche_histogramme(&h);
  return 0;
}
