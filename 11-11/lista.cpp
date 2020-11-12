#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

struct contato {
    string nome, email, fone;
};

int menu() {
    cout << "1: Novo contato\n"
         << "2: Consultar\n"
         << "3: Excluir\n"
         << "4: Listar\n"
         << "5: Salvar\n"
         << "0: Sair\n"
         << "Selecione uma opção: ";
    int opcao;
    cin >> opcao;
    cin.ignore();
    return opcao;
}

void novo_contato(list<contato> &lista) {
    contato aux;

    cout << "Nome  : ";
    getline(cin, aux.nome);
    cout << "e-Mail: ";
    getline(cin, aux.email);
    cout << "Fone  : ";
    getline(cin, aux.fone);
    if (lista.empty() || lista.front().nome > aux.nome)
        lista.push_front(aux);
    else if (lista.back().nome < aux.nome)
        lista.push_back(aux);
    else {
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->nome >= aux.nome) {
                lista.insert(it, aux);
                break;
            }
        }
    }
}

void listar_contatos(const list<contato> &lista) {
    cout << setw(40) << left << "Nome" << ' '
         << setw(40) << left << "e-Mail" << ' '
         << setw(30) << left << "Telefone" << endl;

    for (auto c : lista) {
        cout << setw(40) << left << c.nome << ' '
             << setw(40) << left << c.email << ' '
             << setw(30) << left << c.fone << endl;
    }
    cout << lista.size() << " contatos cadastrados\n\n";
}

void salvar_lista(const list<contato> &lista) {
    ofstream arq("contatos.txt");
    for (auto c : lista) {
        arq << c.nome << '\n'
            << c.email << '\n'
            << c.fone << '\n';
    }
    arq.close();
}

void carregar_lista(list<contato> &lista) {
    ifstream arq("contatos.txt");
    if(!arq) return;
    contato aux;
    while(getline(arq, aux.nome) && getline(arq, aux.email) && getline(arq, aux.fone)){
        lista.push_back(aux);
    }
}

void consulta_contato(const list<contato> &lista){
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    for (auto c : lista){
        if(c.nome == nome){
            cout << "e-Mail: " << c.email << endl
                 << "Fone  : " << c.fone  << endl << endl;

            return;
        } 
        if(c.nome > nome) break;
    }
    cout << "Não encontrado!\n\n";
}

void excluir_contato(list<contato> &lista){
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    for(auto it=lista.begin(); it!=lista.end(); ++it){
        if(it->nome == nome){
            lista.erase(it);
            cout << "Excluido com sucesso\n\n";
            return;
        }
        if(it->nome > nome) break;
    }
    cout << "Não encontrado!\n\n";
}

int main() {
    list<contato> lista;
    carregar_lista(lista);

    int op;
    while ((op = menu()) != 0) {
        switch (op) {
            case 1:
                novo_contato(lista);
                break;
            case 2:  
                consulta_contato(lista);
                break;
            case 3:  
                excluir_contato(lista);
                break;
            case 4:
                listar_contatos(lista);
                break;
            case 5:
                salvar_lista(lista);
                break;
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }
    
    salvar_lista(lista);
    return 0;
}