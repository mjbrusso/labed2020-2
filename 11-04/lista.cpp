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

// Esta função deve testar se os valores armazenados na lista encadeada l
//    estão ordenados em ordem alfabética crescente.
// Considerar que uma lista vazia ou com um único nodo está ordenada.
bool lista_esta_ordenada(lista l)
{
    if(l.tamanho < 2) return true;
    nodolista *it = l.inicio;

    while(it->elo != nullptr){
        if(it->info > it->elo->info) return false;
        it = it->elo;
    }
    return true;
}


// Esta função deve verificar se duas listas encadeadas passadas por parâmetro (l1 e l2) são iguais.
// Duas  listas  são  consideradas  iguais  se  têm  o mesmo tamanho e
// exatamente a  mesma  sequência  de  valores (info), ou se ambas estão vazias.
// A função deve retornar true, caso as listas sejam iguais, ou false em caso contrário.
bool lista_igual(lista l1, lista l2)
{
    if(l1.tamanho != l2.tamanho) return false;

    nodolista *it1 = l1.inicio, *it2 = l2.inicio;
    while(it1 != nullptr){
        if(it1->info != it2->info) return false;
        it1 = it1->elo;
        it2 = it2->elo;
    }
    return true;
}