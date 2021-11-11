#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "peintre.h"

struct toile *enonce(){
  struct rectangle rect_vert = {.x = 165, .y = 10, .larg = 60, .haut = 20,
                           .c = {.r = 0, .g = 200, .b = 0 } };
  struct rectangle rect_bleu = {.x = 80, .y = 40, .larg = 60, .haut = 40,
                           .c = {.r = 0, .g = 0, .b = 255 } };
  struct rectangle rect_rouge = {.x = 40, .y = 60, .larg = 80, .haut = 30,
                           .c = {.r = 255, .g = 0, .b = 0 } };
  struct toile *fond = canevas(200, 120);
  trace(&rect_vert, fond);
  trace(&rect_bleu, fond);
  trace(&rect_rouge, fond);
  return fond;
}

//feet Kasimir Malevitch
struct toile *suprematism1915(){
  struct toile *fond = canevas(400, 600);
  struct rectangle rect[] =
    { {.x = 200, .y = 10, .larg = 40, .haut = 600,
       .c = {.r = 0, .g = 0, .b = 0 } },
      {.x = 20, .y = 10, .larg = 370, .haut = 25,
       .c = {.r = 200, .g = 0, .b = 0 } },
      {.x = 60, .y = 60, .larg = 300, .haut = 50,
       .c = {.r = 200, .g = 0, .b = 0 } },
      {.x = 20, .y = 150, .larg = 230, .haut = 20,
       .c = {.r = 200, .g = 0, .b = 0 } },
      {.x = 80, .y = 550, .larg = 300, .haut = 25,
       .c = {.r = 200, .g = 0, .b = 0 } },
      {.x = 0, .y = 330, .larg = 380, .haut = 20,
       .c = {.r = 0, .g = 0, .b = 0 } },
      {.x = 95, .y = 380, .larg = 25, .haut = 120,
       .c = {.r = 200, .g = 0, .b = 0 } },
      {.x = 5, .y = 430, .larg = 80, .haut = 60,
       .c = {.r = 255, .g = 234, .b = 128 } },
      {.x = 290, .y = 225, .larg = 20, .haut = 30,
       .c = {.r = 255, .g = 234, .b = 128 } },
      {.x = 300, .y = 160, .larg = 40, .haut = 60,
       .c = {.r = 102, .g = 25, .b = 255 } }
    };
  for(int i=0; i<10; i=i+1){
    trace(&rect[i], fond);
  }
  return fond;
}


int main(){
  struct toile *t = enonce();
  affiche(t);
  detruit_toile(t);
}
