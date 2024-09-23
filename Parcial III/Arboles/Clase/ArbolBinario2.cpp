// ArbolBinario2.cpp
// implementa un AB basico
// Autor: Julio Santillán Castillo

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main()
{ // programa principal
     system("color f0");
     ArbolBinario a; // declara un árbol binario
     int sum = 0;
     void leerAB(ArbolBinario * b);       // prototipo de funcion ingreso AB
     void imprimirAB(ArbolBinario a);     // prototipo de funcion que imprime AB
     // void verDatosAB(ArbolBinario a);     // prototipo de funcion para visualizar datos generales de un arbol
     // void verHojasAB(ArbolBinario a);     // prototipo de funcion para visualizar los nodos hoja del Ab
     // void recorrerAB(ArbolBinario a);     // protipo de la funcion que implementa los diversos recorridos de un AB
     leerAB(&a);                          // llamado a funcion de ingreso AB
     //verDatosAB(a);                       // llamado a impresion datos generales AB

     imprimirAB(a); // llamado a funcion que imprime un AB

     //verHojasAB(a); // llamado a impresion de nodos hoja del AB
    // recorrerAB(a); // llamado a la funcion que implementa diversos recorridos de AB
     //cout << "La suma de las de las ramas es: " << a.SumarNodosRama(a.getRaiz()) << endl;
     cout<<""<<endl;
     cout << endl;
     system("pause");
}

NodoBinario *leerNodo(int margen)
{                    // funcion para ingresar AB por nodos
     Tipo aux;       // var de lectura
     Tipo fin = 999; // marca de fin de lectura
     NodoBinario *p; // puntero a nuevo nodo

     void imprimirEsp(int c); // funcion para imprimir espacios

     cout << endl;
     imprimirEsp(margen); // imprimir espacios
     cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
     cin >> aux; // lectura

     if (aux != fin)
     {                              // no ingresa marcador de fin lectura
          p = new NodoBinario(aux); // construye nuevo nodo solo con dato

          // dirección de memoria |null| p |null|

          imprimirEsp(margen); // imprimir espacios
          cout << "--- SUBARBOL IZQUIERDO ---";
          p->setIzq(leerNodo(margen + 1)); // puntero izq recibe direccion nuevo nodo ingresado
          imprimirEsp(margen);             // imprimir espacios
          cout << "--- SUBARBOL DERECHO ---";
          p->setDer(leerNodo(margen + 1)); // puntero der recive direccion nuevo nodo ingresado
          return p;                        // devuelve direccion nuevo nodo creado
     }
     else
     {                 // ingreso marcador final de lectura
          return NULL; // no se creo el nodo
     }
}

void leerAB(ArbolBinario *b)
{
     b->setRaiz(leerNodo(0)); // actualiza raiz del arbol nuevo con apuntador devuelto
     //  se pasa 0 como valor inicial para margen, indicando que la raíz debe imprimirse sin ningún margen adicional (sin espacios previos)
}

void imprimirEsp(int c)
{ // funcion para imprimir espacios
     for (int i = 1; i <= c; i++)
     { // ciclo impresion espacios
          cout << "   ";
     }
}

void imprimirAB(ArbolBinario a)
{
     cout << endl
          << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
     a.imprimirABSimple(a.getRaiz()); // llama metodo impresion simple de AB

     cout << endl
          << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl<< endl;
     a.imprimirABJerarquia(a.getRaiz(), 0); // llama a metodo impresion con formato jerarquico de AB
}

void verDatosAB(ArbolBinario a)
{ // visualizar datos generales de un arbol
     cout << endl
          << "IMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl
          << endl;
     cout << endl
          << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
     cout << endl
          << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
     cout << endl
          << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
     cout << endl
          << "El nodo raiz es: " << a.getRaiz()->getDato();
}

void verHojasAB(ArbolBinario a)
{ // visualizar los nodos hoja del Ab
     cout << endl
          << "IMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl
          << endl;
     a.verHojas(a.getRaiz()); // llama a metodo que visualiza nodos hoja del AB
}

void recorrerAB(ArbolBinario a)
{ // funcion que implementa los diversos recorridos de un AB
     cout << endl
          << "RECORRIDOS DE ARBOL BINARIO" << endl
          << endl;
     cout << endl
          << "RECORRIDO EN PREORDEN" << endl; // raiz, izquierdo, derecho
     a.recorrerEnPreorden(); // llama al metodo correspondiente
     cout << endl
          << "RECORRIDO EN INORDEN" << endl; // izquierdo, raiz, derecho
     a.recorrerEnInorden(); // llama al metodo correspondiente
     cout << endl
          << "RECORRIDO EN POSORDEN" << endl;     // izquierdo, derecho, raiz
     a.recorrerEnPostorden(); // llama al metodo correspondiente
}

