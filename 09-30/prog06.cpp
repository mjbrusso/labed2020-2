#include <cstdlib>
#include <fstream>  // file stream
#include <iostream>

using namespace std;

int main() {
    string filename;
    cout << "Arquivo de entrada: ";
    getline(cin, filename);
    ifstream arq;
    arq.open(filename);
    if(!arq){
        cout << "Erro ao abrir arquivo " << filename << endl;
        exit(1);
    }
    cout << "Arquivo de saída: ";
    getline(cin, filename);
    ofstream arq2;
    arq2.open(filename);    
    if(!arq2){
        cout << "Erro ao criar arquivo " << filename << endl;
        exit(1);
    }
    string line;

    while(getline(arq, line))
        arq2 << line << endl;

    arq.close();    
    arq2.close();
}

