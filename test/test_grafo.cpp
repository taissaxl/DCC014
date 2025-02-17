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
    Grafo grafo = new Grafo();

    Vertice* v = new Vertice(0);

    grafo.adicionarVertice(v);

    ASSERT_EQ(v, grafo.getVertice(0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}