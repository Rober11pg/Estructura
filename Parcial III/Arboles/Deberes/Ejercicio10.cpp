/*10. Permitir el ingreso de varios AB y determinar cuáles,
 entre ellos son LLENOS (no hay nodos que tengan un solo nodo descendiente),
  COMPLETOS (hasta el nivel n-1 todos los nodos son llenos, y en el nivel n todos 
  los nodos hoja ocupan las posiciones mas a la izquierda) y DEGENERADOS (solo existe un nodo hoja, 
  y todos los demás nodos solo tienen un nodo descendiente)
  Nombre: Roberto Jiménez-7048*/

#include <iostream>
#include "ArbolBinario.h"

bool esArbolLleno(NodoBinario* nodo);
bool esArbolCompleto(NodoBinario* nodo);
bool esArbolDegenerado(NodoBinario* nodo);
NodoBinario* leerNodo(int margen);
void leerAB(ArbolBinario* b);
void imprimirEsp(int c);
void imprimirAB(ArbolBinario a);

int main() {
    system("color f0");
    int numArboles;
    cout << "Ingrese la cantidad de arboles que desea ingresar: ";
    cin >> numArboles;

    ArbolBinario* arboles = new ArbolBinario[numArboles];
    for (int i = 0; i < numArboles; i++) {
        cout << endl << "ARBOL " << i + 1 << endl;
        leerAB(&arboles[i]);
        imprimirAB(arboles[i]);
    }

    cout << endl << "RESULTADOS:" << endl;
    for (int i = 0; i < numArboles; i++) {
        cout << endl << "ARBOL " << i + 1 << ":" << endl;
        if (esArbolLleno(arboles[i].getRaiz())) {
            cout << "Es un arbol LLENO" << endl;
        } else {
            cout << "No es un arbol LLENO" << endl;
        }

        if (esArbolCompleto(arboles[i].getRaiz())) {
            cout << "Es un arbol COMPLETO" << endl;
        } else {
            cout << "No es un arbol COMPLETO" << endl;
        }

        if (esArbolDegenerado(arboles[i].getRaiz())) {
            cout << "Es un arbol DEGENERADO" << endl;
        } else {
            cout << "No es un arbol DEGENERADO" << endl;
        }
    }

    delete[] arboles;

    cout << endl;
    system("pause");
}

NodoBinario* leerNodo(int margen) {
    Tipo aux;
    Tipo fin = 999;
    NodoBinario* p = nullptr;

    void imprimirEsp(int c);

    cout << endl;
    imprimirEsp(margen);
    cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
    cin >> aux;

    if (aux != fin) {
        p = new NodoBinario(aux);
        imprimirEsp(margen);
        cout << "--- SUBARBOL IZQUIERDO ---";
        p->setIzq(leerNodo(margen + 1));
        imprimirEsp(margen);
        cout << "--- SUBARBOL DERECHO ---";
        p->setDer(leerNodo(margen + 1));
    }

    return p;
}

void leerAB(ArbolBinario* b) {
    b->setRaiz(leerNodo(0));
}

void imprimirEsp(int c) {
    for (int i = 1; i <= c; i++) {
        cout << "   ";
    }
}

void imprimirAB(ArbolBinario a) {
    cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABSimple(a.getRaiz());

    cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);
}

bool esArbolLleno(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return true;
    }

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        return true;
    }

    if (nodo->getIzq() != nullptr && nodo->getDer() != nullptr) {
        return esArbolLleno(nodo->getIzq()) && esArbolLleno(nodo->getDer());
    }

    return false;
}

bool esArbolCompleto(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return true;
    }

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        return true;
    }

    if (nodo->getIzq() != nullptr && nodo->getDer() != nullptr) {
        return esArbolCompleto(nodo->getIzq()) && esArbolCompleto(nodo->getDer());
    }

    return false;
}

bool esArbolDegenerado(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return false;
    }

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        return true;
    }

    if (nodo->getIzq() != nullptr && nodo->getDer() == nullptr) {
        return esArbolDegenerado(nodo->getIzq());
    }

    if (nodo->getIzq() == nullptr && nodo->getDer() != nullptr) {
        return esArbolDegenerado(nodo->getDer());
    }

    return false;
}