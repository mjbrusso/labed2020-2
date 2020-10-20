#include <iostream>
#include <algorithm>

using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

void exibe_aluno(aluno a)
{
    cout << "Matricula: " << a.matricula  << endl
         << "Nome: " << a.nome  << endl
         << "Nota: " << a.nota << endl;
}

int main() {
    aluno eu;

    eu.matricula = 990088;
    eu.nome = "Fulano de tal";
    eu.nota = 9.9;

    exibe_aluno(eu);
    
    return 0;
}

