/* programa que implementa la gestion básica del TDA cola
    Autor: Roberto Jiménez */
#include <iostream>
#include "ColaCircular.h"
// # instrucciones de prefuncionamiento, gobernar la compilación 
#define FIN 9999 // definicion del marcado de fin de lecura
using namespace std;

int main()
{
    ColaCircular c;
    void leerCola(Cola * c1);   // prototipo de la funcion que ingresa valores en el TDA (se pone por referencia por que va a cambiar los datos de la funcion)
    void imprimirCola(Cola c1); // prototipo de la funcion que imprime los valroes del TDA
    leerCola(&c);
    cout << "Elementos contenidos en el TDA cola circular" << endl;
    cout << "***********************************" << endl;
    imprimirCola(c);
    cout << "" << endl;

    system("pause");
}

void leerCola(ColaCircular *c1)
{
    Tipo x; // variable de lectura
    cout << "Ingrese el valor a insertar. Finalice con 999 [" << FIN << "]" << endl;
    cin >> x;
    if (x != FIN) // no ingresa el marcado del final
    {
        if (!c1->colaLlena()) // cuadno aun hay disponibilidad para insertar nuevos valores
        {
            c1->insertar(x); // llamado a metetodo de inserccion
            leerCola(c1);    // llamado recursivo al metodo de lectura
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}

void imprimirCola(ColaCircular c1) // no se hace cambios por esos está por valor, si se hace cambios se hace con punteros 
{
    if (!c1.colaVacia()) // aun hay elementos en el TDA ?
    {
        cout << "> " << c1.quitar() << endl;
        imprimirCola(c1); // llamado recursivo al TDA
    }
}