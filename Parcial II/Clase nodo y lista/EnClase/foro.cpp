// Un ejemplo practico podria ser una lista de codigo de estudiantes.Donde se se ingresan en orden alfabetico, y luego se registra un estudiante con un codigo intermedio, se ingresa en su lugar correspondiente.
/*
    Programa que permite el ingreso de dos lista y genera una lista de sus elementos pares.
    Autor: Erick Alexander Cajamarca Concha(7160)
*/
#include <iostream>

using namespace std;

class Nodo
{
public:
    int dato;
    Nodo *siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaEnlazada
{
public:
    Nodo *primero;

    ListaEnlazada() : primero(nullptr) {}

    ~ListaEnlazada()
    {
        Nodo *actual = primero;
        while (actual != nullptr)
        {
            Nodo *siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertar(int valor)
    {
        Nodo *nuevo = new Nodo(valor);
        if (primero == nullptr)
        {
            primero = nuevo;
            primero->siguiente = primero;
        }
        else
        {
            Nodo *actual = primero;
            while (actual->siguiente != primero)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
            nuevo->siguiente = primero;
        }
    }
};

bool esPar(int valor)
{
    return valor % 2 == 0;
}

int main()
{

    system("color f0");
    ListaEnlazada lista1;
    ListaEnlazada lista2;

    int valor;
    cout << endl
         << "\t - - - - LISTA 1 - - - - " << endl;
    cout << endl
         << "Ingrese los valores de la Lista 1 (-1 para terminar): " << endl;
    while (cin >> valor && valor != -1)
    {
        lista1.insertar(valor);
    }
    cout << endl
         << "==========================================================================" << endl;
    cout << endl
         << "\t - - - - LISTA 2 - - - - " << endl;
    cout << endl
         << "Ingrese los valores de la Lista 2 (-1 para terminar): " << endl;
    while (cin >> valor && valor != -1)
    {
        lista2.insertar(valor);
    }

    // Creación de la lista de valores pares
    ListaEnlazada listaPares;

    // Recorrido de la lista 1
    Nodo *actual1 = lista1.primero;
    if (actual1 != nullptr)
    {
        Nodo *siguiente1 = actual1->siguiente;
        do
        {
            if (esPar(actual1->dato))
            {
                listaPares.insertar(actual1->dato);
            }
            actual1 = siguiente1;
            siguiente1 = siguiente1->siguiente;
        } while (actual1 != lista1.primero);
    }

    // Recorrido de la lista 1
    Nodo *actual2 = lista2.primero;
    if (actual2 != nullptr)
    {
        Nodo *siguiente2 = actual2->siguiente;
        do
        {
            if (esPar(actual2->dato))
            {
                listaPares.insertar(actual2->dato);
            }
            actual2 = siguiente2;
            siguiente2 = siguiente2->siguiente;
        } while (actual2 != lista2.primero);
    }
    cout << endl
         << "==========================================================================" << endl;
    cout << endl
         << "Lista de valores pares: ";
    Nodo *actualPares = listaPares.primero;
    if (actualPares != nullptr)
    {
        Nodo *siguientePares = actualPares->siguiente;
        do
        {
            cout << actualPares->dato << " -> ";
            actualPares = siguientePares;
            siguientePares = siguientePares->siguiente;
        } while (actualPares != listaPares.primero);
    }
    cout << "NULL" << endl;

    cout << endl;
    system("pause");
    return 0;
}
