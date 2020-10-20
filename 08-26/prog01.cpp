// Exemplo de if else

#include <iostream>

using namespace std;

int main() {
  int n;

  cout << "Informe um número: ";
  cin >> n;
  if (n < 0) {  // os parênteses são obrigatórios
    cout << "Negativo\n";
  } else if (n == 0) {
    cout << "Zero\n";
  } else {
    cout << "Maior que zero\n";
  }
  return 0;
}
