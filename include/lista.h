#ifndef LISTA_H
#define LISTA_H

using namespace std;

template <typename T>
class Lista {
    private:
        No<T> *primeiro;
        No<T> *ultimo;
        int tamanho;

    public:
        Lista();
        ~Lista();
        void adicionar(T* elemento);
        void remover(T* elemento);
        No<T>* getPrimeiro();
        No<T>* getUltimo();
        int getTamanho();
        void setPrimeiro(No<T>* primeiro);
        void setUltimo(No<T>* ultimo)
};

#endif // LISTA_H

