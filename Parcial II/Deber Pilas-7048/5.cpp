/* Implementar el ordenamiento por inserción en una pila
Autor: Roberto Jiménez
Codigo: 7048 */
#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{                                 // programa principal
    Pilas p;                      // declracion de la pila a procesar
    void LeerPilaR(Pilas * p1);   // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1); // prototipo de la funcion que imprime los valores del resutado
    void Inserccion(Pilas * p);   // prototipo que va a ordenar los elementos
    LeerPilaR(&p);                // llamos a la lectura de pila
    Inserccion(&p);
    cout << "" << endl;
    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    system("pause");
}

void LeerPilaR(Pilas *p1) // funcion que permite el ingreso de valores de la pila
{
    Tipo aux;       // variable de lectura
    Tipo fin = 999; // declaracino del valor que marca fin de lectura
    do
    { // ciclo de lecturas
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

void Inserccion(Pilas *p1)
{
    Pilas aux;
    while (!p1->pilaVacia())
    {
        Tipo tem = p1->pop();
        while (!aux.pilaVacia() && aux.cimaPila() > tem) // cima pila debe ser mayor que la variable tamporal
        {
            p1->push(aux.pop());
        }
        aux.push(tem);
    }

    while (!aux.pilaVacia()) // Ingresar los los elementos al objeto p1, mientras al mismo tiempo voy quitando los elementos del objeto aux
    {
        p1->push(aux.pop());
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
