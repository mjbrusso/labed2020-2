 /*
 Implementar na biblioteca "lista.cpp" a seguinte função:

      void lista_insere_inicio(lista &l, std::string s)

 Ela recebe uma lista l por referência e uma string s por valor.
 Inserir no início da lista l uma cópia da string passada em s e atualiza o tamanho da lista.
 
 Usar o programa abaixo para validar a implementação
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
    lista_insere_inicio(l, s);    
    assert(l.tamanho==1);
    assert(l.inicio==l.fim);
    assert(l.inicio->info=="aa");
    assert(l.fim->info=="aa");
    cout << "Inseriu " << s << " no inicio" <<endl;

    s = "bb";
    lista_insere_inicio(l, s);
    assert(l.tamanho==2);
    assert(l.inicio!=l.fim);
    assert(l.inicio->info==s);
    assert(l.inicio->elo->info=="aa");
    assert(l.fim->info=="aa");
    cout << "Inseriu " << s << " no inicio" << endl;

    s = "cc";
    lista_insere_inicio(l, s);
    assert(l.tamanho==3);
    assert(l.inicio!=l.fim);
    assert(l.inicio->info==s);
    assert(l.inicio->elo->info=="bb");
    assert(l.inicio->elo->elo->info=="aa");
    assert(l.fim->info=="aa");
    cout << "Inseriu " << s << " no inicio" << endl;

    s = "dd";
    lista_insere_inicio(l, s);
    assert(l.tamanho==4);
    assert(l.inicio!=l.fim);
    assert(l.inicio->info==s);
    assert(l.inicio->elo->info=="cc");
    assert(l.inicio->elo->elo->info=="bb");
    assert(l.inicio->elo->elo->elo->info=="aa");
    assert(l.fim->info=="aa");
    cout << "Inseriu " << s << " no inicio" << endl << endl;

    cout << "\nFim (OK)!\n";
    return 0;
}
