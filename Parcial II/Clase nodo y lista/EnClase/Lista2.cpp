
// Lista1.cpp
// Implementar una lista simplemente enlazada
// Autor: Julio Santillán C.

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999 // marcador de final de lectura

int main()
{ // programa principal
    system("color f0");
    Lista l;                        // crea el objeto de tipo lista
    void ingresarLista(Lista * l1); // funcion que permite el ingreso de valores a la lista
    void imprimirLista(Lista l1);   // funcion que permite el ingreso de valores a la lista
    int contarNodos(Nodo * act);
    ingresarLista(&l);
    cout << "La lista contiene: " << contarNodos(l.getPrimero()) << endl;

    cout << endl
         << "El apuntador primero apunta a: " << l.getPrimero();
    cout << endl
         << "La lista " << (l.esVacia() ? "SI" : "NO") << " esta vacia";
    imprimirLista(l);

    cout << endl;
    system("pause");
}

void ingresarLista(Lista *l1)
{             // funcion que permite el ingreso de valores a la lista
    Tipo aux; // var de lectura

    cout << endl
         << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if (aux != FIN)
    {
        //		l1->insertarAlInicio(aux);		//se añade elemento a la lista
        //		l1->insertarAlFinal(aux);		//se añade elemento a la lista
        l1->insertarEnOrden(aux); // se añade elemento a la lista
        ingresarLista(l1);
    }
}

void imprimirLista(Lista l1)
{ // funcion que permite el ingreso de valores a la lista
    Nodo *act;

    act = l1.getPrimero();
    while (act != NULL)
    {
        cout << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}

int contarNodos(Nodo *act) // funcion que contabilisa el numero de nodos
{
    if (act != NULL) // act apunta a un nodo dentro de la lista
    {
        return 1 + contarNodos(act->getPunt()); // direccino donde apunta el nodo actual para que camine y le vuelva a transferir la misma lista
                                                // devolver conteo del nodo actual mas el resultado devuelto del siguiente llamado recursivo
    }
    return 0; // valor devuelto por el ultimo llamado a la función recursiva
}