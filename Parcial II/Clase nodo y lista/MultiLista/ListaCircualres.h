// ListaCircular.h
// Implementa el TDA Lista Circular basado en la clase Lista

#ifndef _LISTACIRCULAR_H
#define _LISTACIRCULAR_H

#include "Lista.h"

class ListaCircular : public Lista
{
public:
    void insertarAlFinal(Tipo v);   // Inserta un nuevo nodo al final de la lista
    bool eliminarNodo(Tipo v);      // Elimina el nodo que contiene el valor v
};

void ListaCircular::insertarAlFinal(Tipo v)
{
    Nodo* nuevo = new Nodo(v);

    if (esVacia()) {
        setPrimero(nuevo);
        nuevo->setPunt(nuevo);
    }
    else {
        Nodo* ult = ultimo();
        ult->setPunt(nuevo);
        nuevo->setPunt(getPrimero());
    }
}

bool ListaCircular::eliminarNodo(Tipo v)
{
    Nodo* act = getPrimero();
    Nodo* ant = NULL;
    bool encontrado = false;

    if (!esVacia()) {
        do {
            if (act->getDato() == v) {
                encontrado = true;
                break;
            }

            ant = act;
            act = act->getPunt();
        } while (act != getPrimero());

        if (encontrado) {
            if (act == getPrimero()) {
                setPrimero(act->getPunt());
                Nodo* ult = ultimo();
                ult->setPunt(getPrimero());
            }
            else {
                ant->setPunt(act->getPunt());
            }

            delete act;
            return true;
        }
    }

    return false;
}

#endif
