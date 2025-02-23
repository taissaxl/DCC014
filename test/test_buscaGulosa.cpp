#include <gtest/gtest.h>
#include "grafo.h"
#include "fazGrafo.h"
#include "lista.h"
#include "vertice.h"
#include "algoritmos/gulosa.h"

class BuscaGulosaTest : public ::testing::Test {
    protected:
        void SetUp() override {
            // Inicialização necessária antes de cada teste
        }
    
        void TearDown() override {
            // Limpeza necessária após cada teste
        }
};

#define CIDADE_A 0
#define CIDADE_B 1
#define CIDADE_C 2
#define CIDADE_D 3
#define CIDADE_E 4
#define CIDADE_F 5

// Teste da busca gulosa
TEST_F(BuscaGulosaTest, TestBuscaGulosa)
{
    Grafo* grafo = new Grafo();
    int auxId;

    // Adiciona vértices ao grafo
    for (int i = CIDADE_A; i <= CIDADE_F; i++){
        auxId = grafo->adicionarVertice();
    }

    // Adiciona arestas ao grafo
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

    // Executa a busca gulosa
    Lista<Vertice> caminhoCalculado = buscaGulosa(grafo, CIDADE_A, CIDADE_D);

    // Define o caminho esperado
    Lista<Vertice> caminhoEsperado;
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_A));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_B));
    caminhoEsperado.adicionar(grafo->getVertice(CIDADE_D));

    // Verifica se o caminho calculado é igual ao caminho esperado
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

// Função principal para executar os testes
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}