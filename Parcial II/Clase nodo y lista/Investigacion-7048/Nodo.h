// Nodo.h
// Implementa el TDA Nodo
// Autor: Roberto Jiménez-7048
#ifndef _NODO_H
#define _NODO_H

typedef int Tipo; // Tipo de dato a almacenar en el nodo

class Nodo
{
private:
    Tipo dato;
    Nodo *siguiente;
    Nodo *anterior;

public:
    Nodo(Tipo valor);
    Tipo getDato();
    void setDato(Tipo valor);
    Nodo *getSiguiente();
    void setSiguiente(Nodo *siguiente);
    Nodo *getAnterior();
    void setAnterior(Nodo *anterior);
    Nodo *getPunt();
    void setPunt(Nodo *puntero);
};

Nodo::Nodo(Tipo valor)
{
    dato = valor;
    siguiente = nullptr;
    anterior = nullptr;
}

Tipo Nodo::getDato()
{
    return dato;
}

void Nodo::setDato(Tipo valor)
{
    dato = valor;
}

Nodo *Nodo::getSiguiente()
{
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente)
{
    this->siguiente = siguiente;
}

Nodo *Nodo::getAnterior()
{
    return anterior;
}

void Nodo::setAnterior(Nodo *anterior)
{
    this->anterior = anterior;
}

Nodo *Nodo::getPunt()
{
    return siguiente;
}

void Nodo::setPunt(Nodo *puntero)
{
    siguiente = puntero;
}

#endif
