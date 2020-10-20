#include <iostream>

using namespace std;

int* mostra(){
    static int n = 0;

    n++;
    cout << n << endl;
    return &n;
}

int main() {
    int* p = mostra();
    *p = 55;
    mostra();
    mostra();
}








