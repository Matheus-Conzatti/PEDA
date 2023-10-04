#include <iostream>
#include "Mapa.h"

using namespace std;

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
  m.une("", "", 115.0);
  m.une("", "", 132.0);
  m.une("", "", 221.2);
  m.une("", "", 185.9);
  m.une("", "", 155.0);
  m.une("", "", 143.0);
  m.une("", "", 165.0);
  m.une("", "", 136.0);
  m.une("", "", 209.0);
  m.une("", "", 271.0);
  m.une("", "", 349.0);
  m.une("", "", 223.0);
  m.une("", "", 231.0);
  m.une("", "", 102.0);
  m.une("", "", 52.3);
  m.une("", "", 86.2);

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