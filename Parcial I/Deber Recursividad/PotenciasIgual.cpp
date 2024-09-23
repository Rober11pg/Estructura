#include <iostream>
using namespace std;
int main()
{
    int n, num;
    int leerN(int limInf, int limSup);
    void leerVector(int v[], int i, int n);
    void LeerNums(int n);
    n = leerN(0, 300);
    LeerNums(n);
    return 0;
}

int leerN(int limInf, int limSup)
{
    int x;
    cout << "Ingresar un numero en el rango [" << limInf << "..." << limSup << endl;
    cin >> x;
    if (x < limInf || x > limSup)
    {
        leerN(limInf, limSup);
    }
    return x;
}

void LeerNums(int n)
{
    int suma = 0;
    int exponete = 1;
    void IndividualizarDig(int n, int *sum, int *expo);
    int num;
    if (n > 1)
    {
        cout << "Ingrese un numero: " << endl;
        cin >> num;
        IndividualizarDig(n, &suma, &exponete);
        cout << "La suma de los digitos de " << num << " es: " << suma << endl;
        LeerNums(n - 1);
    }
}

void IndividualizarDig(int n, int *sum, int *expo)
{
    int Exponente(int n, int *expo);
    int digito, aux = n;
    aux = aux % 10;
    if (*sum <= n)
    {
        if (n != 0)
        {
            *sum += Exponente(aux, expo);
            IndividualizarDig(n / 10, sum, expo);
        }
    }
    n=aux;
}

void Exponente(int n, int *expo)
{
    if (*expo > 0)
    {
        Exponente(n, expo + 1);
    }
}