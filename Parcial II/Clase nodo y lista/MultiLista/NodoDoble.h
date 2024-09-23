#ifndef _NODODOB_H
#define _NODODOB_H
#include<iostream>
typedef int Tipo; // Tipo de dato del nodo (puedes cambiarlo según tus necesidades)

class NodoDoble
{
private:
    Tipo dato;         // Dato almacenado en el nodo
    NodoDoble *siguiente; // Puntero al siguiente nodo
    NodoDoble *anterior;  // Puntero al nodo anterior

public:
    NodoDoble(Tipo v);          // Constructor que recibe el dato del nodo
    Tipo getDato();             // Devuelve el dato del nodo
    void setDato(Tipo v);       // Establece el dato del nodo
    NodoDoble *getSiguiente();  // Devuelve el puntero al siguiente nodo
    void setSiguiente(NodoDoble *nodo); // Establece el puntero al siguiente nodo
    NodoDoble *getAnterior();   // Devuelve el puntero al nodo anterior
    void setAnterior(NodoDoble *nodo);  // Establece el puntero al nodo anterior
};

NodoDoble::NodoDoble(Tipo v)
{
    dato = v;
    siguiente = NULL;
    anterior = NULL;
}

Tipo NodoDoble::getDato()
{
    return dato;
}

void NodoDoble::setDato(Tipo v)
{
    dato = v;
}

NodoDoble *NodoDoble::getSiguiente()
{
    return siguiente;
}

void NodoDoble::setSiguiente(NodoDoble *nodo)
{
    siguiente = nodo;
}

NodoDoble *NodoDoble::getAnterior()
{
    return anterior;
}

void NodoDoble::setAnterior(NodoDoble *nodo)
{
    anterior = nodo;
}

#endif
