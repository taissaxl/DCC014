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

        class Iterador {
            private:
                No<T>* atual;
        
            public:
                Iterador(No<T>* no) : atual(no) {}
        
                // preincremento
                Iterador& operator++() {
                    if (atual) {
                        atual = atual->getProximo();
                    }
                    return *this;
                }
        
                // desigualdade
                bool operator!=(const Iterador& outro) const {
                    return atual != outro.atual;
                }
        
                // retorna o elemento do iterador
                T* operator*() const {
                    return atual->getElemento();
                }
            };
        
            // Métodos para retornar iteradores
            Iterador begin() {
                return Iterador(primeiro);
            }
        
            Iterador end() {
                return Iterador(nullptr);
            }
};

#endif // LISTA_H

