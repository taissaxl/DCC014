#include "algoritmos/largura.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "grafo.h"
#include <queue>
#include <unordered_map>

using namespace std; 

// Classe auxiliar para a execução do BFS
class Fila {
private:
    queue<int> abertos;                  // Fila FIFO para BFS
    unordered_map<int, int> pais;        // Armazena os pais para reconstrução do caminho
    unordered_map<int, bool> visitados;  // Marca os nós já visitados
    Grafo* grafo;
    int idDestino;
    int idVisitado;

public:
    Fila(int idDestino, int idVisitado, Grafo* grafo)
        : idDestino(idDestino), idVisitado(idVisitado), grafo(grafo) {
        abertos.push(idVisitado);        // Inicia a fila com o nó de origem
        visitados[idVisitado] = true;      // Marca o nó de origem como visitado
    }

    // Explora o próximo vértice na fila
    bool explorar() {
        if (abertos.empty()) return false;

        int idAtual = abertos.front();
        abertos.pop();

        if (idAtual == idDestino) return false; // Se chegou no destino, interrompe a exploração

        Vertice* verticeAtual = grafo->getVertice(idAtual);
        Lista<Aresta>* listaArestas = verticeAtual->getArestas();

        // Explora todos os vizinhos (arestas) do vértice atual
        for (Aresta* aresta : *listaArestas) {
            int idFilho = aresta->getDestino()->getId();
            if (!visitados[idFilho]) {  // Se o vértice ainda não foi visitado
                visitados[idFilho] = true;
                pais[idFilho] = idAtual;  // Registra o pai
                abertos.push(idFilho);    // Adiciona à fila
            }
        }
        return true;
    }

    // Reconstrói o caminho do destino até a origem utilizando o mapa de pais
    Lista<Vertice> reconstruirCaminho() {
        Lista<Vertice> caminho;
        int atual = idDestino;

        // Se não houver pai registrado para o destino, não há caminho
        if (pais.find(atual) == pais.end()) {
            return caminho;
        }

        while (pais.find(atual) != pais.end()) {
            caminho.inserirNoInicio(grafo->getVertice(atual));
            atual = pais[atual];
        }

        // Insere o nó de origem
        caminho.inserirNoInicio(grafo->getVertice(idVisitado));
        return caminho;
    }
};

// Função principal que executa o BFS e retorna o caminho encontrado
Lista<Vertice> buscaLargura(Grafo* grafo, int idOrigem, int idDestino) {
    Fila fila(idDestino, idOrigem, grafo);
    while (fila.explorar()) {}
    return fila.reconstruirCaminho();
}
