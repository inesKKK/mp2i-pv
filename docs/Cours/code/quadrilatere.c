#include <stdlib.h>

struct point {
  int x, y;
};

struct quadrilatere {
  struct point p[4];
};

/** renvoie un quadrilatere representant un carre de coin en
 * bas a gauche (x, y) et de cote c
 */
struct quadrilatere carre(int x, int y, int c){
  struct quadrilatere q;
  
  q.p[0].x = x;
  q.p[0].y = y;
  q.p[1].x = x+c;
  q.p[1].y = y;
  q.p[2].x = x+c;
  q.p[2].y = y+c;
  q.p[3].x = x;
  q.p[3].y = y+c;

  return q;
}



int main() {
  struct quadrilatere c;

  c = carre(2, 7, 5);

  return 0;
}
