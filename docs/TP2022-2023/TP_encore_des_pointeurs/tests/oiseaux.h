#ifndef _OISEAUX_H
#define _OISEAUX_H

struct oiseau {
    double x, y; // entre 0 et 1 pour être visible
    int ami;     // indice de l'ami dans la nuee (voir ci-dessous)
    int ennemi;  // indice de l'ennemi dans la nuee
};

struct nuee {
    int taille; // nombre d'oiseaux
    struct oiseau *cui;
};

void ecrire_image(int n, bool **img, int largeur, int hauteur);

#endif
