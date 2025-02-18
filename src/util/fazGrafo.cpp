#include "grafo.h"
#define  JUIZ_DE_FORA               0
#define  CEL_PACHECO                1
#define  BICAS                      2
#define  RIO_POMBA                  3 
#define  GOIANA                     4 
#define  SAO_JOAO_NEPOMUCENO        5 
#define  LEOPOLDINA                 6 
#define  GUARANI                    7 
#define  RIO_NOVO                   8  
#define  CATAGUASES                 9    
#define  TOCANTINS                  10
#define  PIRAUBA                    11
#define  SANTANA_DO_CAMPESTE        12
#define  RODEIRO                    13
#define  UBA                        14
#define  VISCONDE_DO_RIO_BRANCO     15
#define  MIRAI                      16
#define  MURIAE                     17
#define  ERVALIA                    18
#define  VICOSA                     19

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