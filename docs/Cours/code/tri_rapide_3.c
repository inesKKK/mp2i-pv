#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** entree : un tableau d'entiers et deux indices
 * sortie : on a inverse les valeurs des deux cases 
 */
void echanger(int *t, int i, int j){
  int tmp;

  tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

/** entree : un tableau d'entiers, et deux indices tq debut < fin < longueur du tableau
 * sortie : tableau trie en place entre debut et fin */
void tri_rapide_3(int *t, int debut, int fin){
  int pivot, inf, sup, egal;
  
  if(debut >= fin) return;

  pivot = t[debut];
  inf = debut;
  sup = fin;
  egal = debut;

  while(egal <= sup){
    if(pivot > t[egal]){
      echanger(t, inf, egal);
      inf = inf + 1;
      egal = egal + 1;
    } else if (pivot < t[egal]){
      echanger(t, egal, sup);
      sup = sup - 1;
    } else {
      egal = egal + 1;
    }
    
    tri_rapide_3(t, debut, inf - 1);
    tri_rapide_3(t, sup + 1, fin);
  }
}


int main(int argc, char **argv){
  int *t = (int *)malloc((argc-1)*sizeof(int));
  
  for(int i=1; i<argc; i = i+1){
    t[i-1] = atoi(argv[i]);
  }
  
  tri_rapide_3(t, 0, argc-2);
  
  for(int i=0; i<argc-1; i++){
    printf("%d\n", t[i]);
  }
}
