/** n : entier positif ou nul
 */
int factorielle(int n){
  if(n==0){
    return 1;
  }
  return n*factorielle(n-1);
}
