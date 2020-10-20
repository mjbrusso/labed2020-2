#include <iostream>
#include "funcoes.cpp"

using namespace std;

int main() {
    int a, b;
    cout << "Informe dois valores: ";
    cin >> a >> b;
    troca(a, b);
    cout << a << " " << b << endl;
    return 0;
}

