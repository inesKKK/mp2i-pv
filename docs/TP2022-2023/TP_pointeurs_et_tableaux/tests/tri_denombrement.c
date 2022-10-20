#include <assert.h>
#include <stdlib.h>

int main(void){
  int a1[] = {1};
  int *a2 = tri_denombrement(a1, 1, 5);
  int b1[] = {1, 1, 1};
  int *b2 = tri_denombrement(b1, 3, 5);
  int c1[] = {5, 4, 3, 2, 1, 0};
  int *c2 = tri_denombrement(c1, 6, 5);
  int d1[] = {2, 3, 1, 2, 0, 1, 5, 5, 4, 3, 0, 4};
  int *d2 = tri_denombrement(d1, 12, 5);

  assert(a2[0]==1);
  free(a2);

  for(int i=0; i<3; i=i+1){
    assert(b2[i]==1);
  }
  free(b2);

  for(int i=0; i<6; i=i+1){
    assert(c2[i]==i);
  }
  free(c2);

  for(int i=0; i<12; i=i+1){
    assert(d2[i]==i/2);
  }
  free(d2);

  return 0;
}
