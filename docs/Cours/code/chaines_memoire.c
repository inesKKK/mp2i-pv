#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char t[] = {'a', 'b', 'c', '\0'};
  char *p = (char *)malloc(4*sizeof(char));
  int *n = (int *)malloc(sizeof(int));
  char *s1 = "abc";
  char *s2 = "abc";
  
  p[0] = 'a';
  p[1] = 'b';
  p[2] = 'c';
  p[3] = '\0';
  *n = 3;

  printf("t (pile) : \t%p\n", t);
  printf("p (tas) : \t%p\n", p);
  printf("n (tas) : \t%p\n", (void *)n);
  printf("s1 : \t\t%p\n", s1);
  printf("s2 : \t\t%p\n", s2);

  /* t[1] = 'z'; // autorise */
  /* printf("t = %s\n", t); */
  /* p[1] = 'z'; // autorise */
  /* printf("p = %s\n", p); */
  /* s1[1] = 'z'; // interdit */
  /* printf("s1 = %s\n", s1); */
  /* s1 = "def"; // autorise */
  /* printf("s1 = %s\n", s1); */
  /* printf("s1 : \t\t%p\n", s1); */
  /* printf("s2 : \t\t%p\n", s2); */
  /* s1 = (char *)malloc(3*sizeof(char)); // autorise */
  /* s1[0] = 'a'; */
  /* s1[1] = 'h'; */
  /* s1[2] = '\0'; */
  /* printf("s1 = %s\n", s1); */
  /* printf("s1 : \t\t%p\n", s1); */
}
