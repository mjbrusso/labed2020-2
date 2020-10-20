#include <iostream> 
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    vector<string> nomes;
    string s;

    cout << "Digite nomes [ENTER para finalizar]\n";
    while(getline(cin, s) && s!=""){
        nomes.push_back(s);
    }
    //for(auto nome: nomes)
    //    cout << nome << endl;
        
    cout << "Pesquisar: ";
    getline(cin, s);
    auto it = find(nomes.begin(), nomes.end(), s);
    if(it==nomes.end())
        cout << "Não encontrou\n";
    else
        cout << "Encontrou no índice " << distance(nomes.begin(), it) << endl;
}


