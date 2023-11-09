#ifndef _PYTHAGORE_H_
#define _PYTHAGORE_H_

/** p et q représentent des points, on renvoie le milieu du segment [p, q] */
double *milieu(double *p, double *q);
/** p est un point, u un vecteur, on renvoie l'image du point p par la translation de vecteur u */
double *translate(double *p, double *u);
/** vecteur alpha pq */
double *vecteur(double p[2], double q[2], double alpha);

/** carre est un carre, img1 et img2 ses deux images */
void suivants(double **carre, double **img1, double **img2);

/** renvoie le carré initial dont les côté sont parallèles aux axes et qui possède comme diagonal (0,0)--(100,100) */
double **carre_initial();
/** gen est une génération de carrés de taille n, la fonction renvoie la génération suivante (de taille 2*n) */
double ***generation_suivante(double ***gen, int n);

/** renvoie un tableau bidimensionnel de booléens dont la dimension extérieure est larg et la dimension intérieure est haut, et qui représente une image blanche */
bool **fenetre(int larg, int haut);
/** dessine le carre dans la fenetre */
void dessin(bool **fenetre, int larg, int haut, double **carre);
#endif
