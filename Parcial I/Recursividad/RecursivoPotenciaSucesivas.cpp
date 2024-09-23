#include <iostream>
using namespace std;

int main()
{
    int Leern();
    void CantidadN(int n, int i1);
    int calcularExponente(int base, int exponente, int i, int j);
    int n = Leern();
    CantidadN(n, 0);
    return 0;
}

int Leern()
{
    int x;
    cout << "Ingresar la cantidad de valores que quiere calcular: " << endl;
    cin >> x;
    if (x < 1)
    {
        x = Leern();
    }
    return x;
}

int calcularExponentesuma(int base, int exponente, int i, int j)
{
    int resultado = 0;
    if (j <= exponente)
    {
        resultado +=base;
        calcularExponentesuma(base, exponente, i, j+1);
    }
    return resultado;
}

int calcularExponente(int base, int exponente, int i, int j)
{
    int x=0;
    if (exponente == 0)
    {
        return 1;
    }
    else if (exponente == 1)
    {
        return base;
    }
    else
    {
        int resultado = base;
        if (i <= exponente)
        {
            resultado = resultado + base;
            calcularExponente(base, exponente, i + 1, 0);
            x=calcularExponentesuma(base, exponente, i, 0);
            resultado +=x;
        }

        return resultado;
    }
}

void CantidadN(int n, int i1)
{
    int base, exponente;
    if (i1 < n)
    {
        cout << "Ingrese la base: ";
        cin >> base;
        cout << "Ingrese el exponente: ";
        cin >> exponente;
        if (exponente < 0)
        {
            cout << "El exponente debe ser un valor positivo o cero." << endl;
            CantidadN(n, i1 - 1);
        }
        else
        {
            cout << "Resultado: " << calcularExponente(base, exponente, 2, 0) << endl;
            CantidadN(n, i1 + 1);
        }
    }
}
