#include <assert.h>
#include <stdlib.h>
#include "liste_chainee2.h"

void detruire_rec(struct maillon *M){
  struct maillon *M2;
  if(M==NULL){
    return;
  }
  M2 = M->suiv;
  free(M);
  detruire_rec(M2);
}

/** L : adresse non nulle d'une liste;
 * sortie : libère la mémoire associée à la liste
 * complexité linéaire
 */
void detruire_recursif(struct liste *L){
  assert(L!=NULL);
  detruire_rec(L->tete);
}


/** L : adresse non nulle d'une liste;
 * sortie : libère la mémoire associée à la liste
 * complexité linéaire
 */
void detruire_iteratif(struct liste *L){
  struct maillon *M, *M2;
  assert(L!=NULL);
  M = L->tete;
  while(M!=NULL){
    M2 = M->suiv;
    free(M);
    M = M2;
  }
}

/** L : adresse non nulle d'une liste;
 * constructeur -- initialise la liste
 */
void initialise(struct liste *L){
  assert(L != NULL);
  L->tete = NULL;
}


/** L : adresse non nulle d'une liste;
 * v : valeur à ajouter à la liste;
 * transformateur -- ajoute la valeur en début de liste;
 * complexité constante
 */
void ajoute(struct liste *L, int v){
  struct maillon *M;

  assert(L != NULL);
  
  M = (struct maillon *)malloc(sizeof(struct maillon));
  M->val = v;
  M->suiv = L->tete;
  L->tete = M;
}


int lg_recursif(struct maillon *M){
  if(M == NULL){
    return 0;
  }
  return 1 + lg_recursif(M->suiv);
}


/** L : adresse non nulle d'une liste;
 * accesseur -- renvoie la longueur de la liste;
 * fonction récursive, complexité linéaire
 */
int longueur_recursif(struct liste *L){
  assert(L != NULL);
  return lg_recursif(L->tete);
}


/** L : adresse non nulle d'une liste;
 * accesseur -- renvoie la longueur de la liste;
 * fonction itérative, complexité linéaire
 */
int longueur_iteratif(struct liste *L){
  int n;
  struct maillon *M;
  
  assert(L != NULL);

  if(L->tete == NULL){
    return 0;
  }
  M = L->tete;
  n = 0;
  while(M != NULL){
    n = n+1;
    M = M->suiv;
  }
  return n;
}


/** L : adresse non nulle d'une liste non vide;
 * transformateur -- supprime le premier maillon de la liste;
 * complexité constante
 */
void supprime_tete(struct liste *L){
  struct maillon *M;
  
  assert(L != NULL && L->tete != NULL);
  
  M = L->tete;
  L->tete = M->suiv;
  free(M);
}


struct maillon *supprime_occ_1_recursif(struct maillon *M, int val){
  if(M == NULL){
    return NULL;
  }
  if(M->val == val){
    struct maillon *res = M->suiv;
    free(M);
    return res;
  }

  M->suiv = supprime_occ_1_recursif(M->suiv, val);
  return M;
}


/** L : adresse non nulle d'une liste non vide;
 * v : valeur à supprimer;
 * modificateur -- supprime la première occurence de v dans la liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
void supprime_premiere_occurence_recursif(struct liste *L, int val){
  assert(L != NULL && L->tete != NULL);

  L->tete = supprime_occ_1_recursif(L->tete, val);
}


/** L : adresse non nulle d'une liste non vide;
 * v : valeur à supprimer;
 * transformateur -- supprime la première occurence de v dans la liste;
 * fonction itérative, complexité linéaire en la taille de la liste
 */
void supprime_premiere_occurence_iteratif(struct liste *L, int val){
  struct maillon *p;

  assert(L!=NULL && L->tete!=NULL);
  
  if(L->tete->val == val){
    supprime_tete(L);
    return;
  }

  p = L->tete;
  for(struct maillon *q=L->tete->suiv; q!=NULL; p=p->suiv, q=q->suiv){
    if(q->val == val){
      p->suiv = q->suiv;
      free(q);
      break;
    }
  }
}



struct maillon *supprime_occ_n_recursif(struct maillon *M, int val){
  if(M == NULL){
    return NULL;
  }

  if(M->val == val){
    struct maillon *res = M->suiv;
    free(M);
    return supprime_occ_n_recursif(res, val);
  }
  
  M->suiv = supprime_occ_n_recursif(M->suiv, val);
  return M;
}

/** L : adresse non nulle d'une liste non vide;
 * v : valeur à supprimer;
 * transformateur -- supprime toutes les occurences de v dans la liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
void supprime_toutes_occurences_recursif(struct liste *L, int val){
  assert(L != NULL && L->tete != NULL);

  L->tete = supprime_occ_n_recursif(L->tete, val);
}


struct maillon *suppr_recursif(struct maillon *M){
  if(M->suiv == NULL){
    free(M);
    return NULL;
  }
  M->suiv = suppr_recursif(M->suiv);
  return M;
}

/** L : adresse non nulle d'une liste non vide;
 * transformateur -- supprime le dernier élément de la liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
void supprime_dernier_recursif(struct liste *L){
  assert(L != NULL && L->tete != NULL);
  L->tete = suppr_recursif(L->tete);
}


/** L : adresse non nulle d'une liste non vide;
 * transformateur -- supprime le dernier élément de la liste;
 * fonction itérative, complexité linéaire en la taille de la liste
 */
void supprime_dernier_iteratif(struct liste *L){
  struct maillon *M;
  assert(L != NULL && L->tete != NULL);

  if(L->tete->suiv == NULL){
    L->tete = NULL;
    return;
  }

  M = L->tete;
  while(M->suiv->suiv != NULL){
    M = M->suiv;
  }
  M->suiv = NULL;
}


int main(){
  struct liste L;
  initialise(&L);
  ajoute(&L, 1);
  ajoute(&L, 2);
  ajoute(&L, 3);
  ajoute(&L, 1);
  ajoute(&L, 2);
  ajoute(&L, 3);
  supprime_premiere_occurence_recursif(&L, 3);
  supprime_premiere_occurence_iteratif(&L, 1);
  supprime_toutes_occurences_recursif(&L, 2);
}
