// grafo2.cpp
// GESTIONA UN GRAFO CON MATRIZ DE ADYACENCIA

using namespace std;
#include <iostream>
#include "GrafoMatriz.h"
#include "utilidades.h"

int main(){
	system("color fc");					//interfaz
	GrafoMatriz g;						//declara un grafo para manipular las clases
	int n;								//cantidad de vertices a crear
	
	GrafoMatriz ingresarVertices(int n1);
	void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoMatriz *g);		//añade arcos => grafos valorados
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	
	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);					//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);				//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
	//ingresarArcosValor(&g);				//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
	
	cout << endl;
	system("pause");
}

GrafoMatriz ingresarVertices(int n1){				//funcion que ingresa los datos de los vértices de un grafo
	Tipo aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoMatriz *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoMatriz *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;						//peso del arco
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoMatriz g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
	Tipo aux;
	cout << endl << "===============================================";
	cout << endl << "M A T R I Z     D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato();
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}
