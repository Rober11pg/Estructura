/*Generar un listado ordenado descendentemente
con los valores que contienen una cantidad impar de dígitos,
 tomados de entre varios números enteros ingresados por el usuario
  (aplíquese el algoritmo de ordenamiento por inserción)
 Autor: Roberto Jiménez
 Código: 7048*/
#include <iostream>
using namespace std;
#define EXT 10

int main()
{
    system("color f0");
    int a[EXT];
    int n, aux1;
    int LeerN(int limInf, int limSup);     // Prototipo de leer n
    void LeerArreglo(int z[], int n1);     // prototipo para leer arreglo
    void Inserccion(int z[], int n1);      // Prototipo de método de insercción
    void ContarDigitos(int z[], int n1);   // Cuenta los dígitos del arreglo
    void ImprimirArreglo(int z[], int n1); // Prototipo de los métodos impresos del arreglo
    n = LeerN(1, EXT);
    LeerArreglo(a, n);
    Inserccion(a, n);
    ImprimirArreglo(a, n);
    cout << " " << endl;
    ContarDigitos(a, n);

    cout << "" << endl;
    system("pause");
}

int LeerN(int limInf, int limSup)
{          // función que lee el valor de n
    int x; // variable de lectura de datos
    do
    {
        cout << "Ingrese un valor comprendido en el rango [" << limInf << "..." << limSup << "]" << endl;
        cin >> x;
    } while (x < limInf || x > limSup); // limites para el rango del número
    return x;
}
void LeerArreglo(int z[], int n1)
{
    cout << "Contiene el arreglo" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "Posicion: [" << i << "]: " << endl;
        cin >> z[i];
    }
}

void Inserccion(int z[], int n1) // Arreglo de los elementos de manera ascendente
{
    cout<<"Inserccion"<<endl;
    int pos, aux;
    for (int i = 0; i < n1; i++)
    {
        pos = i;
        aux = z[i];
        while ((pos > 0) && (z[pos - 1] < aux))
        {
            z[pos] = z[pos - 1];
            pos--;
            cout << "pos " << i << ": " << pos << endl;
        }
        z[pos] = aux;
    }
}

void ImprimirArreglo(int z[], int n1)
{
    cout << "Contenido del arreglo" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "Posicion: [" << i << "]: " << z[i] << endl;
    }
}

void ContarDigitos(int z[], int n1)
{
    cout << "Listado ordenado descendentemente con los valores que contienen una cantidad impar de digitos:" << endl;
    for (int i = 0; i < n1; i++)
    {
        int num = z[i];
        int digitos = 0;
        if (z[i] == 0)
        {
            cout << "Posicion: [" << i << "]: " << z[i] << endl;
        }
        else
        {
            while (num != 0)
            {
                num /= 10;
                digitos++;
            }
            if (digitos % 2 == 1)
            {
                cout << "Posicion: [" << i << "]: " << z[i] << endl;
            }
        }
    }
}