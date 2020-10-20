#include <iostream>
#include <fstream> // file stream
#include <cstdlib>

using namespace std;

int main() {
    ofstream saida; // output file stream
    saida.open("tabuada.csv");
    if(!saida){
        cout << "Falhou ao abrir arquivo\n";
        exit(1);  // Finaliza com código de erro
    }
    int n;  
    cout << "Informe N:";  
    cin >> n;
    for(int i=1; i<=10; i++){
        saida << i << "," << n << "," << i*n << endl;
    }
    saida.close();
}

