/* 9. Generalizar la solución anterior */

#include <iostream>
#include <cmath>
using namespace std;
#include "utilidades.h"

int main()
{
    double a, b;
    double incre = 0.001;
    a = PinicialA();
    b = PfinalB();
    void imprimirTablaRaiz(double incremento, double incio, double fin);
    imprimirTablaRaiz(incre, a, b);

    return 0;
}

void imprimirTablaRaiz(double incremento, double incio, double fin)
{
    double raiz = sqrt(incio);
    cout << "La raiz cuadrada de " << incio << " es " << raiz << endl;

    if (incio + incremento <= fin)
    {
        imprimirTablaRaiz(incremento, incio + incremento, fin);
    }
}

