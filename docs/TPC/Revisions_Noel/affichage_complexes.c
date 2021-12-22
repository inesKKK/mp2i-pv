#include <stdio.h>
#include <stdlib.h>


void affiche(complexe c){
  if(c.re != 0){
    printf("%.2f", c.re);
  }
  if(c.im != 0){
    if(c.im > 0){
      printf(" + %.2f i", c.im);
    } else {
      printf(" - %.2f i", -c.im);
    }
  }

  if(c.re == 0 && c.im == 0){
    printf("0");
  }
  
  fflush(NULL);
}

