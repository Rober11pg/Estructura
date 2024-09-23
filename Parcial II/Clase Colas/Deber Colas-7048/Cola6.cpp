/* 6.Generar una pila ordenada descendentemente con los valores comunes a varias colas ingresadas
Aoutor: Roberto Jiménez-7048 */
#include <iostream>
#include "Cola.h"
#include "Pila.h"
#define FIN 9999
using namespace std;


int main()
{
    system("color f0");
    int cantidadColas;
    void imprimirCola(Cola c);
    void IngresoColas(Cola *Colas, int cantColas);
    void leerCola(Cola *c);
    void ImpresionColas(Cola *Colas, int cantColas);
    void generarPilaOrdenada(Cola *colas, int cantColas);
    cout << "Ingrese la cantidad de colas: ";
    cin >> cantidadColas;

    Cola *colas = new Cola[cantidadColas];
    IngresoColas(colas, cantidadColas);
    ImpresionColas(colas, cantidadColas);

    generarPilaOrdenada(colas, cantidadColas);

    return 0;
    system("Pause");
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


void imprimirCola(Cola c)
{
    while (!c.colaVacia())
    {
        cout << c.quitar() << " ";
    }
    cout << endl;
}

void IngresoColas(Cola *Colas, int cantColas)
{
    for (int i = 0; i < cantColas; i++)
    {
        cout << "Ingresar elementos en la cola " << i + 1 << endl;
        leerCola(&Colas[i]);
    }
}

void ImpresionColas(Cola *Colas, int cantColas)
{
    for (int i = 0; i < cantColas; i++)
    {
        cout << "Elementos contenidos en la cola " << i + 1 << ": ";
        imprimirCola(Colas[i]);
    }
}

void generarPilaOrdenada(Cola *colas, int cantColas)
{
    Cola colaComun;
    Pilas pilaOrdenada;

    while (!colas[0].colaVacia())
    {
        Tipo valor = colas[0].quitar();

        bool esComun = true; // Indicador de si el valor es común a todas las colas
        
        for (int i = 1; i < cantColas; i++)
        {
            Cola colaActual = colas[i];

            bool encontrado = false;
            while (!colaActual.colaVacia())
            {
                Tipo elemento = colaActual.quitar();
                if (elemento == valor)
                {
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                esComun = false;
                break;
            }
        }

        if (esComun)
        {
            colaComun.insertar(valor);
        }
    }

    while (!colaComun.colaVacia())
    {
        pilaOrdenada.push(colaComun.quitar());
    }

    cout << "Pila ordenada descendentemente con los valores comunes:" << endl;
    while (!pilaOrdenada.pilaVacia())
    {
        cout << pilaOrdenada.pop() << endl;
    }
}
