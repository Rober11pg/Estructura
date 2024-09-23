// Grafos1.cpp
// Implementar gestion basica de varios vertices
// Autor: Julio Santillán C.

using namespace std;
#include <iostream>
#include "Vertice.h"
#include "Utilidades.h"

int main(){					//programa principal
	system("color f0");
	int n;					//cantidad de vertices a procesar
	Vertice* v;				//definicion del apuntador al vector de vertices
	
	void leerVertices(Vertice v1[], int n1);	//prototipo de la funcion de ingreso de vector de vertices
	void imprimirVertices(Vertice v1[], int n1);	//prototipo de la funcion de impresion de vector de vertices
	void buscarVerticesDato(Vertice v1[], int n1);	//prototipo de la funcion que permite buscar vertices por dato almacenado 
	void buscarVerticesNumero(Vertice v1[], int n1);	//prototipo de la funcion que permite buscar vertices por numero almacenado 
	
	cout << endl << "CANTIDAD DE VERTICES A PROCESAR";
	n = LeerN(1, 100);			//funcion de ingreso de cantidad de valores

	v = new Vertice[n];		//dimensionar el vector de vertices

	leerVertices(v, n);		//llamado a funcion de lectura de vertices
	imprimirVertices(v, n);	//llamado a funcion de visualizacion de vector vertices

	buscarVerticesDato(v,n); //funcion que permite buscar vertices por dato almacenado 

	cout << endl;
	system("pause");
}

void leerVertices(Vertice v1[], int n1){	//prototipo de la funcion de ingreso de vector de vertices
	Tipo aux;				//var de lectura
	
	for (int i = 0; i < n1; i++){			//recorrido del vector
		cout << endl << "Ingrese valor para el vertice: ";
		cin >> aux;
		v1[i].setDato(aux);					//actualiza el dato en el vertice
		v1[i].setNum(i);					//actualiza el numero de vertice
	}
}

void imprimirVertices(Vertice v1[], int n1){	//prototipo de la funcion de impresion de vector de vertices
	for (int i = 0; i < n1; i++){			//recorrido del vector
		cout << endl << "Valor almacenado en el vertice[" << v1[i].getNum() << "]: " << v1[i].getDato();
	}
}

void buscarVerticesDato(Vertice v1[], int n1){	//funcion que permite buscar vertices por dato almacenado 
	int n;				//cantidad de busquedas a realizar
	Tipo aux;
	bool enc;
	
	cout << endl << "CANTIDAD DE BUSQUEDAS POR DATO";
	n = LeerN(1, 100);
	
	for (int i = 0; i < n; i++){
		cout << endl << "Ingrese valor a buscar: ";
		cin >> aux;
		enc = false;
		
		for (int j = 0; j < n1; j++){
			if (v1[j].esIgualDato(aux)){
				enc = true;
			}
		}
		cout << endl << "El valor " << aux << (enc ? "SI" : "NO") << " existe entre los vertices...";

	}
}