/* 5. Determinar los puntos de coordenadas enteras que est�n sobre la circunferencia X^2 + Y^2 = 25
Autor: Roberto Jim�nez
C�digo: 7048 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    void CalcularPuntos(int x, int fin);
    cout << "Cordenadas para radio 5 \n x^2 + y^2 = 25 \n";
    CalcularPuntos(-5, 5);
    system("pause");
    return 0;
}

void CalcularPuntos(int x, int fin)
{
        if (x <= fin)
        {
            int y = round(sqrt(25 - x * x));
            if (x * x + y * y == 25)
            {
                cout << "(" << x << "," << y << ")" << endl;
            }
            CalcularPuntos(x + 1, fin);
        }
}

