#include <iostream>
#include <fstream> // file stream
#include <cstdlib>

using namespace std;

int main() {
    ofstream saida; // output file stream
    saida.open("aula.txt");
    if(!saida){
        cout << "Falhou ao abrir arquivo\n";
        exit(1);  // Finaliza com código de erro
    }

    for(int i=0; i<10; i++){
        saida << i << endl;
    }
    saida.close();
}

