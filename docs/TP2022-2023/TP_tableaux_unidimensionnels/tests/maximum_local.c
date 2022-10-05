#include <assert.h>

int main(void){
  int t[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2};
  int t2[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2, 3, 3, 3, 3, 1, 4, 4, 4};

  assert(! maximum_local(t, 12, 0));
  assert(maximum_local(t, 12, 2));
  assert(maximum_local(t, 12, 7));
  assert(! maximum_local(t, 12, 9));
  assert(! maximum_local(t, 12, 12));

  //à décommenter pour la question 2
  /*  assert(! vrai_maximum_local(t2, 20, 0));
  assert(vrai_maximum_local(t2, 20, 2));
  assert(vrai_maximum_local(t2, 20, 7));
  assert(vrai_maximum_local(t2, 20, 9));
  assert(vrai_maximum_local(t2, 20, 12));
  assert(vrai_maximum_local(t2, 20, 13));
  assert(vrai_maximum_local(t2, 20, 14));
  assert(vrai_maximum_local(t2, 20, 15));
  assert(! vrai_maximum_local(t2, 20, 16));
  assert(! vrai_maximum_local(t2, 20, 18));
  assert(! vrai_maximum_local(t2, 20, 19));
  */
  
  return 0;
}
