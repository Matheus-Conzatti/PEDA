#include "Mapa.h"

Mapa::Mapa(){
  //Cria uma classe com zero NOS como cidade
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