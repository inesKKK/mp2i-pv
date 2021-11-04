void mettre_a_42(int *n){
  *n = 42;
}

int main(){
  int a = 3;
  int tab[] = {1, 2, 3, 4};

  mettre_a_42(&a);
  mettre_a_42(&tab[2]);
}
