// Exemplos de laços de repetição

#include <iostream>

using namespace std;

int main() {
  int n=10;

  cout << "Laço 'while':\n";
  // Teste antes de entrar no laço. Pode não executar nenhuma vez, caso falso
  while (n < 10) {
    cout << n << endl;
    n++;
  }

  cout << "Laço 'do while':\n";
  // Teste no final do laço. Garante que executa pelo menos uma vez.
  do {
    cout << n << endl;
    n--;
  } while (n > 0);

  // Laço "for":
  // Tem 3 partes separadas por ;
  //    (Inicialização da variável de controle;
  //     teste while : vai permanecer no laço enquanto a condição for
  //     verdadeira; atualização da variável)
  cout << "Laço 'for':\n";

  for (int i = 1; i < 100; i*=2){
    cout << i << endl;
  }

  for(int i=1, j=100; i<j; i++, j--){
      cout << i << " " << j << endl;
  }
}
