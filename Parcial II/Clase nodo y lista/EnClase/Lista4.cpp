/*Permitir el ingreso de 2 listar
1 preceder a intercalar

Lista 1         Lista 2         Lista 3
1                   6               1
2                   7               6
                                    2
                                    7

Autor: Roberto Jiménez*/
#include <iostream>
#include "Lista.h"
#include "Pila.h"
#define FIN 99999 // marcador de final de lectura

using namespace std;

void ingresarLista(Lista* l); // función que permite el ingreso de valores a la lista
void imprimirLista(Lista l);  // función que imprime los elementos de la lista
void TerceraLista(Lista l1, Lista l2, Lista* l3); // función que intercala los elementos de l1 y l2 en l3

int main()
{
    system("color f0");
    Lista l1; // crea el objeto de tipo lista
    Lista l2; // crea el objeto de tipo lista
    Lista l3; // crea el objeto de tipo lista

    cout << "Primera lista" << endl;
    cout << "===================" << endl;
    ingresarLista(&l1);
    cout << "Segunda lista" << endl;
    cout << "===================" << endl;
    ingresarLista(&l2);

    TerceraLista(l1, l2, &l3);

    cout << "Tercera lista (intercalada):" << endl;
    cout << "===================" << endl;
    imprimirLista(l3);

    cout << endl;
    system("pause");
    return 0;
}

void ingresarLista(Lista* l)
{
    Tipo aux; // variable de lectura

    cout << endl << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    while (aux != FIN)
    {
        l->insertarAlFinal(aux); // se añade el elemento a la lista
        cout << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";
        cin >> aux;
    }
}

void imprimirLista(Lista l)
{
    Nodo* actual = l.getPrimero();

    while (actual != NULL)
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt();
    }
}

void TerceraLista(Lista l1, Lista l2, Lista* l3)
{
    Nodo* act1 = l1.getPrimero();
    Nodo* act2 = l2.getPrimero();

    while (act1 != NULL && act2 != NULL)
    {
        l3->insertarAlFinal(act1->getDato());
        l3->insertarAlFinal(act2->getDato());
        act1 = act1->getPunt();
        act2 = act2->getPunt();
    }

    // Si aún quedan elementos en la lista 1, los agregamos al final de la lista 3
    while (act1 != NULL)
    {
        l3->insertarAlFinal(act1->getDato());
        act1 = act1->getPunt();
    }

    // Si aún quedan elementos en la lista 2, los agregamos al final de la lista 3
    while (act2 != NULL)
    {
        l3->insertarAlFinal(act2->getDato());
        act2 = act2->getPunt();
    }
}
