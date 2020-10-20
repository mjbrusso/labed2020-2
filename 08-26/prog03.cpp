// Exemplo de switch case

#include <iostream>

using namespace std;

int main() {
  int mes;

  cout << "Mes (1..12): ";
  cin >> mes;

  switch (mes) {
    case 1:
      cout << "Janeiro\n";
      break;                // break termina o case
    case 2:
      cout << "Fevereiro\n";
      break;
    case 3:
      cout << "Março\n";
      break;
    case 4:
      cout << "Abril\n";
      break;
    case 5:
      cout << "Maio\n";
      break;
    case 6:
      cout << "Junho\n";
      break;
    case 7:
      cout << "Julho\n";
      break;
    case 8:
      cout << "Agosto\n";
      break;
    case 9:
      cout << "Setembro\n";
      break;
    case 10:
      cout << "Outubro\n";
      break;
    case 11:
      cout << "Novembro\n";
      break;
    case 12:
      cout << "Dezembro\n";
      break;
    default:                    // Se não for nenhum case anterior
      cout << "Mês inválido\n";
  }
}
