#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include "lista.h"
#include "aresta.h"
#include "no.h"

template <typename T>
class Lista;

class Aresta;

class Vertice {
    private:
        int id;
        Lista<Aresta>* arestas;
    public:
        Vertice(int id) : id(id), arestas(new Lista<Aresta>()) {}
        ~Vertice() {
            delete arestas;
        }
        int getId() { return id; }
        void adicionarAresta(Aresta* aresta) { arestas->adicionar(aresta); }

        bool isVerticeAdjacente(Vertice* vertice) {
            for (Aresta* aresta : *arestas)
            {
                if (aresta->getDestino() == vertice) return true;
            }

            return false;
        }

        Lista<Aresta>* getArestas() { return arestas; }

};

#endif // VERTICE_H