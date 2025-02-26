#ifndef PROFUNDIDADE_H
#define PROFUNDIDADE_H

#include "lista.h"
#include "vertice.h"
#include "grafo.h"

Lista<Vertice> buscaProfundidade(Grafo* grafo, int idOrigem, int idDestino);

#endif // PROFUNDIDADE_H
