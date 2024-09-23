/* 10. Permitir el ingreso de varios números enteros,
y generar una cola ordenada con los divisores primos de cada uno de ellos
Autor: Roberto Jiménez-7048 */

#include <iostream>
#include "Cola.h"
#include <vector>
#include <algorithm>
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    Cola numeros;
    bool esPrimo(int num);
    void generarColaDivisoresPrimos(Cola * c1);
    void leerCola(Cola * c1);
    void imprimirCola(Cola c1);
    leerCola(&numeros);

    cout << "Elementos ingresados en la cola:" << endl;
    cout << "*******************************" << endl;
    imprimirCola(numeros);
    cout << endl;
    generarColaDivisoresPrimos(&numeros);

    system("pause");
    return 0;
}

bool esPrimo(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void generarColaDivisoresPrimos(Cola *c1)
{
    vector<Tipo> divisoresPrimosOrdenados;
    while (!c1->colaVacia())
    {
        Tipo num = c1->quitar();
        Cola divisores;
        if (num == 1)
        {
            divisores.insertar(1);
        }
        else
        {
            for (int i = 2; i <= num; i++)
            {
                if (num % i == 0 && esPrimo(i))
                {
                    divisores.insertar(i);
                }
            }
        }

        while (!divisores.colaVacia())
        {
            Tipo divisor = divisores.quitar();
            divisoresPrimosOrdenados.push_back(divisor);
        }
    }

    sort(divisoresPrimosOrdenados.begin(), divisoresPrimosOrdenados.end());

    cout << "Cola de divisores primos ordenados:" << endl;
    cout << "**********************************" << endl;
    for (const Tipo &divisor : divisoresPrimosOrdenados)
    {
        cout << divisor << " ";
    }
    cout << endl;
}

void leerCola(Cola *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con [" << FIN << "]" << endl;
    cin >> x;
    while (x != FIN)
    {
        if (!c1->colaLlena())
        {
            c1->insertar(x);
            cin >> x;
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}

void imprimirCola(Cola c1)
{
    if (!c1.colaVacia())
    {
        Tipo elemento = c1.quitar();
        cout << elemento << " ";
        imprimirCola(c1);
        c1.insertar(elemento);
    }
}
