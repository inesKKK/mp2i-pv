#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool assert_identiques(bool *r, bool *rep){
  for(int i=0; i<8; i=i+1){
    if(r[i] != rep[i]){
      return false;
    }
  }
  return true;
}

int main(void){
  bool *r0 = complement_a_deux(0);
  bool rep0[8] = {0,0,0,0,0,0,0,0};
  bool *r1 = complement_a_deux(0);
  bool rep1[8] = {0,0,0,0,0,0,0,0};
  bool *rm1 = complement_a_deux(0);
  bool repm1[8] = {0,0,0,0,0,0,0,0};
  bool *r4 = complement_a_deux(0);
  bool rep4[8] = {0,0,0,0,0,0,0,0};
  bool *rm4 = complement_a_deux(0);
  bool repm4[8] = {0,0,0,0,0,0,0,0};
  bool *r10 = complement_a_deux(0);
  bool rep10[8] = {0,0,0,0,0,0,0,0};
  bool *rm10 = complement_a_deux(0);
  bool repm10[8] = {0,0,0,0,0,0,0,0};

  assert_identiques(r0, rep0);
  assert_identiques(r1, rep1);
  assert_identiques(rm1, repm1);
  assert_identiques(r4, rep4);
  assert_identiques(rm4, repm4);
  assert_identiques(r10, rep10);
  assert_identiques(rm10, repm10);
  
  free(r0);
  free(r1);
  free(rm1);
  free(r4);
  free(rm4);
  free(r10);
  free(rm10);
  
  return 0;
}
