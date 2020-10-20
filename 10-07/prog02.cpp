#include <iostream>

using namespace std;

int main() {
    const int N=4;
    float vet[N]={1.5, 7.0, 9.1, 0.3};

    for(float *pf = vet; pf < vet+N ; pf++){        
        cout << *pf << endl;
    }
}



