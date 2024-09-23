// NodoG.h
// crear la definicion de los nodos de una lista simplemente enlazada para emplearse en grafos 
#ifndef _NODOG_H
#define _NODOG_H

#include <iostream>
typedef int Tipo;			//definicion del tipo de valor a almacenar en cada nodo

class NodoG{			//definicion de la clase a la que pertenecen los nodos de la lista
private:					//privados de la clase: atributos
	Tipo dato;				//atributo que almacena los valores de la lista
	int peso;				//atributo que almacena los pesos de cada arco del grafo
	NodoG* punt;		//atributo que permite enlazar este nodo con el siguiente
	
public:									//públicos: métodos
	NodoG();						//constructor
	NodoG(Tipo v);					//constructor con parametro dato
	NodoG(Tipo v, int q);			//constructor con parametro dato y el peso
	NodoG(Tipo v, NodoG* p);	//constructor con parametro dato y direccion a la cual apuntar
	NodoG(Tipo v, int q, NodoG* p);	//constructor con parametro dato, peso y direccion a la cual apuntar
	void setDato(Tipo v);				//actualiza el estado del atributo
	void setPeso(int v);				//actualiza el estado del atributo
	void setPunt(NodoG* v);  		//actualiza el estado del atributo
	Tipo getDato();						//devuelve el estado del atributo
	int getPeso();						//devuelve el estado del atributo
	NodoG* getPunt();				//devuelve el estado del atributo
};

NodoG::NodoG(){					//constructor sin parametros
	setPunt(NULL);
}

NodoG::NodoG(Tipo v){			//constructor con parametro dato
	setDato(v);
	setPunt(NULL);
}

NodoG::NodoG(Tipo v, int q){	//constructor con parametro dato y el peso
	setDato(v);
	setPeso(q);
	setPunt(NULL);
}

NodoG::NodoG(Tipo v, NodoG* p){	//constructor con parametro dato y direccion a la cual apuntar
	setDato(v);
	setPunt(p);
}

NodoG::NodoG(Tipo v, int q, NodoG* p){	//constructor con parametro dato, peso y direccion a la cual apuntar
	setDato(v);
	setPeso(v);
	setPunt(p);
}

void NodoG::setDato(Tipo v){	//metodo que actualiza el estado del atributo
	dato = v;
}

void NodoG::setPeso(int v){  //metodo que actualiza el estado del atributo
	peso = v;
}

void NodoG::setPunt(NodoG* v){  //metodo que actualiza el estado del atributo
	punt = v;
}

Tipo NodoG::getDato(){		//metodo que devuelve el estado del atributo
	return dato;
}

int NodoG::getPeso(){		//metodo que devuelve el estado del atributo
	return peso;
}

NodoG* NodoG::getPunt(){		//metodo que devuelve el estado del atributo
	return punt;
}
#endif
