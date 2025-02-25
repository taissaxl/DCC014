#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "lista.h"
#include "vertice.h"
#include "grafo.h"

// Declara a função de busca por backtracking (DFS recursivo)
Lista<Vertice> buscaBacktracking(Grafo* grafo, int idOrigem, int idDestino);

#endif // BACKTRACKING_H
