#include <gtest/gtest.h>
#include "grafo.h"
#include "fazGrafo.h"
#include "lista.h"
#include "vertice.h"
#include "algoritmos/backtracking.h"  // Inclui a implementação do backtracking

class BuscaBacktrackingTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Inicializações, se necessário
    }
    
    void TearDown() override {
        // Limpeza dos recursos, se necessário
    }
};

#define CIDADE_A 0
#define CIDADE_B 1
#define CIDADE_C 2
#define CIDADE_D 3
#define CIDADE_E 4
#define CIDADE_F 5

TEST_F(BuscaBacktrackingTest, TestBuscaBacktracking)
{
    Grafo* grafo = new Grafo();
    
    // Cria 6 vértices (índices 0 a 5)
    for (int i = CIDADE_A; i <= CIDADE_F; i++){
        grafo->adicionarVertice();
    }

    // Adiciona as arestas ao grafo
    grafo->adicionarAresta(CIDADE_A, CIDADE_B, 1);
    grafo->adicionarAresta(CIDADE_A, CIDADE_F, 2);
    grafo->adicionarAresta(CIDADE_B, CIDADE_F, 1);
    grafo->adicionarAresta(CIDADE_B, CIDADE_D, 7);
    grafo->adicionarAresta(CIDADE_B, CIDADE_C, 4);
    grafo->adicionarAresta(CIDADE_F, CIDADE_C, 2);
    grafo->adicionarAresta(CIDADE_F, CIDADE_D, 9);
    grafo->adicionarAresta(CIDADE_F, CIDADE_E, 5);
    grafo->adicionarAresta(CIDADE_D, CIDADE_C, 5);
    grafo->adicionarAresta(CIDADE_D, CIDADE_E, 3);

    // Executa a busca por backtracking (DFS)
    Lista<Vertice> caminhoCalculado = buscaBacktracking(grafo, CIDADE_A, CIDADE_D);

    // Espera-se o caminho: A, B, F, D (ou seja, índices: 0, 1, 5, 3)
    Lista<Vertice> caminhoEsperado;
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_A));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_B));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_F));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_C));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_D));

    // Verifica se os tamanhos dos caminhos são iguais
    ASSERT_EQ(caminhoCalculado.getTamanho(), caminhoEsperado.getTamanho());

    // Compara cada vértice do caminho (assumindo que Lista possui begin() e end())
    auto it1 = caminhoCalculado.begin();
    auto it2 = caminhoEsperado.begin();
    while (it1 != caminhoCalculado.end() && it2 != caminhoEsperado.end()) {
        EXPECT_EQ((*it1)->getId(), (*it2)->getId());
        ++it1;
        ++it2;
    }

    delete grafo; // Libera a memória do grafo
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
