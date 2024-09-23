/* Permitir el ingreso de una Pila de valores, y desplazar de sus valores N posiciones (considere valores positivos y negativos).
Autor: Roberto Jiménez
Codigo: 7048  */

#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{
    Pilas p;
    int N;
    void LeerPilaR(Pilas * p1);
    void ImprimirPilaR(Pilas p1);
    void DesplazarPila(Pilas * p, int N);
    LeerPilaR(&p);

    cout << "Ingrese el numero de posiciones a desplazar (positivo para desplazar a la derecha, negativo para desplazar a la izquierda): " << endl;
    cin >> N;

    cout << "Pila original" << endl;
    ImprimirPilaR(p);
    DesplazarPila(&p, N);

    cout << "Pila desplazada: " << endl;
    ImprimirPilaR(p);
    cout << endl;
    system("pause");
    return 0;
}

void LeerPilaR(Pilas *p1)
{
    Tipo aux;
    Tipo fin = 999;

    do
    {
        cout << "Ingrese un valor a apilar. Finalice con " << fin << ": " << endl;
        cin >> aux;

        if (aux != fin)
        {
            if (!p1->pilaLlena())
            {
                p1->push(aux);
            }
            else
            {
                cout << "Error... Pila llena..." << endl;
                aux = fin;
            }
        }
    } while (aux != fin);
}

void ImprimirPilaR(Pilas p1)
{
    if (!p1.pilaVacia())
    {
        Tipo valor = p1.pop();
        cout << valor << endl;
        ImprimirPilaR(p1);
        p1.push(valor);
    }
}

void DesplazarPila(Pilas *p, int N)
{
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            Tipo valor = p->pop();
            p->push(valor);
        }
    }
    else if (N < 0)
    {
        N = -N;
        Pilas aux;

        for (int i = 0; i < N; i++)
        {
            Tipo valor = p->pop();
            aux.push(valor);
        }

        while (!aux.pilaVacia())
        {
            Tipo valor = aux.pop();
            p->push(valor);
        }
    }
}
