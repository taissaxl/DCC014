#ifndef ORDENADA_H
#define ORDENADA_H

#include "algoritmos/ordenada.h"
#include "heapMin.h"
#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "grafo.h"
#include <unordered_map>
#include <unordered_set>

#define CAPACIDADE 20

class FilaOrdenada {
    private:
        HeapMin abertos;
        std::unordered_set<int> fechados_ids;
        std::unordered_map<int, int> pais;
        std::unordered_map<int, int> gCustoVertice;
        Grafo* grafo;
        int idDestino;
        int idVisitado;
    
    public:
        FilaOrdenada(int idDestino, int idVisitado, Grafo* grafo)
            : idDestino(idDestino), idVisitado(idVisitado), grafo(grafo), abertos(CAPACIDADE) {
    
            gCustoVertice[idVisitado] = 0;
            Aresta arestaInicial(grafo->getVertice(idVisitado), 0);
            abertos.inserir(arestaInicial);
        }
    

        bool exploraMenorAberto() {
            if (abertos.getTamanho() == 0) {
                return false; 
            }
    
            Aresta atualAresta = abertos.extrairMin();
            Vertice* verticeAtual = atualAresta.getDestino();
            int idAtual = verticeAtual->getId();
    
            if (fechados_ids.find(idAtual) != fechados_ids.end()) {
                return true;
            }
    
            
            if (idAtual == idDestino) {
                fechados_ids.insert(idAtual);
                return false; 
            }
    
            fechados_ids.insert(idAtual);
    
            Lista<Aresta>* arestas = verticeAtual->getArestas();
            for (Aresta* aresta : *arestas) {
                Vertice* verticeFilho = aresta->getDestino();
                int idFilho = verticeFilho->getId();
    
                if (fechados_ids.find(idFilho) != fechados_ids.end()) {
                    continue; 
                }
    
                int novoCusto = gCustoVertice[idAtual] + aresta->getCusto();
    
                if (gCustoVertice.find(idFilho) == gCustoVertice.end() || novoCusto < gCustoVertice[idFilho]) {
                    gCustoVertice[idFilho] = novoCusto;
                    pais[idFilho] = idAtual;
                    abertos.removerPeloId(idFilho);
                    Aresta novaAresta(verticeFilho, novoCusto);
                    abertos.inserir(novaAresta);
                }
            }
    
            return true;
        }
    
        Lista<Vertice> reconstruirCaminho() {
            Lista<Vertice> caminho;
            if (gCustoVertice.find(idDestino) == gCustoVertice.end()) {
                return caminho;
            }
            int atual = idDestino;
            while (pais.find(atual) != pais.end()) {
                caminho.inserirNoInicio(grafo->getVertice(atual));
                atual = pais[atual];
            }

            caminho.inserirNoInicio(grafo->getVertice(idVisitado));

            return caminho;
        }
    };
    
Lista<Vertice> buscaOrdenada(Grafo* grafo, int idOrigem, int idDestino);

#endif 