#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tableaux_arbres.h"

tableau init(){
  struct tableau tab = {.len = 0, .echelle = 1, .racine = NULL };
  return tab;
}

int get(struct tableau tab, int indice){
  int ech = tab.echelle;
  arbre *a = tab.racine;

  while(ech > 0){ // on descend jusqu'à la bonne feuille
    a = a->fils[indice / ech];
    indice = indice % ech;
    ech = ech / NODE_SIZE;
  }

  return a->val;
}

/** hauteur >= 0 
 * old est le fils le plus à gauche de l'arbre à créer,
 * si old est NULL, alors on créée la branche la plus à gauche, sans valeurs
 */
arbre *nouvel_arbre(int hauteur, arbre *old){
  arbre *a = (arbre *)malloc(sizeof(arbre));
  a->hauteur = hauteur;
  a->fils_courant = 0;
  a->val = NO_VALUE;
  if(hauteur == -1){ // case représentant une valeur
    a->fils = NULL;
  } else {
    a->fils = (arbre **)malloc(NODE_SIZE*sizeof(arbre *));
    if(hauteur == 0){ // feuille de l'arbre -> on prépare les cases valeur
      for(int i=0; i<NODE_SIZE; i=i+1){
        a->fils[i] = nouvel_arbre(hauteur - 1, NULL);
      }
    } else { // noeud interne -> on crée la branche la plus à gauche
      if(old != NULL){
        a->fils[0] = old;
      } else {
        a->fils[0] = nouvel_arbre(hauteur - 1, NULL);
      }
      for(int i=1; i<NODE_SIZE; i=i+1){ // les autres branches sont vides
        a->fils[i] = NULL;    
      }
    }
  }
  return a;
}


/** ajoute la valeur à la fin logique de l'arbre
 * renvoie true si ajout fait, false si l'arbre est plein
 */
bool add_tree(arbre *a, int val){
  if(a->hauteur == 0){
    if(a->fils_courant < NODE_SIZE){ // encore de la place dans le tableau courant
      a->fils[a->fils_courant]->val = val;
      a->fils_courant = a->fils_courant + 1;
      return true;
    } else { // plus de place dans le tableau courant
      return false;
    }
  } else {
    if(add_tree(a->fils[a->fils_courant], val)){ // il reste de la place dans le sous-arbre du fils courant
      return true;
    } else if(a->fils_courant < NODE_SIZE - 1) { // sinon, si encore un fils disponible
      a->fils_courant = a->fils_courant + 1;
      a->fils[a->fils_courant] = nouvel_arbre(a->hauteur - 1, NULL);
      add_tree(a->fils[a->fils_courant], val);
      return true;
    } else { // sinon, plus de place dans l'arbre
      return false;
    }
  }
}


void add(struct tableau *tab, int val){
  if(tab->racine == NULL){ // tableau vide
    tab->racine = nouvel_arbre(0, NULL);
  }
  if(!add_tree(tab->racine, val)){ //  ajout impossible : il faut augmenter la hauteur
    arbre *oldroot = tab->racine;
    tab->racine = nouvel_arbre(oldroot->hauteur + 1, oldroot);
    tab->echelle = NODE_SIZE * tab->echelle;
    add_tree(tab->racine, val);
  }
  tab->len = tab->len + 1;
}


int len(tableau tab){
  return tab.len;
}

int main(){
  tableau tab = init();
  for(int i = 0; i< 1255; i++){
    add(&tab, i+17);
  }

  for(int i=0; i<1255; i++){
    printf("tab[%d] = %d\n", i, get(tab, i));
  }
}
