#include <cstdlib>
#include <fstream>  // file stream
#include <iostream>

using namespace std;

int main() {
  ofstream saida;  // output file stream
  saida.open("tabuada.html");
  if (!saida) {
    cout << "Falhou ao abrir arquivo\n";
    exit(1);  // Finaliza com código de erro
  }
  int n;
  cout << "Informe N:";
  cin >> n;
  saida << "<!DOCTYPE html>\n<html>\n<body>\n<table border=\"1\">\n";
  for (int i = 1; i <= 10; i++) {
    saida << "<tr><td>" << i << "</td><td>X</td><td>" << n
          << "</td><td>=</td><td>" << i * n << "</td></tr>" << endl;
  }
  saida << "</table></body></html>";
  saida.close();
}
