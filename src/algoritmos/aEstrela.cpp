#include "algoritmos/aEstrela.h"
#include "heapMin.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "grafo.h"
#include <unordered_map> // Para armazenar referências aos pais

#define CAPACIDADE 20

class FilaAEstrela {
    private: 
        HeapMin abertos; // Heap para os vértices abertos
        HeapMin fechados; // Heap para os vértices fechados
        int idDestino; // ID do vértice de destino
        int idVisitado; // ID do vértice visitado
        Grafo* grafo; // Ponteiro para o grafo

        std::unordered_map<int, int> pais; // Mapeia cada vértice ao seu pai
        std::unordered_map<int, int> gCustoVertice; // Mapeia cada vértice ao seu custo real

    public:
        FilaAEstrela(int idDestino, int idVisitado, Grafo* grafo)
            : idDestino(idDestino), idVisitado(idVisitado), 
              abertos(CAPACIDADE), fechados(CAPACIDADE), grafo(grafo) {

                // Inicializa o vértice de partida
                Vertice* vertice = grafo->getVertice(idVisitado);
                gCustoVertice[idVisitado] = 0;
                Aresta aresta(vertice, 0);
                abertos.inserir(aresta);
            }

        // Explora o vértice com a menor função de avaliação
        bool exploraMenorAberto() {
            if (abertos.getTamanho() == 0) return false;

            Aresta verticeMenorAberto = abertos.extrairMin();
            Vertice* verticeVisitado = verticeMenorAberto.getDestino();
            int idAtual = verticeVisitado->getId();

            //std::cout << "Explorando vértice: " << idAtual << std::endl;

            if (idAtual == idDestino) {
                fechados.inserir(verticeMenorAberto);
                return false;
            }

            Lista<Aresta>* listaArestas = verticeVisitado->getArestas();

            for (Aresta* aresta : *listaArestas) {
                Vertice* verticeFilho = aresta->getDestino();
                int idFilho = verticeFilho->getId();

                int novoG = gCustoVertice[idAtual] + aresta->getCusto();

                // Atualiza o custo real e insere o vértice filho nos abertos se necessário
                if (gCustoVertice.find(idFilho) == gCustoVertice.end() || novoG < gCustoVertice[idFilho]) {
                    if (gCustoVertice.find(idFilho) != gCustoVertice.end()) {
                        abertos.removerPeloId(idFilho);
                    }
                    gCustoVertice[idFilho] = novoG;
                    pais[idFilho] = idAtual;

                    int heuristica = calcularHeuristica(verticeFilho);
                    int f = novoG + heuristica;
                    Aresta novaAresta(verticeFilho, f);
                    abertos.inserir(novaAresta);
                }
            }
            
            fechados.inserir(verticeMenorAberto);
            return true;
        }

        // Calcula a heurística como a média das distâncias das arestas do vértice
        int calcularHeuristica(Vertice* vertice) {
            Lista<Aresta>* listaArestas = vertice->getArestas();
            int somaDistancias = 0;
            int numArestas = listaArestas->getTamanho();

            for (Aresta* aresta : *listaArestas) {
                somaDistancias += aresta->getCusto();
            }

            return numArestas > 0 ? somaDistancias / numArestas : 0;
        }

        // Reconstrói o caminho do destino até a origem
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

// Função principal da busca A*
Lista<Vertice> buscaAEstrela(Grafo* grafo, int idOrigem, int idDestino) {
    FilaAEstrela fila(idDestino, idOrigem, grafo);

    while (fila.exploraMenorAberto()) {}

    return fila.reconstruirCaminho();
}