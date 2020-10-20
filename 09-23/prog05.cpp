#include <algorithm>
#include <iostream>
#include <cctype>

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

bool cmpnota(aluno a, aluno b){
    // return (a.nota==b.nota) ? a.nome < b.nome : a.nota > b.nota;
    return a.nota > b.nota || (a.nota==b.nota && a.nome < b.nome);
}

bool cmpmat(aluno a, aluno b){
    return a.matricula < b.matricula;
}

int main() {
  aluno turma[4] = {{998877, "Fulano de tal", 9.9},
                    {887766, "Cicrano", 10.0},
                    {776655, "Beltrano", 7.1},
                    {665544, "Augustinho", 10.0}};

  cout << "Ordenar por: [M]atricula/[N]ota: ";
  char opcao;
  cin >> opcao;
  if(toupper(opcao)=='N')
    sort(turma, turma+4, cmpnota);
  else
    sort(turma, turma+4, cmpmat);

  for (auto a : turma) {
    exibe_aluno(a);
  }

  return 0;
}
