#include <iostream>

using namespace std;

int main()
{
    const int tamanho=5;    
    int vet[tamanho], soma=0; 

    for(int i=0; i<tamanho; ++i){
        cin >> vet[i];
        soma += vet[i];
    }

    cout << "Média = " << soma / tamanho << endl;
    return 0;
}
