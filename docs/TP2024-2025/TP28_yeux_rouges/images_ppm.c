#include <stdio.h>
#include <stdlib.h>
#include "images_ppm.h"

void charger_image(char *fic){
  FILE *fichier;
  int largeur, hauteur;

  fichier = fopen(fic, "r");
  fscanf(fichier, " %*s"); // pour sauter la premiere ligne
  fscanf(fichier, " %d", &largeur);
  fscanf(fichier, " %d", &hauteur);

  if(largeur != larg || hauteur != haut){
    fprintf(stderr, "pas la bonne dimension d'image\n");
    exit(1);
  }
  
  fscanf(fichier, "%d", max);
  for(int i=0; i<hauteur; i=i+1){
    for(int j=0; j<largeur; j=j+1){
      fscanf(fichier, "%d", &img[i][j]);
    }
  }

  fclose(fichier);
}


void ecrire_image_pgm(char *fic, int img[haut][larg], int max){
  FILE *fichier;

  fichier = fopen(fic, "w");
  fprintf(fichier, "P2\n%d %d\n%d\n", larg, haut, max);
  for(int i=0; i < haut; i=i+1){
    for(int j=0; j < larg; j=j+1){
      fprintf(fichier, "%d ", img[i][j]);
    }
    fprintf(fichier, "\n");
  }

  fclose(fichier);
}

