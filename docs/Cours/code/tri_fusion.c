#include <stdlib.h>
#include <stdio.h>

/**
 * entree : un tableau tab ou il faut fusionner les valeurs entre debut et milieu-1 
 * et les valeurs en milieu et fin-1, les valeurs sont supposees dans l'ordre croissant
 * dans ces deux parties
 * sortie : la fusion voulue est faite
 */
void fusion(int *tab, int debut, int milieu, int fin){
  int g = 0, d = 0, t = debut;
  int *gauche = (int *)malloc((milieu-debut)*sizeof(int));
  int *droite = (int *)malloc((fin-milieu)*sizeof(int));

  for(int i=0; i<milieu-debut; i=i+1){
    gauche[i] = tab[debut+i];
  }
  for(int i=0; i<fin-milieu; i=i+1){
    droite[i] = tab[milieu+i];
  }
  
  while(g<milieu-debut && d<fin-milieu){
    if(gauche[g]<droite[d]){
      tab[t] = gauche[g];
      g = g+1;
    } else {
      tab[t] = droite[d];
      d = d+1;
    }
    t = t+1;
  }
  while(g<milieu-debut){
      tab[t] = gauche[g];
      g = g+1;
      t = t+1;
  }
  while(d<fin-milieu){
      tab[t] = droite[d];
      d = d+1;
      t = t+1;
  }

  free(gauche);
  free(droite);
}

/**
 * entree : un tableau d'entiers, a trier entre les indices debut et fin-1 compris
 * sortie : le tableau est trie entre les indices debut et fin-1
 */
void tri_fusion(int *tab, int debut, int fin){
  if (debut==fin-1) return;
  int lg = (fin-debut)/2;
  tri_fusion(tab, debut, debut+lg);
  tri_fusion(tab, debut+lg, fin);
  fusion(tab, debut, debut+lg,fin);
}


int main(){
  int tab[] = {-5,17,4,20,-12,30,6};
  int n = 7;
  tri_fusion(tab, 0, n);
  for(int i=0; i<n; i++){
    printf("%d\n", tab[i]);
  }
}
