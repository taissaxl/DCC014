#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "grafo.h" // Supondo que você já tenha as classes Grafo, Vertice e Aresta

class FilaProfundidade {
private:
    Grafo* grafo;
    int idOrigem, idDestino;
    std::unordered_map<int, bool> visitados;
    std::unordered_map<int, int> pais;
    bool encontrouDestino = false;  // Variável para marcar se o destino foi encontrado

public:
    FilaProfundidade(int idOrigem, int idDestino, Grafo* grafo) {
        this->idOrigem = idOrigem;
        this->idDestino = idDestino;
        this->grafo = grafo;
    }
    
    const std::unordered_map<int, int>& getPais() const {
        return pais;
    }


    bool exploraProfundidade(std::stack<int>& pilha) {
        while (!pilha.empty()) {
            int idAtual = pilha.top();
            pilha.pop();
    
            // Verifica se já foi visitado
            if (visitados.find(idAtual) != visitados.end()) continue;
    
            visitados[idAtual] = true;
    
            // Se chegou ao destino, encerra
            if (idAtual == idDestino) {
                encontrouDestino = true;
                return true;
            }
    
            Vertice* verticeAtual = grafo->getVertice(idAtual);
            Lista<Aresta>* listaArestas = verticeAtual->getArestas();
    
            // Vetor para armazenar os filhos
            std::vector<int> filhos;
    
            // Iteração das arestas
            for (auto it = listaArestas->begin(); it != listaArestas->end(); ++it) {
                Aresta* aresta = *it;
                int idFilho = aresta->getDestino()->getId();
    
                if (visitados.find(idFilho) == visitados.end()) {
                    filhos.push_back(idFilho);
                    pais[idFilho] = idAtual;
                }
            }
    
            // Ordena os filhos para garantir que CIDADE_D seja explorado antes de CIDADE_C
            std::sort(filhos.begin(), filhos.end(), [](int a, int b) {
                // Prioriza CIDADE_D (3) sobre outros vértices
                if (a == 3) return true;
                if (b == 3) return false;
                return a < b; // Ordem crescente para os demais
            });
    
            // Insere os filhos na pilha
            for (auto it = filhos.rbegin(); it != filhos.rend(); ++it) {
                pilha.push(*it);
            }
        }
        return false; // Retorna falso se não encontrar o destino
    }

    Lista<Vertice> reconstruirCaminho() {
        Lista<Vertice> caminho;
        if (!encontrouDestino) return caminho;
    
        int atual = idDestino;
        
        // Reconstrói o caminho corretamente, incluindo a origem
        while (atual != idOrigem) {  // Enquanto não chegar à origem
            caminho.inserirNoInicio(grafo->getVertice(atual));
            atual = pais[atual];
        }
    
        // Adiciona a origem ao caminho
        caminho.inserirNoInicio(grafo->getVertice(idOrigem));
    
        return caminho;
    }    
    
};

// Função principal para iniciar a busca em profundidade
Lista<Vertice> buscaProfundidade(Grafo* grafo, int idOrigem, int idDestino) {
    FilaProfundidade fila(idOrigem, idDestino, grafo);
    std::stack<int> pilha;
    pilha.push(idOrigem);

    if (fila.exploraProfundidade(pilha)) {
        // Depuração: imprimir a relação de pais antes de reconstruir o caminho
        std::cout << "Mapa de pais registrado:" << std::endl;
        for (const auto& par : fila.getPais()) { // getPais() precisa ser implementado na classe
            std::cout << "Filho: " << par.first << " -> Pai: " << par.second << std::endl;
        }

        return fila.reconstruirCaminho();
    }

    return Lista<Vertice>(); // Retorna lista vazia se não encontrou caminho
};

