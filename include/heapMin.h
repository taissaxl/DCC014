using namespace std;

class HeapMin {
    private:
        int *heap;
        int tamanho;
        int capacidade;

        void subir(int i);
        void descer(int i);

    public:
        HeapMin(int capacidade);
        ~HeapMin();
        void inserir(int elemento);
        int remover();
        int getMin();
        int getTamanho();
        void imprimir();
}