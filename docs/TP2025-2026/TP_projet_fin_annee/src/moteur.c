#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void svg_plateau(char *fic, int min, int max){
  FILE *f = fopen("plateau", "w");
  fprintf(f, "%d\n%d", min, max);
  fclose(f);
}


int main(void){
  int g = 0, d = 100;

  srand(time(NULL));
  int a_trouver = rand() % 101, proposition;

  svg_plateau("plateau", g, d);

  while(true){
    scanf("%d", &proposition);
    fprintf(stderr, "valeur lue : %d\n", proposition);
    if(proposition < g || proposition > d){
      printf("hors bornes, perdu...\n");
      return 1;
    }
    if(proposition == a_trouver){
      printf("%d... gagné!\n", a_trouver);
      return 1;
    }
    if(proposition < a_trouver){
      g = proposition+1;
      printf("%d trop petit\n", proposition);
    } else {
      d = proposition-1;
      printf("%d trop grand\n", proposition);
    }
    svg_plateau("plateau", g, d);
  }
  
  return 0;
}
