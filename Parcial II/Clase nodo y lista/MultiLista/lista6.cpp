/* lista 5
Imprentacino de un programa que permite el ingreso de varios numero
y general una lista con los digitos contendios en cada uno
Autor: Roberto Jiménez-7048*/
#include <iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;

#define FIN 999 // marcador de final de lectura
#define EXT 9   // extension maxima de los vectores

void ingresarNumeros(int nu[], int *n1);
void imprimirNumeros(int nu[], Lista l[], int n1);
void generarListas(int nu[], Lista l[], int n1, int cantDigitos[]);
void ordenarListas(Lista l[], int n1, int cantDigitos[]);

int main()
{
    int nums[EXT];
    Lista Listas[EXT];    // vector de listas de digitos
    int cantDigitos[EXT]; // cantidad de dígitos en cada lista

    int n = 0; // cantidad de elementos a procesar
    ingresarNumeros(nums, &n);
    generarListas(nums, Listas, n, cantDigitos); // llamado a funcion que genera la lista de numeros y almacena la cantidad de dígitos

    imprimirNumeros(nums, Listas, n);
    cout << endl;

    ordenarListas(Listas, n, cantDigitos); // llamar a la función para ordenar los dígitos de cada lista

    cout << "Listas ordenadas:" << endl;
    imprimirNumeros(nums, Listas, n);

    cout << endl;
    system("pause");
    return 0;
}

void ingresarNumeros(int nu[], int *n1)
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

void generarListas(int nu[], Lista l[], int n1, int cantDigitos[])
{
    int aux; // individualizar digitos
    int cont = 0;
    for (int i = 0; i < n1; i++)
    {
        aux = nu[i];
        int digitos = 0; // Variable para contar la cantidad de dígitos generados

        do // ciclo de individualización de digitos ejem: 120,12,14
        {
            l[i].insertarAlInicio(aux % 10);
            aux /= 10; // corta el digito 120, 12 ,1, 0
            digitos++; // Incrementar la cantidad de dígitos generados
        } while (aux != 0);

        cantDigitos[i] = digitos; // Almacenar la cantidad de dígitos generados en el arreglo correspondiente
    }
}

void ordenarListas(Lista l[], int n1, int cantDigitos[])
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < cantDigitos[i] - 1; j++)
        {
            Nodo *actual = l[i].getPrimero();

            while (actual != NULL && actual->getPunt() != NULL)
            {
                if (actual->getDato() > actual->getPunt()->getDato())
                {
                    int temp = actual->getDato();
                    actual->setDatos(actual->getPunt()->getDato());
                    actual->getPunt()->setDatos(temp);
                }

                actual = actual->getPunt();
            }
        }
    }
}
