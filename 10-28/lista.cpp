#include <iostream>
#include <string>

struct nodolista {
    std::string info;
    nodolista *elo;
};

struct lista {
    nodolista *inicio = nullptr, *fim = nullptr;
    unsigned tamanho = 0;
};

void lista_insere_fim(lista &l, std::string valor) {
    nodolista *novo = new nodolista;
    novo->info = valor;
    novo->elo = nullptr;
    if (l.inicio == nullptr) {
        l.inicio = l.fim = novo;
    } else {
        l.fim->elo = novo;
        l.fim = novo;
    }
    l.tamanho++;
}

void lista_mostra(lista l) {
    nodolista *p = l.inicio;
    while (p) {
        std::cout << p->info << std::endl;
        p = p->elo;
    }
}
