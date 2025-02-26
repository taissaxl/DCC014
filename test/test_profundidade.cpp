#include <gtest/gtest.h>
#include "grafo.h"
#include "fazGrafo.h"
#include "lista.h"
#include "vertice.h"
#include "algoritmos/profundidade.h"
#include <iostream> // Para mensagens de depuração

class BuscaProfundidadeTest : public ::testing::Test {
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

TEST_F(BuscaProfundidadeTest, TestBuscaProfundidade)
{
    Grafo* grafo = new Grafo();
    int auxId;

    // Adicionando vértices ao grafo
    for (int i = CIDADE_A; i <= CIDADE_F; i++) {  // Ajustei o <= para incluir F
        auxId = grafo->adicionarVertice();
        std::cout << "Vértice adicionado: " << auxId << std::endl;  // Depuração
    }

    // Adicionando arestas ao grafo
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

    // Verificando se os vértices existem
    Vertice* v1 = grafo->getVertice(CIDADE_A);
    Vertice* v2 = grafo->getVertice(CIDADE_B);
    Vertice* v3 = grafo->getVertice(CIDADE_D);

    if (!v1 || !v2 || !v3) {
        std::cerr << "Erro: Um dos vértices é nullptr!" << std::endl;
        exit(1);  // Interrompe o teste caso um vértice seja inválido
    }

    // Definindo o caminho esperado
    Lista<Vertice> caminhoEsperado;
    caminhoEsperado.adicionar(v1);
    caminhoEsperado.adicionar(v2);
    caminhoEsperado.adicionar(v3);

    Lista<Vertice> caminhoCalculado = buscaProfundidade(grafo, CIDADE_A, CIDADE_D);

    // Exibir caminho calculado
    std::cout << "Caminho calculado:" << std::endl;
    for (auto it = caminhoCalculado.begin(); it != caminhoCalculado.end(); ++it) {
        std::cout << (*it)->getId() << " ";
    }
    std::cout << std::endl;

    // Verificando se a busca retornou um caminho válido
    if (caminhoCalculado.getTamanho() == 0) {
        std::cerr << "Erro: Caminho não encontrado na busca em profundidade!" << std::endl;
        exit(1);
    }

    // Verificando o tamanho do caminho
    ASSERT_EQ(caminhoCalculado.getTamanho(), caminhoEsperado.getTamanho());

    // Comparando os vértices dos caminhos calculados e esperados
    auto it1 = caminhoCalculado.begin();
    auto it2 = caminhoEsperado.begin();

    while (it1 != caminhoCalculado.end() && it2 != caminhoEsperado.end()) {
        EXPECT_EQ((*it1)->getId(), (*it2)->getId());
        ++it1;
        ++it2;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
