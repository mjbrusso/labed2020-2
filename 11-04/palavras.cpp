#include <iostream>
#include <fstream>
#include "lista.cpp"

using namespace std;

int main()
{
    ifstream input("licence.txt");
    if(!input){
        cout << "Erro na abertura do arquivo!\n";
        return 1;
    }
    string palavra;
    lista palavras;

    while(input >> palavra){
        if(!lista_ordenada_consulta(palavras, palavra)){
            lista_ordenada_insere(palavras, palavra);
        }
    }    
    input.close();

    cout << "Encontradas " << palavras.tamanho << " palavras\n";
    ofstream output("glossario.txt");
    if(!output){
        cout << "Erro ao criar glossario.txt\n";
        return 2;
    }
    nodolista *it = palavras.inicio;
    while(it){
        output << it->info << endl;
        it = it->elo;
    }
    output.close();
    return 0;
}