/*
    Implementar, na biblioteca lista.cpp uma nova função:

        bool lista_igual(lista l1, lista l2)

    Esta função deve verificar se duas listas encadeadas passadas por parâmetro (l1 e l2) são iguais.
    Duas  listas  são  consideradas  iguais  se  têm  o mesmo tamanho e
    exatamente a  mesma  sequência  de  valores (info), ou se ambas estão vazias.

    A função deve retornar true, caso as listas sejam iguais, ou false em caso contrário.
*/

#include <iostream>
#include <cassert>
#include "lista.cpp"

using namespace std;

int main()
{
    lista l1, l2;

    assert(lista_igual(l1, l2)==true);  // Ambas estãoo vazias, então são iguais

    lista_insere_fim(l1, "a");
    assert(lista_igual(l1, l2)==false); // l1: ["a"] l2: []

    lista_insere_fim(l2, "a");
    assert(lista_igual(l1, l2)==true);  // l1: ["a"] l2: ["a"]

    lista_insere_fim(l2, "b");
    assert(lista_igual(l1, l2)==false); // l1: ["a"] l2: ["a", "b"]

    lista_insere_fim(l2, "x");
    assert(lista_igual(l1, l2)==false); // l1: ["a"] l2: ["a", "b", "x"]

    lista_insere_fim(l1, "b");
    assert(lista_igual(l1, l2)==false); // l1: ["a", "b"] l2: ["a", "b", "x"]

    lista_insere_fim(l1, "x");
    assert(lista_igual(l1, l2)==true);  // l1: ["a", "b", "x"] l2: ["a", "b", "x"]

    lista_insere_fim(l1, "d");
    assert(lista_igual(l1, l2)==false); // l1: ["a", "b", "x", "d"] l2: ["a", "b", "x"]

    lista_insere_fim(l2, "c");
    assert(lista_igual(l1, l2)==false); // l1: ["a", "b", "x", "d"] l2: ["a", "b", "x", "c"]

    cout << "\nFim (OK)!\n";
    return 0;
}
