#ifndef NO_H
#define NO_H

template <typename T>
class No {
    private:
        T* elemento;
        No<T>* proximo;
        No<T>* anterior;
    public:
        No(T* elemento) : elemento(elemento), proximo(nullptr), anterior(nullptr) {}
        T* getElemento() { return elemento; }
        No<T>* getProximo() { return proximo; }
        No<T>* getAnterior() { return anterior; }
        void setProximo(No<T>* proximo) { this->proximo = proximo; }
        void setAnterior(No<T>* anterior) { this->anterior = anterior; }
};

#endif // NO_H