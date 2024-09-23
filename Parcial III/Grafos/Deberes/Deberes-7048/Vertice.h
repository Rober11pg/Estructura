// vertice.h
// Implementa la definicion de los vértices de un grafo

#ifndef _VERTICE_H
#define _VERTICE_H

#include <iostream>
using namespace std;

class Vertice {						//implementación de la clase
private:							//atributos
	string nombre;					//valor almacenado (nombre) del vertice
	int numero;						//numero de vertice

public:								//metodos publicos
	Vertice ();						//constructor por defecto
	Vertice(string no);				//constructor conociendo valor a almacenar en vertice y pone el número de vértice e -1
	Vertice(string no, int nu);		//constructor conociendo valor a almacenar en vértice y numero que le corresponde
	string getNombre();				//devuelve el estado del atributo nombre
	int getNumero();				//retorna el estado del atributo numero de vertice
	void setNombre(string no);		//actualiza estado del atributo
	void setNumero(int nu);			//actualiza estado del atributo
	bool igual(string no);			//determina si nombre del vertice es igual al parámetro
	bool igual(int nu);				//determina si numero del vertice es igual al paramtero
};

Vertice::Vertice () {				//constructor por defecto
}

Vertice::Vertice(string no) {		//constructor conociendo valor a almacenar en vertice y pone el número de vértice e -1
	setNombre(no);					//actualiza nombre
	setNumero(-1);					//actualiza numero
}

Vertice::Vertice(string no, int nu) {	//constructor conociendo valor a almacenar en vértice y numero que le corresponde
	setNombre(no);						//actualiza nombre
	setNumero(nu);						//actualiza numero
}

string Vertice::getNombre(){			//devuelve el estado del atributo nombre
	return nombre;						//devuelve valor del atributo
}

int Vertice::getNumero() { 				//devuelve el estado del atributo numero
	return numero;						//devuelve valor del atributo
}

void Vertice::setNombre(string no) {	//actualiza estado atributo nombre
	nombre = no;						//guarda valor del parametro den atributo
}

void Vertice::setNumero(int nu) { 		//actualiza el estado del atributo numero
	numero = nu;						//guarda valor del parametro en el atributo
}

bool Vertice::igual(string no) {		//metodo que determina si nombre del vertice es igual al parametro
	return (getNombre() == no);			//calcula valor booleano producto de comparación
}

bool Vertice::igual(int nu) {			//metodo que determina si numero de vertice es igual al parametro
	return (getNumero() == nu);			//calcula valor booleano producto de comparar numero con parametro
}
#endif
