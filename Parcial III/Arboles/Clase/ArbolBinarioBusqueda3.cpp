// ArbolBinario2.cpp
// implementa un AB basico
// Autor: Roberto Jiménez

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main()
{ // programa principal
    system("color f0");
    ArbolBinario a;                   // declara un árbol binario
    void leerABB(ArbolBinario * b);   // prototipo de funcion ingreso AB
    void imprimirABB(ArbolBinario a); // prototipo de funcion que imprime AB
    bool buscarEnABB(ArbolBinario a); // prototipo de la funcino que busca un valor en un  ABB
    leerABB(&a);                      // llamado a funcion de ingreso AB
    imprimirABB(a);                   // llamado a funcion que imprime un AB
    bool enc = buscarEnABB(a);
    cout << "El valor ingresado" << (enc ? " Si" : " No") << " existe en el ABB procesado..." << endl;
    cout << "" << endl;
    cout << endl;
    system("pause");
}
void leerABB(ArbolBinario *b)
{
    Tipo aux;      // Hacer la lectura
    int fin = 999; // Marcador de fin de lectura
    do
    {
        cout << "Ingrese un valor a incluir en el ABB. Finalice con[" << fin << "]" << endl;
        cin >> aux;
        if (aux != fin)
        {
            b->insertarNodo(aux);
        }
    } while (aux != fin); // repetir lectura mientras aux digerente de fin
}

void imprimirABB(ArbolBinario a)
{
    cout << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl;
    a.imprimirABSimple(a.getRaiz()); // llama metodo impresion simple de AB

    cout << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0); // llama a metodo impresion con formato jerarquico de AB
}

bool buscarEnABB(ArbolBinario a)
{
    Tipo aux; // Hacer la lectura
    cout << "Ingrese un valor a buscar en el ABB" << endl;
    cin >> aux;
    return (a.buscarNodo(aux) != NULL); // Devuelve verdadero cuando recibe apuntador a un nodo, falso cuando recibe NULL
}