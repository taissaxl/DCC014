#include "lista.h"
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
        No<T>* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

template <typename T>
void Lista<T>::adicionar(T* elemento) {
    No<T>* novo = new No<T>;
    novo->elemento = elemento;
    novo->proximo = NULL;
    if (this->primeiro == NULL) {
        this->primeiro = novo;
        this->ultimo = novo;
    } else {
        this->ultimo->proximo = novo;
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
    while (atual != NULL && atual->elemento != elemento) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
        return;

    if (anterior == NULL) {
        this->primeiro = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
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

template <typename T>
void Lista<T>::setPrimeiro(No<T>* primeiro) {
    this->primeiro = primeiro;
}

template <typename T>
void Lista<T>::setUltimo(No<T>* ultimo) {
    this->ultimo = ultimo;
}


