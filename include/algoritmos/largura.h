#ifndef LARGURA_H
#define LARGURA_H

#include "lista.h"
#include "vertice.h"
#include "grafo.h"

// Declara a função de busca em largura (BFS)
Lista<Vertice> buscaLargura(Grafo* grafo, int idOrigem, int idDestino);

#endif // LARGURA_H
