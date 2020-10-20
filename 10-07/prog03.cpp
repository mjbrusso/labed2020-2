#include <iostream>

using namespace std;

struct contato{
    string nome;
    string fone;
};

int main() {
    contato c1 = {"Fulano de tal", "90123-4567"};
    cout << c1.nome << endl;
    contato *pc;
    pc = &c1;

    cout << pc->fone << endl;
}









