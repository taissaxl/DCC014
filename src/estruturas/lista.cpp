#include "lista.h"
#include "aresta.h"
#include "vertice.h"
#include <cstddef>

template <typename T>
Lista<T>::Lista() {
    this->primeiro = NULL;
    this->ultimo = NULL;
    this->tamanho = 0;
}

template <typename T>
Lista<T>::~Lista() {
    No<T>* atual = this->primeiro;
    while (atual != NULL) {
        No<T>* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
}

template <typename T>
void Lista<T>::adicionar(T* elemento) {
    No<T>* novo = new No<T>(elemento);
    novo->setProximo(NULL);
    if (this->primeiro == NULL) {
        this->primeiro = novo;
        this->ultimo = novo;
    } else {
        this->ultimo->setProximo(novo);
        this->ultimo = novo;
    }
    this->tamanho++;
}

template <typename T>
void Lista<T>::remover(T* elemento) {
    if (this->primeiro == NULL)
        return;

    No<T>* anterior = NULL;
    No<T>* atual = this->primeiro;
    while (atual != NULL && atual->getElemento() != elemento) {
        anterior = atual;
        atual = atual->getProximo();
    }

    if (atual == NULL) //nao achou o elemento
        return;

    if (anterior == NULL) { // o elemento eh o começo
        this->primeiro = atual->getProximo();
    } else {
        anterior->setProximo(atual->getProximo());
    }

    if (atual == this->ultimo) {
        this->ultimo = anterior;
    }

    delete atual;
    this->tamanho--;
}

template <typename T>
bool Lista<T>::estaVazia() {
    return this->primeiro == NULL;
}

template <typename T>
int Lista<T>::getTamanho() {
    return this->tamanho;
}

template <typename T>
No<T>* Lista<T>::getPrimeiro() {
    return this->primeiro;
}

template <typename T>
No<T>* Lista<T>::getUltimo() {
    return this->ultimo;
}

template class Lista<int>;
template class Lista<Aresta>;
template class Lista<Vertice>;