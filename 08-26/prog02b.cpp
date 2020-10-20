// Exemplo de operador ternário

#include <iostream>

using namespace std;

int main() {    
  cout << "Informe três valores: ";
  double a, b, c;

  cin >> a >> b >> c;  
  double m = (a > b && a > c ? a : (b > c ? b : c));
  cout << "Maior: " << m << endl;
}
