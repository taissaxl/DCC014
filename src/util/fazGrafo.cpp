#include "grafo.h"
#include "fazGrafo.h"

Grafo* fazerGrafo() {
    Grafo* grafo = new Grafo();

    int auxInt;

    for (int i = 0; i < 20; i++) {
        auxInt = grafo->adicionarVertice();
    }
    

    grafo->adicionarAresta(JUIZ_DE_FORA, CEL_PACHECO, 35);
    grafo->adicionarAresta(JUIZ_DE_FORA, BICAS, 40);
    grafo->adicionarAresta(CEL_PACHECO, RIO_POMBA, 50);
    grafo->adicionarAresta(CEL_PACHECO, GOIANA, 15);
    grafo->adicionarAresta(BICAS, SAO_JOAO_NEPOMUCENO, 25);
    grafo->adicionarAresta(BICAS, LEOPOLDINA, 60);
    grafo->adicionarAresta(RIO_POMBA, TOCANTINS, 20);
    grafo->adicionarAresta(GOIANA, RIO_NOVO, 20);
    grafo->adicionarAresta(SAO_JOAO_NEPOMUCENO, GUARANI, 35);
    grafo->adicionarAresta(LEOPOLDINA, CATAGUASES, 25);
    grafo->adicionarAresta(TOCANTINS, PIRAUBA, 30);
    grafo->adicionarAresta(TOCANTINS, UBA, 15);
    grafo->adicionarAresta(RIO_NOVO, GUARANI, 15);
    grafo->adicionarAresta(GUARANI, PIRAUBA, 20);
    grafo->adicionarAresta(CATAGUASES, SANTANA_DO_CAMPESTE, 20);
    grafo->adicionarAresta(CATAGUASES, MIRAI, 35);
    grafo->adicionarAresta(PIRAUBA, SANTANA_DO_CAMPESTE, 25);
    grafo->adicionarAresta(UBA, VISCONDE_DO_RIO_BRANCO, 25);
    grafo->adicionarAresta(SANTANA_DO_CAMPESTE, RODEIRO, 15);
    grafo->adicionarAresta(MIRAI, VISCONDE_DO_RIO_BRANCO, 40);
    grafo->adicionarAresta(MIRAI, MURIAE, 30);
    grafo->adicionarAresta(VISCONDE_DO_RIO_BRANCO, VICOSA, 30);
    grafo->adicionarAresta(VISCONDE_DO_RIO_BRANCO, RODEIRO, 15);
    grafo->adicionarAresta(MURIAE, ERVALIA, 45);
    grafo->adicionarAresta(ERVALIA, VICOSA, 25);

    return grafo;
}