#include <iostream>
#include "Pila.h"

using namespace std;

void ingresarNumeros(Pilas& pila);
bool esPrimo(int numero);
int obtenerSiguientePrimo(int numero);
int obtenerMenorFactorPrimo(int numero);
int obtenerProductoFactoresComunes(Pilas& pila);

int main()
{
    Pilas pila;
    ingresarNumeros(pila);

    int producto = obtenerProductoFactoresComunes(pila);
    cout << "El producto de los factores primos comunes es: " << producto << endl;

    return 0;
}

void ingresarNumeros(Pilas& pila)
{
    int numero;
    cout << "Ingrese los numeros. Finalice con 0." << endl;
    do
    {
        cin >> numero;
        if (numero != 0)
        {
            pila.push(numero);
        }
    } while (numero != 0);
}

bool esPrimo(int numero)
{
    if (numero <= 1)
        return false;

    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
            return false;
    }

    return true;
}

int obtenerSiguientePrimo(int numero)
{
    do
    {
        numero++;
    } while (!esPrimo(numero));

    return numero;
}

int obtenerMenorFactorPrimo(int numero)
{
    int factor = 2;

    while (numero % factor != 0)
    {
        factor = obtenerSiguientePrimo(factor);
    }

    return factor;
}

int obtenerProductoFactoresComunes(Pilas& pila)
{
    if (pila.pilaVacia())
        return 1;

    int numero = pila.pop();
    int menorFactor = obtenerMenorFactorPrimo(numero);
    int producto = obtenerProductoFactoresComunes(pila);

    while (menorFactor != 1)
    {
        if (producto % menorFactor == 0)
        {
            producto /= menorFactor;
        }
        else
        {
            producto *= menorFactor;
        }

        menorFactor = obtenerMenorFactorPrimo(numero);
    }

    return producto;
}
