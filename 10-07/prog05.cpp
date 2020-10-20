#include <iostream>

using namespace std;

int main() {
    double *pd;

    pd = new double;
    *pd = 3.1415;
    cout << *pd << endl;
    delete pd;
}







