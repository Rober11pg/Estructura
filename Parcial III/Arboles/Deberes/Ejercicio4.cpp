/* 4. Imprimir el subárbol que tiene como nodo raíz el valor menor de un AB ingresado
Autor: Roberto Jiménez-7048 */

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main()
{ // programa principal
	system("color f0");
	ArbolBinario a;	  // declara un árbol binario
	NodoBinario nodo; // declara el nodo

	void leerAB(ArbolBinario * b);						  // prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a);					  // prototipo de funcion que imprime AB
	NodoBinario *encontrarNodoMinimo(NodoBinario * nodo); // Prototipo de función que encuentra el nodo mínimo
	void imprimirSubArbol(NodoBinario * nodo, int nivel); // Prototipo de función que imprime el subárbol con hojas

	leerAB(&a);	   // llamado a función de ingreso AB
	imprimirAB(a); // llamado a función que imprime un AB

	// Encontrar el nodo mínimo en el árbol
	NodoBinario *nodoMinimo = encontrarNodoMinimo(a.getRaiz()); // esto es importante ya que le pasa como parametro a la funcion imprimirSubArbol

	// Imprimir el subárbol con el nodo mínimo como raíz y sus hojas correspondientes
	cout << endl
		 << "Subarbol con el valor minimo como raiz:" << endl;
	imprimirSubArbol(nodoMinimo, 0);

	cout << endl;
	system("pause");
}

NodoBinario *leerNodo(int margen)
{					// funcion para ingresar AB por nodos
	Tipo aux;		// var de lectura
	Tipo fin = 999; // marca de fin de lectura
	NodoBinario *p; // puntero a nuevo nodo

	void imprimirEsp(int c); // funcion para imprimir espacios

	cout << endl;
	imprimirEsp(margen); // imprimir espacios
	cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> aux; // lectura

	if (aux != fin)
	{							  // no ingresa marcador de fin lectura
		p = new NodoBinario(aux); // construye nuevo nodo solo con dato
		imprimirEsp(margen);	  // imprimir espacios
		cout << "--- SUBARBOL IZQUIERDO ---";
		p->setIzq(leerNodo(margen + 1)); // puntero izq recibe direccion nuevo nodo ingresado
		imprimirEsp(margen);			 // imprimir espacios
		cout << "--- SUBARBOL DERECHO ---";
		p->setDer(leerNodo(margen + 1)); // puntero der recive direccion nuevo nodo ingresado
		return p;						 // devuelve direccion nuevo nodo creado
	}
	else
	{				 // ingreso marcador final de lectura
		return NULL; // no se creo el nodo
	}
}

void leerAB(ArbolBinario *b)
{
	b->setRaiz(leerNodo(0)); // actualiza raiz del arbol nuevo con apuntador devuelto
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
		 << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl
		 << endl;
	a.imprimirABSimple(a.getRaiz()); // llama metodo impresion simple de AB

	cout << endl
		 << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl
		 << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0); // llama a metodo impresion con formato jerarquico de AB
}

NodoBinario *encontrarNodoMinimo(NodoBinario *nodo)
{
	if (nodo == NULL)
	{
		return NULL;
	}

	NodoBinario *nodoMinIzq = encontrarNodoMinimo(nodo->getIzq());
	NodoBinario *nodoMinDer = encontrarNodoMinimo(nodo->getDer());

	NodoBinario *nodoMinActual = nodo;
	if (nodoMinIzq != NULL && nodoMinIzq->getDato() < nodoMinActual->getDato())
	{
		nodoMinActual = nodoMinIzq;
	}
	if (nodoMinDer != NULL && nodoMinDer->getDato() < nodoMinActual->getDato())
	{
		nodoMinActual = nodoMinDer;
	}

	return nodoMinActual;
}

void imprimirSubArbol(NodoBinario *nodo, int nivel)
{
	if (nodo == NULL)
	{
		return;
	}

	for (int i = 0; i < nivel; i++)
	{
		cout << "   ";
	}
	cout << nodo->getDato() << endl;

	imprimirSubArbol(nodo->getIzq(), nivel + 1);
	imprimirSubArbol(nodo->getDer(), nivel + 1);
}