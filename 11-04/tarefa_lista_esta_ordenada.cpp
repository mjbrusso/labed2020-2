/*
    Implementar, na biblioteca lista.cpp uma nova função:

        bool lista_esta_ordenada(lista l)

    Esta função deve testar se os valores armazenados na lista encadeada l
    estão ordenados em ordem alfabética crescente.

    Retorna true se a lista está ordenada.  Retorna false se não está.

    Considerar que uma lista vazia ou com um único nodo está ordenada.
*/

#include <iostream>
#include <cassert>
#include "lista.cpp"

using namespace std;

int main()
{
    lista l1;
    assert(lista_esta_ordenada(l1)==true);            // Vazia!
    
    lista_insere_fim(l1, "a");
    lista_insere_fim(l1, "b");
    lista_insere_fim(l1, "c");
    lista_insere_fim(l1, "d");
    assert(lista_esta_ordenada(l1)==true);

    lista l2;
    lista_insere_fim(l2, "a");
    lista_insere_fim(l2, "b");
    lista_insere_fim(l2, "d");
    lista_insere_fim(l2, "c");
    assert(lista_esta_ordenada(l2)==false);

    lista l3;
    lista_insere_fim(l3, "a");
    assert(lista_esta_ordenada(l3)==true);

    lista l4;
    lista_insere_fim(l4, "a");
    lista_insere_fim(l4, "z");
    lista_insere_fim(l4, "a");
    assert(lista_esta_ordenada(l4)==false);

    cout << "Fim (OK)!\n";
    return 0;
}
