#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 164  // Nombre de péages
#define MAX 23  // Longueur maximale d'un nom de péage (+1)

// Lecture dans `noms` des noms des péages
void read_names(char noms[N][MAX]) {
  FILE *f = fopen("noms.txt", "r");
  if (f == NULL) {
    fprintf(stderr, "Cannot open file noms.txt\n");
    exit(1);
  }
  for (int i = 0; i < N; i++) {
    fscanf(f, "%[^\n]\n", noms[i]);
  }
  fclose(f);
}

// Initialise une matrice d'adjacence avec des `0` sur la diagonale et
// des -1 (pour plus l'infini) partout.
void init(double mat[N][N]) {
  // À implémenter
}

// Lecture dans `dist` et dans `prix` des matrices d'adjacence (qui
// doivent avoir été initialisées au préalable.
void read_graph(double dist[N][N], double prix[N][N]) {
  FILE *f = fopen("graph.txt", "r");
  if (f == NULL) {
    fprintf(stderr, "Cannot open file graph.txt\n");
    exit(1);
  }
  while (true) {
    int x, y;
    double p, d;
    int c = fscanf(f, "%d,%d,%lf,%lf", &x, &y, &p, &d);
    if (c != 4) {
      break;
    }
    dist[x][y] = p;
    prix[x][y] = d;
  }
  fclose(f);
}

void floyd_warshall(double best[N][N], double prix[N][N]) {
  // À implémenter
}


int main(void) {

  char noms[N][MAX] = {{'\0'}};
  read_names(noms);

  double dist[N][N];
  init(dist);
  double prix[N][N];
  init(prix);
  read_graph(dist, prix);

}

