#include <iostream>
#include "grafo.h"
#include "fazGrafo.h"
#include "algoritmos/ordenada.h"
#include "algoritmos/aEstrela.h"
#include "algoritmos/largura.h"
#include "algoritmos/backtracking.h"
#include "algoritmos/gulosa.h"
#include "algoritmos/profundidade.h"
#include "vertice.h"
#include "lista.h"



int calculaCustoCaminho(Lista<Vertice> caminho) {
    int custo = 0;

    auto it = caminho.begin();
    if (it == caminho.end()) return 0;
    
    Vertice* prev = *it;
    ++it;
    
    while (it != caminho.end()) {
        Vertice* current = *it;
        
        Lista<Aresta>* arestas = prev->getArestas();
        bool found = false;
        for (auto itAresta = arestas->begin(); itAresta != arestas->end(); ++itAresta) {
            Aresta* aresta = *itAresta;
            if (aresta->getDestino()->getId() == current->getId()) {
                custo += aresta->getCusto();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Error: No edge found between vertices " << prev->getId() 
                 << " and " << current->getId() << endl;
        }
        
        prev = current;
        ++it;
    }
    
    return custo;
}

int main (int argc, char *argv[]) {
    Grafo* grafo = fazerGrafo();



    cout << "Buscando caminho entre Juiz de Fora e Vicosa pelo algoritmo A*..." << endl;
    Lista<Vertice> caminhoBuscaAEstrela = buscaAEstrela(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pelo algoritmo A*: " << endl;
    for (Vertice* v : caminhoBuscaAEstrela) {
        cout << v->getId() << " ";
    }
    cout << endl;

    cout << "Buscando caminho entre Juiz de Fora e Vicosa pela busca em largura..." << endl;
    Lista<Vertice> caminhoBuscaLargura = buscaLargura(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pela busca em largura: " << endl;
    for (Vertice* v : caminhoBuscaLargura) {
        cout << v->getId() << " ";
    }
    cout << endl;

    cout << "Buscando caminho entre Juiz de Fora e Vicosa pelo algoritmo de backtracking..." << endl;
    Lista<Vertice> caminhoBuscaBacktracking = buscaBacktracking(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pelo algoritmo de backtracking: " << endl;
    for (Vertice* v : caminhoBuscaBacktracking) {
        cout << v->getId() << " ";
    }
    cout << endl;

    cout << "Buscando caminho entre Juiz de Fora e Vicosa pelo algoritmo guloso..." << endl;
    Lista<Vertice> caminhoBuscaGulosa = buscaGulosa(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pelo algoritmo guloso: " << endl;
    for (Vertice* v : caminhoBuscaGulosa) {
        cout << v->getId() << " ";
    }
    cout << endl;

    cout << "Buscando caminho entre Juiz de Fora e Vicosa pela busca em profundidade..." << endl;
    Lista<Vertice> caminhoBuscaProfundidade = buscaProfundidade(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pela busca em profundidade: " << endl;
    for (Vertice* v : caminhoBuscaProfundidade) {
        cout << v->getId() << " ";
    }
    cout << endl;
    /*
    cout << "Buscando caminho entre Juiz de Fora e Vicosa pela busca ordenada..." << endl;
    Lista<Vertice> caminhoBuscaOrdenada = buscaOrdenada(grafo, JUIZ_DE_FORA, VICOSA);
    cout << "Caminho encontrado pela busca ordenada: " << endl;
    for (Vertice* v : caminhoBuscaOrdenada) {
        cout << v->getId() << " ";
    }
    cout << endl;

    int custoBuscaOrdenada = calculaCustoCaminho(caminhoBuscaOrdenada);*/
    int custoBuscaAEstrela = calculaCustoCaminho(caminhoBuscaAEstrela);
    int custoBuscaLargura = calculaCustoCaminho(caminhoBuscaLargura);
    int custoBuscaBacktracking = calculaCustoCaminho(caminhoBuscaBacktracking);
    int custoBuscaGulosa = calculaCustoCaminho(caminhoBuscaGulosa);
    int custoBuscaProfundidade = calculaCustoCaminho(caminhoBuscaProfundidade);

    //cout << "Custo da busca ordenada: " << custoBuscaOrdenada << endl;
    cout << "Custo da busca AEstrela: " << custoBuscaAEstrela << endl;
    cout << "Custo da busca largura: " << custoBuscaLargura << endl;
    cout << "Custo da busca backtracking: " << custoBuscaBacktracking << endl;
    cout << "Custo da busca gulosa: " << custoBuscaGulosa << endl;
    cout << "Custo da busca profundidade: " << custoBuscaProfundidade << endl;

    return 0;
}
