/* Promgrama que implementa un TDA Cola Básico
Autor: Roberto Jimenez */
#include <iostream>
#include "Cola.h"
using namespace std;

int main()
{
    system("color f0");
    Cola c;
    cout << "El TDA cola contiene el valor final: " << c.getFinal() << endl;
    cout << "El TDA " << (c.colaVacia() ? "SI" : "NO") << " esta vacia" << endl;

    cout << "El TDA " << (c.colaVacia() ? "SI" : "NO") << " esta vacia" << endl;

    c.insertar(100); // añade un valor arbitrario en el tda
    c.insertar(200);

    cout << "El TDA " << (c.colaVacia() ? "SI" : "NO") << " no esta vacia " << endl;
    cout << "El TDA " << c.tamanioCola() << " elementos" << endl;
    cout << "El TDA " << (c.colaVacia() ? "SI" : "NO") << " esta llena " << endl;
    cout << "" << endl;
    cout << "El valor obtenido en la posicion frente es: " << c.frentecola() << endl;
    c.quitar();
    cout << "El TDA " << (c.colaVacia() ? "SI" : "NO") << " no esta vacia " << endl;
    cout << "El TDA " << c.tamanioCola() << " elementos" << endl;
    cout << "" << endl;
    system("pause");
}