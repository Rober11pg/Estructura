// Grafos0.cpp
// Implementar gestion basica de vertices
// Autor: Julio Santillán C.

using namespace std;
#include <iostream>
#include "Vertice.h"

int main(){			//programa principal
	system("color f0");
	Vertice v1;
	Vertice v2("500");		//llama al constructor conociendo valor a almacenar
	Vertice v3("700", 3);		//llama al constructor conociendo valor e identificador del vertice
	Tipo aux;
	
	cout << endl << "Ingrese un valor a almacenar en el vertice: ";
	cin >> aux;
	
	v1.setDato(aux);			//almacena el valor ingresado
	
	cout << endl << "El valor almacenado en el vertice es: " << v1.getDato();
	cout << endl << "El numero asignado a el vertice es: " << v1.getNum();

	cout << endl << "El valor almacenado en el vertice es: " << v2.getDato();
	cout << endl << "El numero asignado a el vertice es: " << v2.getNum();
	
	cout << endl << "El valor almacenado en el vertice es: " << v3.getDato();
	cout << endl << "El numero asignado a el vertice es: " << v3.getNum();

	cout << endl;
	system("pause");
}