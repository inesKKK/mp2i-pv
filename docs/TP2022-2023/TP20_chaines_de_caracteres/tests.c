#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "tp21.h"

void test_longueur(){
  assert( longueur("") == 0 );
  assert( longueur("a") == 1 );
  assert( longueur("anticonstitutionnellement") == 25);
}

void test_nombre_occurences(){
  assert ( nombre_occurences('a', "") == 0 );
  assert ( nombre_occurences('a', "123456") == 0 );
  assert ( nombre_occurences('a', "a123456") == 1 );
  assert ( nombre_occurences('a', "a12a34a56") == 3 );
  assert ( nombre_occurences('a', "123456a") == 1 );
  assert ( nombre_occurences('a', "12aaa3456a") == 4 );
}

void test_derniere_occurence(){
  assert( derniere_occurence('a', "") == -1 );
  assert( derniere_occurence('1', "23456") == -1 );
  assert( derniere_occurence('A', "Atout") == 0);
  assert( derniere_occurence('a', "carreau") == 5);
  assert( derniere_occurence('a', "abracadabra") == 10);
}

void test_split(){
  char *s = "ceci est un essai pour un exemple";
  char **t1 = split(' ', s);
  char **t2 = split('e', s);
  char **t3 = split('z', s);
  assert( strcmp(t1[0], "ceci") == 0 );
  assert( strcmp(t1[2], "un") == 0 );
  assert( strcmp(t1[6], "exemple") == 0 );
  assert( strcmp(t2[1], "ci ") == 0 );
  assert( strcmp(t2[6], "") == 0);
  assert( strcmp(t3[0], s) == 0 );
}

int main(void){
  test_longueur();
  test_nombre_occurences();
  test_derniere_occurence();
  test_split();
}
