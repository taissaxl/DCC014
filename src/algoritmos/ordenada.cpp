#include "algoritmos/ordenada.h"
#include "heapMin.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "grafo.h"
#include <unordered_map> // For storing parent references

#define CAPACIDADE 20

class Fila {
    private: 
        HeapMin abertos;
        HeapMin fechados;
        int idDestino;
        int idVisitado;
        Grafo* grafo;

        std::unordered_map<int, int> pais; 
        std::unordered_map<int, int> minCustoVertice;  

    public:
        Fila(int idDestino, int idVisitado, Grafo* grafo)
            : idDestino(idDestino), idVisitado(idVisitado), 
              abertos(CAPACIDADE), fechados(CAPACIDADE), grafo(grafo) {

                Vertice* vertice = grafo->getVertice(idVisitado);
                minCustoVertice[idVisitado] = 0;
                Aresta aresta(vertice, 0);
                abertos.inserir(aresta);

            }

        bool exploraMenorAberto() {
            if (abertos.getTamanho() == 0) return false;

            Aresta verticeMenorAberto = abertos.extrairMin();
            Vertice* verticeVisitado = verticeMenorAberto.getDestino();
            int idAtual = verticeVisitado->getId();

            if (idAtual == idDestino) {
                fechados.inserir(verticeMenorAberto);
                return false;
            }

            Lista<Aresta>* listaArestas = verticeVisitado->getArestas();

            for (Aresta* aresta : *listaArestas) {
                Vertice* verticeFilho = aresta->getDestino();
                int idFilho = verticeFilho->getId();

                int novoCusto = minCustoVertice[idAtual] + aresta->getCusto();

                // insere nos abertos se não está no neg de minCustoVertice ou se o novo custo for menor
                if (minCustoVertice.find(idFilho) == minCustoVertice.end() || novoCusto < minCustoVertice[idFilho]) {
                    if (minCustoVertice.find(idFilho) != minCustoVertice.end()) {
                        abertos.removerPeloId(idFilho);
                    }
                    minCustoVertice[idFilho] = novoCusto;
                    pais[idFilho] = idAtual; // Store parent for path reconstruction

                    Aresta novaAresta(verticeFilho, novoCusto);
                    abertos.inserir(novaAresta);
                }
            }
            
            fechados.inserir(verticeMenorAberto);
            return true;
        }

        Lista<Vertice> reconstruirCaminho() {
            Lista<Vertice> caminho;
            int atual = idDestino;

            while (pais.find(atual) != pais.end()) {
                caminho.inserirNoInicio(grafo->getVertice(atual));
                atual = pais[atual];
            }

            
            caminho.inserirNoInicio(grafo->getVertice(idVisitado));

            return caminho;
        }
};

Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino) {
    Fila fila(idDestino, idOrigem, grafo);

    while (fila.exploraMenorAberto()) {}

    return fila.reconstruirCaminho();
}
