#include <iostream>
#include <cassert>
#include "funcoes.cpp"

using namespace std;

int main()
{
    int a=10, b=5;
    troca(a, b);
    assert(a==5 && b==10);

    a=20; b=40;
    troca(a, b);
    assert(a==40 && b==20);

    a=0; b=0;
    troca(a, b);
    assert(a==0 && b==0);

    a=-20; b=40;
    troca(a, b);
    assert(a==40 && b==-20);

    a=-2; b=-1;
    troca(a, b);
    assert(a==-1 && b==-2);

    float x=1.5, y=3.0;
    troca(x, y);
    assert(y==1.5 && x==3.0);

    cout << "FIM\n";
}