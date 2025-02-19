#include <iostream>
#include "grafo.h"

int main (int argc, char *argv[]) {
    Grafo* grafo = new Grafo();

    int idOrigem = grafo->adicionarVertice();
    int idSaidaEsquerda = grafo->adicionarVertice();
    int idSaidaDireita = grafo->adicionarVertice();

    grafo->adicionarAresta(idOrigem, idSaidaEsquerda, 3);
    grafo->adicionarAresta(idOrigem, idSaidaDireita, 2);

    grafo->imprimirMatrizAdj();
    return 0;
}
