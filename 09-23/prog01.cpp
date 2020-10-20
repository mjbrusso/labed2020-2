#include <iostream>
#include <algorithm>

using namespace std;

bool compara(float a, float b){
    return a>b;
}

int main() {
    float vet[] = {1.5, 0.4, 8.9, 3.3, 10.1};
    
    sort(vet, vet+5, compara);
    for(auto f: vet){
        cout << f << endl;
    }
    return 0;
}

