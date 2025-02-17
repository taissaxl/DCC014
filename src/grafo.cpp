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

int Grafo::adicionarVertice() {
    Vertice* vertice = new Vertice(numVertices);
    vertices->adicionar(vertice);
    numVertices++;
    return numVertices - 1;
}

void Grafo::adicionarAresta(int idOrigem, int idDestino, int custo) {

    Vertice* origem = getVertice(idOrigem);
    Vertice* destino = getVertice(idDestino);

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

    if (vertices->getPrimeiro() == nullptr) return nullptr;

    for (Vertice* vertice : *vertices)
    {
        if (vertice->getId() == id) return vertice;
    }

    return nullptr;
}

int Grafo::getCustoEntreVertices(int origemId, int destinoId)
{
    Vertice* origem = getVertice(origemId);

    for (Aresta* aresta : *origem->getArestas())
    {
        if (aresta->getDestino() == getVertice(destinoId)) return aresta->getCusto();
    }

    return -1;
}
