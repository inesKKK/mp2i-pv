#ifndef _TABLEAUX_ARBRES_H
#define _TABLEAUX_ARBRES_H

#define NODE_SIZE 10
#define NO_VALUE 666

struct arbre {
  int hauteur;           // si -1 c'est une valeur
  int val;                   // si c'est une valeur
  int fils_courant;     // le prochain fils à utiliser
  struct arbre **fils; // NODE_SIZE cases, chacune référence un fils
};

typedef struct arbre arbre;

struct dynarray {
  int len;                 // nombre d'éléments du tableau
  int echelle;          // plus grande puissance de NODE_SIZE telle que echelle < len
  struct arbre *racine;
};

typedef struct dynarray dynarray;

/** cree un tableau vide de capacite NODE_SIZE */
dynarray init();

/** tableau existant
 * indice < longueur du tableau 
 * renvoie le contenu de la case indice */
int get(struct dynarray tab, int indice);

/** tab non NULL 
 * ajoute une nouvelle case à la fin de tab, avec la valeur val */
void add(struct dynarray *tab, int val);

#endif
