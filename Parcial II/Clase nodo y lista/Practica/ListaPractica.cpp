/* Elaborar un programa recursivo que permita modificar el orden de los elementos de una lista ingresada,
de forma que los N últimos nodos pasen a ser los primeros. Ejemplo:
Lista: 1 -> 2 -> 3 -> 4 -> 5 -> 6.
Si N = 4 (los cuatro últimos elementos pasan a ser los primeros)
Lista: 3 -> 4 -> 5 -> 6 -> 1 -> 2
Autor: Roberto Jiménez-7048*/

#include <iostream>
#include "Lista.h"
#define FIN 999 // Marcador final de lectura

void imprimirLista(Lista *l);
void modificarOrden(Lista *l, int n);
void ingresarLista(Lista *l);

int main()
{
    Lista l;

    ingresarLista(&l);

    int N;
    std::cout << "Ingrese el número de últimos elementos que desea pasar como primeros en la lista: ";
    std::cin >> N;

    modificarOrden(&l, N);

    std::cout << "Lista modificada:" << std::endl;
    imprimirLista(&l);

    return 0;
}

void imprimirLista(Lista *l)
{
    Nodo *actual = l->getPrimero();
    while (actual != NULL)
    {
        std::cout << "> " << actual->getDato() << std::endl;
        actual = actual->getPunt();
    }
}

void modificarOrden(Lista *l, int n)
{
    Nodo *actual = l->getPrimero();
    Nodo *nuevoPrimero = nullptr;
    Nodo *ultimoNuevo = nullptr;
    Nodo *ultimoOriginal = nullptr;
    int count = 0;

    while (actual != nullptr)
    {
        count++;
        if (count > n)
        {
            if (nuevoPrimero == nullptr)
            {
                nuevoPrimero = actual;
            }
            if (actual->getPunt() == nullptr)
            {
                ultimoNuevo = actual;
            }
        }
        if (actual->getPunt() == nullptr)
        {
            ultimoOriginal = actual;
        }
        actual = actual->getPunt();
    }

    if (nuevoPrimero != nullptr && ultimoNuevo != nullptr && ultimoOriginal != nullptr)
    {
        ultimoOriginal->setPunt(l->getPrimero());
        l->setPrimero(nuevoPrimero);
        ultimoNuevo->setPunt(nullptr);
    }
}

void ingresarLista(Lista *l)
{
    Tipo aux;

    std::cout << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";
    std::cin >> aux;

    while (aux != FIN)
    {
        l->insertarAlFinal(aux);
        std::cout << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";
        std::cin >> aux;
    }
}
