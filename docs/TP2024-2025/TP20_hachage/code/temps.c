#include <time.h>
#include <stdio.h>
#include <math.h>
#include "temps.h"

clock_t debut, fin;

void debut_mesure_temps(){
  debut = clock();
}

void fin_mesure_temps(){
  fin = clock();
}

void affiche_mesure_temps(){
  printf("%f", (fin - debut + .0)/CLOCKS_PER_SEC);
}
void affiche_mesure_log_temps(){
  printf("%f", log((fin - debut + .0)/CLOCKS_PER_SEC));
}
