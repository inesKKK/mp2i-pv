#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int N1, N2;
int64_t A, B;

void affiche(int64_t *t, int lg){
  int i;
  printf("[ ");
  for(i=0; i<lg-1; i++){
    printf("%ld, ", t[i]);
  }
  printf("%ld ]\n", t[i]);
}


void subsums(int64_t *nb, int lg, int64_t *sommes){
  sommes[0] = 0;
  /* chaque case représente un ensemble d'entiers donné par
  l'écriture binaire de son indice
  pour avoir la somme, on adopte une stratégie de programmation
  dynamique: c'est la somme de l'entier de plus grand indice avec la
  somme du reste du sous-ensemble */
  
  for(uint64_t k=1; k < lg; k++){
    int ind = 8*sizeof(int64_t)- __builtin_clzl(k)-1;
    //  __builtin_clzl(k) : nombre de 0 à gauche dans l'écriture
    // binaire de k
    sommes[k] = nb[ind] + sommes[k & ~(1UL<<ind)];
    // k & ~(1UL<<ind) : on a passé à 0 le bit de poids fort de k
    // nb[ind] : valeur de l'entier de plus grand indice
    // sommes[k & ~(1UL<<ind)] : somme du reste du sous-ensemble
  }
}

uint64_t indice_min(int64_t nb, int64_t *sommes, uint64_t lg, uint64_t min){
  while(min>=0){
    if(nb+sommes[min] < A){
      return min+1;
    }
    if (min==0){
      return 0;
    }
    min--;
  }
  return 0;
}

uint64_t indice_max(int64_t nb, int64_t *sommes, uint64_t lg, uint64_t max){
  while(max>=0){
    if(nb+sommes[max] <= B){
      return max;
    }
    if (max==0){
      return lg;
    }
    max--;
  }
  return 0;//jamais atteint
}

int superieur(const void *k1, const void *k2){
  return (*(int64_t*)k2) < (*(int64_t*)k1);
}

uint64_t fusion(int64_t *sommes1, int lg1, int64_t *sommes2, int lg2){
  uint64_t k, min = lg2-1, max = lg2-1;
  uint64_t res = 0;

  qsort(sommes1, lg1, sizeof(int64_t), superieur);
  qsort(sommes2, lg2, sizeof(int64_t), superieur);
  
  for(k=0; k < lg1; k++){
    min = (min>lg2-1) ? lg2-1 : min;
    min = indice_min(sommes1[k], sommes2, lg2, min);
    max = indice_max(sommes1[k], sommes2, lg2, max);
    if(max==lg2) return res;
    if (min <= max){
      res += max - min + 1;
    }
  }
  return res;
}


int main(){
  uint64_t res;
  int N, i;
  int64_t *nb1, *nb2;
  int64_t *sommes1, *sommes2;

  scanf("%d %ld %ld", &N, &A, &B);

  if(N==0){
    printf("%d\n", (A<=0 && B>=0)?1:0); //sous-ensemble vide
    return 1;
  }

  N1 = N/2;
  N2 = N-N1;
  nb1 = (int64_t*)malloc(N1*sizeof(int64_t));
  nb2 = (int64_t*)malloc(N2*sizeof(int64_t));

  for(i=0; i<N1; i++){
    scanf("%ld", &nb1[i]);
  }
  for(i=0; i<N2; i++){
    scanf("%ld", &nb2[i]);
  }

  // calloc : de la famille de malloc, toutes les cases sont initialisées à 0
  sommes1 = (int64_t *)calloc((1UL<<N1), sizeof(int64_t));
  sommes2 = (int64_t *)calloc((1UL<<N2), sizeof(int64_t));

  subsums(nb1, 1UL<<N1, sommes1);
  subsums(nb2, 1UL<<N2, sommes2);
  res = fusion(sommes1, 1UL<<N1, sommes2, 1UL<<N2);

  printf("%lu\n", res);
  
  return 0;
}
