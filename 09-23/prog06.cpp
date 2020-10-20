#include <algorithm>
#include <iostream>

using namespace std;

struct aluno {
  int matricula;
  string nome;
  float nota;
};

void exibe_aluno(aluno a) {
  std::cout << "Matricula: " << a.matricula << endl
            << "Nome: " << a.nome << endl
            << "Nota: " << a.nota << endl
            << endl;
}

int main() {
  const int numalunos = 3;
  aluno turma[numalunos];

  for(int i=0; i<numalunos; i++){
      cout << "Informe dados do aluno #" << i+1 << endl;
      cout << "Matrícula: "; 
      cin >> turma[i].matricula;
      cout << "Nome: ";
      cin.ignore(); // Descarta o ENTER deixado no buffer do kbd pelo cin >>
      getline(cin, turma[i].nome);
      cout << "Nota: ";
      cin >> turma[i].nota;
  }

  for (auto a : turma) {
    exibe_aluno(a);
  }

  return 0;
}

