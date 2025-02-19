#ifndef ARESTA_H
#define ARESTA_H

#include <string>

class Vertice;

class Aresta {
    private:
        Vertice* destino;
        int custo;
    public:
        Aresta() : destino(nullptr), custo(0) {}
        Aresta(Vertice* destino, int custo) : destino(destino), custo(custo) {}
        int getCusto() const { return custo; }

        Vertice* getDestino() const {
            return destino;
        }

};

inline bool operator>(const Aresta& a1, const Aresta& a2) {
    return a1.getCusto() > a2.getCusto();
}

inline bool operator<(const Aresta& a1, const Aresta& a2) {
    return a1.getCusto() > a2.getCusto();
}

#endif // ARESTA_H