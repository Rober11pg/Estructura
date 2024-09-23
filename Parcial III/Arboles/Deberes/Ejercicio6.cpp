/* 6. Permitir el ingreso de N valores por parte del usuario, y 
proceder a generar todos los ABB posibles construidos a partir de los mismos.
Autor: Roberto Jiménez-7048 */

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

const int MAX_VALORES = 100;

int main() {
    system("color f0");
    
    int valores[MAX_VALORES];
    int tamano;
     void leerAB(ArbolBinario* b);    // prototipo de función ingreso AB
    void imprimirAB(ArbolBinario a); // prototipo de función que imprime AB
    void generarABB(Tipo valores[], int tamano, int indice, ArbolBinario& a);
    void generarTodosABB(int valores[], int tamano);


    cout << "Ingrese la cantidad de valores: ";
    cin >> tamano;

    cout << "Ingrese los valores:" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];
    }

    generarTodosABB(valores, tamano);

    cout << endl;
    system("pause");
    return 0;
}

void generarABB(Tipo valores[], int tamano, int indice, ArbolBinario& a) {
    if (indice >= tamano) {
        // Se han considerado todos los valores, imprimir el ABB generado
        cout << "ABB generado:" << endl;
        a.imprimirABSimple(a.getRaiz());
        cout << endl;
        return;
    }

    // Generar el ABB insertando el valor actual
    a.insertarNodo(valores[indice]);
    generarABB(valores, tamano, indice + 1, a);
    a.eliminarNodo(valores[indice]); // Eliminar el valor insertado para probar la otra opción

    // Generar el ABB sin insertar el valor actual
    generarABB(valores, tamano, indice + 1, a);
}


void generarTodosABB(int valores[], int tamano) {
    ArbolBinario a;
    generarABB(valores, tamano, 0, a);
}
