/* Insertar N elementos en las posiciones centrales de una pila
Autor: Roberto Jiménez
Codigo: 7048 */

#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{            // programa principal
    Pilas p; // declracion de la pila a procesar
    Pilas Auxp;
    int sum = 0;
    void LeerPilaR(Pilas * p1);              // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1);            // prototipo de la funcion que imprime los valores del resutado
    void Insertar(Pilas * p1, Pilas * Auxp); // prototipo de la funcion que inserta valorees en la posicion central
    LeerPilaR(&p);                           // llamos a la lectura de pila
    cout << "" << endl;
    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    Insertar(&p, &Auxp);
    cout << "Pilas con valores insertados" << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    cout << "" << endl;
    system("pause");
}

void LeerPilaR(Pilas *p1) // funcion que permite el ingreso de valores de la pila
{
    Tipo aux;       // variable de lectura
    Tipo fin = 999; // declaracino del valor que marca fin de lectura
    do
    { // ciclo de lectura
        cout << "Ingrese un valor a apilar. Finalice con  " << fin << ": " << endl;
        cin >> aux; // Lectura

        if (aux != fin) // el valor ingresado no es igual al marcador de fin
        {
            if (!p1->pilaLlena()) // aun no esta llena la pila
            {
                p1->push(aux); // apilar el valor leido
            }
            else // la pila ya no esta llena
            {
                cout << "Error... Pila llena..." << endl;
                aux = fin; // valor ingreso paso al final
            }
        }
    } while (aux != fin); // repetir lectura si no ingresa
}

void Insertar(Pilas *p1, Pilas *Auxp)
{
    int n = p1->tamanioPila();

    if (n % 2 == 1) // inserta para los impares
    {
        for (int i = 0; i <= n / 2; i++)
        {
            Auxp->push(p1->pop());
        }

        LeerPilaR(Auxp);

        while (!p1->pilaVacia())
        {
            Auxp->push(p1->pop());
        }

        while (!Auxp->pilaVacia())
        {
            p1->push(Auxp->pop());
        }
    }
    else // Si la cantidad de elementos es par
    {
        int mitad = n / 2;
        for (int i = 0; i < mitad; i++)
        {
            Auxp->push(p1->pop());
        }
        LeerPilaR(Auxp);

        while (!Auxp->pilaVacia())
        {
            p1->push(Auxp->pop());
        }
    }
}

void ImprimirPilaR(Pilas p1)
{
    if (!p1.pilaVacia()) // la pila aun tiene elementos
    {
        cout << "> " << p1.pop() << endl; // presentamos el elemento extraido y lo eliminamos de la pila
        ImprimirPilaR(p1);                // funcino recursiva que vuelve a llamar a la funcino
    }
}
