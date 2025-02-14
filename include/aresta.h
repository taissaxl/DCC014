#ifndef ARESTA_H
#define ARESTA_H

#include <string>

class Aresta {
    private:
        no destino;
        int custo;
    public:
        Aresta(no destino, int custo) : destino(destino), custo(custo) {}
        int getCusto() { return custo; }

};