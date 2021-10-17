#include <stdlib.h>
#include <assert.h>
#include "liste_chainee1.h"

/** L : liste;
 * v : valeur à ajouter à la liste;
 * transformateur -- ajoute la valeur en début de liste
 * et renvoie le nouveau début de liste
 */
struct maillon *ajoute(struct maillon *L, int v){
  struct maillon *L2 = (struct maillon *)malloc(sizeof(struct maillon));
  L2->val = v;
  L2->suiv = L;
  return L2;
}


/** L : liste non vide;
 * transformateur -- supprime le premier maillon de la liste
 * et renvoie la nouvelle tête de liste;
 * complexité constante
 */
struct maillon *supprime_tete(struct maillon *L){
  struct maillon *L2;
  if(L==NULL){
    return NULL;
  }
  L2 = L->suiv;
  free(L);
  return L2;
}


/** L : liste;
 * accesseur -- renvoie la longueur de la liste;
 * fonction récursive, complexité linéaire
 */
int longueur_recursif(struct maillon *L){
  if(L == NULL){
    return 0;
  }
  return 1 + longueur_recursif(L->suiv);
}


/** L : liste;
 * accesseur -- renvoie la longueur de la liste;
 * fonction itérative, complexité linéaire
 */
int longueur_iteratif(struct maillon *L){
  int n;
  struct maillon *M;
  
  if(L == NULL){
    return 0;
  }
  M = L;
  n = 0;
  while(M != NULL){
    n = n+1;
    M = M->suiv;
  }
  return n;
}


/** L : liste;
 * v : valeur à supprimer;
 * modificateur -- supprime la première occurence de v dans la liste
 * et renvoie la tête de la nouvelle liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
struct maillon *supprime_premiere_occurence_recursif(struct maillon *L, int val){
  struct maillon *M;

  if(L == NULL){
    return NULL;
  }
  if(L->val == val){
    M = L->suiv;
    free(L);
    return M;
  }
  L->suiv = supprime_premiere_occurence_recursif(L->suiv, val);
  return L;
}


/** L : liste;
 * v : valeur à supprimer;
 * transformateur -- supprime la première occurence de v dans la liste
 * et renvoie la tête de la nouvelle liste;
 * fonction itérative, complexité linéaire en la taille de la liste
 */
struct maillon *supprime_premiere_occurence_iteratif(struct maillon *L, int val){
  struct maillon *p;

  if(L == NULL){
    return NULL;
  }
  if(L->val == val){
    return supprime_tete(L);
  }

  p = L;
  for(struct maillon *q=L->suiv; q!=NULL; p=p->suiv, q=q->suiv){
    if(q->val == val){
      p->suiv = q->suiv;
      free(q);
      break;
    }
  }
  return L;
}


/** L : liste;
 * v : valeur à supprimer;
 * transformateur -- supprime toutes les occurences de v dans la liste
 * et renvoie la nouvelle tête de liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
struct maillon *supprime_toutes_occurences_recursif(struct maillon *L, int val){
  struct maillon *M;

  if(L == NULL){
    return NULL;
  }
  if(L->val == val){
    M = L->suiv;
    free(L);
    return supprime_toutes_occurences_recursif(M, val);
  }
  L->suiv = supprime_toutes_occurences_recursif(L->suiv, val);
  return L;
}


/** L : liste non vide;
 * transformateur -- supprime le dernier élément de la liste et renvoie la nouvelle
 * tête de liste;
 * fonction récursive, complexité linéaire en la taille de la liste
 */
struct maillon *supprime_dernier_recursif(struct maillon *L){
  assert(L != NULL);
  if(L->suiv == NULL){
    free(L);
    return NULL;
  }
  L->suiv = supprime_dernier_recursif(L->suiv);
  return L;
}

/** L : liste non vide;
 * transformateur -- supprime le dernier élément de la liste et renvoie la nouvelle
 * tête de liste;
 * fonction itérative, complexité linéaire en la taille de la liste
 */
struct maillon *supprime_dernier_iteratif(struct maillon *L){
  struct maillon *M;
  assert(L != NULL);

  if(L->suiv == NULL){
    free(L);
    return NULL;
  }

  M = L->suiv;
  while(M->suiv->suiv != NULL){
    M = M->suiv;
  }
  free(M->suiv);
  M->suiv = NULL;

  return L;
}



int main(){
  struct maillon *L = ajoute(NULL, 1);
  L = ajoute(L, 2);
  L = ajoute(L, 3);
  L = supprime_tete(L);
  L = supprime_tete(L);
  L = supprime_tete(L);
}
