#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "image.h"
#include "ppm.h"

/******************************/
/* Que des fonctions fournies */
/******************************/

void affiche(image *tableau){
  assert(tableau != NULL);
  printf("P3\n%d %d\n255\n", tableau->larg, tableau->haut);
  for(int j=0; j < tableau->haut; j=j+1){
      for(int i=0; i < tableau->larg; i=i+1){
        couleur c = tableau->c[j][i];
        printf("%d %d %d ", c.r, c.g, c.b);
    }
    printf("\n");
  }
}

image *lecture(const char *fichier){
  image *img;
  FILE *file;
  char *ligne = NULL;
  size_t n = (size_t) 0;
  int max;

  file = fopen(fichier, "r");
  if(file == NULL){
    return NULL;
  }

  getline(&ligne, &n, file);
  if(!strcmp(ligne, "P3") != 0){
    fclose(file);
    free(ligne);
    return NULL;
  }
  
  img = (image *)malloc(sizeof(image));
  fscanf(file, "%d %d\n", &img->larg, &img->haut);
  fscanf(file, "%d\n", &max);
  img->c = (couleur **)malloc(img->haut * sizeof(couleur *));
  for(int j=0; j<img->haut; j=j+1){
    img->c[j] = (couleur *)malloc(img->larg * sizeof(couleur));
    for(int i=0; i<img->larg; i=i+1){
      int r, g, b;
      fscanf(file, "%d", &r);
      fscanf(file, "%d", &g);
      fscanf(file, "%d", &b);      
      img->c[j][i].r = r*255 / max;
      img->c[j][i].g = g*255 / max;
      img->c[j][i].b = b*255 / max;
    }
  }

  fclose(file);
  return img;
}

