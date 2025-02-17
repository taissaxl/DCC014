#include <gtest/gtest.h>
#include "vertice.h"
#include "aresta.h"
#include "no.h"

class ArestaTest : public ::testing::Test {
protected:

    void SetUp() override {
        // Caso necessário, inicialize o objeto lista aqui
    }

    void TearDown() override {
        // Caso necessário, limpe os recursos aqui
    }
};

TEST_F(ArestaTest, TestCusto) {
    Vertice* v = new Vertice(0);
    Aresta* a = new Aresta(v, 1);
    EXPECT_EQ(a->getCusto(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}