#ifndef _COMPAGNON_H
#define _COMPAGNON_H

#include <stdbool.h>
#include "auxiliaire.h"

/* CODE A ECRIRE (dans compagnon.c) */

/* Partie 1 : Fonctions auxiliaires */
void affiche_miroir(char *mot); // Q1
void affiche_liste(liste lst); // Q2
void ajout_lettre(char c, liste lst); // Q3


/* Partie 2 : Recherche de mots */
liste sous_mots_possibles(lexique *lex, char *mot, bool obligatoire); // Q6

#endif
