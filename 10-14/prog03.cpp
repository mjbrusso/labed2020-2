#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<string> nomes;
    string s;

    cout << "Digite nomes [ENTER para finalizar]\n";
    while (getline(cin, s) && s != "") {
        nomes.push_back(s);
    }

    sort(nomes.begin(), nomes.end());

    for (auto nome : nomes)
        cout << nome << endl;

    cout << "Pesquisar: ";
    getline(cin, s);

    bool achou = binary_search(nomes.begin(), nomes.end(), s);
    if (achou)
        cout << "Encontrou\n";
    else
        cout << "Não Encontrou\n";
}
