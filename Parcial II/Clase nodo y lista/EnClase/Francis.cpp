/* Ingresar vario números en orden y luego verificar si es primo, si es primo eliminar su nodo
Autor: Francis Sepulveda-7220 */
#include <iostream>
#include "Lista.h"
#define FIN 99999 // marcador de final de lectura

int main()
{
    system("color f0");
    Lista l;
    void ingresarLista(Lista * l1);
    void imprimirLista(Lista l1);
    bool esPrimo(Tipo num);
    void eliminarPrimos(Lista * l);
    cout << "El apuntador primero apunta a: " << l.getPrimero() << endl;
    cout << "La lista " << (l.esVacia() ? "SI" : "NO") << " esta vacia" << endl;

    ingresarLista(&l);
    cout << "Lista ingresada:" << endl;
    imprimirLista(l);
    eliminarPrimos(&l);
    cout << "Lista despues de eliminar los numeros primos:" << endl;
    imprimirLista(l);
    cout << endl;
    system("pause");
}

void ingresarLista(Lista *l1)
{
    Tipo aux; // var de lectura

    cout << endl
         << "Ingrese un valor a anadir en la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if (aux != FIN)
    {
        l1->insertarEnOrden(aux); // se añade elemento a la lista
        ingresarLista(l1);
    }
}

void imprimirLista(Lista l1)
{
    Nodo *act = l1.getPrimero();

    while (act != nullptr)
    {
        cout << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}

bool esPrimo(Tipo num)
{
    if (num <= 1)
    {
        return false;
    }
    for (Tipo i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void eliminarPrimos(Lista *l)
{
    Nodo *actual = l->getPrimero();
    Nodo *anterior = nullptr;

    while (actual != nullptr)
    {
        Tipo dato = actual->getDato();
        if (esPrimo(dato))
        {
            if (anterior == nullptr)
            {
                l->setPrimero(actual->getPunt());
                delete actual;
                actual = l->getPrimero();
            }
            else
            {
                anterior->setPunt(actual->getPunt());
                delete actual;
                actual = anterior->getPunt();
            }
        }
        else
        {
            anterior = actual;
            actual = actual->getPunt();
        }
    }
}