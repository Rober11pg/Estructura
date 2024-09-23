/* Encontrar el máximo y mínimo elemento de una pila
Autor: Roberto Jiménez
Código: 7048  */
#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main() // programa principal
{
    Pilas p;                        // declracion de la pila a procesar
    void LeerPilaR(Pilas * p1);     // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1);   // prototipo de la funcion que imprime los valores del resutado
    int Mayor(Pilas p1, int mayor); // prototipo de la funcion que verifica el numero mayor de la pila.
    int Menor(Pilas p1, int menor); // prototipo de la funcion que verifica el numero menor de la pila.
    LeerPilaR(&p);                  // llamos a la lectura de pila
    cout << "" << endl;
    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    cout << "El numero mayor es: " << Mayor(p, p.cimaPila()) << endl;
    cout << "El numero menor es: " << Menor(p, p.cimaPila()) << endl;
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

int Mayor(Pilas p1, int mayor)
{
    if (!p1.pilaVacia())
    {
        int elemento = p1.pop();
        if (elemento > mayor)
        {
            mayor = elemento;
        }
        return Mayor(p1, mayor);
    }

    return mayor;
}

int Menor(Pilas p1, int menor)
{
    if (!p1.pilaVacia())
    {
        int elemento = p1.pop();
        if (elemento < menor)
        {
            menor = elemento;
        }
        return Menor(p1, menor);
    }

    return menor;
}