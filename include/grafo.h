#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"

class Grafo {
    private:
        int numVertices;
        int numArestas;
        Lista<Vertice>* vertices;

    public:
        Grafo();
        ~Grafo();
        int adicionarVertice();
        void adicionarAresta(int idOrigem, int idDestino, int custo);
        int getCustoEntreVertices(int origemId, int destinoId);

        Vertice* getVertice(int id);
        void imprimirMatrizAdj();
        //int getNumVertices() { return numVertices; }
        //int getNumArestas() { return numArestas; }
        //Lista<Vertice>* getVertices() { return vertices; }
};

#endif // GRAFO_H