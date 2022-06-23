#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using TipoDado = int;

const int MAXPILHA = 10;
const int MAXFILA = 10;
const int TAM = 1000;

class Pilha{
private:
    array<TipoDado, MAXPILHA> dados;
    int topo_;
public:
    Pilha();
    void push(TipoDado);
    void pop();
    TipoDado topo();
    bool vazia();
    bool cheia();
};

class Fila{
private:
    TipoDado dados[MAXFILA];
    int frente_;
    int fim;

public:
    Fila();
    void insere(TipoDado elemento);
    TipoDado frente();
    void remove();
    bool vazia();
    bool cheia();
};

int main(){
    Pilha p;
    Fila f;

    double Tempo;
    clock_t Ticks[2];
    int igual, vetor[TAM];
    int somaPilha = 0, somaFila = 0;

    srand(time(NULL));
    //------------------- PILHA -------------------------------//
    Ticks[0] = clock();
    cout << "Pilha: ";
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % TAM + 1;
        p.push(vetor[i]);
        cout << "[" << p.topo() << "],";
        p.pop();//Remove o 1° da pilha 
        somaPilha = somaPilha + vetor[i];
    }

    cout << endl;
    p.push(somaPilha);

    Ticks[1] = clock();
    Tempo = double(Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC; //Faz a medição do tempo
    cout << "Tempo: " << Tempo << endl;
    cout << "Soma Pilha: " << p.topo() << endl;
    cout << endl;

    //----------------FILA-------------------------//
    Ticks[0] = clock();
    cout << "Fila:";    
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % TAM+1; 
        f.insere(vetor[i]); //Adiciona o numero aleátorios na fila.
        cout << "[" << f.frente() << "],";
        f.remove(); //Remove o 1° da fila     
        somaFila = somaFila + vetor[i];
    }

    cout << endl;

    f.insere(somaFila);

    Ticks[1] = clock();
    Tempo = double(Ticks[1] - Ticks[0])*1000 / CLOCKS_PER_SEC;//Faz a medição do tempo.
    cout << "Tempo: " << Tempo << " Segundos" << endl;
    cout << "Soma Fila: " << f.frente() << endl;
}

//Começo da Pilha
Pilha::Pilha(){
    topo_ = -1;
}

void Pilha::push(TipoDado elem){
    if (!cheia()){
        ++topo_;
        dados[topo_] = elem;
    }else{
        cerr << "Pilha cheia!" << endl;
    }
}

void Pilha::pop(){
    if (!vazia()){
        --topo_;
    }else{
        cerr << "Pilha esta vazio" << endl;
    }
}

TipoDado Pilha::topo(){
    if (!vazia()){
        return dados[topo_];
    }else{
        cerr << "Pilha vazia!" << endl;
        return -1;
    }
}

bool Pilha::vazia(){
    if (topo_ == -1){
        return true;
    }else{
        return false;
    }
}

bool Pilha::cheia(){
    return topo_ == MAXPILHA - 1;
}

//Começo da Fila
int prox(int i){
    return (i + 1) % MAXFILA;
}

Fila::Fila(){
    frente_ = fim = MAXFILA - 1;
}

void Fila::insere(TipoDado elemento){
    if (!cheia()){
        fim = prox(fim);
        dados[fim] = elemento;
    }else
        cerr << "Fila cheia" << endl;
}

TipoDado Fila::frente(){
    if (vazia()){
        cerr << "Fila vazia!" << endl;
        return -1;
    }else
        return dados[prox(frente_)];
}

void Fila::remove(){
    if (!vazia()){
        frente_ = prox(frente_);
    }
}

bool Fila::vazia(){
    return (frente_ == fim);
}

bool Fila::cheia(){
    return (frente_ == prox(fim));
}