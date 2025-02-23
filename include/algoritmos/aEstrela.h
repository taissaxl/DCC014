#ifndef AESTRELA_H
#define AESTRELA_H

#include "lista.h"
#include "vertice.h"
#include "grafo.h"

Lista<Vertice> buscaAEstrela(Grafo* grafo, int idOrigem, int idDestino);

#endif // AESTRELA_H