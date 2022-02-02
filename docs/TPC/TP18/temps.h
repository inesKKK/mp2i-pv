#ifndef _TEMPS_H
#define _TEMPS_H

#include <time.h>

/** commence à mesurer le temps d'exécution */
void debut_mesure_temps();
/** arrête de mesurer le temps d'exécution */
void fin_mesure_temps();
/** affiche en seconde le dernier temps d'exécution mesuré */
void affiche_mesure_temps();
/** affiche le log dernier temps d'exécution mesuré */
void affiche_mesure_log_temps();

#endif
