#ifndef _POINT_H
#define _POINT_H

strut point {
  int x, y;
};

typedef struct point point;

/** tab: tableau d'entiers positifs
 * n: nombre de cases de tab
 * sortie: max de tab
 */
int max(int *tab, int n);

/** abs: abscisse de départ, entier positif
 * ord: tableau d'ordonnées toutes positives
 * n: nombre de points
 * sortie: tableau de points triés selon l'ordonnée décroissante
 */
point *liste_points(int abs, int *ord, int n);


/** abs: abscisse de départ, entier positif
 * ord: tableau d'ordonnées toutes positives
 * n: nombre de points
 * effet: affiche les points en ascii art, espace pour les pixels blancs, x pour les pixels noirs
 */
void affiche(int abs, int *ord, int n);

#endif
