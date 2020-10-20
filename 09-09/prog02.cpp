#include <iostream>
#include "funcoes.cpp"

using namespace std;

int main() {
  cout << "Informe um inteiro: ";
  int n, f;
  cin >> n;
  f = fatorial(n);
  cout << f << endl;

  return 0;
}

