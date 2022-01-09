#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int partitionner(int *t, int debut, int fin);

/** entree : un tableau d'entiers, et deux indices tq debut < fin < longueur du tableau
 * sortie : tableau trie en place entre debut et fin */
void tri_rapide(int *t, int debut, int fin){
  int pivot;
  
  if(debut >= fin) return;
  pivot = partitionner(t, debut, fin);
  // l'élément en case pivot est maintenant à sa place définitive
  tri_rapide(t, debut, pivot-1);
  tri_rapide(t, pivot + 1, fin);
}


/** entree : un tableau d'entiers et deux indices
 * sortie : on a inverse les valeurs des deux cases 
 */
void echanger(int *t, int i, int j){
  int tmp;

  tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

/** entree : un tableau d'entiers et deux indices tq debut < fin < longueur du tableau
 * sortie : un indice tel que toutes les donnees entre debut et cet indice dans le tableau
 * sont plus petites que la valeur a cet indice et toutes les donnees entre cet indice 
 * et fin sont plus grandes que la valeur a cet indice */
int partitionner(int *t, int debut, int fin){
  int pivot = t[debut]; //à modifier pour que ce soit efficace
  int inf = debut + 1, sup = fin;

  while (true) {
    while (t[sup] >= pivot && sup > debut) {
      sup = sup - 1;
    }
    while (t[inf] < pivot && inf < fin) {
      inf = inf + 1;
    }
    if (inf >= sup){ // tous les éléments sont du bon côté
      break;
    }
    echanger(t, inf, sup); // inf et sup sont du mauvais côté : on les inverse
  }

  echanger(t, debut, sup);
  
  return sup;
}


int main(int argc, char **argv){
  int *t = (int *)malloc((argc-1)*sizeof(int));

  for(int i=1; i<argc; i = i+1){
    t[i-1] = atoi(argv[i]);
  }
  
  tri_rapide(t, 0, argc-2);
  
  for(int i=0; i<argc-1; i++){
    printf("%d\n", t[i]);
  }
}
