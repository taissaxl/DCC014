#ifndef LISTA_H
#define LISTA_H

#include "no.h"

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
        bool estaVazia();
        int getTamanho();
};

#endif // LISTA_H

