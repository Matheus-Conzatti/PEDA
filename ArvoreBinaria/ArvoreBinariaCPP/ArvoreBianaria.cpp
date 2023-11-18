#include <iostream>
#include <time.h>
#include <iomanip>

//Nome: Matheus Conzatti de Souza Turma: Engenharia de Computação 

using namespace std;
using TipoDado = int;

struct No{
    TipoDado info;
    No *pai;
    No *esq;
    No *dir;
};

class ArvBin{
protected:
    No *raiz;

protected:
    TipoDado info(No *p);
    No *esq(No *p);
    No *dir(No *p);
    No *pai(No *p);
    No *irmao(No *p);
    bool eh_esq(No *p);
    bool eh_dir(No *p);
    void cria_no_esq(No *pai, TipoDado x);
    void cria_no_dir(No *pai, TipoDado x);
    void adiciona(No *r, TipoDado x); // Adiciona recursivo
    void percorre(No *r);             // Percorre recursivo
public:
    ArvBin();  // Constrói árvore binária vaiza
    ~ArvBin(); // Libera memória utilizada pelos nós
    void limpa(No *r);
    void adiciona(TipoDado x); // cria nova árvore ou adiciona á existente
    void percorre();
    No* buscador(No *raiz, int num);
};

TipoDado ArvBin::info(No *p){
    return p -> info;
}

No *ArvBin::esq(No *p){
    return p -> esq;
}

No *ArvBin::dir(No *p){
    return p -> dir;
}

No *ArvBin::pai(No *p){
    return p->pai;
}

No *ArvBin::irmao(No *p){
    if (p == raiz)
        return nullptr;
    else
    {
        if (eh_esq(p))
            return dir(pai(p));
        else
            return esq(pai(p));
    }
}

bool ArvBin::eh_esq(No *p){
    if (p == raiz)
        return false;
    else
        return (esq(pai(p)) == p);
}

bool ArvBin::eh_dir(No *p){
    if (p == raiz)
        return false;
    else
        return (dir(pai(p)) == p);
}

void ArvBin::cria_no_esq(No *pai, TipoDado x){
    if (esq(pai) == nullptr)
    {
        No *novono = new No;
        novono->info = x;
        novono->pai = pai;
        novono->esq = novono->dir = nullptr;
        pai->esq = novono;
    }
}

void ArvBin::cria_no_dir(No *pai, TipoDado x){
    if (dir(pai) == nullptr)
    {
        No *novono = new No;
        novono->info = x;
        novono->pai = pai;
        novono->esq = novono->dir = nullptr;
        pai->dir = novono;
    }
}

void ArvBin::adiciona(No *r, TipoDado x){
    if (x == info(r))
        cout << "Repetido!" << endl;
    else if (x < info(r))
    {
        if (esq(r) == nullptr)
            cria_no_esq(r, x);
        else
            adiciona(esq(r), x);
    }
    else
    {
        if (dir(r) == nullptr)
            cria_no_dir(r, x);
        else
            adiciona(dir(r), x);
    }
}

void ArvBin::percorre(No *r){
    if (r != nullptr)
    {
        percorre(esq(r));
        cout << info(r) << endl; // Visitar a raiz
        percorre(dir(r));
    }
}

ArvBin::ArvBin(){
    raiz = nullptr;
}

ArvBin::~ArvBin(){
    limpa(raiz);
}

void ArvBin::limpa(No *r){
    if (r != nullptr)
    {
        percorre(esq(r));
        percorre(dir(r));
        delete r;
    }
}

void ArvBin::adiciona(TipoDado x){
    if (raiz == nullptr){
        raiz = new No;
        raiz->info = x;
        raiz->pai = nullptr;
        raiz->esq = raiz->dir = nullptr;
    }
    else{
        adiciona(raiz, x);
    }
}

void ArvBin::percorre(){
    percorre(raiz);
}

No* ArvBin::buscador(No *raiz, int num){
    while(raiz){
        if(num < raiz -> info){
            raiz = raiz -> esq;
        }else if(num > raiz -> info){
            raiz = raiz -> dir;
        }else{
            return raiz;
        }
    }

    return NULL;
}


int main(){
    ArvBin ab;
    int valor;
    No *raiz = NULL;
    No *busca = NULL;
    clock_t end, start;

    start = clock();
    for (int i = 1; i < 10000; i++){
        cout << rand() << endl;
    }
    
    ab.adiciona(rand());
    ab.percorre();
    end = clock();

    cout << "Tempo: " << 1000 * (double)(end-start)/(double)(CLOCKS_PER_SEC) / 1000 << " segundos"<< endl;

    cout << "----------------------------------" << endl;
    cout << endl;

    cout << "Digite um valor inteiro: ";
    cin >> valor;

    busca = ab.buscador(raiz, valor);
    if (busca){
        cout << "Valor Encontrado!" << busca -> info << endl;
    }else{
        cout << "Valor nao encontrado!" << endl;
    }
    cout << "----------------------------------" << endl;
    return 0;
}