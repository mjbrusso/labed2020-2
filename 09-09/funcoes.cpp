int fatorial(int num) {
  int fat = 1;
  for (int i = 2; i <= num; i++) {
    fat *= i;
  }
  return fat;
}

template<typename T>
void troca(T &n1, T &n2){
    T aux = n1;
    n1 = n2;
    n2 = aux;
}

