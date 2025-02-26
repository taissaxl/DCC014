#include "algoritmos/backtracking.h"
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include <unordered_set>

using namespace std;


bool dfsBacktracking(Grafo* grafo, int atual, int destino, unordered_set<int>& visitados, Lista<Vertice>& caminho) {
    visitados.insert(atual);
    caminho.adicionar(grafo->getVertice(atual));

    if (atual == destino) {
        return true;
    }
    
    Lista<Aresta>* listaArestas = grafo->getVertice(atual)->getArestas();
    for (Aresta* aresta : *listaArestas) {
        int idFilho = aresta->getDestino()->getId();
        
        
        if (visitados.find(idFilho) == visitados.end()) {
            if (dfsBacktracking(grafo, idFilho, destino, visitados, caminho)) {
                return true; 
            }
        }
    }
    
    if (caminho.getUltimo() != NULL) {
        caminho.remover(caminho.getUltimo()->getElemento());
    }
    visitados.erase(atual);
    return false;
}


Lista<Vertice> buscaBacktracking(Grafo* grafo, int idOrigem, int idDestino) {
    Lista<Vertice> caminho;
    unordered_set<int> visitados;
    
    
    if (!dfsBacktracking(grafo, idOrigem, idDestino, visitados, caminho)) {
        
        while (!caminho.estaVazia()) {
            caminho.remover(caminho.getUltimo()->getElemento());
        }
    }
    
    return caminho;
}