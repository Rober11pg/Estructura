/* Implementación de un programa que permite el ingreso de varios numero
y generar una lista con los digitos contendios en cada uno, y sumar sus dígitos para sacar su promedio
Autor: Roberto Jiménez-7048 */

#include <iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;

#define FIN 999 // marcador de final de lectura
#define EXT 9   // extension maxima de los vectores

int main()
{
    int nums[EXT];
    Lista Listas[EXT]; // vector de listas de digitos

    int n = 0;                                         // cantidad de elementos a procesar
    void ingresarNumeros(int nu[], int *n1);           // prototipo de la funcion de ingreso de valores
    void imprimirNumeros(int nu[], Lista l[], int n1); // prototipo de la funcion que imprime el valor dado
    void generarListas(int nu[], Lista l[], int n1);   // prototipo de la funcion que genera la lista de digitos de cada numero
    void SumadeLista(Lista l[], int n1);               // prototipo de la funcion que suma los digitos de cada lista
    void PromedioLista(Lista l[], int n1);             // prototipo de la funcion que imprime el promedio de sus digitos de cada lsita
    ingresarNumeros(nums, &n);
    generarListas(nums, Listas, n); // llamado a funcion que genera la lista de numeros
    imprimirNumeros(nums, Listas, n);
    SumadeLista(Listas, n);
    PromedioLista(Listas, n);
    cout << endl;
    system("pause");
    return 0;
}

void ingresarNumeros(int nu[], int *n1) // prototipo de la funcion de ingreso de valores
{
    int aux;

    do // ciclo de lectura
    {
        cout << "Ingrese un numero entero.. Finalice con [" << FIN << "] " << endl;
        cin >> aux;

        if ((aux != FIN) && (*n1 < EXT)) // NO ingresa el valor de fin y aun hay espacio en el vector
        {
            nu[*n1] = aux; // añadir el elemento en el vector
            (*n1)++;       // el valor apuntado por el apuntador n1 debe incrementarse // contar el elemento añadido
        }
    } while (((aux != FIN) && (*n1 < EXT))); // repite si no ingresa fin y aun hay espacio en el vector
}

void imprimirNumeros(int nu[], Lista l[], int n1)
{
    cout << "Valores procesados " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "> " << nu[i] << endl;
        Nodo *act;               // nodo actual de la lista
        act = l[i].getPrimero(); // apunta al primer nodo de la lista
        while (act != NULL)      // no se alcanza aun el final de la lista
        {
            cout << "\t> " << act->getDato() << endl;
            act = act->getPunt();
        }
    }
}

void generarListas(int nu[], Lista l[], int n1) // prototipo de la funcion que genera la lista de digitos de cada numero
{
    int aux; // individualizar digitos
    int cont = 0;
    for (int i = 0; i < n1; i++)
    {
        aux = nu[i];

        do // ciclo de individualización de digitos ejem: 120,12,14
        {
            l[i].insertarAlInicio(aux % 10);
            aux /= 10; // corta el digito 120, 12 ,1, 0
        } while (aux != 0);
    }
}

void SumadeLista(Lista l[], int n1)
{
    for (int i = 0; i < n1; i++)
    {
        Nodo *act = l[i].getPrimero();
        int suma = 0; // Inicializar la suma en 0

        while (act != NULL)
        {
            suma += act->getDato();
            act = act->getPunt();
        }

        cout << "La suma de la lista " << i + 1 << " es: " << suma << endl;
    }
}


void PromedioLista(Lista l[], int n1)
{
    for (int i = 0; i < n1; i++)
    {
        Nodo *act = l[i].getPrimero();
        float suma = 0;
        int cont = 0;
        float promedio = 0;
        while (act != NULL)
        {
            suma += act->getDato();
            cont++;
            act = act->getPunt();
        }
        promedio = suma / cont;
        cout << "El promedio de la lista " << i + 1 << " es: " << promedio << endl;
    }
}