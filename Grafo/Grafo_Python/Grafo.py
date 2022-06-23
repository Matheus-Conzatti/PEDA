class Vertice:
    def __init__(self, rotulo):
        self.rotulo = rotulo
        self.visitado = False
        self.adjacentes = []

    def adicionaAdjacente(self, adjacente):
        self.adjacentes.append(adjacente)

    def mostraAdjacentes(self):
        for i in self.adjacentes:
            print(i.vertice.rotulo, '->', i.custo)

class Adjacente:
    def __init__(self, vertice, custo):
        self.vertice = vertice
        self.custo = custo

class Grafo:
    arad      = Vertice('Arad')
    zerind    = Vertice('Zerind')
    oradea    = Vertice('Oradea')
    sibiu     = Vertice('Sibiu')
    timisoara = Vertice('Timisoara')
    lugoj     = Vertice('Lugoj')
    mehadia   = Vertice('Mehadia')
    dobreta   = Vertice('Dobreta')
    craiova   = Vertice('Craiova')
    rimnicu   = Vertice('Rimnicu')
    fagaras   = Vertice('Fagaras')
    pitesti   = Vertice('Pitesti')
    bucharest = Vertice('Bucharest')
    giurgiu   = Vertice('Giurgiu')

    arad.adicionaAdjacente(Adjacente(zerind, 75))
    arad.adicionaAdjacente(Adjacente(sibiu, 140))
    arad.adicionaAdjacente(Adjacente(timisoara, 118))

    zerind.adicionaAdjacente(Adjacente(arad, 75))
    zerind.adicionaAdjacente(Adjacente(sibiu, 71))

    oradea.adicionaAdjacente(Adjacente(zerind, 71))
    oradea.adicionaAdjacente(Adjacente(sibiu, 151))

    sibiu.adicionaAdjacente(Adjacente(oradea, 151))
    sibiu.adicionaAdjacente(Adjacente(arad, 140))
    sibiu.adicionaAdjacente(Adjacente(fagaras, 99))
    sibiu.adicionaAdjacente(Adjacente(rimnicu, 80))

    timisoara.adicionaAdjacente(Adjacente(arad, 118))
    timisoara.adicionaAdjacente(Adjacente(lugoj, 111))

    lugoj.adicionaAdjacente(Adjacente(timisoara, 111))
    lugoj.adicionaAdjacente(Adjacente(mehadia, 70))

    mehadia.adicionaAdjacente(Adjacente(lugoj, 70))
    mehadia.adicionaAdjacente(Adjacente(dobreta, 75))

    dobreta.adicionaAdjacente(Adjacente(mehadia, 75))
    dobreta.adicionaAdjacente(Adjacente(craiova, 120))

    craiova.adicionaAdjacente(Adjacente(dobreta, 120))
    craiova.adicionaAdjacente(Adjacente(pitesti, 138))
    craiova.adicionaAdjacente(Adjacente(rimnicu, 146))

    rimnicu.adicionaAdjacente(Adjacente(craiova, 146))
    rimnicu.adicionaAdjacente(Adjacente(sibiu, 80))
    rimnicu.adicionaAdjacente(Adjacente(pitesti, 97))

    fagaras.adicionaAdjacente(Adjacente(sibiu, 99))
    fagaras.adicionaAdjacente(Adjacente(bucharest, 211))

    pitesti.adicionaAdjacente(Adjacente(rimnicu, 97))
    pitesti.adicionaAdjacente(Adjacente(craiova, 138))
    pitesti.adicionaAdjacente(Adjacente(bucharest, 101))

    bucharest.adicionaAdjacente(Adjacente(fagaras, 211))
    bucharest.adicionaAdjacente(Adjacente(pitesti, 101))
    bucharest.adicionaAdjacente(Adjacente(giurgiu, 90))

g = Grafo()
g.arad.mostraAdjacentes()
g.bucharest.mostraAdjacentes()