#include "algoritmos/ordenada.h"
#include "grafo.h"
#include "vertice.h"
#include "lista.h"

#define CAPACIDADE 20
Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino) {
    if (grafo->getVertice(idOrigem) == nullptr || grafo->getVertice(idDestino) == nullptr) {
        throw std::runtime_error("Vertice não encontrado");
    }
    Fila fila(idDestino, idOrigem, grafo);

    while (fila.exploraMenorAberto()) {}

    return fila.reconstruirCaminho();
}
