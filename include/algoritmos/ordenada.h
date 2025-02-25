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
              abertos(CAPACIDADE), fechados(CAPACIDADE), grafo(grafo) {

                Vertice* vertice = grafo->getVertice(idVisitado);
                assert(vertice != nullptr && "Erro: Vertice inicial não encontrado no grafo!");
                
                minCustoVertice[idVisitado] = 0;
                Aresta aresta(vertice, 0);
                abertos.inserir(aresta);
            }

        bool exploraMenorAberto() {
            if (abertos.getTamanho() == 0) return false;

            Aresta verticeMenorAberto = abertos.extrairMin();
            Vertice* verticeVisitado = verticeMenorAberto.getDestino();
            
            assert(verticeVisitado != nullptr && "Erro: verticeVisitado é nullptr em exploraMenorAberto!");
            
            int idAtual = verticeVisitado->getId();

            if (idAtual == idDestino) {
                fechados.inserir(verticeMenorAberto);
                return false;
            }

            Lista<Aresta>* listaArestas = verticeVisitado->getArestas();
            assert(listaArestas != nullptr && "Erro: listaArestas é nullptr em exploraMenorAberto!");

            for (Aresta* aresta : *listaArestas) {
                Vertice* verticeFilho = aresta->getDestino();
                assert(verticeFilho != nullptr && "Erro: aresta apontando para um vertice nulo!");
                
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
                assert(grafo->getVertice(atual) != nullptr && "Erro: reconstruirCaminho encontrou um vértice nulo!");
                caminho.inserirNoInicio(grafo->getVertice(atual));
                atual = pais[atual];
            }

            assert(grafo->getVertice(idVisitado) != nullptr && "Erro: vértice inicial não encontrado no caminho!");
            caminho.inserirNoInicio(grafo->getVertice(idVisitado));

            return caminho;
        }
};


Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino);

#endif //ORDENADA_H