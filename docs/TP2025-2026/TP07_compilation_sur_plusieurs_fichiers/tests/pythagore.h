#ifndef _PYTHAGORE_H_
#define _PYTHAGORE_H_

struct point {
  double x, y;
};

struct vecteur {
  double x, y;
};

struct carre {
  struct point s[4];
};

/** on renvoie le milieu du segment [p, q] */
struct point milieu(struct point p, struct point q);
/** p est un point, u un vecteur, on renvoie l'image du point p par la translation de vecteur u */
struct point translate(struct point p, struct vecteur u);
/** vecteur alpha pq */
struct vecteur vecteur(struct point p, struct point q, double alpha);

/** carre est un carre, img1 et img2 ses deux images */
void suivants(struct carre A, struct carre *B, struct carre *C);

/** renvoie le carré initial dont les côté sont parallèles aux axes et qui possède comme diagonal (0,0)--(100,100) */
struct carre carre_initial();
/** gen est une génération de carrés de taille n, la fonction renvoie la génération suivante (de taille 2*n) */
struct carre *generation_suivante(struct carre *gen, int n);

/** renvoie un tableau bidimensionnel de booléens dont la dimension extérieure est larg et la dimension intérieure est haut, et qui représente une image blanche */
bool **fenetre(int larg, int haut);
/** dessine le carre dans la fenetre */
void dessin(bool **fenetre, int larg, int haut, struct carre c);
#endif
