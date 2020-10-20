// Exemplo de operador ternário

#include <iostream>

using namespace std;

int main() {    
  cout << "Informe dois valores: ";
  double a, b;

  cin >> a >> b;  
  double m = (a > b ? a : b);  // os parênteses não são obrigatórios
  cout << "Maior: " << m << endl;
}
