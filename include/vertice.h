#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

class Vertice {
    private:
        int id;
        Lista<Aresta> *arestas;
    public:
        Vertice(int id) : id(id) {
            this->arestas = new Lista<Aresta>();
        } 
};
