/* 3. Ingresar tres n�meros, y proceder a ordenarlos (ascendente o descendentemente,
 de acuerdo a lo requerido por el usuario)
Autor: Roberto Jim�nez-7048 */
#include <iostream>
#define EXT 3
using namespace std;
#include "utilidades.h"
int main()
{
    int a[EXT];
    int n, op;
    void Burbuja(int v[], int n1, int i, int j);
    void Opcion(int v[], int n1, int op);
    cout << "Programa que ordena de manera ascendente y desecendente 3 numeros..." << endl;
    LeerArreglo(a, EXT, 0);
    Burbuja(a, EXT, 1, 0);
    Opcion(a, EXT, op);

    system("pause");
    return 0;
}

// Ordenamiento por burbuja
void Burbuja(int v[], int n1, int i, int j)
{
    if (i < n1)
    {
        if (j < (n1 - i))
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
            Burbuja(v, n1, i, j + 1);
        }
        Burbuja(v, n1, i + 1, j);
    }
}

int Opcion(int v[], int n1, int op)
{
        cout << "Ingrese la opcion de como desea imprimir sus datos:" << endl;
        cout << "1. Asecendente: " << endl;
        cout << "2. Descendente: " << endl;
        cin >> op;
        switch (op)
        {
        case 1:
        	cout << "Contiene el arreglo" << endl;
            IprimirAsc(v, n1, 0);
            break;
        case 2:
        	cout << "Contiene el arreglo" << endl;
            IprimirDes(v, n1, n1-1);
            break;

        default:
            cout << "Se ha salido del rango de opciones ..." << endl;
            break;
        }

    if(op != 1 && op != 2){
    	Opcion(v, n1, op);
    }
	
}
