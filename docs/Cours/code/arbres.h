#ifndef _ARBRES_H_
#define _ARBRES_H_

struct noeud {
  int v;
  struct noeud *g, *d;
};

typedef struct noeud *arbre;

/** sauvegarde le contenu de l'arbre dans le fichier,
 * si l'arbre est vide, le fichier le sera aussi
 */
void sauvegarde(arbre a, char *f);


arbre chargement(char *f);

#endif
