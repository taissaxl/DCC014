#include <gtest/gtest.h>
#include "lista.h"
#include "aresta.h"
#include "vertice.h"
#include "grafo.h"

class GrafoTest : public ::testing::Test {
    protected:
        void SetUp() override {
            // Caso necessário, inicialize o objeto lista   aqui
        }

        void TearDown() override {
            // Caso necessário, limpe os recursos aqui
        }
};

TEST_F(GrafoTest, TestAdicionaVertice) {
    Grafo* grafo = new Grafo();

    int idVertice = grafo->adicionarVertice();

    ASSERT_EQ(0, grafo->getVertice(idVertice)->getId());
}

TEST_F(GrafoTest, TestAdicionaAresta) {
    Grafo* grafo = new Grafo();

    int idOrigem = grafo->adicionarVertice();
    int idDestino = grafo->adicionarVertice();

    grafo->adicionarAresta(idOrigem, idDestino, 3);

    ASSERT_EQ(3, grafo->getCustoEntreVertices(idOrigem, idDestino));
}

TEST_F(GrafoTest, TestDuplaSaidaDeUmVertice) {
    Grafo* grafo = new Grafo();

    int idOrigem = grafo->adicionarVertice();
    int idSaidaEsquerda = grafo->adicionarVertice();
    int idSaidaDireita = grafo->adicionarVertice();

    grafo->adicionarAresta(idOrigem, idSaidaEsquerda, 3);
    grafo->adicionarAresta(idOrigem, idSaidaDireita, 2);

    ASSERT_EQ(3, grafo->getCustoEntreVertices(idOrigem, idSaidaEsquerda));
    ASSERT_EQ(2, grafo->getCustoEntreVertices(idOrigem, idSaidaDireita));
}

TEST_F(GrafoTest, TestImprimir) {
    Grafo* grafo = new Grafo();

    int idOrigem = grafo->adicionarVertice();
    int idSaidaEsquerda = grafo->adicionarVertice();
    int idSaidaDireita = grafo->adicionarVertice();

    grafo->adicionarAresta(idOrigem, idSaidaEsquerda, 3);
    grafo->adicionarAresta(idOrigem, idSaidaDireita, 2);

    grafo->imprimirMatrizAdj();

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}