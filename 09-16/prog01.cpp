#include <iostream>

using namespace std;

template <typename T>
T somavet(T vet[], int n){
    T acum=0;
    for(int i=0; i<n; ++i){
        acum += vet[i];        
    }
    return acum;
}

int main() {
    double vet[]={1.5, 0.7, 3.1, 8.8, 0.1};
    double s = somavet(vet, 5);
    cout << "Soma: " << s << endl;

    int vb[]={5, 10, 20};
    cout << "Soma: " << somavet(vb, 3) << endl;
}

