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
        if (i < 0 || i >= tamanho) return;  
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
        //TODO
//std::cout << "Heap initialized with capacity: " << capacidade << ", size: " << tamanho << std::endl;
    }

    ~HeapMin() {}

    void inserir(Aresta aresta) {  
        //TODO
//std::cout << "Inserting edge with cost: " << aresta.getCusto() << " into heap of size: " << tamanho << std::endl;
    
        // Resize if the heap is full
        if (tamanho >= capacidade) {
            capacidade = (capacidade == 0) ? 1 : capacidade * 2;
            heap.resize(capacidade);
            //TODO
//std::cout << "Resized heap to capacity: " << capacidade << std::endl;
        }
    
        // Add the new element at the end
        heap[tamanho] = aresta;
        tamanho++; // Increment size AFTER insertion
    
        // Heapify up
        int i = tamanho - 1;
        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    
        //TODO
//std::cout << "After insertion, heap size: " << tamanho << std::endl;
    }

    Aresta* getRaiz() {
        if (tamanho <= 0) return nullptr;
        return &heap[0];  // Return address
    }

    Aresta extrairMin() {
        //TODO
//std::cout << "Extracting min from heap of size: " << tamanho << std::endl;
        if (tamanho <= 0) throw std::runtime_error("A heap esta vazia!");
        if (tamanho == 1) {
            tamanho--;
            return heap[0];
        }

        Aresta raiz = heap[0];
        heap[0] = heap[tamanho - 1];
        tamanho--;

        heapify(0);
        //TODO
//std::cout << "After extraction, heap size: " << tamanho << std::endl;
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
            if (heap[i].getDestino()->getId() == idVertice && heap[i].getDestino() != nullptr) {
                
                //TODO
//std::cout << "Removing vertex with ID: " << idVertice << std::endl;
                remover(heap[i]);
                return;
            }
        }
        //TODO
//std::cout << "Vertex with ID: " << idVertice << " not found in heap" << std::endl;
    }

    int getTamanho() const {
        return tamanho;
    }
};

#endif
