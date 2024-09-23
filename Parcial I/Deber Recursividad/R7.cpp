/*  7. Imprimir solamente el N-�simo d�gito fraccionario de cada numero real
(posee parte entera y parte fraccionaria) ingresado.
Autor: Roberto Jim�nez*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double num, decimal;
    int pos, entero;

    double LeernR();
    int PosFrancion();

    num = LeernR();
    pos = PosFrancion();
    bool VerificarEntero(double decimal);
    bool VerificarFueraRango(int digito, int pos);
    int CalcularDigito(double decimal, int pos);
    void Imprimir(int pos, double num, int digito);
    entero = floor(num);
    decimal = num - entero;

    if (VerificarEntero(decimal))
    {
        return 0;
    }

    int digito = CalcularDigito(decimal, pos);

    if (VerificarFueraRango(digito, pos))
    {
        return 0;
    }
    Imprimir(pos, num, digito);
    return 0;
}

double LeernR()
{
    double num;
    cout << "Ingrese un numero real: ";
    cin >> num;
    if (num == 0)
    {
        LeernR();
    }
    return num;
}

int PosFrancion()
{
    int pos;
    cout << "Ingrese la posicion del digito fraccionario que desea imprimir: ";
    cin >> pos;
    return pos;
}

bool VerificarEntero(double decimal)
{
    if (decimal == 0)
    {
        cout << "El numero ingresado es un entero." << endl;
        return true;
    }
    return false;
}

bool VerificarFueraRango(int digito, int pos)
{
    if (digito == 0 && pos > 0)
    {
        cout << "La posicion ingresada esta fuera del rango del numero." << endl;
        return true;
    }
    return false;
}

int CalcularDigito(double decimal, int pos)
{
   int digito = static_cast<int>(floor(decimal * pow(10, pos))) % 10; // La static_cast<int> se utiliza para realizar una conversi�n de tipo expl�cita
    return digito;
}

void Imprimir(int pos, double num, int digito)
{
    cout << "El digito en la posicion " << pos << " del numero " << num << " es " << digito << endl;
}
