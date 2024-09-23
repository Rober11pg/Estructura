// pila 3
// programa que permita el ingreso de una pila de valores
// y proceda a multiplicar sus elementos por un nuevo valor ingresado por el usr

// Autro Roberto Jiménez

#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{            // programa principal
    Pilas p; // declracion de la pila a procesar
    Pilas aux;
    Tipo val;                                             // valor que se multiplica
    void LeerPilaR(Pilas * p1);                           // prototipo de la funcion que se diferencie el ingreso por recursividad
    void amplificarPila(Pilas * p1, Pilas * aux, Tipo a); // prototipo de la funcion que amplifica la pila
    void ImprimirPilaR(Pilas p1);                         // prototipo de la funcion que permite imprimir la pila respuesta

    LeerPilaR(&p); // llamos a la lectura de pila
    cout << "Ingrese el valor que se debe multiplicar: " << endl;
    cin >> val;
    cout << "" << endl;
    amplificarPila(&p, &aux, val); // llamada a la funcino amplificada
    ImprimirPilaR(p);              // llamada a la funcion Imprimir
    system("pause");
}

void LeerPilaR(Pilas *p1) // funcion que permite el ingreso de valores de la pila
{
    Tipo vl; // variable de lectura
    cout << "Ingrese el valor a apliar. Finalice con 999" << endl;
    cin >> vl;

    if (vl != FIN) // aun no se ingresa el valor final de la pila
    {
        p1->push(vl);  // apilr el elemento
        LeerPilaR(p1); // llamado recursivo al nuevo valor por apilar
    }
}
void amplificarPila(Pilas *p1, Pilas *aux, Tipo a)
{
    if (!p1->pilaVacia())
    {
        aux->push(p1->pop() * a); // extrae un elemento de p1, lo multiplica por a, y lo que se obtiene del producto lo guarda en la pila auxiliar
        cout << "El numero aux es: " << aux->cimaPila() << endl;
        amplificarPila(p1, aux, a); // llamado recursivo amplicar
        p1->push(aux->pop());       // Devolver el valor ya amplifica a p1
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