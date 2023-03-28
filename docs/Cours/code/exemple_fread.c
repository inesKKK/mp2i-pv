#include <stdio.h>

struct point {
  //  char nom;
  double x, y;
};

int main(void){
  char c;
  char s[7];
  int n;
  struct point P;

  FILE *f = fopen("fichier_char", "r");
  fread(&c, sizeof(char), 1, f);
  fclose(f);
  printf("caractere lu : %c\n", c);

  f = fopen("fichier_chaine", "r");
  fread(&s, sizeof(char), 6, f);
  s[6] = '\0';
  fclose(f);
  printf("chaine lue : %s\n", s);

  f = fopen("fichier_int", "r");
  fread(&n, sizeof(int), 1, f);
  fclose(f);
  printf("entier lu : %d\n", n);

  f = fopen("fichier_point", "r");
  fread(&P, sizeof(struct point), 1, f);
  fclose(f);
  printf("point lu : (%f, %f)\n", P.x, P.y);
  //printf("point lu : %c (%f, %f)\n", P.nom, P.x, P.y);

  
  return 0;
}
