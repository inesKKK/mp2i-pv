#include <stdio.h>
#include <unistd.h>

int proposition(){
  FILE *f = fopen("plateau", "r");

  int min, max;
  fscanf(f, "%d\n%d", &min, &max);
  fclose(f);
  return (min + max) / 2;
}

int main(void){
  printf("%d\n", proposition()); // retour à la ligne pour vider le buffer
  return 0;
}
