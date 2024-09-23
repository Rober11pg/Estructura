/* 3. Determinar el valor numéricamente menor más cercano a la hoja más alejada de la raíz de un AB ingresado
Autor: Roberto Jiménez-7048 */

using namespace std;
#define EXT 200 
#include <iostream>
#include "Lista.h"
#include "ArbolBinario.h"

int main(){
	system("color f0");
	Tipo menor;
	ArbolBinario a;			
	Lista Listas[EXT];
	
	void leerAB(ArbolBinario *b, Lista l[]);		//prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a);	//prototipo de funcion que imprime AB
	void encontrarMenor(ArbolBinario a, Lista l[], int i, Tipo* m);
	
	leerAB(&a, Listas);							//llamado a funcion de ingreso AB
	imprimirAB(a);						//llamado a funcion que imprime un AB
	
	menor = Listas[a.calcularAltura(a.getRaiz())-1].ultimo()->getDato();
	encontrarMenor(a, Listas, 0, &menor);
	cout << endl <<"Valor numericamente menor mas cercano a la hoja mas alejada de la raiz de un AB ingresado: " << menor;
	
	cout << endl;
	system("pause");
}

NodoBinario* leerNodo(int margen, Lista l[]){	//funcion para ingresar AB por nodos
	Tipo aux;			//var de lectura
	Tipo fin = 999;	//marca de fin de lectura
	NodoBinario* p;		//puntero a nuevo nodo

	void imprimirEsp(int c);	//funcion para imprimir espacios

	cout << endl;
	imprimirEsp(margen);	//imprimir espacios
	cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> aux;			//lectura
	
	if (aux != fin){	//no ingresa marcador de fin lectura
		l[margen].insertarEnOrden(aux);
	    p = new NodoBinario(aux);	//construye nuevo nodo solo con dato
 	    imprimirEsp(margen);	//imprimir espacios
 	    cout << "--- SUBARBOL IZQUIERDO ---";
 	    p -> setIzq(leerNodo(margen+1, l)) ;	//puntero izq recibe direccion nuevo nodo ingresado
	    imprimirEsp(margen);	//imprimir espacios
	    cout << "--- SUBARBOL DERECHO ---";
	    p -> setDer(leerNodo(margen+1, l)) ;	//puntero der recive direccion nuevo nodo ingresado
	    return p;	//devuelve direccion nuevo nodo creado
	} else {		//ingreso marcador final de lectura
		return NULL;	//no se creo el nodo
	}
}

void leerAB(ArbolBinario *b, Lista l[]){
	b -> setRaiz(leerNodo(0, l));	//actualiza raiz del arbol nuevo con apuntador devuelto
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

void encontrarMenor(ArbolBinario a, Lista l[], int i, Tipo* m){
	Tipo aux;
	Tipo aux2;
	
	if(i <= a.calcularAltura(a.getRaiz())-2){
		aux = l[a.calcularAltura(a.getRaiz())-1].ultimo()->getDato();
		aux2 = l[i].getPrimero()->getDato();
		if(aux2 < aux){
			*m = aux2;
		}
		encontrarMenor(a, l, i+1, m);
	}
}