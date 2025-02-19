#include <gtest/gtest.h>
#include "lista.h"

class ListaTest : public ::testing::Test {
protected:
    Lista<int> lista;

    void SetUp() override {
        // Caso necessário, inicialize o objeto lista aqui
    }

    void TearDown() override {
        // Caso necessário, limpe os recursos aqui
    }
};

TEST_F(ListaTest, TestAdicionar) {
    int elemento = 5;
    lista.adicionar(&elemento);
    EXPECT_EQ(lista.getTamanho(), 1);
    EXPECT_EQ(*(lista.getPrimeiro()->getElemento()), elemento);
}

TEST_F(ListaTest, TestRemover) {
    int elemento = 5;
    lista.adicionar(&elemento);
    lista.remover(&elemento);
    EXPECT_EQ(lista.getTamanho(), 0);
    EXPECT_TRUE(lista.estaVazia());
}

TEST_F(ListaTest, TestEstaVazia) {
    EXPECT_TRUE(lista.estaVazia());
    int elemento = 5;
    lista.adicionar(&elemento);
    EXPECT_FALSE(lista.estaVazia());
}

TEST_F(ListaTest, TestGetTamanho) {
    EXPECT_EQ(lista.getTamanho(), 0);
    int elemento1 = 5;
    int elemento2 = 10;
    lista.adicionar(&elemento1);
    lista.adicionar(&elemento2);
    EXPECT_EQ(lista.getTamanho(), 2);
}

TEST_F(ListaTest, TestGetPrimeiroUltimo) {
    int elemento1 = 5;
    int elemento2 = 10;
    lista.adicionar(&elemento1);
    lista.adicionar(&elemento2);
    EXPECT_EQ(*(lista.getPrimeiro()->getElemento()), elemento1);
    EXPECT_EQ(*(lista.getUltimo()->getElemento()), elemento2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

