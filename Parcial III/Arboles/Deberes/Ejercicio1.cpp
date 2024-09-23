/* 1. Generar una lista con los nodos externos de un �rbol previamente ingresado
Autor: Roberto Jiménez-7048 */

using namespace std;
#include <iostream>
#include "Lista.h"
#include "ArbolBinario.h"

int main(){
	system("color f0");
	ArbolBinario a;			
	Lista l;
	
	void leerAB(ArbolBinario *b);		//prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a);	//prototipo de funcion que imprime AB

	void guardarNodosExternos(NodoBinario* p, Lista *l1);
	void imprimirLista(Nodo * act);
	
	leerAB(&a);							//llamado a funcion de ingreso AB
	imprimirAB(a);						//llamado a funcion que imprime un AB

	guardarNodosExternos(a.getRaiz(), &l);
	cout << endl << "Lista de Nodos externos";
	imprimirLista(l.getPrimero());
	
	cout << endl;
	system("pause");
}

NodoBinario* leerNodo(int margen){	//funcion para ingresar AB por nodos
	Tipo aux;			//var de lectura
	Tipo fin = 999;	 //marca de fin de lectura
	NodoBinario* p;		//puntero a nuevo nodo

	void imprimirEsp(int c);	//funcion para imprimir espacios

	cout << endl;
	imprimirEsp(margen);	//imprimir espacios
	cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> aux;			//lectura
	
	if (aux != fin){	//no ingresa marcador de fin lectura
	   p = new NodoBinario(aux);	//construye nuevo nodo solo con dato
	   imprimirEsp(margen);	//imprimir espacios
	   cout << "--- SUBARBOL IZQUIERDO ---";
	   p -> setIzq(leerNodo(margen+1)) ;	//puntero izq recibe direccion nuevo nodo ingresado
	   imprimirEsp(margen);	//imprimir espacios
	   cout << "--- SUBARBOL DERECHO ---";
	   p -> setDer(leerNodo(margen+1)) ;	//puntero der recive direccion nuevo nodo ingresado
	   return p;	//devuelve direccion nuevo nodo creado
	} else {		//ingreso marcador final de lectura
		return NULL;	//no se creo el nodo
	}
}

void leerAB(ArbolBinario *b){
	b -> setRaiz(leerNodo(0));	//actualiza raiz del arbol nuevo con apuntador devuelto
}

void imprimirEsp(int c){	//funcion para imprimir espacios
	for (int i = 1; i <= c; i++){	//ciclo impresion espacios
		cout << "   ";
    }
}

void imprimirAB(ArbolBinario a){
	cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

void guardarNodosExternos(NodoBinario* p, Lista *l1) {
    if (p != NULL) {
        if (p->getIzq() == NULL && p->getDer() == NULL) {
            l1->insertarAlFinal(p->getDato());  // Si es una hoja, la agregamos a la lista
        } else {
            guardarNodosExternos(p->getIzq(), l1);  // Explorar subárbol izquierdo
            guardarNodosExternos(p->getDer(), l1);  // Explorar subárbol derecho
        }
    }
}

void imprimirLista(Nodo * act){
	if (act != NULL){
		cout << endl
			 << "> " << act->getDato() << endl;
		imprimirLista(act -> getPunt());
	}	
}
