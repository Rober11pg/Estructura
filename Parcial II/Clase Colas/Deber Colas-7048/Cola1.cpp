/*  1. Eliminar los valores repetidos en una cola previamente ingresada
Autor: Roberto Jiménez-7048
*/

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
    void EliminarRepetidos(Cola * c1, Cola * c2);
    leerCola(&a);
    cout << "Elementos contenidos en el TDA" << endl;
    cout << "***********************************" << endl;
    imprimirCola(a);
    cout << endl;

    EliminarRepetidos(&a, &b);
    cout << "Elementos contenidos en la cola sin repetidos" << endl;
    cout << "***********************************" << endl;
    imprimirCola(b);
    cout << endl;

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
    if (!c1.colaVacia())
    {
        cout << "> " << c1.quitar() << endl;
        imprimirCola(c1);
    }
}

void EliminarRepetidos(Cola *c1, Cola *c2)
{
    Cola aux;

    while (!c1->colaVacia())
    {
        Tipo elemento = c1->quitar();
        bool repetido = false;

        // Verificar si el elemento ya está en la cola aux
        while (!c2->colaVacia())
        {
            Tipo tempElemento = c2->quitar();
            if (tempElemento == elemento)
            {
                repetido = true;
            }
            aux.insertar(tempElemento);
        }

        // Restaurar los elementos en c2
        while (!aux.colaVacia())
        {
            Tipo tempElemento = aux.quitar();
            c2->insertar(tempElemento);
        }

        // Si no es repetido, agregarlo a c2
        if (!repetido)
        {
            c2->insertar(elemento);
        }
    }
}
