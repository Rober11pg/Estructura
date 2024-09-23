/*
Programa de gesetión de cadenas
Autor: Roberto Jiménez
 */
#include <iostream>
using namespace std;
int main()
{ // programa principal
    system("color f0");
    char f[15];
    // primer estrategia leer de caracter en caracter
    // segunda forma más rápida unsando una función
    cout << "Ingrese una cadena de caracteres: " << endl;
    // cin>> f;
    cin.getline(f, 15, '.') >> f; // lee una línea hasta que ecuentres un etender
                                  // donde quiero guardad, logitud máximo del vector, caracter de fin
    cout << "La cadena ingresada es: " << f << endl;
    cout << endl; // todo aquello que no es letra le pone fin de cadena, queda memoria intermedia eso se llama bufer

    system("pause");
}

//
