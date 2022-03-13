#include <stdio.h>
#include <unistd.h>

int main(void){
  FILE *f = fopen("toto", "w");

  fprintf(f, "ceci ne sera pas ecrit dans le fichier");

  _exit(0);  // permet de sortir sans vider les flux, on pourrait mettre 1 / 0 à la place
}
