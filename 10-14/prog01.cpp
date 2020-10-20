#include <iostream> 
#include <vector>

using namespace std;

int main() {
    vector<int> vet; // vetor dinâmico de ints, inicialmente vazio  

    cout << "Tamanho: " << vet.size() << endl;
    vet.push_back(10);
    vet.push_back(8);
    vet.push_back(75);
    vet.push_back(999);
    cout << "Tamanho: " << vet.size() << endl;
    
    cout << "Old school for\n";
    for(auto i=0; i<vet.size(); i++){
        cout << vet[i] << " ";
    }
    cout << endl;

    cout << "Usando iterator\n";
    // vector<int>::iterator it;
    for(auto it=vet.begin(); it!=vet.end(); ++it){
        cout << *it << " ";
    }
    
    cout << endl;

    cout << "Último: " << vet.back() << endl;
    vet.pop_back();
    cout << "Usando o range for\n";
    for(auto v: vet){
        cout << v << " ";
    }
    cout << endl;

    auto p = vet.begin() + (vet.size() / 2); // deleta do meio
    vet.erase(p);
    for(auto v: vet){
        cout << v << " ";
    }
    cout << endl;

    vet.clear();    
}


