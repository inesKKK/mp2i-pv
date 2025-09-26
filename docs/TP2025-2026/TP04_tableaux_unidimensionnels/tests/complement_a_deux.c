#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

/** n : entier
 * t : tableau suppose de taille 8 */
void complement_a_deux(int n, bool *t){
  // TODO
}

bool assert_identiques(bool *r, bool *rep){
  for(int i=0; i<8; i=i+1){
    if(r[i] != rep[i]){
      return false;
    }
  }
  return true;
}

int main(void){
  bool rep0[8] = {0,0,0,0,0,0,0,0}, r0[8];
  complement_a_deux(0, r0);
  
  bool rep1[8] = {0,0,0,0,0,0,0,1}, r1[8];
  complement_a_deux(1, r1);

  bool repm1[8] = {1,1,1,1,1,1,1,1}, rm1[8];
  complement_a_deux(-1, rm1);

  bool rep4[8] = {0,0,0,0,0,1,0,0}, r4[8];
  complement_a_deux(4, r4);

  bool repm4[8] = {1,1,1,1,1,1,0,0}, rm4[8];
  complement_a_deux(-4, rm4);

  bool rep10[8] = {0,0,0,0,1,0,1,0}, r10[8];
  complement_a_deux(10, r10);

  bool repm10[8] = {1,1,1,1,0,1,1,0}, rm10[8];
  complement_a_deux(-10, rm10);

  assert(assert_identiques(r0, rep0));
  assert(assert_identiques(r1, rep1));
  assert(assert_identiques(rm1, repm1));
  assert(assert_identiques(r4, rep4));
  assert(assert_identiques(rm4, repm4));
  assert(assert_identiques(r10, rep10));
  assert(assert_identiques(rm10, repm10));
  
  return 0;
}
