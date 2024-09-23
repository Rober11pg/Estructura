/*Permitir el ingreso de varios AB y determinar cuáles, entre ellos son SIMILARES
(iguales estructuras, contenidos de los nodos distintas), EQUIVALENTES (similares,
y los nodos contienen los mismos valores) y DISTINTOS (con estructuras distintas)
Nombre: Roberto Jiménez-7048 */

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

bool sonArbolesSimilares(NodoBinario *nodo1, NodoBinario *nodo2);
bool sonArbolesEquivalentes(NodoBinario *nodo1, NodoBinario *nodo2);
bool sonArbolesDistintos(NodoBinario *nodo1, NodoBinario *nodo2);
NodoBinario *leerNodo(int margen);
void leerAB(ArbolBinario *b);
void imprimirEsp(int c);
void imprimirAB(ArbolBinario a);

int main()
{
    system("color f0");
    int numArboles;
    cout << "Ingrese la cantidad de arboles que desea ingresar: ";
    cin >> numArboles;

    ArbolBinario *arboles = new ArbolBinario[numArboles];
    for (int i = 0; i < numArboles; i++)
    {
        cout << endl
             << "ARBOL " << i + 1 << endl;
        leerAB(&arboles[i]);
        imprimirAB(arboles[i]);
    }

    cout << endl
         << "RESULTADOS:" << endl;
    for (int i = 0; i < numArboles; i++)
    {
        for (int j = i + 1; j < numArboles; j++)
        {
            cout << endl
                 << "ARBOL " << i + 1 << " y ARBOL " << j + 1 << ":" << endl;
            if (sonArbolesSimilares(arboles[i].getRaiz(), arboles[j].getRaiz()))
            {
                cout << "Son arboles SIMILARES" << endl;
            }
            else
            {
                cout << "No son arboles SIMILARES" << endl;
            }

            if (sonArbolesEquivalentes(arboles[i].getRaiz(), arboles[j].getRaiz()))
            {
                cout << "Son arboles EQUIVALENTES" << endl;
            }
            else
            {
                cout << "No son arboles EQUIVALENTES" << endl;
            }

            if (sonArbolesDistintos(arboles[i].getRaiz(), arboles[j].getRaiz()))
            {
                cout << "Son arboles DISTINTOS" << endl;
            }
            else
            {
                cout << "No son arboles DISTINTOS" << endl;
            }
        }
    }

    delete[] arboles;

    cout << endl;
    system("pause");
}

NodoBinario *leerNodo(int margen)
{
    Tipo aux;
    Tipo fin = 99999;
    NodoBinario *p = nullptr;

    void imprimirEsp(int c);

    cout << endl;
    imprimirEsp(margen);
    cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
    cin >> aux;

    if (aux != fin)
    {
        p = new NodoBinario(aux);
        imprimirEsp(margen);
        cout << "--- SUBARBOL IZQUIERDO ---";
        p->setIzq(leerNodo(margen + 1));
        imprimirEsp(margen);
        cout << "--- SUBARBOL DERECHO ---";
        p->setDer(leerNodo(margen + 1));
    }

    return p;
}

void leerAB(ArbolBinario *b)
{
    b->setRaiz(leerNodo(0));
}

void imprimirEsp(int c)
{
    for (int i = 1; i <= c; i++)
    {
        cout << "   ";
    }
}

void imprimirAB(ArbolBinario a)
{
    cout << endl
         << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl
         << endl;
    a.imprimirABSimple(a.getRaiz());

    cout << endl
         << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl
         << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);
}

bool sonArbolesSimilares(NodoBinario *nodo1, NodoBinario *nodo2)
{
    if (nodo1 == NULL && nodo2 == NULL)
    {
        return true;
    }

    if (nodo1 == NULL || nodo2 == NULL)
    {
        return false;
    }

    return sonArbolesSimilares(nodo1->getIzq(), nodo2->getIzq()) &&
           sonArbolesSimilares(nodo1->getDer(), nodo2->getDer());
}

bool sonArbolesEquivalentes(NodoBinario *nodo1, NodoBinario *nodo2)
{
    if (nodo1 == NULL && nodo2 == NULL)
    {
        return true;
    }

    if (nodo1 == NULL || nodo2 == NULL)
    {
        return false;
    }

    return nodo1->getDato() == nodo2->getDato() &&
           sonArbolesEquivalentes(nodo1->getIzq(), nodo2->getIzq()) &&
           sonArbolesEquivalentes(nodo1->getDer(), nodo2->getDer());
}

bool sonArbolesDistintos(NodoBinario *nodo1, NodoBinario *nodo2)
{
    if (nodo1 == NULL && nodo2 == NULL)
    {
        return false;
    }

    if (nodo1 == NULL || nodo2 == NULL)
    {
        return true;
    }

    return nodo1->getDato() != nodo2->getDato() ||
        sonArbolesDistintos(nodo1->getIzq(), nodo2->getIzq()) ||
        sonArbolesDistintos(nodo1->getDer(), nodo2->getDer());
}