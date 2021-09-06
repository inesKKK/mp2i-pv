/* exemple en C */
int plus_grande_puissance_de_2(int n){
  int rep = 0;
  while (n%2==0){
    n = n/2;
    rep = rep+1;
  }
  return rep;
}
