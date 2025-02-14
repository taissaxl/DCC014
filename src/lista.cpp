#include "lista.h"

Lista::Lista() {
    this->primeiro = NULL;
    this->ultimo = NULL;
    this->tamanho = 0;
}

Lista::~Lista() {
    No* atual = this->primeiro;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

void Lista::adicionar(T* elemento) {
    No* novo = new No;
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

void Lista::remover(T* elemento) {
    if (this->primeiro == NULL)
        return;

    No* anterior = NULL;
    No* atual = this->primeiro;
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

bool Lista::estaVazia() {
    return this->primeiro == NULL;
}

int Lista::getTamanho() {
    return this->tamanho;
}

No<T>* Lista::getPrimeiro() {
    return this->primeiro;
}

No<T>* Lista::getUltimo() {
    return this->ultimo;
}

void Lista::setPrimeiro(No<T>* primeiro) {
    this->primeiro = primeiro;
}

void Lista::setUltimo(No<T>* ultimo) {
    this->ultimo = ultimo;
}


