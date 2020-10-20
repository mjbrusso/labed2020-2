#include <iostream>

using namespace std;

double *criavet(int n){
    double *p = new double[n];
    for(int i=0; i<n; i++)
        p[i] = 0;

    return p;
}

int main() {
    int n;
    cout << "N: ";
    cin >> n;

    double *pd = criavet(n);
    for(int i=0; i<n; i++){
        cout << pd[i] << endl;
    }
    delete[] pd; 
}







