/* 5. Calcular el rango (diferencia entre el valor mayor y el menor) de un ABB ingresado
Autor: Roberto Jiménez-7048 */

using namespace std;
#include<climits>
#include <iostream>
#include "ArbolBinario.h"

int main() {
    system("color f0");
    ArbolBinario a;       // declara un árbol binario
    void leerAB(ArbolBinario* b);    // prototipo de función ingreso AB
    void imprimirAB(ArbolBinario a); // prototipo de función que imprime AB
    int encontrarMaximo(NodoBinario* nodo); // Prototipo de función que encuentra el máximo
    int calcularRango(ArbolBinario a); // Prototipo de función que calcula el rango


    leerAB(&a);           // llamado a función de ingreso AB
    imprimirAB(a);        // llamado a función que imprime un AB

    // Calcular el rango del árbol
    int rango = calcularRango(a);

    cout << endl <<"---------RANGO----------";
    cout << endl << "Rango del arbol: " << rango << endl;
    cout << endl;
    system("pause");
}

NodoBinario* leerNodo(int margen) { // función para ingresar AB por nodos
    Tipo aux;                 // var de lectura
    Tipo fin = 999;         // marca de fin de lectura
    NodoBinario* p;           // puntero a nuevo nodo

    void imprimirEsp(int c);  // función para imprimir espacios

    cout << endl;
    imprimirEsp(margen);      // imprimir espacios
    cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
    cin >> aux;               // lectura

    if (aux != fin) {         // no ingresa marcador de fin lectura
        p = new NodoBinario(aux);       // construye nuevo nodo solo con dato
        imprimirEsp(margen);  // imprimir espacios
        cout << "--- SUBARBOL IZQUIERDO ---";
        p->setIzq(leerNodo(margen + 1)); // puntero izq recibe direccion nuevo nodo ingresado
        imprimirEsp(margen);  // imprimir espacios
        cout << "--- SUBARBOL DERECHO ---";
        p->setDer(leerNodo(margen + 1)); // puntero der recive direccion nuevo nodo ingresado
        return p;             // devuelve direccion nuevo nodo creado
    } else {                  // ingreso marcador final de lectura
        return NULL;          // no se creó el nodo
    }
}

void leerAB(ArbolBinario* b) {
    b->setRaiz(leerNodo(0));  // actualiza raíz del árbol nuevo con apuntador devuelto
}

void imprimirEsp(int c) {    // función para imprimir espacios
    for (int i = 1; i <= c; i++) {  // ciclo impresion espacios
        cout << "   ";
    }
}

void imprimirAB(ArbolBinario a) {
    cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABSimple(a.getRaiz());  // llama metodo impresion simple de AB

    cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);  // llama a metodo impresion con formato jerarquico de AB
}

int encontrarMinimo(NodoBinario* nodo) { // Función que encuentra el mínimo
    if (nodo == nullptr) {
        return INT_MAX;
    }

    int min_izq = encontrarMinimo(nodo->getIzq());
    int min_der = encontrarMinimo(nodo->getDer());

    return min(min(nodo->getDato(), min_izq), min_der);
}

int encontrarMaximo(NodoBinario* nodo) { // Función que encuentra el máximo
    if (nodo == nullptr) {
        return INT_MIN;
    }

    int max_izq = encontrarMaximo(nodo->getIzq());
    int max_der = encontrarMaximo(nodo->getDer());

    return max(max(nodo->getDato(), max_izq), max_der);
}

int calcularRango(ArbolBinario a) { // Función que calcula el rango
    int min = encontrarMinimo(a.getRaiz());
    int max = encontrarMaximo(a.getRaiz());

    return max - min;
}