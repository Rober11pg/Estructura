
/* Permitir el ingreso de una pila de valores, proceder a intercalar sus valores de inicio y final
 (primero, último, segundo, penúltimo, tercero, antepenúltimo, etc.)
 Autor Roberto Jiménez
 Codigo:7048 */

#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

void LeerPilaR(Pilas *p1);        // prototipo de la función que se encarga del ingreso por recursividad
void IntercalarPila(Pilas *pila); // prototipo de la función que intercala los valores de inicio y final
void ImprimirPilaR(Pilas p1);     // prototipo de la función que imprime los valores de la pila

int main()
{
    Pilas p; // declaración de la pila a procesar
    LeerPilaR(&p);

    cout << "Pila original: " << endl;
    ImprimirPilaR(p);

    cout << "Pila intercalada: " << endl;
    IntercalarPila(&p);
    ImprimirPilaR(p);

    return 0;
}

void LeerPilaR(Pilas *p1)
{
    Tipo aux;       // variable de lectura
    Tipo fin = 999; // valor que marca el fin de la lectura
    do
    {
        cout << "Ingrese un valor a apilar. Finalice con " << fin << ": ";
        cin >> aux;

        if (aux != fin) // el valor ingresado no es igual al marcador de fin
        {
            if (!p1->pilaLlena()) // la pila aún no está llena
            {
                p1->push(aux); // apilar el valor leído
            }
            else // la pila está llena
            {
                cout << "Error... Pila llena..." << endl;
                aux = fin; // valor de ingreso se coloca al final
            }
        }
    } while (aux != fin); // repetir la lectura si no se ingresa el marcador de fin
}

void IntercalarPila(Pilas *pila)
{
    Pilas pilaAux1; // pila auxiliar para almacenar la mitad inferior de los valores
    Pilas pilaAux2; // pila auxiliar para almacenar la mitad superior de los valores

    int tamanio = pila->tamanioPila();
    int mitad = tamanio / 2;

    // Extraer los valores de la pila original y almacenarlos en las pilas auxiliares
    for (int i = 0; i < tamanio; i++)
    {
        if (i < mitad)
        {
            Tipo valor = pila->pop();
            pilaAux1.push(valor);
        }
        else
        {
            Tipo valor = pila->pop();
            pilaAux2.push(valor);
        }
    }

    // Intercalar los valores en la pila original
    while (!pilaAux1.pilaVacia() || !pilaAux2.pilaVacia())
    {
        if (!pilaAux1.pilaVacia())
        {
            Tipo valor = pilaAux1.pop();
            pila->push(valor);
        }

        if (!pilaAux2.pilaVacia())
        {
            Tipo valor = pilaAux2.pop();
            pila->push(valor);
        }
    }
}

void ImprimirPilaR(Pilas p1)
{
    if (!p1.pilaVacia()) // la pila aún tiene elementos
    {
        Tipo valor = p1.pop();
        cout << "> " << valor << endl; // presentamos el elemento extraído
        ImprimirPilaR(p1);             // función recursiva que vuelve a llamar a la función
    }
}
