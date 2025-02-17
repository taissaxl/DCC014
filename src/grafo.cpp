#include "lista.h"
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

Grafo::Grafo() {
    numVertices = 0;
    numArestas = 0;
    vertices = new Lista<Vertice>();
}

Grafo::~Grafo() {
    delete vertices;
}

void Grafo::adicionarVertice(Vertice* vertice) {
    vertices->adicionar(vertice);
    numVertices++;
}

void Grafo::adicionarAresta(Vertice* origem, Vertice* destino, int custo) {

    if (origem->getId() == destino->getId()) {
        return;
    }

    if (origem->isVerticeAdjacente(destino)) {
        return;
    }

    Aresta* aresta = new Aresta(destino, custo);
    origem->adicionarAresta(aresta);

    aresta = new Aresta(origem, custo);
    destino->adicionarAresta(aresta);

    numArestas++;
    
}

Vertice* Grafo::getVertice(int id) {

    if (vertices->getPrimeiro() == nullptr) return;

    Vertice *vAtual = vertices->getPrimeiro();

    while (vAtual != nullptr)
    {
        if (vAtual->getId() == id) return vAtual;

        vAtual = vertices->getProximo();
    }

    return;
}
