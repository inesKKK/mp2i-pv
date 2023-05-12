#include <stdio.h>

void fpp(int **t){
  printf("fpp\n");
}

void fpt(int *t[]){
  printf("fpt\n");
}

void ftt1(int t[3][2]){
  printf("ftt1\n");
}

void ftt2(int t[][2]){
  printf("ftt2\n");
}
