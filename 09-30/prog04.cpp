#include <cstdlib>
#include <fstream>  // file stream
#include <iostream>

using namespace std;

int main() {
    string filename = "tabuada.csv";
    ifstream arq;
    arq.open(filename);
    if(!arq){
        cout << "Erro ao abrir arquivo " << filename << endl;
        exit(1);
    }    
    int num1, num2, num3;
    char foo;
    while(arq >> num1 >> foo >> num2 >> foo >> num3){
        cout << num1 << " X " << num2 << " = " << num3 << endl;
    }
    arq.close();    
}

