#include <stdio.h>
#include <stdbool.h>
#include "fichier.h"

void ecrire_image(int n, bool **img, int largeur, int hauteur){
    char fichier[20];
    FILE *file;
    char couleur[2][7] = {"1 1 1 ", "0 0 0 "};
    
    sprintf(fichier, "serpent-%03d.ppm", n);
    file = fopen(fichier, "w");
    fprintf(file, "P3\n%d %d\n1\n", largeur, hauteur);
    for(int j=0; j<hauteur; j=j+1){
        for(int i=0; i<largeur; i=i+1){
            fprintf(file, "%s", couleur[img[j][i]]);
        }
    }
    fclose(file);
}
