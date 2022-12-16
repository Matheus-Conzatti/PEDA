class No:
    def __init__(self, valor):
        self.valor = valor
        self.esq = None
        self.dir = None

    def mostraNo(self):
        print(self.valor)

class ArvoreBinariaBusca:
    def __init__(self):
        self.raiz = None
        self.ligacoes = []

    def inserir(self, valor):
        novo = No(valor)

        if self.raiz == None:
            self.raiz = novo
        else:
            atual = self.raiz
            while True:
                pai = atual

                if valor < atual.valor:
                    atual = atual.valor
                    if atual == None:
                        pai.esq = novo
                        self.ligacoes.append(str(pai.valor) + '->' + str(novo.valor))
                        return
                else:
                    atual = atual.dir
                    if atual == None:
                        pai.dir = novo
                        self.ligacoes.append(str(pai.valor) + '->' + str(novo.valor))
                        return
    
    def pesquisar(self, valor):
        atual = self.raiz
        while atual.valor != valor:
            if valor < atual.valor:
                atual = atual.esq
            else:
                atual = atual.dir

            if atual == None:
                return None
        return atual