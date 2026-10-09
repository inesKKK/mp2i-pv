#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * iso1 et iso2 sont deux tableaux de tableaux d'entiers représentant deux isométries
 * res doit être le produit des deux matrices à l'issue de la fonction 
 * les contenus de iso1 et iso2 ne doivent pas être modifiés
 */
void compose(int iso1[3][3], int iso2[3][3], int res[3][3]){
  // TODO
}


/**
 * iso représente une isométrie
 * point représente un point
 * res doit être le point image du point par l'isometrie iso
 * les contenus de iso et point ne doivent pas être modifiés
 */
void bouge_point(int iso[3][3], int point[3], int res[3]){
  // TODO
}

/**
 * iso représente une isométrie
 * polygone représente un polygone
 * res doit être le polygone image de polygone par l'isometrie iso
 * les contenus de iso et polygone ne doivent pas être modifiés
 */
void bouge_polygone(int iso[3][3], int polygone[20][3], int res[20][3]){
  // TODO
}



/** polygone représente le polygone de depart
 * isos est un tableau de 50 isometries
 * res contient en fin d'appel : une copie de polygone en case 0, l'image de polygone par
 * l'isometrie isos[i] dans la case i+1
 * les contenus de isos et polygone ne doivent pas être modifiés
 */
void dessin(int polygone[20][3], int isos[50][3][3], int res[51][20][3]){
  // TODO
}


/** mettre tous les pixels de fenetre a false */
void initialise_fenetre(bool fenetre[600][400]){
  // TODO
}


/** fenetre est la fenetre de dessin
 * p1 et p2 sont les deux extremites du segment a tracer
 * les contenus de p1 et p2 ne doivent pas être modifiés
 */
void trace_segment(bool fenetre[600][400], int p1[3], int p2[3]){
  // TODO
}


/** fenetre est la fenetre de dessin
 * polygone est le polygone a tracer
 * le contenu de polygone ne doit pas être modifié
 */
void trace_polygone(bool fenetre[600][400], int polygone[20][3]){
  // TODO
}


/** gen est le nombre d'isometries dont on dispose au depart, elles sont stockees dans
 * les premieres cases de isos
 * en sortie isos a ete complete avec les nouvelles isometries
 * (on ne demande pas de verifier que les elements de isos sont deux a deux distincts)
 */
void generation(int isos[50][3][3], int gen){
  // TODO
}

/** fenetre : une fenetre graphique
 * ficheir : un nom de fichier
 * sauvegarde le dessin dans le fichier au format pgm
 */
int sauvegarder_image(char *fichier, bool fenetre[600][400]){
  FILE *f;

  f = fopen(fichier, "w");

  if(f == NULL){
    fprintf(stderr, "problème de sauvegarde");
    return 2;
  }

  fprintf(f, "P2\n600 400\n100\n");
  for(int i=0; i<400; i=i+1){
    for(int j=0; j<600; j=j+1){
      if(fenetre[j][i]) {
        fprintf(f, "0 ");
      } else {
        fprintf(f, "100 ");
      }
    }
    fprintf(f, "\n");
  }
  
  fclose(f);
  return 0;
}


void polygone1(int polygone[20][3]){
  int p[20][2] = { {0, 0,}, {20, 0}, {20, 10}, {40, 0}, {40, 0},
                   {60, 0}, {60, 20}, {70, 20}, {60, 40}, {60, 40},
                   {60, 60}, {40, 60}, {20, 70}, {20, 60}, {20, 60},
                   {0, 60}, {0, 40}, {10, 20}, {0, 20}, {0, 20} };
  for(int i=0; i<20; i=i+1){
    for(int j=0; j<2; j=j+1){
      polygone[i][j] = p[i][j];
    }
    polygone[i][2] = 1;
  }
}

int isos1(int isos[50][3][3]){
  int is[][3][3] = { { {1, 0, 60}, {0, 1, 0}, {0, 0, 1} },
                     { {1, 0, 0}, {0, 1, 60}, {0, 0, 1} },
                     { {1, 0, -60}, {0, 1, 0}, {0, 0, 1} },
                     { {1, 0, 0}, {0, 1, -60}, {0, 0, 1} }};

  for(int k=0; k<4; k=k+1){
    for(int i=0; i<3; i=i+1){
      for(int j=0; j<3; j=j+1){
        isos[k][i][j] = is[k][i][j];
      }
    }
  }

  return 4;
}

/** permet d'obtenir le pavage p1 du plan
 * le polygone sera stocke dans polygone, les isometries dans isos
 * renvoie le nombre d'isometries
 */
int pavage1(int polygone[20][3], int isos[50][3][3]){
  polygone1(polygone);
  return isos1(isos);
}


void polygone2(int polygone[20][3]){
  int p[][2] = { {0, 0,}, {10, 0}, {20, 10}, {40, -10}, {50, 0},
                   {60, 0}, {60, 10}, {50, 20}, {70, 40}, {60, 50},
                   {60, 60}, {50, 60}, {40, 70}, {20, 50}, {10, 60},
                   {0, 60}, {0, 50}, {10, 40}, {-10, 20}, {0, 10} };
  for(int i=0; i<20; i=i+1){
    for(int j=0; j<2; j=j+1){
      polygone[i][j] = p[i][j];
    }
    polygone[i][2] = 1;
  }
}


int isos2(int isos[50][3][3]){
  int is[][3][3] = { { {-1, 0, 0}, {0, -1, 0}, {0, 0, 1} },
                     { {-1, 0, 120}, {0, -1, 0}, {0, 0, 1} },
                     { {-1, 0, 120}, {0, -1, 120}, {0, 0, 1} },
                     { {-1, 0, 0}, {0, -1, 120}, {0, 0, 1} },
                     { {-1, 0, 60}, {0, -1, 0}, {0, 0, 1} },
                     { {-1, 0, 60}, {0, -1, 120}, {0, 0, 1} }};
  for(int k=0; k<6; k=k+1){
    for(int i=0; i<3; i=i+1){
      for(int j=0; j<3; j=j+1){
        isos[k][i][j] = is[k][i][j];
      }
    }
  }

  return 6;
}

/** permet d'obtenir le pavage p2 du plan
 * le polygone sera stocke dans polygone, les isometries dans isos
 * renvoie le nombre d'isometries
 */
int pavage2(int polygone[20][3], int isos[50][3][3]){
  polygone2(polygone);
  return isos2(isos);
}


int main(int argc, char** argv){
  int p[20][3];
  int isos[50][3][3];
  int nb_isos;
  int polygones[51][20][3];
  bool fenetre[600][400];

  nb_isos = pavage2(p, isos);
  generation(isos, nb_isos);
  initialise_fenetre(fenetre);
  dessin(p, isos, polygones);
  for(int i=0; i<51; i=i+1){
    trace_polygone(fenetre, polygones[i]);
  }

  sauvegarder_image("resultat_pavage1.pgm", fenetre);


  nb_isos = pavage1(p, isos);
  generation(isos, nb_isos);
  initialise_fenetre(fenetre);
  dessin(p, isos, polygones);
  for(int i=0; i<51; i=i+1){
    trace_polygone(fenetre, polygones[i]);
  }

  sauvegarder_image("resultat_pavage2.pgm", fenetre);

}
