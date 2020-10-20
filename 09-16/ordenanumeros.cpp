#include <iostream>
#include "ordenacao.cpp"
#include <algorithm>

using namespace std;

const int N=100000;

int main()
{
    int vet[N];

// Entrada
    for(int i=0; i<N; i++)
        cin >> vet[i];

// Ordenação
//    bubblesort(vet, N);       // 22s
//      selectionsort(vet, N);  // 14.5s
//        insertionsort(vet, N);  // 3s

    sort(vet, vet+N); // Introsort

//  Saída
    for(int i=0; i<N; i++)
        cout << vet[i] << '\n';
    
    return 0;
}
