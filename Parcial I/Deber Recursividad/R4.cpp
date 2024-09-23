/* 4. Generar los N valores m�ltiplos de X.
Calcular el promedio de aquellos valores generados
que est�n dentro del rango comprendido entre A y B;
si no est�n en ese rango, los valores solo deber�n imprimirse.

Autor: Roberto Jim�nez */
#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
    int n, x, a, b;
    int Leern();
    void Multiplos(int n1, int a, int b, int i, int *multi, int x);
    void Verifi_Multiplos(int n1, int a, int b, int i, int *multi, int x, float *suma, int *cont);
    float Promedio(int n1, int a, int b, int i, int *multi, int x, float *suma, int *cont, float promedio);
    cout << "\n Ingreso de N valores, que quiera sacar para los multiplos de X \n" << endl;
    n = Leern();
    cout << "\n Ingreso del valor X para generar sus multiplos \n " << endl;
    x = Leerx();
    a = PinicialA();
    b = PfinalB();

    int multi[n];
    float suma = 0;
    int cont = 0;

    Multiplos(n, a, b, 1, multi, x);
    Verifi_Multiplos(n, a, b, 1, multi, x, &suma, &cont);
    float promedio = Promedio(n, a, b, 1, multi, x, &suma, &cont, 0);
    cout << "El promedio de los valores generados que estan dentro del rango [" << a << "," << b << "] es: " << promedio << endl;

    system("pause");
    return 0;
}

void Multiplos(int n1, int a, int b, int i, int *multi, int x)
{
    if (i <= n1)
    {
        multi[i - 1] = x * i;
        Multiplos(n1, a, b, i + 1, multi, x);
    }
}

void Verifi_Multiplos(int n1, int a, int b, int i, int *multi, int x, float *suma, int *cont)
{
    if (i <= n1)
    {
        if (multi[i - 1] >= a && multi[i - 1] <= b)
        {
            *suma += multi[i - 1];
            *cont += 1;
        }
        else
        {
            cout << "\n El valor " << multi[i - 1] << " no esta dentro del rango...\n" << endl;
        }
        Verifi_Multiplos(n1, a, b, i + 1, multi, x, suma, cont);
    }
}

float Promedio(int n1, int a, int b, int i, int *multi, int x, float *suma, int *cont, float promedio)
{
    if (*cont != 0)
    {
        promedio = *suma / *cont;
        return promedio;
    }
    else
    {
        cout << "No se generaron valores dentro del rango especificado." << endl;
        return 0;
    }
}

