#include <stdio.h>

void f();
void g();
void h();
void i();

void f(){
  char c = 'f';
  g();
}


void g(){
  char c = 'g';
  h();
}

void h(){
  char c = 'h';
  i();
}

void i(){
  char c = 'i';
}

int main(void){
  f();
  return 0;
}
