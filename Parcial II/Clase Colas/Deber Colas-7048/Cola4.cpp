/* 4. Ingresar ordenadamente los valores en una cola
Autor: Roberto Jiménez-7048*/
#include <iostream>
#include "Cola.h"
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    Cola a, b;
    void leerCola(Cola * c1);
    void imprimirCola(Cola c1);
    void elimiarElementoCola(Cola * c);
    void ordenarCola(Cola * c);

    leerCola(&a);
    cout << "Elementos contenidos en el TDA" << endl;
    cout << "***********************************" << endl;
    // imprimirCola(a);
    cout << endl;
    cout << "Elementos ordenados" << endl;
    cout << "***********************************" << endl;
    // imprimirCola(b);
    ordenarCola(&a);
    imprimirCola(a);
    cout << endl;

    system("pause");
}

void imprimirCola(Cola c1)
{
    if (!c1.colaVacia())
    {
        cout << c1.quitar() << " ";
        imprimirCola(c1);
    }
}

void leerCola(Cola *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con [" << FIN << "]" << endl;
    cin >> x;
    if (x != FIN)
    {
        if (!c1->colaLlena())
        {
            c1->insertar(x);
            leerCola(c1);
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}

void elimiarElementoCola(Cola *c, Tipo x)
{
    Tipo a1;
    Cola b;

    while (!c->colaVacia()) // ciclo para insertar todos los valores en la cola <b> excepto el valor a eliminar
    {
        a1 = c->quitar();
        if (a1 != x)
        {
            b.insertar(a1);
        }
    }
    // cola <b> llena y cola <a> vacia
    while (!b.colaVacia()) // ciclo para insertar en cola <a> los valores de cola <b>
    {
        c->insertar(b.quitar());
    }
}

//[ 2 1 9 3 7 4 ]
void ordenarCola(Cola *c)
{
    Tipo a1, men, a2;
    Cola a, b; // cola auxiliares{a: para calculos / b: para respuesta}

    while (!c->colaVacia())
    {
        a = *c; // cola <a> llena
        men = a.quitar();

        while (!a.colaVacia()) // ciclo para buscar valor menor de la cola
        {
            a1 = a.quitar();
            a2 = men;
            if (a1 < men)
            {
                men = a1;
            }
        }
        b.insertar(men); // valor menor se inserta en cola de respuesta
        elimiarElementoCola(c, men);
    }
    
    //b.insertar(men); // valor menor se inserta en cola de respuesta
    *c = b;
}
