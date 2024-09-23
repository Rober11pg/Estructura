/* 9. Calcular la diferencia existente entre el N-ésimo elemento de una cola, y los valores precedentes a este
Autor: Roberto Jiménez*/

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#define FIN 9999

using namespace std;

int main()
{
    system("color f0");
    Cola c;
    Tipo vb;
    Cola presentacion;
    void leerCola(Cola * c1);
    void imprimirCola(Cola c1);
    bool estaEnCola(Cola c1, Tipo v);
    void DiferenciaNesimo(Cola * c1, Tipo v, Cola * Presentacion);

    leerCola(&c);
    cout << "Elementos contenidos en la TDA" << endl;
    cout << "***********************************" << endl;
    imprimirCola(c);
    cout << endl;

    cout << "Ingrese el valor de la cola de valores para calcular los N-esimos terminos: " << endl;
    cin >> vb;

    if (estaEnCola(c, vb))
    {
        DiferenciaNesimo(&c, vb, &presentacion);
        cout << "La diferencia existente entre el N-ésimo elemento (" << vb << ") de la cola y los valores precedentes a este son:" << endl;
        cout << "***********************************" << endl;
        imprimirCola(presentacion);
    }
    else
    {
        cout << "El valor no se encuentra en la cola." << endl;
    }

    return 0;
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
    Cola aux = c1;
    while (!aux.colaVacia())
    {
        cout << "> " << aux.frentecola() << endl;
        aux.quitar();
    }
}

bool estaEnCola(Cola c1, Tipo v)
{
    Cola aux = c1;
    while (!aux.colaVacia())
    {
        if (aux.frentecola() == v)
        {
            return true;
        }
        aux.quitar();
    }
    return false;
}

void DiferenciaNesimo(Cola *c1, Tipo v, Cola *Presentacion)
{
    Pilas aux;

    while (c1->frentecola() != v)
    {
        aux.push(c1->frentecola());
        c1->quitar();
    }

    c1->quitar(); // Quitamos el elemento N-ésimo
    while (!aux.pilaVacia())
    {
        Tipo diferencia = v - aux.pop();
        Presentacion->insertar(diferencia);
    }
}
