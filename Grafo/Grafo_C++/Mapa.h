#ifndef MAPA_H
#define MAPA_H
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

#endif