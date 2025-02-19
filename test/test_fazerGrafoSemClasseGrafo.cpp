#include <gtest/gtest.h>
#include "lista.h"
#include "aresta.h"
#include "vertice.h"

class FazerGrafoSemClasseGrafoTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Caso necessário, inicialize o objeto lista aqui
    }

    void TearDown() override {
        // Caso necessário, limpe os recursos aqui
    }
};

TEST_F(FazerGrafoSemClasseGrafoTest, FazerGrafo) {
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);

    Aresta* aV1pV2 = new Aresta(v1, 1);
    Aresta* a2V2pV1 = new Aresta(v2, 1);

    v1->adicionarAresta(aV1pV2);
    v2->adicionarAresta(a2V2pV1);

    EXPECT_EQ(v1->getId(), 1);
    EXPECT_EQ(v2->getId(), 2);
    EXPECT_EQ(aV1pV2->getCusto(), 1);
    EXPECT_EQ(a2V2pV1->getCusto(), 1);
}

TEST_F(FazerGrafoSemClasseGrafoTest, TestarTamanhoArestas) {
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);

    Aresta* aV1pV2 = new Aresta(v1, 1);
    Aresta* a2V2pV1 = new Aresta(v2, 1);

    v1->adicionarAresta(aV1pV2);
    v2->adicionarAresta(a2V2pV1);

    EXPECT_EQ(v1->getArestas()->getTamanho(), 1);
    EXPECT_EQ(v2->getArestas()->getTamanho(), 1);

}

TEST_F(FazerGrafoSemClasseGrafoTest, TestarGetCustosArestas) {
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);

    Aresta* aV1pV2 = new Aresta(v1, 1);
    Aresta* a2V2pV1 = new Aresta(v2, 1);

    v1->adicionarAresta(aV1pV2);
    v2->adicionarAresta(a2V2pV1);

    EXPECT_EQ(v1->getArestas()->getPrimeiro()->getElemento()->getCusto(), 1);
    EXPECT_EQ(v2->getArestas()->getPrimeiro()->getElemento()->getCusto(), 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
