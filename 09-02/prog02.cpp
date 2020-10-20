#include <iostream>

using namespace std;

int main() {
  float v[] = {1.5, 0.3, 4.7, 8.8, 0.1};
  float soma = 0.0;

  for (auto valor : v) {
    soma += valor;
  }

  cout << "Soma " << soma << endl;
  return 0;
}
