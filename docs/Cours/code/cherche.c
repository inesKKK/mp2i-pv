/** tableau tab (non NULL) de longueur n,
 * renvoie la distance entre la première et la dernière occurence de val
 * dans tab si val apparaît dans tab, <0 sinon */
int cherche(int *tab, int n, int val){
  int premier, dernier, i;
  assert(tab != NULL && n>0);
  
  for(i=0; i<n; i=i+1){
    if (tab[i] == val) {
      break;
    }
  }
  premier = i;

  for(i=n-1; i>=0; i=i-1){
    if (tab[i] == val) {
      break;
    }
  }
  dernier = i;
  
  return dernier - premier;
}
