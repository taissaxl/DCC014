#ifndef HEAPMIN_H
#define HEAPMIN_H

#include <vector>
#include <algorithm>
#include "aresta.h"
#include "vertice.h"
using namespace std;

class HeapMin {
private:
    vector<Aresta> heap; 
    int tamanho;
    int capacidade;

    void heapify(int i) {
        int menor = i;
        int esquerda = 2 * i + 1;
        int direita = 2 * i + 2;

        if (esquerda < tamanho && heap[esquerda] < heap[menor])
            menor = esquerda;

        if (direita < tamanho && heap[direita] < heap[menor])
            menor = direita;  

        if (menor != i) {
            swap(heap[i], heap[menor]);
            heapify(menor);
        }
    }

public:
    HeapMin(int capacidade) {
        this->tamanho = 0;
        this->capacidade = capacidade;
        this->heap.resize(capacidade);
    }

    ~HeapMin() {}

    void inserir(Aresta aresta) {  // Accepts object instead of pointer
        if (tamanho == capacidade) {
            capacidade *= 2;
            heap.resize(capacidade);
        }

        tamanho++;
        int i = tamanho - 1;
        heap[i] = aresta;  // Store a copy

        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    Aresta* getRaiz() {
        if (tamanho <= 0) return nullptr;
        return &heap[0];  // Return address
    }

    Aresta extrairMin() {
        if (tamanho <= 0) return Aresta(nullptr, -1);
        if (tamanho == 1) {
            tamanho--;
            return heap[0];
        }

        Aresta raiz = heap[0];
        heap[0] = heap[tamanho - 1];
        tamanho--;

        heapify(0);
        return raiz;
    }

    void remover(Aresta aresta) {
        int indice = -1;
        for (int i = 0; i < tamanho; ++i) {
            if (heap[i].getDestino() == aresta.getDestino() && heap[i].getCusto() == aresta.getCusto()) {
                indice = i;
                break;
            }
        }

        if (indice == -1) return;

        if (indice == tamanho - 1) {
            tamanho--;
            return;
        }

        heap[indice] = heap[tamanho - 1];
        tamanho--;

        heapify(indice);
    }

    void removerPeloId(int idVertice) {
        for (int i = 0; i < tamanho; ++i) {
            if (heap[i].getDestino()->getId() == idVertice) {
                remover(heap[i]);
                return;
            }
        }
    }

    int getTamanho() {
        return tamanho;
    }
};

#endif
