#include <stdlib.h>

void f_x_n(int p[][3]){
  p[0][0] = 1;
}

void f_n_n(int p[2][3]){
  p[0][0] = 1;
}


int main(void){
  int p23[2][3];
  int p25[2][5];
  int p21[2][1];
  int p73[7][3];
  int p72[7][2];
  int p74[7][4];
  int p13[1][3];
  int p14[1][4];
  int p12[1][2];
  
  f_x_n(p23);
  f_x_n(p25); // interdit
  /* f_x_n(p21); // interdit */
  f_x_n(p73);
  /* f_x_n(p74); // interdit */
  /* f_x_n(p72); // interdit */
  f_x_n(p13);
  /* f_x_n(p14); // interdit */
  /* f_x_n(p12); // interdit */
  
  f_n_n(p23);
  /* f_n_n(p25); // interdit */
  /* f_n_n(p21); // interdit */
  f_n_n(p73);
  /* f_n_n(p74); // interdit */
  /* f_n_n(p72); // interdit */
  f_n_n(p13);
  /* f_n_n(p14); // interdit */
  /* f_n_n(p12); // interdit */
  
  return 0;
}
