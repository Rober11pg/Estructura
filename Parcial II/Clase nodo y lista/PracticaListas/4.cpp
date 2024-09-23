/* 4. Ordenar los valores de una lista de números en base a la cantidad de dígitos que posee
Auto: Roberto Jiménez-7048*/

#include <iostream>
#include "Lista.h"
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    Lista l;
    Nodo no;
    void leerLista(Lista * l1);   // Prototipo de función que permite leer los valores a ingresar
    void imprimirLista(Lista l1); // Prototipo de función que imprime los valores ingresados ordenados por cantidad de dígitos

    leerLista(&l);
    imprimirLista(l);

    cout << endl;
    system("pause");
    return 0;
}

void leerLista(Lista *l1)
{ // Función que permite leer los valores a ingresar
    Tipo x;
    cout << endl
         << "Ingrese los valores: Finalice con [" << FIN << "]: ";
    cin >> x;

    if (x != FIN)
    {
        l1->insertarAlFinal(x);
        leerLista(l1);
    }
}

void imprimirLista(Lista l1)
{ // Función que imprime los valores ingresados ordenados por cantidad de dígitos
    Nodo *act;
    act = l1.getPrimero();

    // Crear una lista auxiliar para almacenar los valores ordenados
    Lista listaOrdenada;

    // Insertar el primer nodo en la lista ordenada
    if (act != NULL)
    {
        listaOrdenada.insertarAlFinal(act->getDato());
        act = act->getPunt();
    }

    // Recorrer la lista original y ordenar los valores en la lista auxiliar
    while (act != NULL)
    {
        Tipo valor = act->getDato();
        Nodo *aux = listaOrdenada.getPrimero();
        Nodo *ant = NULL;
        bool insertado = false;

        // Buscar la posición adecuada para insertar el valor en la lista ordenada
        while (aux != NULL && !insertado)
        {
            // Comparar la cantidad de dígitos del valor con el de cada nodo en la lista ordenada
            int digitosValor = 0; // toma los valores de la lista original 
            int digitosNodo = 0; // tomas los valores de la lsita ordenada

            // Calcular la cantidad de dígitos del valor
            Tipo temp = valor;
            while (temp != 0)
            {
                temp /= 10;
                digitosValor++;
            }

            // Calcular la cantidad de dígitos del nodo actual
            temp = aux->getDato();
            while (temp != 0)
            {
                temp /= 10;
                digitosNodo++;
            }

            // Comparar la cantidad de dígitos y determinar si se debe insertar el valor antes del nodo actual
            if (digitosValor < digitosNodo)
            {
                Nodo *nuevo = new Nodo(valor);

                // Si el nodo anterior es NULL, el valor se inserta al inicio de la lista ordenada
                if (ant == NULL)
                {
                    nuevo->setPunt(aux);
                    listaOrdenada.setPrimero(nuevo);
                }
                else //  valor a insertar en la lista ordenada debe ubicarse entre dos nodos existentes
                {
                    nuevo->setPunt(aux);
                    ant->setPunt(nuevo);
                }

                insertado = true;
            }
            else
            {
                // Avanzar al siguiente nodo en la lista ordenada
                ant = aux;
                aux = aux->getPunt();
            }
        }

        // Si el valor no se ha insertado en la lista ordenada, se agrega al final
        if (!insertado)
        {
            listaOrdenada.insertarAlFinal(valor);
        }

        act = act->getPunt();
    }

    // Imprimir la lista ordenada
    Nodo *actOrdenada = listaOrdenada.getPrimero();
    while (actOrdenada != NULL)
    {
        cout << endl
             << "> " << actOrdenada->getDato() << endl;
        actOrdenada = actOrdenada->getPunt();
    }
}
