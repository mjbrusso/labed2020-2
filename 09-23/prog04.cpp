#include <algorithm>
#include <iostream>

using namespace std;

struct aluno {
  int matricula;
  string nome;
  float nota[3];
};

void exibe_aluno(aluno a) {
  cout << "Matricula: " << a.matricula << endl
       << "Nome: " << a.nome << endl
       << "Nota: " << a.nota << endl;
}

int main() {
  aluno turma[3] = {{998877, "Fulano de tal", {9.9, 8.8, 0.5}},
                    {887766, "Cicrano", {10.0, 10.0, 9.9}},
                    {776655, "Beltrano", {7.1, 5.5, 9.2}}};

  cout << turma[1].matricula << endl;
  cout << turma[2].nota[0] << endl;
  
  cout << turma[0].nome[1] << endl;

      return 0;
}
