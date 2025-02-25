#include "algoritmos/backtracking.h"
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include <unordered_set>

using namespace std;

// Função auxiliar recursiva que realiza a busca com backtracking (DFS)
bool dfsBacktracking(Grafo* grafo, int atual, int destino, unordered_set<int>& visitados, Lista<Vertice>& caminho) {
    visitados.insert(atual);
    // Adiciona o vértice atual no final do caminho
    caminho.adicionar(grafo->getVertice(atual));

    // Se chegou no destino, retorna sucesso
    if (atual == destino) {
        return true;
    }

    // Obtém as arestas (vizinhos) do vértice atual
    Lista<Aresta>* listaArestas = grafo->getVertice(atual)->getArestas();
    for (Aresta* aresta : *listaArestas) {
        int idFilho = aresta->getDestino()->getId();
        // Se o vizinho ainda não foi visitado
        if (visitados.find(idFilho) == visitados.end()) {
            if (dfsBacktracking(grafo, idFilho, destino, visitados, caminho)) {
                return true; // Se encontrou um caminho, propaga o sucesso
            }
        }
    }
    // Se nenhum vizinho levou ao destino, remove o último vértice adicionado (backtracking)
    if (caminho.getUltimo() != NULL) {
        caminho.remover(caminho.getUltimo()->getElemento());
    }
    return false;
}

// Função principal que prepara e chama a busca recursiva (DFS)
Lista<Vertice> buscaBacktracking(Grafo* grafo, int idOrigem, int idDestino) {
    Lista<Vertice> caminho;
    unordered_set<int> visitados;
    dfsBacktracking(grafo, idOrigem, idDestino, visitados, caminho);
    return caminho;
}
