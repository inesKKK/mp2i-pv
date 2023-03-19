#include <stdio.h>
#include <stdbool.h>

#define NB_REINES 8


/** teste si on peut placer la reine sur la ligne et la colonne transmises, 
 * sans qu'elle ne menace une reine sur une ligne précédente */
bool est_compatible(int *places, int ligne, int colonne){
  for(int i=0; i<ligne; i=i+1){
    if ( places[i] == colonne
         || places[i] == colonne+ligne-i
         || places[i] == colonne-ligne+i ){
      return false;
    }
  }
  
  return true;
}


/** affiche un échiquier */
void affiche_solution(int *places){
  for(int i=0; i<NB_REINES; i=i+1){
    for(int j=0; j<NB_REINES; j=j+1){
      if(j == places[i]){
        printf("R");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf("\n");  
}


/** affiche toutes les solutions au problème des reines avec places 
 * comme début de remplissage,
 * où places[i] donne la colonne où placer la reine qui est sur la ligne i */
void reines(int *places, int ligne){
  if(ligne == NB_REINES){// on a placé toutes les reines
    affiche_solution(places);
    return;
  }
  for(int colonne=0; colonne<NB_REINES; colonne=colonne+1){
    if(est_compatible(places, ligne, colonne)){
      places[ligne] = colonne;
      reines(places, ligne+1);
    }
  }
  
}

int main(void){
  int places[NB_REINES];
  for(int i=0; i<NB_REINES; i++){
	  places[i] = -1;
  }
  reines(places, 0);
  return 0;
}








