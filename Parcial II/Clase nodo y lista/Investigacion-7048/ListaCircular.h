// ListaCircular.h
// Implementa el TDA Lista Circular
//Autor: Roberto Jiménez-7048 
#ifndef _LISTACIRCULAR_H
#define _LISTACIRCULAR_H

#include <iostream>
#include "Nodo.h"

class ListaCircular {
private:
    Nodo* primero;

public:
    ListaCircular();
    Nodo* getPrimero();
    void setPrimero(Nodo* p);
    bool esVacia();
    void insertarAlFinal(Tipo v);
    void imprimirLista();
    Nodo* buscarElemento(Tipo v);
    bool eliminarNodo(Tipo v);
    Nodo* ultimo();
};

ListaCircular::ListaCircular() {
    setPrimero(nullptr);
}

Nodo* ListaCircular::getPrimero() {
    return primero;
}

void ListaCircular::setPrimero(Nodo* p) {
    primero = p;
}

bool ListaCircular::esVacia() {
    return (getPrimero() == nullptr);
}

void ListaCircular::insertarAlFinal(Tipo v) {
    Nodo* nuevo = new Nodo(v);

    if (esVacia()) {
        setPrimero(nuevo);
        nuevo->setPunt(nuevo);
    } else {
        Nodo* ult = ultimo();
        nuevo->setPunt(ult->getPunt());
        ult->setPunt(nuevo);
    }
}

void ListaCircular::imprimirLista() {
    Nodo* actual = getPrimero();

    if (actual != nullptr) {
        do {
            std::cout << actual->getDato() << " ";
            actual = actual->getPunt();
        } while (actual != getPrimero());
    }

    std::cout << std::endl;
}

Nodo* ListaCircular::buscarElemento(Tipo v) {
    Nodo* actual = getPrimero();

    if (actual != nullptr) {
        do {
            if (actual->getDato() == v) {
                return actual;
            }
            actual = actual->getPunt();
        } while (actual != getPrimero());
    }

    return nullptr;
}

bool ListaCircular::eliminarNodo(Tipo v) {
    Nodo* actual = getPrimero();
    Nodo* anterior = nullptr;

    if (actual != nullptr) {
        do {
            if (actual->getDato() == v) {
                if (actual == getPrimero()) {
                    setPrimero(actual->getPunt());
                }

                if (anterior != nullptr) {
                    anterior->setPunt(actual->getPunt());
                }

                delete actual;
                return true;
            }

            anterior = actual;
            actual = actual->getPunt();
        } while (actual != getPrimero());
    }

    return false;
}

Nodo* ListaCircular::ultimo() {
    Nodo* actual = getPrimero();

    if (actual == nullptr) {
        return nullptr;
    }

    while (actual->getPunt() != getPrimero()) {
        actual = actual->getPunt();
    }

    return actual;
}

#endif
