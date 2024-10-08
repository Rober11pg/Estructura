/* Intercambiar, por parejas, los elementos de una pila previamente ingresada (primero con segundo, tercero con cuarto, etc.).
Autor: Roberto Jiménez
Código: 7048 */
#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{                                   // programa principal
    Pilas p;                        // declracion de la pila a procesar
    Tipo val;                       // valor que se multiplica
    void LeerPilaR(Pilas * p1);     // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1);   // prototipo de la funcion que imprime los valores del resutado
    void Intercambiarpos(Pilas p1); // prototipo de la funcion que intercambia la posicion primera con segunda, tercera con cuarta etc..
    LeerPilaR(&p);                  // llamos a la lectura de pila
    cout << "" << endl;

    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    Intercambiarpos(p);
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

void ImprimirPilaR(Pilas p1)
{
    if (!p1.pilaVacia()) // la pila aun tiene elementos
    {
        cout << "> " << p1.pop() << endl; // presentamos el elemento extraido y lo eliminamos de la pila
        ImprimirPilaR(p1);                // funcino recursiva que vuelve a llamar a la funcino
    }
}

void Intercambiarpos(Pilas p1)
{
    Pilas aux;
    Pilas aux2;
    while (!p1.pilaVacia())
    {
        Tipo var1 = p1.pop();
        Tipo var2 = p1.pop();
        aux.push(var2);
        aux.push(var1);
    }

    while (!aux.pilaVacia())
    {
        Tipo v = aux.pop();
        aux2.push(v);
    }
    cout << "Pila intercambiada: " << endl;
    ImprimirPilaR(aux2);
}
