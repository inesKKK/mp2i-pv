/* exemple en C */
#include <stdbool.h>
#include <stdio.h>

/**
 * entree : un tableau d'entiers et sa taille
 * sortie : le tableau est trie en place
 */
void tri_bulle(int *tab, int n){
  bool permutation = true;
  while(permutation){ // si le dernier passage a fait au moins une modification
    permutation = false;
    for(int i=0; i<n-1; i++){
      if(tab[i] > tab[i+1]){ // si ce n'est pas dans le bon ordre, on inverse
        int tmp = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = tmp;
        permutation = true;
      }
    }
    n = n - 1;
  }
}


int main(){
  int tab[] = {5,2,17,3,-8,6};
  int n = 6;
  
  tri_bulle(tab, n);
  for(int i=0; i<n; i++)
    printf("%d ", tab[i]);
  printf("\n");
}
