/* Ingresar una pila de elementos entre los cuales se admite únicamente hasta N valores repetidos
 (Si se alcanza dicho valor, se aceptarán solamente valores únicos.
 Autor: Roberto Jiménez
 Código: 7048*/
#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{                                 // programa principal
    Pilas p;                      // declracion de la pila a procesar
    void LeerPilaR(Pilas * p1);   // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1); // prototipo de la funcion que imprime los valores del resutado
    bool ExisteN(Pilas p1, Tipo valor, int N);
    LeerPilaR(&p); // llamos a la lectura de pila
    cout << "" << endl;
    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    system("pause");
}

bool ExisteN(Pilas p1, Tipo valor, int N)
{
    Pilas pAux;
    int cont = 0;
    while (!p1.pilaVacia())
    {
        Tipo elemento = p1.pop();
        if (elemento == valor)
        {
            cont += 1;
            if (cont >= N)
            {
                return true;
            }
        }
        pAux.push(elemento);
    }

    while (!pAux.pilaVacia())
    {
        p1.push(pAux.pop());
    }

    return false;
}

void LeerPilaR(Pilas *p1) // funcion que permite el ingreso de valores de la pila
{

    Tipo aux;       // variable de lectura
    Tipo fin = 999; // declaracino del valor que marca fin de lectura
    int N;
    cout << "Ingrese la cantidad de N veces que quiera que se repita un numero: " << endl;
    cin >> N;
    do
    { // ciclo de lectura
        cout << "Ingrese un valor a apilar. Finalice con  " << fin << ": " << endl;
        cin >> aux; // Lectura

        if (aux != fin) // el valor ingresado no es igual al marcador de fin
        {
            if (!ExisteN(*p1, aux, N))
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
            else
            {
                cout << "El valor " << aux << " que ingreso solo puede repetirse " << N << " veces ..." << endl;
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