// ListaDoblementeEnlazada.h
// Implementa el TDA Lista Doblemente Enlazada
// Autor: Roberto Jiménez-7048 

#ifndef _LISTADOBLEMENTEENLAZADA_H
#define _LISTADOBLEMENTEENLAZADA_H
using namespace std;
#include <iostream>
#include "Nodo.h"

class ListaDoblementeEnlazada
{
private:
    Nodo *primero;
    Nodo *ultimo;
    int tamano;

public:
    ListaDoblementeEnlazada();
    bool esVacia();
    void insertarAlPrincipio(Tipo valor);
    void insertarAlFinal(Tipo valor);
    void eliminarAlPrincipio();
    void eliminarAlFinal();
    int buscar(Tipo valor);
    int obtenerTamano();
    void imprimir();
    Nodo *getPrimero();
    Nodo *getUltimo();
	void invertir();
};

ListaDoblementeEnlazada::ListaDoblementeEnlazada()
{
    primero = nullptr;
    ultimo = nullptr;
    tamano = 0;
}

bool ListaDoblementeEnlazada::esVacia()
{
    return (primero == nullptr);
}

void ListaDoblementeEnlazada::insertarAlPrincipio(Tipo valor)
{
    Nodo *nuevo = new Nodo(valor);

    if (esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->setPunt(primero);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }

    tamano++;
}

void ListaDoblementeEnlazada::insertarAlFinal(Tipo valor)
{
    Nodo *nuevo = new Nodo(valor);

    if (esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->setAnterior(ultimo);
        ultimo->setPunt(nuevo);
        ultimo = nuevo;
    }

    tamano++;
}

void ListaDoblementeEnlazada::eliminarAlPrincipio()
{
    if (!esVacia())
    {
        Nodo *temp = primero;
        primero = primero->getPunt();
        if (primero != nullptr)
        {
            primero->setAnterior(nullptr);
        }
        else
        {
            ultimo = nullptr;
        }
        delete temp;
        tamano--;
    }
}

void ListaDoblementeEnlazada::eliminarAlFinal()
{
    if (!esVacia())
    {
        Nodo *temp = ultimo;
        ultimo = ultimo->getAnterior();
        if (ultimo != nullptr)
        {
            ultimo->setPunt(nullptr);
        }
        else
        {
            primero = nullptr;
        }
        delete temp;
        tamano--;
    }
}

int ListaDoblementeEnlazada::buscar(Tipo valor)
{
    Nodo *actual = primero;
    int indice = 0;

    while (actual != nullptr)
    {
        if (actual->getDato() == valor)
        {
            return indice;
        }

        actual = actual->getPunt();
        indice++;
    }

    return -1;
}

int ListaDoblementeEnlazada::obtenerTamano()
{
    return tamano;
}

void ListaDoblementeEnlazada::imprimir()
{
    if (!esVacia())
    {
        Nodo *actual = primero;

        while (actual != nullptr)
        {
            std::cout << actual->getDato() << " ";
            actual = actual->getPunt();
        }

        std::cout << std::endl;
    }
}

Nodo *ListaDoblementeEnlazada::getPrimero()
{
    return primero;
}

Nodo *ListaDoblementeEnlazada::getUltimo()
{
    return ultimo;
}

void ListaDoblementeEnlazada::invertir()
{
    if (!esVacia())
    {
        Nodo *actual = primero;
        Nodo *temp = nullptr;

        while (actual != nullptr)
        {
            temp = actual->getAnterior();
            actual->setAnterior(actual->getSiguiente());
            actual->setSiguiente(temp);
            actual = actual->getAnterior();
        }

        temp = primero;
        primero = ultimo;
        ultimo = temp;
    }
}


#endif
