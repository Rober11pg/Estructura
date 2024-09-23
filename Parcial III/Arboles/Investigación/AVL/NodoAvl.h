/* Autor: Roberto Jiménez-7048*/
typedef int Tipoelemento;

#include <iostream>
using namespace std;

#ifndef _NODOAVL_H
#define _NODOAVL_H
class NodoAvl
{
protected:
	Tipoelemento dato;
	NodoAvl *izdo;
	NodoAvl *dcho;
	int fe;

public:
	NodoAvl(Tipoelemento valor)
	{
		dato = valor;
		izdo = dcho = NULL;
		fe = 0;
	}

	NodoAvl(Tipoelemento valor, int vfe)
	{
		dato = valor;
		izdo = dcho = NULL;
		fe = vfe;
	}

	NodoAvl(NodoAvl *ramaIzdo, Tipoelemento valor, NodoAvl *ramaDcho)
	{
		dato = valor;
		izdo = ramaIzdo;
		dcho = ramaDcho;
		fe = 0;
	}

	NodoAvl(NodoAvl *ramaIzdo, int vfe, Tipoelemento valor, NodoAvl *ramaDcho)
	{
		dato = valor;
		izdo = ramaIzdo;
		dcho = ramaDcho;
		fe = vfe;
	}
	// operaciones de acceso
	Tipoelemento valorNodo() { return dato; }
	NodoAvl *subarbolIzdo() { return izdo; }
	NodoAvl *subarbolDcho() { return dcho; }
	void nuevoValor(Tipoelemento d) { dato = d; }
	void ramaIzdo(NodoAvl *n) { izdo = n; }
	void ramaDcho(NodoAvl *n) { dcho = n; }
	void visitar() { cout << dato << endl; }
	void Pfe(int vfe) { fe = vfe; }
	int Ofe() { return fe; }
};
#endif
