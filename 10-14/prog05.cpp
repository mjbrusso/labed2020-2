#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct cidade {
    string uf;
    int populacao;
    string nome;
};

bool cmp(const cidade &c1, const cidade &c2) {
    return c1.populacao > c2.populacao ||
           (c1.populacao == c2.populacao && c1.nome < c2.nome);
}

int main() {
    vector<cidade> cidades;
    cidade aux;
    ifstream arq("cidades.txt");

    while (arq >> aux.uf) {
        arq >> aux.populacao;
        arq.ignore();
        getline(arq, aux.nome);

        cidades.push_back(aux);
    }
    arq.close();
    cout << "Leu " << cidades.size() << endl;

    sort(cidades.begin(), cidades.end(), cmp);
    
    ofstream saida("cidadesord.txt");
    for (auto c : cidades)
        saida << c.uf << endl << c.populacao << endl << c.nome << endl;
    
    saida.close();    
}
