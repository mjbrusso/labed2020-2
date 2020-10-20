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

    auto p = equal_range(nomes.begin(), nomes.end(), s);
    if (p.first == p.second)
        cout << "Não encontrou!\n";
    else {
        cout << "Encontrou " << distance(p.first, p.second) << " valores\n";
        nomes.erase(p.first, p.second);
    }
    for (auto nome : nomes)
        cout << nome << endl;
}
