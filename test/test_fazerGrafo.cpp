#include <gtest/gtest.h>
#include "lista.h"
#include "aresta.h"
#include "vertice.h"

class FazerGrafoTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Caso necessário, inicialize o objeto lista aqui
    }

    void TearDown() override {
        // Caso necessário, limpe os recursos aqui
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
