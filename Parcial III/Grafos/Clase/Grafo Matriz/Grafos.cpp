// Grafos 0.cpp
// Implementar gestión básica de vertices
// Autor: Roberto Jiménez-7048

using namespace std;
#include <iostream>
#include "Vertice.h"

int main()
{
    system("color f0");
    Vertice v;
    Vertice v2;
    Vertice v3;
    Vertice v2("500");
    Vertice v3("700", 3);
    Tipo aux;
    cout << "Ingrese un valor a almacenar en el vertice" << endl;
    cin >> aux;
    v.setDato(aux); // almacena el valor ingresado en el vertice
    cout << "El valor almacenado en el vertice es: " << v.getDato() << endl;
    cout << "El numero asignado en el vertice es: " << v.getNum() << endl;

    cout << "El valor almacenado en el vertice es: " << v2.getDato() << endl;
    cout << "El numero asignado en el vertice es: " << v2.getNum() << endl;


    cout << "El valor almacenado en el vertice es: " << v3.getDato() << endl;
    cout << "El numero asignado en el vertice es: " << v3.getNum() << endl;

    cout << "" << endl;
    system("pause");
}