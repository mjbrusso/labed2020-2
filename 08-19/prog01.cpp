/*
  prog01.cpp

  Changelog:
        2020-08-19  mjbrusso <brusso@upf.br> : File created
 */

#include <iostream>  // Inclui a biblioteca de entrada/saída

float maior(float n1, float n2);

using namespace std;

int main() {
  float a, b, m;

  cout << "Informe dois valores: ";
  cin >> a >> b;

  m = maior(a, b);
  cout << "O maior valor é " << m << endl;

  return 0;
}

float maior(float n1, float n2) {
  if (n1 > n2) {
    return n1;
  } 
  else {
    return n2;
  }
}