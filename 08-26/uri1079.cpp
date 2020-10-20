#include <iostream>
#include <iomanip> // formatação da saída

using namespace std;

int main()
{
    int n;
 
    cin >> n;
    while(n>0){
        double a, b, c;
        cin >> a >> b >> c;
        double mp = (a*2 + b*3 + c*5) / 10;
        cout << fixed << setprecision(1) << mp << endl;
        n--;
    }
    return 0;
}