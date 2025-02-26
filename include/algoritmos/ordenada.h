#ifndef ORDENADA_H
#define ORDENADA_H

#include "lista.h"
#include "heapMin.h"
#include "aresta.h"
#include <unordered_map>
#include "vertice.h"
#include "grafo.h"

#define CAPACIDADE 20
#include <unordered_map>
#include <cassert>

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
              abertos(CAPACIDADE), fechados/(CAPACIDADE), grafo(grafo) {
        
            std::cout << "Fila constructor - Destination: " << idDestino 
                      << ", Source: " << idVisitado << std::endl;

                Vertice* vertice = grafo->getVertice(idVisitado);
            if (vertice == nullptr) {
                throw std::runtime_error("Starting vertex not found in graph");
            }

            std::cout << "Starting vertex found: " << vertice->getId() << std::endl;

                minCustoVertice[idVisitado] = 0;
                Aresta aresta(vertice, 0);
                abertos.inserir(aresta);

            std::cout << "Initial heap size after insertion: " << abertos.getTamanho() << std::endl;
        }

        bool exploraMenorAberto() {
            if (abertos.getTamanho() == 0) return false;
                // Debug output
            std::cout << "Heap size before extraction: " << abertos.getTamanho() << std::endl;
                
            Aresta verticeMenorAberto = abertos.extrairMin();

            std::cout << "Conseguiu extrair o vertice " << verticeMenorAberto.getDestino()->getId() << std::endl;

            if (verticeMenorAberto.getDestino() == nullptr) {
                std::cerr << "Warning: Extractededge has null destination" <<std::endl;
                return false;
            }
                
            // Check if the extraction wassuccessful
            std::cout << "Extracted edge with cost:" << verticeMenorAberto.getCusto() <<std::endl;
            
            Vertice* verticeVisitado = verticeMenorAberto.getDestino();
            
            // Validate the vertex pointer BEFOREthe assertion
            if (verticeVisitado == nullptr) {
                std::cout << "ERROR:verticeVisitado is nullptr" <<std::endl;
                return false; // Return instead ofasserting to get more debug info
            }
            
            //assert(verticeVisitado != nullptr && "Erro: verticeVisitado é nullptr em exploraMenorAberto!");
            
            int idAtual = verticeVisitado->getId();

            if (idAtual == idDestino) {
                fechados.inserir(verticeMenorAberto);
                return false;
            }

            Lista<Aresta>* listaArestas = verticeVisitado->getArestas();
            //assert(listaArestas != nullptr && "Erro: listaArestas é nullptr em exploraMenorAberto!");

            for (Aresta* aresta : *listaArestas) {
                Vertice* verticeFilho = aresta->getDestino();
                //assert(verticeFilho != nullptr && "Erro: aresta apontando para um vertice nulo!");
                
                int idFilho = verticeFilho->getId();
                int novoCusto = minCustoVertice[idAtual] + aresta->getCusto();

                if (minCustoVertice.find(idFilho) == minCustoVertice.end() || novoCusto < minCustoVertice[idFilho]) {
                    if (minCustoVertice.find(idFilho) != minCustoVertice.end()) {
                        abertos.removerPeloId(idFilho);
                    }
                    minCustoVertice[idFilho] = novoCusto;
                    pais[idFilho] = idAtual;
                    
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
                //assert(grafo->getVertice(atual) != nullptr && "Erro: reconstruirCaminho encontrou um vértice nulo!");
                caminho.inserirNoInicio(grafo->getVertice(atual));
                atual = pais[atual];
            }

            //assert(grafo->getVertice(idVisitado) != nullptr && "Erro: vértice inicial não encontrado no caminho!");
            caminho.inserirNoInicio(grafo->getVertice(idVisitado));

            return caminho;
        }
};


Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino);

#endif //ORDENADA_H