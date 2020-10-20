#include <iostream>

using namespace std;

int main() {
    int n=5;
    int *p;
    int **pp;
    
    p = &n; // p recebe o endereço de n
    cout << p << ' ' << *p << endl;
    *p = 22;
    cout << n << ' ' << *p << endl;

    pp = &p;
    cout << pp << ' ' << *pp << ' ' << **pp << endl;
}

