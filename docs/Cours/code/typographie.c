#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/** mots : tableau de chaines de caractères contenant n+1 cases, 
 * les mots se trouvants dans les cases d'indices 1 a n
 * sortie: tableau d'entiers de n+1 cases, la premiere vaut 0, 
 * la i-e la somme des longueurs des chaines de la case 1 a la case i
 */
int *longueurs_cumulees(char **mots, int n){
  int *lg;
  
  lg = (int *)malloc((n+1)*sizeof(int));
  lg[0] = 0;
  for(int i=1; i<=n; i=i+1){
    lg[i] = lg[i-1] + strlen(mots[i]);
  }

  return lg;
}


/** initialise un tableau d'entiers a n+1 cases, avec des INT_MAX a toutes les cases */
int *init_tab(int n){
  int *res = (int *)malloc((n+1)*sizeof(int));
  for(int i=0; i<=n; i=i+1){
    res[i] = INT_MAX;
  }
  return res;
}

/** calcule le cube d'un entier */
int cube(int n){
  return n*n*n;
}

/** lg : longueurs cumulees
 * espaces[i] est le nombre d'espaces en fin de lignes si on commence
 *                 la ligne avec le mot d'indice i [modifie par la fonction]
 * fin_ligne[i] est l'indice du dernier mot de la ligne si on commence
 *                 la ligne avec le mot d'indice i [modifie par la fonction]
 * n : longueur-1 de tous les tableaux
 * M : longueur max de la ligne
 * attention : le premier mot est le mot d'indice 1
 */
void calcul_espacement(int *lg, int *espaces, int *fin_ligne, int n, int M){
  espaces[n+1] = 0;
  for(int i=n; i>=1; i=i-1){
    if (n-i+lg[n]-lg[i-1] < M){ /* on peut ecrire les mots restants sur la ligne */
      espaces[i] = 0;
      fin_ligne[i] = n;
    } else { /* on a besoin d'au moins un retour a la ligne */
      espaces[i] = INT_MAX;
      for(int j=i; j<=n; j=j+1){
        int essai_a_j;
        if( lg[j]-lg[i-1] + j-i > M){ /* s'il n'y a pas de place pour le mot j, */
          break;                           /*  il n'y en a pas pour les suivants */
        }
        essai_a_j = cube( M - (lg[j]-lg[i-1] + j-i) ) + espaces[j+1];
        if (essai_a_j < espaces[i]){
          espaces[i] = essai_a_j;
          fin_ligne[i] = j;
        }
      }
    }
  }
}


/** mots : tableau de mots (premier mot d'indice 1)
 * n : nombre de mots (dernier mot d'indice n)
 * fin_ligne[i] est l'indice du dernier mot sur la ligne, si le premier mot est mot[i]
 * action : effectue l'affichage
 */
void affichage(char **mots, int n, int *fin_ligne){
  int i = 1;
  while(i <= n){
    int j = fin_ligne[i];
    for(int k=i; k<=j; k=k+1){
      printf("%s ", mots[k]);
    }
    printf("\n");
    i = j+1;
  }
}

/** affiche un etalon */
void etalon(int M){
  printf("\n");
  for(int i=0; i<M; i=i+1){
    printf("-");
  }
  printf("\n");
}

int main(int argc, char **argv){
  int M; /* la largeur de la ligne d'affichage */
  char **mots; /* les mots a afficher, premier mot d'indice 1 */
  int n; /* le nombre de mots a afficher */
  int *lg; /* les longueurs cumulees */
  int *espaces; /* les espaces en fin de ligne si la ligne commence au mot i */
  int *fin_ligne; /* indice du dernier mot de la ligne si la ligne commence au mot i */

  if(argc<=2){
    fprintf(stderr, "%s usage: %s M mot1 [ mot2 [...] ]\n", argv[0], argv[0]);
    return 1;
  }

  M = atoi(argv[1]);
  if(M <= 0){
    fprintf(stderr, "M doit être un entier strictement positif\n");
    return 1;
  }
  mots = &argv[1];
  n = argc - 2;
  
  lg = longueurs_cumulees(mots, n);
  espaces = init_tab(n);
  fin_ligne = init_tab(n);
  calcul_espacement(lg, espaces, fin_ligne, n, M);

  etalon(M);
  affichage(mots, n, fin_ligne);

  // toutes les liberations de memoire a ajouter ici
  
  return 0;
}
