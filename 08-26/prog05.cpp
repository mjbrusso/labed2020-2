// Exemplos de continue e break em laços de repetição
#include <iostream>

using namespace std;

int main() {
  // i começa com 100, repete enquanto for menor que 200, incrementando em 1
  for (int i = 100; i < 200; i++) {
    if (i % 3 == 0) {
      continue;  // encerra a iteração atual, volta ao teste do laço
    }
    if (i % 28 == 0) {
      break;    // Cai fora do laço
    }
    cout << i << endl;
  }
  // 
}
