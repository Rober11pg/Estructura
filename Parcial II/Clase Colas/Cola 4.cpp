/* Programa que implementa la gestion básica del TDA Cola
Determinar si una cola A, B estan mutuamnte contenidas*/

#include <iostream>
#include "Cola.h"
// # instrucciones de prefuncionamiento, gobernar la compilación
#define FIN 9999 // definicion del marcado de fin de lecura
using namespace std;

int main()
{

    Cola a, b;                           // declaración de 2 objetos ingresados
    Tipo vb;                             // valor a buscar
    void leerCola(Cola * c1);            // prototipo de la funcion que ingresa valores en el TDA (se pone por referencia por que va a cambiar los datos de la funcion)
    void imprimirCola(Cola c1);          // prototipo de la funcion que imprime los valroes del TDA
    bool estaEnCola(Cola c1, Tipo v);    // prototipo de la funcion que determina si v esta contenido en c1
    bool estaIncluida(Cola c1, Cola c2); // Si cola c1 esta contenida en c2

    cout << "Ingreso de cola A " << endl;
    cout << "***********************" << endl;
    leerCola(&a);

    cout << "Ingreso de cola B " << endl;
    cout << "***********************" << endl;
    leerCola(&b);

    cout << "Elementos contenidos en Cola A" << endl;
    cout << "***********************************" << endl;
    imprimirCola(a);
    cout << "" << endl;

    cout << "Elementos contenidos en Cola B" << endl;
    cout << "***********************************" << endl;
    imprimirCola(b);

    cout << "Todos los elementos de la cola A, B " << ((estaIncluida(a, b)) && (estaIncluida(b, a)) ? " SI" : " NO ") << " estan mutuanmente contenidas..." << endl;
    system("pause");
}

void leerCola(Cola *c1)
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

void imprimirCola(Cola c1) // no se hace cambios por esos está por valor, si se hace cambios se hace con punteros
{
    if (!c1.colaVacia()) // aun hay elementos en el TDA ?
    {
        cout << "> " << c1.quitar() << endl;
        imprimirCola(c1); // llamado recursivo al TDA
    }
}

bool estaEnCola(Cola c1, Tipo v)
{
    while (!c1.colaVacia()) // aun hay elementos en cola
    {
        if (v == c1.quitar()) // encontramos
        {
            return true;
        }
    }
    return false; // no econtramos este valor dntro de la estructura
}

bool estaIncluida(Cola c1, Cola c2)
{
    while (!c1.colaVacia()) // mientras haya elementos en cola c1
    {
        if (!estaEnCola(c2, c1.quitar())) // hay un valor de c1 que no esta en c2
        {
            return false; // devolver respuesta falsa por que almenos un valor de c1 no esta contenido en c2
        }
    }
    return true; // todos los elementos de c1 estan contenidos en c2
}