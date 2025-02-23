#include <gtest/gtest.h>
#include "grafo.h"
#include "fazGrafo.h"
#include "lista.h"
#include "vertice.h"
#include "algoritmos/aEstrela.h"

class BuscaAEstrelaTest : public ::testing::Test {
    protected:
        void SetUp() override {
            // Caso necessário, inicialize o objeto lista aqui
        }
    
        void TearDown() override {
            // Caso necessário, limpe os recursos aqui
        }
};

#define CIDADE_A 0
#define CIDADE_B 1
#define CIDADE_C 2
#define CIDADE_D 3
#define CIDADE_E 4
#define CIDADE_F 5

TEST_F(BuscaAEstrelaTest, TestBuscaAEstrela)
{
    Grafo* grafo = new Grafo();
    int auxId;

    for (int i = CIDADE_A; i <= CIDADE_F; i++){
        auxId = grafo->adicionarVertice();
    }

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

    Lista<Vertice> caminhoCalculado = buscaAEstrela(grafo, CIDADE_A, CIDADE_D);

    Lista<Vertice> caminhoEsperado;

    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_A));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_B));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_D));

    ASSERT_EQ(caminhoCalculado.getTamanho(), caminhoEsperado.getTamanho());

    auto it1 = caminhoCalculado.begin();
    auto it2 = caminhoEsperado.begin();

    while (it1 != caminhoCalculado.end() && it2 != caminhoEsperado.end()) {
        EXPECT_EQ((*it1)->getId(), (*it2)->getId());
        ++it1;
        ++it2;
    }

    delete grafo;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}