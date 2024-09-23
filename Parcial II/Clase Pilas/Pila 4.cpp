// pila 4
// programa que permita el ingreso de una pila de valores
// y proceda a comprobar si esta ordenado

// Autro Roberto Jiménez

#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{            // programa principal
    Pilas p; // declracion de la pila a procesar
    int aux = 0;
    Tipo val;                                        // valor que se multiplica
    void LeerPilaR(Pilas * p1);                      // prototipo de la funcion que se diferencie el ingreso por recursividad
    bool PilaverificarOrden(Pilas * p1, Tipo * aux); // prototipo de la funcion que comprueba si esta ordenada o no la pila
    void ImprimirPilaR(Pilas p1);                    // prototipo de la funcion que permite imprimir la pila respuesta

    LeerPilaR(&p); // llamos a la lectura de pila
    PilaverificarOrden(&p, &aux);

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
bool PilaverificarOrden(Pilas *p1, int *aux)
{
    if (!p1->pilaVacia())
    {
        if (p1->cimaPila() >= *aux)
        {
            *aux = p1->pop();
            PilaverificarOrden(p1, aux);
        }
        // Terminar 
        if(p1->cimaPila() <= *aux){
            *aux = p1->pop();

        }

        return false;
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