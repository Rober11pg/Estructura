#include <iostream>
#include <cstring>
#include "ListaCircular.h"

#define FIN 999
#define EXT 9

void ingresarNumeros(int nu[], int* n1);
void imprimirNumeros(int nu[], ListaCircular l[], int n1);
bool esCapicua(ListaCircular& lista);
char* intToString(int num);

int main()
{
    int nums[EXT];
    ListaCircular Listas[EXT];

    int n = 0;
    ingresarNumeros(nums, &n);
    imprimirNumeros(nums, Listas, n);

    cout << "Verificación de si las listas son capicúas:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (esCapicua(Listas[i]))
        {
            cout << "> La lista " << i + 1 << " es capicúa." << endl;
        }
        else
        {
            cout << "> La lista " << i + 1 << " no es capicúa." << endl;
        }
    }

    cout << endl;
    system("pause");
    return 0;
}

void ingresarNumeros(int nu[], int* n1)
{
    int aux;

    cout << "Ingrese un número entero. Finalice con [" << FIN << "]" << endl;
    cin >> aux;

    if ((aux != FIN) && (*n1 < EXT))
    {
        nu[*n1] = aux;
        (*n1)++;
        ingresarNumeros(nu, n1);
    }
}

void imprimirNumeros(int nu[], ListaCircular l[], int n1)
{
    cout << "Valores procesados:" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "> " << nu[i] << endl;
        Nodo* act = l[i].getPrimero();

        if (act != nullptr)
        {
            Nodo* inicio = act;

            do
            {
                cout << "\t> " << act->getDato() << endl;
                act = act->getPunt();
            } while (act != inicio);
        }
    }
}

bool esCapicua(ListaCircular& lista)
{
    Nodo* inicio = lista.getPrimero();
    Nodo* actual = inicio->getPunt();

    char* str = intToString(actual->getDato());
    int length = strlen(str);

    while (actual != inicio)
    {
        str = strcat(str, intToString(actual->getDato()));
        actual = actual->getPunt();
    }

    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

char* intToString(int num)
{
    int temp = num;
    int length = 0;

    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    char* str = new char[length + 1];
    str[length] = '\0';

    for (int i = length - 1; i >= 0; i--)
    {
        str[i] = '0' + num % 10;
        num /= 10;
    }

    return str;
}
