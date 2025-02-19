#include <gtest/gtest.h>
#include "heapMin.h"
#include "aresta.h"
#include "vertice.h"

class HeapMinTest : public ::testing::Test {
protected:
    HeapMin* heapMin;

    void SetUp() override {
        heapMin = new HeapMin(10);
    }

    void TearDown() override {
        delete heapMin;
    }
};

TEST_F(HeapMinTest, TestInserirExtrairMin) {
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);

    Aresta a1(v1, 10);
    Aresta a2(v2, 5);

    heapMin->inserir(a1);
    heapMin->inserir(a2);

    Aresta minAresta = heapMin->extrairMin();
    EXPECT_EQ(minAresta.getCusto(), 5);
    EXPECT_EQ(minAresta.getDestino()->getId(), 2);

    minAresta = heapMin->extrairMin();
    EXPECT_EQ(minAresta.getCusto(), 10);
    EXPECT_EQ(minAresta.getDestino()->getId(), 1);
}

TEST_F(HeapMinTest, TestGetRaiz) {
    EXPECT_EQ(heapMin->getRaiz(), nullptr);

    Vertice* v = new Vertice(1);
    Aresta a(v, 3);

    heapMin->inserir(a);
    EXPECT_EQ(heapMin->getRaiz()->getCusto(), 3);
}

TEST_F(HeapMinTest, TestRemoverPeloId) {
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);

    Aresta a1(v1, 10);
    Aresta a2(v2, 5);

    heapMin->inserir(a1);
    heapMin->inserir(a2);

    heapMin->removerPeloId(1);
    EXPECT_EQ(heapMin->getRaiz()->getDestino()->getId(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

