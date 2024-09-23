/* 8. Imprimir todos los caminos que van desde la raíz a cada una de las hojas de un AB ingresado
Nombre: Roberto Jiménez-7048 ew*/
using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main() {
    ArbolBinario a;
    system("color f0");
    
    void leerAB(ArbolBinario* b);    // prototipo de función ingreso AB
    void imprimirAB(ArbolBinario a); // prototipo de función que imprime AB
    void imprimirCaminos(NodoBinario* nodo, string camino);
    void imprimirCaminosArbol(ArbolBinario* a);

    leerAB(&a);
    imprimirAB(a);
    imprimirCaminosArbol(&a);

    return 0;
}

NodoBinario* leerNodo(int margen) { // función para ingresar AB por nodos
    int aux;                 // var de lectura
    int fin = 99999;         // marca de fin de lectura
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
        return nullptr;          // no se creó el nodo
    }
}

void leerAB(ArbolBinario* b) {
    b->setRaiz(leerNodo(0));  // actualiza raíz del árbol nuevo con apuntador devuelto
}

void imprimirEsp(int c) {    // función para imprimir espacios
    for (int i = 1; i <= c; i++) {  // ciclo impresion espacios
        std::cout << "   ";
    }
}

void imprimirAB(ArbolBinario a) {
    cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABSimple(a.getRaiz());  // llama metodo impresion simple de AB

    cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);  // llama a metodo impresion con formato jerarquico de AB
}

void imprimirCaminos(NodoBinario* nodo, std::string camino) {
    if (nodo == NULL) {
        return;
    }

    camino += to_string(nodo->getDato());

    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        cout << camino << endl;
        return;
    }

    camino += " -> ";

    imprimirCaminos(nodo->getIzq(), camino);
    imprimirCaminos(nodo->getDer(), camino);
}

void imprimirCaminosArbol(ArbolBinario* a) {
    if (a->esVacio()) {
        cout << "El arbol esta vacio." << endl;
        return;
    }

    cout << "Caminos desde la raiz a cada hoja:" << endl;
    imprimirCaminos(a->getRaiz(), "");
}