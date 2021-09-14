#include <stdio.h>
/* exemple en C */
#include <stdbool.h>

bool note_sous_la_moyenne(int *notes, int n){
  return n>0 && ( notes[n-1]<10 || note_sous_la_moyenne(notes, n-1) );
}

int main(){
  int notes[] = {12,13, 15, 20, 8, 19};
  printf("%d\n", note_sous_la_moyenne(notes, 5));
}
