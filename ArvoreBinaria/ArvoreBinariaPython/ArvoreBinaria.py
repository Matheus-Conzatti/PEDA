import random
import time
import statistics

class Node:
    def __init__(self, chave):
        self.chave = chave
        self.esq = None
        self.dir = None

class ArvoreBinaria:
    def __init__(self):
        self.root = None

    def inserir(self, chave):
        self.root = self._inserir(self.root, chave)

    def _inserir(self, root, chave):
        if root is None:
            return Node(chave)

        if chave < root.chave:
            root.esq = self._inserir(root.esq, chave)
        elif chave > root.chave:
            root.dir = self._inserir(root.dir, chave)

        return root

    def mostrarOrdem(self, root):
        if root:
            self.mostrarOrdem(root.esq)
            print(root.chave, end=' ')
            self.mostrarOrdem(root.dir)

    def mostrarArvore(self):
        self.mostrarOrdem(self.root)
        print()

    def busca(self, chave):
        return self._busca(self.root, chave)

    def _busca(self, root, chave):
        if root is None or root.chave == chave:
            return root

        if chave < root.chave:
            return self._busca(root.esq, chave)
        else:
            return self._busca(root.dir, chave)

#Função para medir o tempo de construção da árvore
def medirTempo(valores):
    start_time = time.time()

    tree = ArvoreBinaria()
    for valor in valores:
        tree.inserir(valor)

    end_time = time.time()
    tempo_execucao = end_time - start_time

    return tree, tempo_execucao

#Criar uma lista com 10.000 números aleatórios
dados = random.sample(range(1, 100001), 10000)

#Medir o tempo de construção da árvore
arvore, tempoConstrucao = medirTempo(dados)

#Mostrar os números da árvore
print("Números na árvore:")
arvore.mostrarArvore()

#Exibir o tempo de construção da árvore
print(f"Tempo de construção da árvore: {tempoConstrucao:.3f} segundos")

#Solicitar ao usuário que digite um número para verificar se está na árvore
while True:
    try:
        numero = int(input("Digite um número para verificar se está na árvore (ou digite '0' para sair): "))
        if numero == 0:
            break

        resultado_busca = arvore.busca(numero)

        if resultado_busca is not None:
            print(f"O número {numero} está presente na árvore.")
        else:
            print(f"O número {numero} não está presente na árvore.")

    except ValueError:
        print("Por favor, digite um número inteiro.")