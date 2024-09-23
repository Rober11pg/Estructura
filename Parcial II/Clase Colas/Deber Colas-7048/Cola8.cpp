/* 8. Calcular la desviación típica existente entre los valores pertenecientes a una cola de valores ingresados
Autor: Roberto Jiménez-7048*/
#include <iostream>
#include "ColaFloat.h"
#include <cmath>
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    ColaFloat a;
    double media;
    double desviacionEstandar = 0;
    void leerCola(ColaFloat * c1);
    void imprimirCola(ColaFloat c1);
    double Media_(ColaFloat a, double Media);
    double calcularDesviacionEstandar(ColaFloat c1, double media);
    leerCola(&a);
    cout << "Elementos contenidos en el TDA" << endl;
    cout << "***********************************" << endl;
    imprimirCola(a);
    cout << endl;

    // Calcular la media
    media = Media_(a, 0);
    // Caalcular la Desviación estandar
    desviacionEstandar = calcularDesviacionEstandar(a, media);

    cout << "Media: " << media << endl;
    cout << "Desviacion estandar: " << desviacionEstandar << endl;

    system("pause");
}

void leerCola(ColaFloat *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con [" << FIN << "]" << endl;
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

void imprimirCola(ColaFloat c1)
{
    if (!c1.colaVacia())
    {
        cout << "> " << c1.quitar() << endl;
        imprimirCola(c1);
    }
}

double Media_(ColaFloat a, double Media)
{
    ColaFloat temp = a; // Creamos una copia temporal de la cola original
    int cantidadElementos = 0;
    while (!temp.colaVacia())
    {
        Media += temp.quitar();
        cantidadElementos++;
    }
    Media /= cantidadElementos;
    return Media;
}
double calcularDesviacionEstandar(ColaFloat c1, double media)
{
    ColaFloat temp = c1; // Creamos una copia temporal de la cola original
    double sumaCuadradosDiferencias = 0;
    int cantidadElementos = 0;

    while (!temp.colaVacia())
    {
        double valor = temp.quitar();
        double diferencia = valor - media;
        sumaCuadradosDiferencias += pow(diferencia, 2);
        cantidadElementos++;
    }

    double varianza = sumaCuadradosDiferencias / cantidadElementos;
    double desviacionEstandar = sqrt(varianza);

    return desviacionEstandar;
}
