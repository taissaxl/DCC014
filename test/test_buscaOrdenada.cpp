#include <gtest/gtest.h>
#include <stdexcept>
#include "aresta.h"
#include "no.h"
#include "grafo.h"
#include "fazGrafo.h"
#include "lista.h"
#include "vertice.h"
#include "algoritmos/ordenada.h"

class BuscaOrdenadaTest : public ::testing::Test {
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




TEST_F(BuscaOrdenadaTest, TestConstrucaoGrafo) {
    Grafo* grafo = new Grafo();


    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();
    int idC = grafo->adicionarVertice();

 
    grafo->adicionarAresta(idA, idB, 1);
    grafo->adicionarAresta(idB, idC, 2);


    ASSERT_NE(grafo->getVertice(idA), nullptr);
    ASSERT_NE(grafo->getVertice(idB), nullptr);
    ASSERT_NE(grafo->getVertice(idC), nullptr);


    ASSERT_TRUE(grafo->existeAresta(idA, idB));
    ASSERT_TRUE(grafo->existeAresta(idB, idC));
    ASSERT_FALSE(grafo->existeAresta(idA, idC)); 
}

TEST_F(BuscaOrdenadaTest, TestFilaInit) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();
    grafo->adicionarAresta(idA, idB, 1);

    FilaOrdenada fila(idB, idA, grafo);

    ASSERT_EQ(fila.exploraMenorAberto(), true);
}

TEST_F(BuscaOrdenadaTest, TestExploraMenorAberto) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();
    int idC = grafo->adicionarVertice();
    grafo->adicionarAresta(idA, idB, 1);
    grafo->adicionarAresta(idB, idC, 2);

    FilaOrdenada fila(idC, idA, grafo);

    ASSERT_TRUE(fila.exploraMenorAberto());

    ASSERT_TRUE(fila.exploraMenorAberto());

    ASSERT_FALSE(fila.exploraMenorAberto());

}

TEST_F(BuscaOrdenadaTest, TestReconstruirCaminho) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();
    int idC = grafo->adicionarVertice();
    grafo->adicionarAresta(idA, idB, 1);
    grafo->adicionarAresta(idB, idC, 2);

    FilaOrdenada fila(idC, idA, grafo);

    while (fila.exploraMenorAberto()) {}

    Lista<Vertice> caminho = fila.reconstruirCaminho();

    ASSERT_EQ(caminho.getTamanho(), 3);
    auto it = caminho.begin();
    ASSERT_EQ((*it)->getId(), idA); 
    ++it;
    ASSERT_EQ((*it)->getId(), idB); 
    ++it;
    ASSERT_EQ((*it)->getId(), idC); 
}

TEST_F(BuscaOrdenadaTest, TestSemCaminho) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();

    Lista<Vertice> caminho = buscaOrdenada(grafo, idA, idB);

    ASSERT_EQ(caminho.getTamanho(), 1);
    ASSERT_EQ((*caminho.begin())->getId(), idA);
}

TEST_F(BuscaOrdenadaTest, TestSingleVertex) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();

    Lista<Vertice> caminho = buscaOrdenada(grafo, idA, idA);
    ASSERT_EQ(caminho.getTamanho(), 1);
    ASSERT_EQ((*caminho.begin())->getId(), idA);
}

TEST_F(BuscaOrdenadaTest, TestLargeGraph) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();
    int idB = grafo->adicionarVertice();
    int idC = grafo->adicionarVertice();
    int idD = grafo->adicionarVertice();
    int idE = grafo->adicionarVertice();

    grafo->adicionarAresta(idA, idB, 1);
    grafo->adicionarAresta(idA, idC, 4);
    grafo->adicionarAresta(idB, idC, 2);
    grafo->adicionarAresta(idB, idD, 5);
    grafo->adicionarAresta(idC, idD, 1);
    grafo->adicionarAresta(idD, idE, 3);

    Lista<Vertice> caminho = buscaOrdenada(grafo, idA, idE);

    // Expected path: A -> B -> C -> D -> E
    ASSERT_EQ(caminho.getTamanho(), 5);
    auto it = caminho.begin();
    ASSERT_EQ((*it)->getId(), idA);
    ++it;
    ASSERT_EQ((*it)->getId(), idB);
    ++it;
    ASSERT_EQ((*it)->getId(), idC);
    ++it;
    ASSERT_EQ((*it)->getId(), idD);
    ++it;
    ASSERT_EQ((*it)->getId(), idE);
}

TEST_F(BuscaOrdenadaTest, TestInputInvalido) {
    Grafo* grafo = new Grafo();
    int idA = grafo->adicionarVertice();

    // Non-existent destination
    EXPECT_THROW(buscaOrdenada(grafo, idA, 999), std::runtime_error);

    // Non-existent start
    EXPECT_THROW(buscaOrdenada(grafo, 999, idA), std::runtime_error);
}

TEST_F(BuscaOrdenadaTest, TestBuscaOrdenada)
{
    Grafo* grafo = new Grafo();
    int auxId;

    for (int i = CIDADE_A; i <= CIDADE_F; i++){
        auxId = grafo->adicionarVertice();
    }

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

    Lista<Vertice> caminhoCalculado = buscaOrdenada(grafo, CIDADE_A, CIDADE_D);

    // Verifica se buscaOrdenada retornou um caminho válido
    ASSERT_GT(caminhoCalculado.getTamanho(), 0) << "buscaOrdenada retornou um caminho vazio!";

    // Recupera os vértices esperados e verifica se não são nulos
    Vertice* vA = grafo->getVertice(CIDADE_A);
    Vertice* vB = grafo->getVertice(CIDADE_B);
    Vertice* vD = grafo->getVertice(CIDADE_D);

    ASSERT_NE(vA, nullptr) << "Vertice CIDADE_A não encontrado!";
    ASSERT_NE(vB, nullptr) << "Vertice CIDADE_B não encontrado!";
    ASSERT_NE(vD, nullptr) << "Vertice CIDADE_D não encontrado!";

    Lista<Vertice> caminhoEsperado;
    caminhoEsperado.adicionar(vA);
    caminhoEsperado.adicionar(vB);
    caminhoEsperado.adicionar(vD);

    // Verifica se os tamanhos das listas são os mesmos antes de iterar
    ASSERT_EQ(caminhoCalculado.getTamanho(), caminhoEsperado.getTamanho()) 
        << "Os tamanhos dos caminhos calculado e esperado não batem!";

    // Verifica se os iteradores não estão vazios
    ASSERT_NE(caminhoCalculado.begin(), caminhoCalculado.end()) 
        << "Iterador de caminhoCalculado aponta para lista vazia!";
    ASSERT_NE(caminhoEsperado.begin(), caminhoEsperado.end()) 
        << "Iterador de caminhoEsperado aponta para lista vazia!";

    auto it1 = caminhoCalculado.begin();
    auto it2 = caminhoEsperado.begin();

    while (it1 != caminhoCalculado.end() && it2 != caminhoEsperado.end()) {
        EXPECT_EQ((*it1)->getId(), (*it2)->getId())
            << "Os IDs dos vértices nos caminhos calculado e esperado não batem!";
        ++it1;
        ++it2;
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}