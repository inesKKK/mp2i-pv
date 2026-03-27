#ifndef _SUDOKU_H
#define _SUDOKU_H

#define COTE 9

typedef int sudoku[COTE][COTE];


void affiche_grille(char *fichier);
int nb_de_lignes(FILE *f);
void recopie(FILE *src, FILE *dest);

#endif
