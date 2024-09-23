/* Ingresar una lista de numeros y invertir su orden
Autor: Roberto Jiménez-7048 */
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    ListaDoblementeEnlazada l;
    void ingresarLista(ListaDoblementeEnlazada * l);
    void imprimirLista(ListaDoblementeEnlazada l1);
    ingresarLista(&l);
    cout << "Lista ingresada:" << endl;
    imprimirLista(l);

    l.invertir();
    cout << "Lista invertida:" << endl;
    imprimirLista(l);

    cout << endl;
    system("pause");
    return 0;
}

void ingresarLista(ListaDoblementeEnlazada *l)
{
    Tipo aux; // variable de lectura
    cout << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: " << endl;
    cin >> aux;

    while (aux != FIN)
    {
        l->insertarAlFinal(aux); // se ingresa elemento a la lista
        cout << "Ingrese otro valor a la lista. Finalice con [" << FIN << "]: " << endl;
        cin >> aux;
    }
}

void imprimirLista(ListaDoblementeEnlazada l1)
{
    Nodo *actual = l1.getPrimero();

    while (actual != nullptr)
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getSiguiente();
    }
}
