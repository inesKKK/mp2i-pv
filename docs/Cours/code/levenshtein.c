#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "min.h"

/** calcule la distance de Levenshtein entre les deux chaînes de caractères,
    bonne complexité */
int levenshtein(const char *a, const char *b){
  int lena = strlen(a), lenb = strlen(b);
  int **d = (int **)malloc((lena+1)*sizeof(int *));
  int res;

  for(int i=0; i<=lena; i=i+1){
    d[i] = (int *)malloc((lenb+1)*sizeof(int));
  }
  

  for(int j=0; j<=lenb; j=j+1){   // initialisation de la première ligne
    d[0][j] = j;
  }
  for(int i=0; i<=lena; i=i+1){   // initialisation de la première colonne
    d[i][0] = i;
  }

  for(int i=1; i<=lena; i++){
    for(int j=1; j<=lenb; j++){
      int k = 0;
      if (a[i-1] != b[j-1]){
        k = 1;
      }
      d[i][j] = min3( d[i][j-1] + 1,
                     d[i-1][j] + 1,
                     d[i-1][j-1] + k);
    }
  }
  
  res = d[lena][lenb];
  for(int i=0; i<=lena; i=i+1){
    free(d[i]);
  }
  free(d);

  return res;
}

int main(int argc, char **argv){
  printf("%d\n", levenshtein(argv[1], argv[2]));
}
