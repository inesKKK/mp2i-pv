#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
//  char nom;
  double x, y;
};

int main(void){
  char c = 'z';
  char *s = "coucou";
  int n = 666;
  struct point P = {.x = 5.7, .y = -3.2};
  //struct point P = {.nom = 'A', .x = 5.7, .y = -3.2};
  
  FILE *f = fopen("fichier_char", "w");
  fwrite(&c, sizeof(char), 1, f);
  fclose(f);

  f = fopen("fichier_chaine", "w");
  fwrite(s, sizeof(char), strlen(s), f);
  fclose(f);

  f = fopen("fichier_int", "w");
  fwrite(&n, sizeof(int), 1, f);
  fclose(f);

  f = fopen("fichier_point", "w");
  fwrite(&P, sizeof(struct point), 1, f);
  fclose(f);
  
  
  return 0;
}
