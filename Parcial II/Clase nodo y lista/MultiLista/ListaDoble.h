#ifndef _LISTADOBLE_H
#define _LISTADOBLE_H

#include "NodoDoble.h"

class ListaDoble {
private:
    NodoDoble* primero;
    NodoDoble* ultimo;

public:
    ListaDoble();
    void setPrimero(NodoDoble* nodo);
    NodoDoble* getPrimero();
    void setUltimo(NodoDoble* nodo);
    NodoDoble* getUltimo();
    bool esVacia();
    void vaciar();
    void insertarAlInicio(Tipo dato);
    void insertarAlFinal(Tipo dato);
    bool eliminarNodo(Tipo dato);
};

ListaDoble::ListaDoble() {
    primero = NULL;
    ultimo = NULL;
}

void ListaDoble::setPrimero(NodoDoble* nodo) {
    primero = nodo;
}

NodoDoble* ListaDoble::getPrimero() {
    return primero;
}

void ListaDoble::setUltimo(NodoDoble* nodo) {
    ultimo = nodo;
}

NodoDoble* ListaDoble::getUltimo() {
    return ultimo;
}

bool ListaDoble::esVacia() {
    return (primero == NULL);
}

void ListaDoble::vaciar() {
    primero = NULL;
    ultimo = NULL;
}

void ListaDoble::insertarAlInicio(Tipo dato) {
    NodoDoble* nuevo = new NodoDoble(dato);

    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        nuevo->setSiguiente(primero);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }
}

void ListaDoble::insertarAlFinal(Tipo dato) {
    NodoDoble* nuevo = new NodoDoble(dato);

    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}

bool ListaDoble::eliminarNodo(Tipo dato) {
    if (esVacia()) {
        return false;
    }

    NodoDoble* actual = primero;

    while (actual != nullptr && actual->getDato() != dato) {
        actual = actual->getSiguiente();
    }

    if (actual == NULL) {
        return false;
    }

    NodoDoble* ant = actual->getAnterior();
    NodoDoble* sig = actual->getSiguiente();

    if (ant != NULL) {
        ant->setSiguiente(sig);
    }
    else {
        primero = sig;
    }

    if (sig != NULL) {
        sig->setAnterior(ant);
    }
    else {
        ultimo = ant;
    }

    delete actual;
    return true;
}

#endif
