#include "lista.cpp"
#include <iostream>

using namespace std;

int main()
{
    lista materiais;

    lista_insere_fim(materiais, "Caneta");
    lista_insere_fim(materiais, "Papel");
    lista_insere_fim(materiais, "Borracha");
    cout << "Tamanho: " << materiais.tamanho << endl; 
    lista_mostra(materiais);

    lista_insere_fim(materiais, "Clips");
    cout << "Tamanho: " << materiais.tamanho << endl; 
    lista_mostra(materiais);

}