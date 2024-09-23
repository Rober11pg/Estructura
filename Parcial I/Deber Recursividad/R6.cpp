/* 6. Generalice la solución al problema anterior
Autor: Roberto Jiménez
Código: 7048 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r;
    void Leern(int *n);
    void CalcularPuntos(int x, int fin, int r);

    Leern(&r);
    cout << "Las coordenadas son: " << endl;
    CalcularPuntos(-r, r, r);
    system("pause");
    return 0;
}

void Leern(int *n)
{
    cout << "\t \n x^2 + y^2 = r^2 \t \n";
    cout << "Ingrese el radio:" << endl;
    cin >> *n;
    if (*n < 0)
    {
        cout << "El radio no puede ser negativo..." << endl;
        Leern(n);
    }
}

void CalcularPuntos(int x, int fin, int r)
{
    if (x <= fin)
    {
        int y = round(sqrt(r * r - x * x));
        if (x * x + y * y == r * r)
        {
            cout << "(" << x << "," << y << ")" << endl;
        }
        CalcularPuntos(x + 1, fin, r);
    }
}

