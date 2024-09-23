#include <iostream>
#include "Utilidades.h"
using namespace std;

int main()
{
    void leer(int n, int A[], int B[], int k);
    int leern(), imprimir(int n, int A[], int B[], int k), resolver(int n, int A[], int B[], int k, int q, int w, int s, int r);
     
    int n, n1;
    int A[n], B[n];
    cout << endl
         << "Calcular [a] elevado [b] de varios numeros ingresados por medio de sumas sucesivas [recursividad]" << endl;
    n = leern(n, A, B, 0);
   
    leer(n, A, B, 0);
    cout << endl;
    imprimir(n, A, B, 0);
    cout << endl
         << endl;
    resolver(n, A, B, 0, 0, 0, A[0], 0);
}
//////////////////////////////////////////////////////////////////////////////////////////
void imprimir(int n, int A[], int B[], int k)
{
    if (k < n)
    {
        cout << "[" << A[k] << "^" << B[k] << "]";
    }
    k++;
    if (k < n)
    {
        imprimir(n, A, B, k);
    }
}

void leer(int n, int A[], int B[], int k)
{
    cout << endl;
    cout << "Ingrese el valor numero [" << k + 1 << "] seguido de su exponente" << endl;
    cin >> A[k];
    cin >> B[k];
    if (A[k] > 0 && B[k] > 0)
    {
        k++;
        if (k < n)
        {
            leer(n, A, B, k);
        }
    }
    else
    {
        cout << "[ERROR] Se ha ingresado un valor no válido, por favor intente de nuevo." << endl;
        leer(n, A, B, k);
    }
}

int leern()
{
    int n;
    cout << "INGRESE CUANTOS EXPONENTES VA A INGRESAR" << endl;
    cin >> n;
    if (n >= 1)
    {
        return (n);
    }
    else
    {
        cout << "[ERROR] Se ha ingresado un valor no valido, por favor intente de nuevo." << endl;
        leern();
    }
}

void impr(int k, int a, int b, int s)
{
    cout << "[" << a << "^" << b << "=" << s << "]";
}

int resolver(int n, int A[], int B[], int k, int q, int w, int s, int r)
{
    if (k < n)
    {
        if (q < B[k] - 1)
        {
            if (w < A[k])
            {
                r = r + s;
                w++;
                resolver(n, A, B, k, q, w, s, r);
            }
            else
            {
                q++;
                w = 0;
                resolver(n, A, B, k, q, w, r, 0);
            }
        }
        else
        {
            impr(k, A[k], B[k], s);
            k++;
            resolver(n, A, B, k, 0, 0, A[k], 0);
        }
    }
}
