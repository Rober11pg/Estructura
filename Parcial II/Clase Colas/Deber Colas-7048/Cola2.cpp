/* 2.Intercambiar las posiciones pares con las impares dentro de un TDA Cola ingresado previamente
Autor: Roberto Jiménez-7048*/
#include <iostream>
#include "Cola.h"
#define FIN 9999
using namespace std;


int main()
{
    system("color f0");
    Cola a, b;
    void leerCola(Cola * c1);
    void imprimirCola(Cola c1);
    void intercambiarPosicionesParesImpares(Cola *cola);

    leerCola(&a);

    cout << "Elementos contenidos en la TDA:" << endl;
    imprimirCola(a);

    intercambiarPosicionesParesImpares(&a);
    cout << "" << endl;
    cout << "Elementos intercambiados:" << endl;
    imprimirCola(a);

    system("pause");
}

void leerCola(Cola *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con [" << FIN << "]" << endl;
    cin >> x;
    if (x != FIN)
    {
        if (!c1->colaLlena())
        {
            c1->insertar(x);
            leerCola(c1);
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}

void imprimirCola(Cola c1)
{
    Cola temp;
    while (!c1.colaVacia())
    {
        Tipo valor = c1.quitar();
        cout << valor << " ";
        temp.insertar(valor);
    }
    cout << endl;

    // Restaurar la cola original
    while (!temp.colaVacia())
    {
        Tipo valor = temp.quitar();
        c1.insertar(valor);
    }
}

void intercambiarPosicionesParesImpares(Cola *cola)
{
    int tamanio = cola->tamanioCola();

    Cola colaPares, colaImpares;

    // Separar los elementos en colas pares e impares
    for (int i = 0; i < tamanio; i++)
    {
        Tipo elemento = cola->quitar();

        if (i % 2 == 0)
        {
            colaPares.insertar(elemento);
        }
        else
        {
            colaImpares.insertar(elemento);
        }
    }

    // Intercambiar posiciones pares e impares
    while (!colaPares.colaVacia() && !colaImpares.colaVacia())
    {
        Tipo elementoPar = colaPares.quitar();
        Tipo elementoImpar = colaImpares.quitar();

        cola->insertar(elementoImpar);
        cola->insertar(elementoPar);
    }

    // Insertar elementos restantes, en caso de haber
    while (!colaPares.colaVacia())
    {
        Tipo elemento = colaPares.quitar();
        cola->insertar(elemento);
    }

    while (!colaImpares.colaVacia())
    {
        Tipo elemento = colaImpares.quitar();
        cola->insertar(elemento);
    }
}