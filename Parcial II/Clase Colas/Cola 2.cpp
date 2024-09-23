/* Programa que implementa la gestion básica del TDA Cola
Determinar la presencia de elementos dentro de la estructura */

#include <iostream>
#include "Cola.h"
// # instrucciones de prefuncionamiento, gobernar la compilación
#define FIN 9999 // definicion del marcado de fin de lecura
using namespace std;

int main()
{

    Cola c;
    Tipo vb;                          // valor a buscar
    void leerCola(Cola * c1);         // prototipo de la funcion que ingresa valores en el TDA (se pone por referencia por que va a cambiar los datos de la funcion)
    void imprimirCola(Cola c1);       // prototipo de la funcion que imprime los valroes del TDA
    bool estaEnCola(Cola c1, Tipo v); // prototipo de la funcion que determina si v esta contenido en c1

    leerCola(&c);
    cout << "Elementos contenidos en el TDA" << endl;
    cout << "***********************************" << endl;
    imprimirCola(c);
    cout << "" << endl;
    cout << "Ingrese el valor a buscar: " << endl;
    cin >> vb;

    cout << "El valor " << vb << ((estaEnCola(c, vb)) ? " SI" : " NO ") << " se ecuenta en el TDA Cola..." << endl;
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
