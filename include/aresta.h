#ifndef ARESTA_H
#define ARESTA_H

#include <string>

class Vertice;

class Aresta {
    private:
        Vertice* destino;
        int custo;
    public:
        Aresta(Vertice* destino, int custo) : destino(destino), custo(custo) {}
        int getCusto() { return custo; }

};

#endif // ARESTA_H