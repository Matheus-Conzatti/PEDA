import numpy as np
import time

class Pilha:
    def __init__(self, capacidade):
        self.capacidade = capacidade
        self.topo = -1
        self.valores = np.empty(self.capacidade, dtype=int)

    def pilhaCheia(self):
        return self.topo == self.capacidade - 1
        
    def pilhaVazia(self):
        return self.topo == -1
    
    def empilhar(self, valor):
        if self.pilhaCheia():
            print('A pilha está cheia!')
        else:
            self.topo += 1
            self.valores[self.topo] = valor
    
    def desempilhar(self):
        if self.pilhaVazia():
            print('A pilha está vazia!')
            return -1
        else:
            valor = self.valores[self.topo]
            self.topo -= 1
            return valor

class Fila:
    def __init__(self, capacidadeFila):
        self.capacidadeFila = capacidadeFila
        self.frente = 0
        self.rear = -1
        self.numElementos = 0
        self.valoresFilas = np.empty(self.capacidadeFila, dtype=int)

    def filaCheia(self):
        return self.numElementos == self.capacidadeFila
    
    def filaVazia(self):
        return self.numElementos == 0
    
    def enfileirar(self, valorFila):
        if self.filaCheia():
            print('A fila está cheia!')
        else:
            self.rear = (self.rear + 1) % self.capacidadeFila
            self.valoresFilas[self.rear] = valorFila
            self.numElementos += 1
    
    def desenfileirar(self):
        if self.filaVazia():
            print('A fila está vazia!')
            return -1
        else:
            valor = self.valoresFilas[self.frente]
            self.frente = (self.frente + 1) % self.capacidadeFila
            self.numElementos -= 1
            return valor

# Função para somar números inteiros de 1 a 1000
def somarInteiros(estrutura):
    for i in range(1, 1001):
        if isinstance(estrutura, Pilha):
            if not estrutura.pilhaCheia():
                estrutura.empilhar(i)
        else:
            if not estrutura.filaCheia():
                estrutura.enfileirar(i)

    soma = 0
    while True:
        if isinstance(estrutura, Pilha):
            if estrutura.pilhaVazia():
                break
            soma += estrutura.desempilhar()
        else:
            if estrutura.filaVazia():
                break
            soma += estrutura.desenfileirar()

    return soma

# Testando o tempo para fazer a soma, usando a classe Pilha
pilha = Pilha(1000)
inicioPilha = time.time()
somaPilha = somarInteiros(pilha)
fimPilha = time.time()
tempoPilha = fimPilha - inicioPilha

# Testando o tempo para fazer a soma, usando a classe Fila
fila = Fila(1000)
inicioFila = time.time()
somaFila = somarInteiros(fila)
fimFila = time.time()
tempoFila = fimFila - inicioFila

print("Soma usando Pilha:", somaPilha)
print("Tempo para somar usando Pilha:", round(tempoPilha, 4), "segundos")
print("\n")
print("Soma usando Fila:", somaFila)
print("Tempo para somar usando Fila:", round(tempoFila, 4), "segundos")
