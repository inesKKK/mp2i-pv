#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char t[] = {'a', 'b', 'c', '\0'};
  char *p = (char *)malloc(4*sizeof(char));
  int *n = (int *)malloc(sizeof(int));
  const char *s = "abc";
  
  p[0] = 'a';
  p[1] = 'b';
  p[2] = 'c';
  p[3] = '\0';
  *n = 3;

  printf("t (pile) : \t%p\n", t);
  printf("p (tas) : \t%p\n", p);
  printf("n (tas) : \t%p\n", (void *)n);
  printf("s : \t\t%p\n", s);
  printf("s' : \t\t%p\n", s);

  /* t[1] = 'z'; // autorise */
  /* printf("t = %s\n", t); */
  /* p[1] = 'z'; // autorise */
  /* printf("p = %s\n", p); */
  /* s[1] = 'z'; // interdit */
  /* printf("s = %s\n", s); */
  s = "def";
  /* printf("s = %s\n", s); */
  printf("s : \t\t%p\n", s);  
}
