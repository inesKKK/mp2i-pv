#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche_image(image im){
  setlocale(LC_ALL, ""); //instruction hors programme, pour les affichages bizarres
  for(int i=0; i < im.haut; i = i+1){
    for(int j=0; j < im.larg; j = j+1){
      if(im.p[i][j]){
        printf("%lc", (wint_t)0x2b1b);
      } else {
        printf("%lc", (wint_t)0x2b1c);
      }
    }
    printf("\n");
  }
}
