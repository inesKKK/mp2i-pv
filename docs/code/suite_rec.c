double nieme(int n, double a, double b, double u0){
  double u = u0;
  for(int i=0; i<n; i=i+1)
    u = a*u + b;
  return u;
}

int main(){
  double u5 = nieme(5, 2, 1, 1),
    u10 = nieme(10, 2, 1, 1);
}
