/*Grafo 0 
Implementacion de los vertices */

using namespace std;
#include <iostream>
#include "Vertice.h"
#include "Utilidades.h"
#include "Lista.h";

int main(){
	system ("color f0");
	int n;
	Lista Vertice v;
	
	void leerVertices(Vertice v1[], int n1, int i);
	void imprimirVertices(Vertice v1[], int n1, int i);
	void buscarVerticesDatos(Vertice v1[], int n1);

	v = new Lista Vertice;
	
	leerVertices(v, n, 0);
	imprimirVertices(v, n, 0);	
	buscarVerticesDatos(v, n);
}


void leerVertices(Vertice v1[], int n1, int i){
	Tipo aux;
	
	if (i != n1){
		cout << endl << "Ingrese valor para el vertice: ";
		cin >> aux;
		v1[i].setDato(aux);
		v1[i].setNum(i);
		leerVertices(v1, n1, i+1);			
	}
}

void imprimirVertices(Vertice v1[], int n1, int i){
	if (i != n1){
		cout << endl << "Valores almacenado en el vertice [" << v1[i].getNum() << "]: " << v1[i].getDato();
		imprimirVertices(v1, n1, i+1);
	}
}

void buscarVerticesDatos(Vertice v1[], int n1){
	int n; 
	Tipo aux;
	bool enc; 
	
	cout << endl << "CANTIDAD DE BUSQUEDAS POR DATO";
	n = LeerN(0, 100);
	
	for(int i = 0; i < n; i++){
		cout << endl <<"Ingrese valor a buscar: ";
		cin >> aux;
		enc = false;
		
		for(int j = 0; j < n1; j++){
			if(v1[j].esIgualDato(aux))
				enc = true;
		}				
		
		cout << endl <<"El valor "<< aux << (enc ? " Si" : " No")<< " existe entre los vertices";
	}
}
	
	
	
	
	
	
	
	
	