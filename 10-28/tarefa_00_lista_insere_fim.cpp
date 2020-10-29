/*
Implementar na biblioteca "lista.cpp" a seguinte função:

     void lista_insere_fim(lista &l, std::string s)

Ela recebe uma lista l por referência e uma string s por valor.
Inserir no final da lista l uma cópia da string passada em s e atualizar o tamanho da lista.

Usar o programa de teste abaixo para validar a implementação.
*/

#include <iostream>
#include <cassert>
#include "lista.cpp"

using namespace std;

int main()
{
    lista l;
    string s;

    s = "aa";
    lista_insere_fim(l, s);
    assert(l.tamanho==1);
    assert(l.inicio==l.fim);
    assert(l.fim->elo==nullptr);
    assert(l.fim->info==s);
    assert(l.inicio->info==s);
    cout << "Inseriu " << s << " no fim" <<endl;

    s = "bb";
    lista_insere_fim(l, s);
    assert(l.tamanho==2);
    assert(l.inicio!=l.fim);
    assert(l.inicio->elo==l.fim);
    assert(l.fim->elo==nullptr);
    assert(l.fim->info==s);
    assert(l.inicio->info=="aa");
    assert(l.inicio->elo->info=="bb");
    cout << "Inseriu " << s << " no fim" << endl;

    s = "cc";
    lista_insere_fim(l, s);
    assert(l.tamanho==3);
    assert(l.inicio!=l.fim);
    assert(l.inicio->elo->elo==l.fim);
    assert(l.fim->elo==nullptr);
    assert(l.fim->info==s);
    assert(l.inicio->info=="aa");
    assert(l.inicio->elo->elo->info=="cc");
    cout << "Inseriu " << s << " no fim" << endl;

    s = "dd";
    lista_insere_fim(l, s);
    assert(l.tamanho==4);
    assert(l.inicio!=l.fim);
    assert(l.inicio->elo->elo->elo==l.fim);
    assert(l.fim->elo==nullptr);
    assert(l.fim->info==s);
    assert(l.inicio->info=="aa");
    assert(l.inicio->elo->elo->elo->info=="dd");
    cout << "Inseriu " << s << " no fim" << endl;

    cout << "\nFim (OK)!\n";
    return 0;
}
