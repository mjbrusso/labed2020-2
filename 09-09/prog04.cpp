#include <iostream>

using namespace std;

template<typename T1, typename T2>
void mostra(T1 a, T2 b){
    cout << a << endl << b << endl;
}

int main()
{
    float x=1.5, y=0.9;
    char letra = 'A';

    mostra(x, letra);
    mostra(x, y);
}