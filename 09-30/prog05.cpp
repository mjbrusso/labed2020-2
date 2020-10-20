#include <cstdlib>
#include <fstream>  // file stream
#include <iostream>

using namespace std;

int main() {
    string filename;
    cout << "Nome do arquivo: ";
    getline(cin, filename);
    ifstream arq;
    arq.open(filename);
    if(!arq){
        cout << "Erro ao abrir arquivo " << filename << endl;
        exit(1);
    }
    string line;

    while(getline(arq, line))
        cout << line << endl;

    arq.close();    
}

