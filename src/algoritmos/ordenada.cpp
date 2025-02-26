#include "algoritmos/ordenada.h"
#include "heapMin.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "grafo.h"
#include <unordered_map>
#include <unordered_set>

#define CAPACIDADE 20


Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino) {
    FilaOrdenada fila(idDestino, idOrigem, grafo);

    // Explore nodes until destination is found or heap is empty
    while (fila.exploraMenorAberto()) {}

    return fila.reconstruirCaminho();
}