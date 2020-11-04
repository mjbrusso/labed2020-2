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

// Operações para lista não ordenada
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

void lista_insere_inicio(lista &l, std::string s) {
    nodolista *novo = new nodolista;

    novo->info = s;
    novo->elo = l.inicio;
    l.inicio = novo;
    if (l.fim == nullptr) l.fim = novo;
    l.tamanho++;
}

bool lista_consulta(lista l, std::string s) {
    nodolista *aux = l.inicio;
    while (aux != nullptr) {
        if (aux->info == s) return true;
        aux = aux->elo;
    }
    return false;
}

bool lista_retira(lista &l, std::string valor) {
    nodolista *ant = nullptr, *it = l.inicio;

    while (it != nullptr) {
        if (it->info == valor) break;
        ant = it;
        it = it->elo;
    }

    if (it == nullptr) return false;

    if (it == l.inicio && it == l.fim)  // ÚNICA
        l.inicio = l.fim = nullptr;
    else if (it == l.inicio)  // INÍCIO
        l.inicio = it->elo;
    else if (it == l.fim)  // FIM
    {
        ant->elo = NULL;
        l.fim = ant;
    } else
        ant->elo = it->elo;  // INTERMEDIÁRIA

    l.tamanho--;
    delete it;
    return true;
}

// Operações para lista ordenada
void lista_ordenada_insere(lista &lo, std::string valor) {
    nodolista *novo, *ant, *post;
    novo = new nodolista;

    novo->info = valor;

    if (lo.inicio == nullptr) {  // UNICA

        novo->elo = nullptr;
        lo.inicio = lo.fim = novo;
    } else if (valor >= lo.fim->info) {  // FIM
        novo->elo = nullptr;
        lo.fim->elo = novo;
        lo.fim = novo;
    } else if (valor <= lo.inicio->info)  // INICIO
    {
        novo->elo = lo.inicio;
        lo.inicio = novo;
    } else {  // INTERMEDIARIO
        ant = lo.inicio;
        post = lo.inicio->elo;
        while (true) {
            if (valor <= post->info) break;
            ant = post;
            post = post->elo;
        }
        ant->elo = novo;
        novo->elo = post;
    }

    lo.tamanho++;
}

bool lista_ordenada_consulta(lista l, std::string valor) {
    nodolista *it = l.inicio;
    while (it != nullptr) {
        if (it->info == valor) return true;
        if (valor < it->info) return false;
        it = it->elo;
    }
    return false;
}

bool lista_ordenada_retira(lista &l, std::string valor) {
    nodolista *ant = nullptr, *it = l.inicio;

    while (it != nullptr) {
        if (it->info == valor) break;
        if (valor < it->info )  return false;
        ant = it;
        it = it->elo;
    }

    if (it == nullptr) return false;

    if (it == l.inicio && it == l.fim)  // ÚNICA
        l.inicio = l.fim = nullptr;
    else if (it == l.inicio)  // INÍCIO
        l.inicio = it->elo;
    else if (it == l.fim)  // FIM
    {
        ant->elo = NULL;
        l.fim = ant;
    } else
        ant->elo = it->elo;  // INTERMEDIÁRIA

    l.tamanho--;
    delete it;
    return true;
}