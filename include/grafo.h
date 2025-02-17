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
        void adicionarVertice(Vertice* vertice);
        void adicionarAresta(Vertice* origem, Vertice* destino, int custo);

        Vertice* getVertice(int id);
        //void imprimirGrafo();
        //int getNumVertices() { return numVertices; }
        //int getNumArestas() { return numArestas; }
        //Lista<Vertice>* getVertices() { return vertices; }
};

#endif // GRAFO_H