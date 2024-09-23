/* 2. Generar el área de los círculos cuyo radio está comprendido entre los valores A y B
Autor: Roberto Jiménez*/
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159
#include "utilidades.h"
int main()
{
    int a1, b1, i = 0, rad = 0;
    double Areacirculo(double radio);
    void Imprimir(int a, int b, int r);
    a1 = PinicialA();
    b1 = PfinalB();
    if (a1 > b1)
    {
        swap(a1, b1); // asegurarse que a <= b, si se cumple la condicion intercambian valores a1, b1
    }
    Areacirculo(rad);
    Imprimir(a1, b1, a1);
    system("pause");
    return 0;
}
double Areacirculo(double radio)
{
    return PI * pow(radio, 2);
}

void Imprimir(int a, int b, int r)
{
    if (r <= b)
    {
        if (r >= 0)
        {
            cout << "El area del circulo con radio " << r << " es " << Areacirculo(r) << endl;
        }
        else
        {
            cout << "El radio " << r << " es negativo, no se puede calcular el area." << endl;
        }
        Imprimir(a, b, r + 1);
    }
}
