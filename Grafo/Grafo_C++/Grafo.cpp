#include <iostream>
#include <random>

using namespace std;
constexpr int MAXNOS = 100;

class Grafo{
public:
    Grafo(int num_nos);
    void une(int a, int b);
    void une(int a, int b, float p);
    void remv(int a, int b);
    bool adjacente(int a, int b) const;
    void imprime() const;
private:
    bool adj[MAXNOS][MAXNOS];
    float peso[MAXNOS][MAXNOS];
    int N;
    bool validos(int a, int b) const;
};

Grafo::Grafo(int num_nos){
    N = num_nos;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            adj[i][j];
        }
    }
}

bool Grafo::validos(int a, int b) const{
    return (a >= 0 && a < N && b >= 0 && b < N);
}

void Grafo::une(int a, int b){
    if(validos(a, b)){
        adj[a][b] = true;
    }
}

void Grafo::une(int a, int b, float p){
    if(validos(a, b)){
        adj[a][b] = true;
        peso[a][b] = p;
    }
}

void Grafo::remv(int a, int b){
    if(validos(a, b)){
        adj[a][b] = false;
    }
}

bool Grafo::adjacente(int a, int b) const{
    if(validos(a, b)){
        return adj[a][b];
    }else{
        return false;
    }
}

void Grafo::imprime() const{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << adj[i][j];
        }

        cout << endl;
    }
}


int main(){
    Grafo g(4);

    g.une(0, 1);
	g.une(0, 3);
	g.une(1, 3);
    g.une(1, 0);
    g.une(2, 1);
    g.une(2, 3);
	g.une(3, 2);
	g.une(3, 0);
  
    g.imprime();

    return 0;
}