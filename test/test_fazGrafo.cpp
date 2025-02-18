#include <gtest/gtest.h>
#include "grafo.h"
#include "fazGrafo.h"

class FazGrafoTest : public ::testing::Test {
    protected:
    
        void SetUp() override {
            // Caso necessário, inicialize o objeto lista aqui
        }
    
        void TearDown() override {
            // Caso necessário, limpe os recursos aqui
        }
    };

TEST_F(FazGrafoTest, TestConfereVizinhancaDeSantanaDoCampeste)
{
    Grafo* grafo = fazerGrafo();

    int custoSantanaDoCampesteParaPirauba = 25;
    int custoSantanaDoCampesteParaCataguases = 20;
    int custoSantanaDoCampesteParaRodeiro = 15;

    ASSERT_EQ(custoSantanaDoCampesteParaPirauba, grafo->getCustoEntreVertices(SANTANA_DO_CAMPESTE, PIRAUBA));
    ASSERT_EQ(custoSantanaDoCampesteParaCataguases, grafo->getCustoEntreVertices(SANTANA_DO_CAMPESTE, CATAGUASES));
    ASSERT_EQ(custoSantanaDoCampesteParaRodeiro, grafo->getCustoEntreVertices(SANTANA_DO_CAMPESTE, RODEIRO));
    ASSERT_EQ(-1, grafo->getCustoEntreVertices(SANTANA_DO_CAMPESTE, JUIZ_DE_FORA));

}
    
int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }