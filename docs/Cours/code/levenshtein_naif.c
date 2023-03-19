#include <string.h>
#include <stdio.h>
#include "min.h"


/** calcule la distance de Levenshtein entre les deux chaînes de caractères,
    très mauvaise complexité */
int levenshtein(const char *a, const char *b){
  int lena = strlen(a), lenb = strlen(b);
  if(min(lena, lenb) == 0){
    return max(lena, lenb);
  }
  if (a[0] == b[0]){
    return levenshtein(&a[1], &b[1]);
  }
  return 1 + min3( levenshtein(&a[1], b),
                   levenshtein(a, &b[1]),
                   levenshtein(&a[1], &b[1]) );
}


int main(int argc, char **argv){
  printf("%d\n", levenshtein(argv[1], argv[2]));
}

