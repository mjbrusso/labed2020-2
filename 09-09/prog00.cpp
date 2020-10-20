#include <iostream>

using namespace std;

int fatorial(int num) {  
  int fat = 1;
  for (int i = 2; i <= num; i++) {
    fat *= i;
  }
  return fat;
}

int main() {
  cout << "Informe um inteiro: ";
  int n, f;
  cin >> n;
  f = fatorial(n);
  cout << "Fatorial de " << n << " é " << f << endl;
  return 0;
}
