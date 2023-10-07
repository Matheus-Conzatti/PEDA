#include <iostream>
#include <vector>
#include <string>

using namespace std;
constexpr int MAXNOS = 15;
constexpr int INFINITO = 1000000;

class Mapa{
  public:
    Mapa();
    void addCidade(string nomeCidade);
    void une(string cidadeA, string cidadeB, float distancia);
    void menorCaminho(string cidadeA, string cidadeB);

  private:
    int N;
    string cidades[MAXNOS];
    bool adj[MAXNOS][MAXNOS];
    float peso[MAXNOS][MAXNOS];
    int indiceCidade(string nomeCidade);
    float distanciaCidade(int corrente, int i);
    bool validos(int a, int b);
};

Mapa::Mapa(){
  N = 0;

  for(int i = 0; i < MAXNOS; ++i){
    for(int j = 0; j < MAXNOS; ++j){
      adj[i][j] = false;
      peso[i][j] = INFINITO;
    }
  }
}

int Mapa::indiceCidade(string nomeCidade){
  for(int i = 0; i < N; ++i){
    if(cidades[i] == nomeCidade)
      return i;
  }

  return -1;
}

bool Mapa::validos(int a, int b){
  return (a > -1 && a < MAXNOS && b > -1 && b < MAXNOS);
}

void Mapa::addCidade(string nomeCidade){
  if(N < MAXNOS){
    cidades[N] = nomeCidade;
    ++N;
  }else
    cerr << "Numeros maximo atingindo!" << endl;
}

void Mapa::une(string cidadeA, string cidadeB, float distancia){
  if(N > 0){
    int a = indiceCidade(cidadeA);
    int b = indiceCidade(cidadeB);

    if(validos(a, b)){
      adj[a][b] = adj[b][a] = true;
      peso[a][b] = peso[b][a] = distancia;
    }
  }
}

float Mapa::distanciaCidade(int atual, int i){
  if(validos(atual, i)){
    if(adj[i][atual])
      return peso[i][atual];
  }else
    return INFINITO;
}

void Mapa::menorCaminho(string cidadeA, string cidadeB){
  int s = indiceCidade(cidadeA);
  int t = indiceCidade(cidadeB);
  int precede[MAXNOS] = {s};
  string menorCaminho[MAXNOS];
  float distancia[MAXNOS];
  bool calculado[MAXNOS];

  for(int i = 0; i < N; ++i){
    distancia[i] = INFINITO;
    calculado[i] = false;
  }

  distancia[s] = 0;
  calculado[s] = true;

  int atual = s;
  while(atual != t){
    float menorDist = INFINITO;
    int k = 0;
    float dc = distancia[atual];
    for(int i = 0; i < N; ++i){
      if(!calculado[i]){
        float novaDist = dc + distanciaCidade(atual, i);
        if(novaDist < distancia[i]){
          distancia[i] = novaDist;
          precede[i] = atual;
        }

        if(distancia[i] < menorDist){
          menorDist = distancia[i];
          k = i;
        }
      }
    }
    atual = k;
    calculado[atual] = true;
  }

  string caminho = cidades[t];
  int caminhoInt = t;
  int cont = 0;

  while(caminho != cidadeA){
    menorCaminho[cont] = caminho;
    caminho = cidades[precede[caminhoInt]];
    caminhoInt = indiceCidade(caminho);
    ++cont;
  }

  for(int i = 0, j = cont - 1; i < cont / 2; i++, j++){
    string temp = menorCaminho[i];
    menorCaminho[i] = menorCaminho[j];
    menorCaminho[j] = temp;
  }

  cout << "Menor Distancia: " << distancia[t] << "Km" << endl;
  cout << "Menor Caminho: ";
  cout << cidadeA << " -> ";
  for(int i = 0; i < cont; i++){
    cout << menorCaminho[i];
    if(i != cont - 1)
      cout << " -> ";
  }
}

int main(){
  Mapa m;

  m.addCidade("Arad");
  m.addCidade("Zerind");
  m.addCidade("Oradea");
  m.addCidade("Sibiu");
  m.addCidade("Timisoara");
  m.addCidade("Lugoj");
  m.addCidade("Mehadia");
  m.addCidade("Dobreta");
  m.addCidade("Craiova");
  m.addCidade("Rimnicu");
  m.addCidade("Fagaras");
  m.addCidade("Pitesti");
  m.addCidade("Bucharest");
  m.addCidade("Giurgiu");

  m.une("Arad", "Zerind", 271.0);
  m.une("Arad", "Oradea", 310.0);
  m.une("Oradea", "Zerind", 174.0);
  m.une("Oradea", "Sibiu", 208.0);
  m.une("Sibiu", "Timisoara", 342.0);
  m.une("Sibiu", "Lugoj", 114.0);
  m.une("Lugoj", "Mehadia", 115.0);
  m.une("Lugoj", "Sibiu", 132.0);
  m.une("Mehadia", "Dobreta", 221.2);
  m.une("Mehadia", "Craiova", 185.9);
  m.une("Mehadia", "Rimnicu", 155.0);
  m.une("Craviova", "Fagaras", 143.0);
  m.une("Craviova", "Mehadia", 165.0);
  m.une("Fagaras", "Rimnicu", 136.0);
  m.une("Fagaras", "Pitesti", 209.0);
  m.une("Fagaras", "Bucharest", 271.0);
  m.une("Fagaras", "Craviova", 349.0);
  m.une("Pitesti", "Bucharest", 223.0);
  m.une("Buchasrest", "Pitesti", 231.0);
  m.une("Buchasrest", "Giurgiu", 102.0);
  m.une("Rimnicu", "Fagasras", 52.3);

  string cidadeA, cidadeB;

  cout << "Cidade A: ";
  getline(cin, cidadeA);
  cout << "Cidade B: ";
  getline(cin, cidadeB);
  cout << endl;
  m.menorCaminho(cidadeA, cidadeB);
  cout << endl;

  return 0;
}