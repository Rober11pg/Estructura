/* ArbolBinario0.cpp
Implementar un primer acercamiento a TDA ArbolBinario
Autro : Roberto Jiménez*/

using namespace std;
#include <iostream>
#include "NodoBinario.h"

int main(){
	system("color f0");
	NodoBinario n1;
	NodoBinario n2 (200);
	NodoBinario n3 (300, &n1, &n2);
	
	n1.setDato(100);
	
	cout << endl << "Valor almacenado en el nodo n1: " << n1.getDato(); 
	cout << endl << "Sub-Arbol izquierdo del nodo n1: "<< n1.getIzq(); 
	cout << endl << "Sub-Arbol derecho del nodo n1: "<< n1.getDer(); 
	
	cout << endl << "Valor almacenado en el nodo n2: " << n2.getDato(); 
	cout << endl << "Sub-Arbol izquierdo del nodo n2: "<< n2.getIzq(); 
	cout << endl << "Sub-Arbol derecho del nodo n2: "<< n2.getDer(); 

	cout << endl << "Valor almacenado en el nodo n3: " << n3.getDato(); 
	cout << endl << "Sub-Arbol izquierdo del nodo n3: "<< n3.getIzq(); 
	cout << endl << "Sub-Arbol derecho del nodo n3: "<< n3.getDer(); 
	
	cout<<endl;
	system("pause");
}