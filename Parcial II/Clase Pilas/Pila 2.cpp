// Programa que permite el ingreso de visualizacion de datos
// en dos pilas y comprobalas
// programa que permite el ingreso y visualizacion de datos en una pila
#include <iostream>
#include "Pila.h"
using namespace std;

int main()
{

    Pilas p, q; // instanciacion de la funciones
    system("pause");
    void leerPila(Pilas * p1);             // prototipo de la funicon que permite el ingreso de elementos de una pila
    void imprimirPila(Pilas * p1);         // prototipo de la funcion permite la visualizacino de elementos de una pila
    bool comprobarPilas(Pilas p, Pilas q); // prototipo de la funcion que permite la comprobacion de las dos pilas

    cout << "Datos de la pila 1" << endl;
    leerPila(&p);     // llamdo de la funcion de lecctura
    imprimirPila(&p); // llamado de funcion imprimir

    cout << "Datos de la pila 2" << endl;
    leerPila(&q);
    imprimirPila(&q);

    cout << "Las dos pilas ingresadas " << (comprobarPilas(p, q) ? "Si" : "No") << " Son iguales" << endl;
}

void leerPila(Pilas *p1)
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

void imprimirPila(Pilas *p1)
{
    Tipo fin = 999; // declaracino del valor que marca fin de lectura
    Tipo aux;       // variable de lectura

    cout << "ELEMOSTOS CONTENIDO EN LA PILA " << endl;
    cout << "===================================" << endl;
    while (!p1->pilaVacia()) // la pila de elementos aun esta llena
    {
        aux = p1->pop();
        cout << "> " << aux << endl;
    }

    do
    { // ciclo de lectura

        if (aux != fin) // el valor ingresado no es igual al marcador de fin
        {
            if (!p1->pilaLlena()) // aun no esta llena la pila
            {
                p1->push(aux); // apilar el valor leido
            }
            else // la pila ya no esta llena
            {
                aux = fin; // valor ingreso paso al final
            }
        }
    } while (aux != fin); // repetir lectura si no ingresa
}

bool comprobarPilas(Pilas p, Pilas q)
{
    if (p.tamanioPila() != q.tamanioPila())
    {
        return false;
    }

    while (!p.pilaVacia()) // la pila tiene elemeos aun
    {
        if (p.pop() != q.pop())
        {
            return false;
        }
    }
    return true;
}
