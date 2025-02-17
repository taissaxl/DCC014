#include <gtest/gtest.h>
#include "vertice.h"
#include "no.h"

class VerticeTest : public ::testing::Test {
protected:

    void SetUp() override {
        // Caso necessário, inicialize o objeto lista aqui
    }

    void TearDown() override {
        // Caso necessário, limpe os recursos aqui
    }
};

TEST_F(VerticeTest, CriaVertice) {
    Vertice vertice(1);
    ASSERT_EQ(vertice.getId(), 1);
    ASSERT_EQ(vertice.getArestas()->getTamanho(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

