/* 1. Calcular el Factorial de cada n�mero ingresado
Autor: Roberto Jim�nez
C�digo: 7048 */
#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
    int n;
    double Factorial(int n1);
    n = Leern();

    cout << "El factorial de " << n <<"! es: "<<Factorial(n) << endl;
    system("pause");
    return 0;
}

double Factorial(int n1)
{
    if (n1 == 0)
    {
        return 1;
    }
    else
    {
        n1 = n1 * Factorial(n1 - 1);
    }
    return n1;
}

