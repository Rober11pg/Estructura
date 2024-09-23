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
    int LeerN(int limInf, int limSup);                         // Prototipo de leer n
    void LeerArreglo(int z[], int n1, int i);                  // prototipo para leer arreglo
    void Inserccion(int z[], int n1, int i, int pos, int aux); // Prototipo de método de insercción
    void insert2(int i, int pos, int aux, int z[]);
    void ContarDigitos(int z[], int *n1, int num, int digitos, int i); // Cuenta los dígitos del arreglo
    void ImprimirArreglo(int z[], int n1);                             // Prototipo de los métodos impresos del arreglo

    n = LeerN(1, EXT);
    LeerArreglo(a, n, 0);
    Inserccion(a, n, 0, 0, 0);
    // ImprimirArreglo(a, n);
    cout << " " << endl;
    ContarDigitos(a, &n, 0, 0, 0);

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
void LeerArreglo(int z[], int n1, int i)
{
    cout << "Contiene el arreglo" << endl;
    if (i < n1)
    {
        cout << "Posicion: [" << i << "]: " << endl;
        cin >> z[i];
        LeerArreglo(z, n1, i + 1);
    }
}

void insert2(int i, int pos, int aux, int z[])
{
    if ((pos > 0) && (z[pos - 1] < aux))
    {
        z[pos] = z[pos - 1];
        cout << "pos " << i << ": " << pos << endl;
        insert2(i, pos - 1, aux, z);
    }
    else
    {
        z[pos] = aux;
    }
}

void Inserccion(int z[], int n1, int i, int pos, int aux) // Arreglo de los elementos de manera ascendente
{
    if (i < n1)
    {
        pos = i;
        aux = z[i];
        // while ((pos > 0) && (z[pos - 1] < aux))
        // {
        //     z[pos] = z[pos - 1];
        //     pos--;
        //     cout << "pos " << i << ": " << pos << endl;
        // }
        insert2(i, pos, aux, z);
        cout << "a" << endl;
        Inserccion(z, n1, i + 1, pos, aux);
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

void ContarDigitos2(int z[], int *n1, int num, int digitos, int i)
{
    if (num != 0)
    {
        num /= 10;
        ContarDigitos2(z, n1, num, digitos + 1, i);
    }
    else
    {
        if (digitos % 2 == 1)
        {
            cout << "iiiiiiiiiiii2: " << i << endl;
            cout << "Posicion: [" << i << "]: " << z[i] << endl;
        }
    }
}
void ContarDigitos(int z[], int *n1, int num, int digitos, int i)
{
    cout << "Listado ordenado descendentemente con los valores que contienen una cantidad impar de digitos:" << endl;
    cout<<"n1 "<< *n1<<endl;
    if (i < *n1)
    {
        num = z[i];
        digitos = 0;
        if (z[i] == 0)
        {
            cout << "Posicion: [" << i << "]: " << z[i] << endl;
        }
        else
        {
            ContarDigitos2(z, n1, num, digitos, i);
            cout << "iiiiiiiiiiii: " << i << endl;
        }
        ContarDigitos2(z, n1, num, digitos, i + 1);
    }
}