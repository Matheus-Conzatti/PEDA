import time
import random
import statistics

class No:
    def __init__(self, chave, dir, esq):
        self.item = chave
        self.dir = dir
        self.esq = esq

class ArvoreBinaria:
    def __init__(self):
        self.root = No(None, None, None)
        self.root = None

    def inserir(self, v):
        novo = No(v, None, None)
        if self.root == None:
            self.root = novo
        else: 
            atual = self.root
            while True:
                anterior = atual
                if v <= atual.item: 
                    atual = atual.esq
                    if atual == None:
                        anterior.esq = novo
                        return
                else:
                    atual = atual.dir
                    if atual == None:
                        anterior.dir = novo
                        return
                
    
    def buscar(self, chave):
        if self.root == None:
            return None 
        atual = self.root 
        while atual.item != chave: 
            if chave < atual.item:
                atual = atual.esq 
            else:
                atual = atual.dir
            if atual == None:
                    return None 
        return atual   

    def Nosucessor(self, apaga):
        paidosucessor = apaga
        sucessor = apaga
        atual = apaga.dir 

        while atual != None:
            paidosucessor = sucessor
            sucessor = atual
            atual = atual.esq

        if sucessor != apaga.dir:
            paidosucessor.esq = sucessor.dir
            sucessor.dir = apaga.dir

        return sucessor
    
    def remove(self, v):
        if self.root == None:
            return False
        
        atual = self.root
        pai = self.root
        filhoEsq = True

        while atual.item != v:
            pai = atual
            if v < atual.item:
                atual = atual.esq
                filhoEsq = True
            else:
                atual = atual.dir
                filhoEsq = False

            if atual == None:
                return False
            
        if atual.esq == None and atual.dir == None:
            if atual == self.root:
                self.root = None
            else:
                if filhoEsq:
                    pai.esq = None
                else:
                    pai.dir = None
        elif atual.dir == None:
            if atual == self.root:
                    self.root = atual.esq
            else:
                if filhoEsq:
                    pai.esq = atual.esq
                else:
                    pai.dir = atual.esq
        elif atual.esq == None:
            if atual == self.root:
                self.root = atual.dir 
            else:
                if filhoEsq:
                    pai.esq = atual.dir 
                else:
                    pai.dir = atual.dir
        else:
            sucessor = self.Nosucessor(atual)

            if atual == self.root:
                self.root = sucessor 
            else:
                if filhoEsq:
                    pai.esq = sucessor 
                else:
                    pai.dir = sucessor
            sucessor.esq = atual.esq 

        return True
    
arvore = ArvoreBinaria()
print('Arvore Binaria')

listaNumerosAleatorios = []

tempos = []

for i in range(0, 100):
    listaNumerosAleatorios = []
    for i in range(0, 1000):
        numAleatorio = random.randint(0, 100000)
        listaNumerosAleatorios.append(numAleatorio)
        arvore.inserir(numAleatorio)  

    tempoInicial = time.time()

    x = random.randint(0, 100000)
    busca = arvore.buscar(x)
    if busca:
        print('Valor digitado ', x, ' foi encontrado na arvore!')
    else:
        print('Valor digitado', x, ' não foi encontrado na arvore!')

    tempoFinal = time.time()

    tempoMedio = tempoFinal - tempoInicial
    tempos.append(tempoMedio)

media = statistics.mean(tempos)
desvio_padrao = statistics.stdev(tempos)

print('Tempo médio da busca:', media)
print('Desvio padrão dos tempos de busca:', desvio_padrao)
