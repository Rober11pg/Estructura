/* Pila 0.cpp
Gestion basica de un tda pila
Autor: Roberto Jiménez */

#include <iostream>
#include "Pila.h"
using namespace std;

int main()
{
    system("color f0");
    Pilas p;

    cout << "El valor de atributo top es: " << p.getTop() << endl;
    cout << "La pila " << (p.pilaVacia() ? "SI" : "NO") << " esta vacia" << endl;
    cout << "La pila " << (p.pilaLlena() ? "SI" : "NO") << " esta llena" << endl;

    p.push(15); 

    cout << "Valor extraido de la pila " << p.pop() << endl;
    cout << "La pila " << (p.pilaVacia() ? "SI" : "NO") << " esta vacia" << endl;
    cout << "La pila " << (p.pilaLlena() ? "SI" : "NO") << " esta llena" << endl;
    
    cout << "Valor extraido de la pila " << p.pop() << endl;
    cout << "La pila " << (p.pilaVacia() ? "SI" : "NO") << " esta vacia" << endl;
    cout << "La pila " << (p.pilaLlena() ? "SI" : "NO") << " esta llena" << endl;
    system("pause");
}