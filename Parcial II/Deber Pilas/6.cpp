/* Calcular el promedio de los elementos que ocupan las posiciones centrales de una pila
Autor: Roberto Jiménez
Código: 7048 */
#include <iostream>
#include "Pila.h"
#define FIN 999 // marcador de fin de lectura
using namespace std;

int main()
{                                     // programa principal
    Pilas p;                          // declracion de la pila a procesar
    void LeerPilaR(Pilas * p1);       // prototipo de la funcion que se diferencie el ingreso por recursividad
    void ImprimirPilaR(Pilas p1);     // prototipo de la funcion que imprime los valores del resutado
    double PromedioPares(Pilas p1);   // prototipo de la funcion que devuelve los valores pares
    double PromedioImpares(Pilas p1); // prototipo de la funcion que devuelve los valores impares
    LeerPilaR(&p);                    // llamos a la lectura de pila
    cout << "" << endl;
    cout << "Pila original: " << endl;
    ImprimirPilaR(p); // llamada a la funcion Imprimir
    int n = p.cimaPila();
    double pares = PromedioImpares(p);
    double impares = PromedioImpares(p);
    if (n % 2 == 1)
    {
        cout << "El pomedio impar es: " << pares << endl;
    }
    else
    {
        cout << "El pomedio par es: " << impares << endl;
    }
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

double PromedioPares(Pilas p1)
{
    if (!p1.pilaVacia())
    {

        double promedio = 0;
        int n = p1.tamanioPila();

        if (n % 2 == 1)
        {
            for (int i = 0; i <= n / 2; i++)
            {
                promedio = p1.pop();
            }
            promedio = p1.cimaPila();
        }
        return promedio;
    }
}

double PromedioImpares(Pilas p1)
{
    if (!p1.pilaVacia())
    {

        double par = 0;
        double promedio = 0;
        int n = p1.tamanioPila();
        for (int i = 0; i < n / 2; i++)
        {
            par = p1.pop();
        }
        par = par + p1.pop();
        promedio = par / 2;
        return promedio;
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
