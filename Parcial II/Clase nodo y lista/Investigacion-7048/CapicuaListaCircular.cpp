/*Verificar si un numero es capicua o no
Autor: Roberto Jiménez-7048 */
#include <iostream>
#include "ListaCircular.h"
#define FIN 9999
using namespace std;
int main()
{
    system("color f0");
    ListaCircular l;
    void ingresarLista(ListaCircular *l);
    void imprimirLista(ListaCircular l1);
    bool esCapicua(int numero);
    ingresarLista(&l);
    imprimirLista(l);

    cout << endl
         << "Verificar si los numeros son capicua:" << endl;

    Nodo *actual = l.getPrimero();
    while (actual != nullptr)
    {
        int numero = actual->getDato();
        cout << numero << ": ";
        if (esCapicua(numero))
        {
            cout << "Es capicua" << endl;
        }
        else
        {
            cout << "No es capicua" << endl;
        }
        actual = actual->getSiguiente();
        if (actual == l.getPrimero())
        {
            break;
        }
    }

    cout << endl;
    system("pause");
    return 0;
}

bool esCapicua(int numero)
{
    int numeroInvertido = 0;
    int numeroOriginal = numero;

    while (numero > 0)
    {
        int digito = numero % 10;
        numeroInvertido = numeroInvertido * 10 + digito;
        numero /= 10;
    }

    return numeroOriginal == numeroInvertido;
}

void ingresarLista(ListaCircular *l)
{
    Tipo aux; // variable de lectura
    cout << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: " << endl;
    cin >> aux;

    if (aux != FIN)
    {
        l->insertarAlFinal(aux); // se ingresa elemento a la lista
        ingresarLista(l);
    }
}

void imprimirLista(ListaCircular l1)
{
    Nodo *actual;
    actual = l1.getPrimero();

    if (actual != nullptr)
    {
        do
        {
            cout << endl
                 << "> " << actual->getDato() << endl;
            actual = actual->getSiguiente();
        } while (actual != l1.getPrimero());
    }
}
