/* exemple en C */
#include <stdbool.h>
#include <stdio.h>

/**
 * entree : tableau d'entiers trie dans l'ordre croissant,
 *               indice de debut positif ou nul,
 *               indice de fin strictement inferieur a la longueur du tableau
 *               et entier a trouver
 * sortie : true si la valeur apparait dans le tableau, false sinon
 */
bool recherche(int *tab, int debut, int fin, int n){
  if (debut>fin) return false;

  int i = (debut+fin)/2;
  if (n==tab[i]) return true;
  else if (n<tab[i]) return recherche(tab, debut, i-1, n);
  else return recherche(tab, i+1, fin, n);
}

int main(){
  int tab[] = {-5,0,3,6,17,21};
  int lg = 6;
  int n = 5;
  
  printf("%d\n", recherche(tab, 0, lg-1, n));
}
