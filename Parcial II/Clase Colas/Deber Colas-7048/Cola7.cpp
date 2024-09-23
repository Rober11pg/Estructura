/* 7. Ingresar una cola de valores, y si hubieran valores consecutivos adyacentes en esta, 
separarlos con un valor correspondiente al promedio calculado entre los dos elementos contiguos al espacio en que se insertará el nuevo valor
Autor: Roberto Jiménez-7048 */
#include <iostream>
#include "ColaFloat.h"
#define FIN 9999 // definicion del marcado de fin de lecura
using namespace std;

int main()
{
    system("color f0");
    ColaFloat c;
    void leerCola(ColaFloat* c1);   // prototipo de la funcion que ingresa valores en el TDA (se pone por referencia por que va a cambiar los datos de la funcion)
    void imprimirCola(ColaFloat c1); // prototipo de la funcion que imprime los valroes del TDA
    void separarConPromedio(ColaFloat *cola);
    leerCola(&c);
    cout << "Elementos contenidos en la TDA antes de separar con promedio" << endl;
    cout << "***********************************" << endl;
    imprimirCola(c);
    cout << endl;

    separarConPromedio(&c);

    cout << "Elementos contenidos en la TDA después de separar con promedio" << endl;
    cout << "***********************************" << endl;
    imprimirCola(c);
    cout << endl;

    system("pause");
}

void leerCola(ColaFloat *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con[" << FIN << "]" << endl;
    cin >> x;
    if (x != FIN)
    {
        if (!c1->colaLlena())
        {
            c1->insertar(x);
            leerCola(c1);
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}


void imprimirCola(ColaFloat c1) // no se hace cambios por eso está por valor, si se hacen cambios se hace con punteros 
{
    if (!c1.colaVacia()) // aún hay elementos en la TDA ?
    {
        cout << "> " << c1.quitar() << endl;
        imprimirCola(c1); // llamado recursivo a la TDA
    }
}

void separarConPromedio(ColaFloat* cola)
{
    ColaFloat colaNueva; // Cola auxiliar para almacenar la nueva versión separada

    while (!cola->colaVacia())
    {
        Tipo valor = cola->quitar(); // Obtener el primer valor de la cola original

        if (!cola->colaVacia())
        {
            Tipo siguiente = cola->frentecola(); // Obtener el siguiente valor de la cola original

            if (siguiente - valor == 1) // Verificar si los valores son consecutivos adyacentes
            {
                Tipo promedio = (valor + siguiente) / 2.0; // Calcular el promedio entre los valores
                colaNueva.insertar(valor); // Insertar el valor original en la nueva cola
                colaNueva.insertar(promedio); // Insertar el valor promedio en la nueva cola
            }
            else
            {
                colaNueva.insertar(valor); // Insertar el valor original en la nueva cola
            }
        }
        else
        {
            colaNueva.insertar(valor); // Insertar el último valor de la cola original
        }
    }

    // Reemplazar la cola original con la nueva versión separada
    *cola = colaNueva;
}