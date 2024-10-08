// Vertice.h
// Implementar los datos y procesos necesarios para construir los vertices de un grafo

#ifndef _VERTICE_H
#define _VERTICE_H

typedef string Tipo;

class Vertice{			//definicion de atr y metodos de la clase
private:
	Tipo dato;			//atr que almacena el valor contenido en el vertice
	int num;			//atr que contiene el numero asignado al vertice
	
public:					//metodos visibles
	Vertice();			//constructor
	Vertice(Tipo v);		//constructor
	Vertice(Tipo v, int p);	//constructor
	void setDato(Tipo v);	//metodo que actualiza el estado del atr
	void setNum(int v);		//metodo que actualiza el estado del atr	
	Tipo getDato();			//metodo que devuelve el estado del atr
	int getNum();			//metodo que devuelve el estado del atr
	bool esIgualDato(Tipo v); //metodo determina si el atr dato contiene un valor igual al par
	bool esIgualNum(int v); //metodo determina si el atr num contiene un valor igual al par
};

Vertice::Vertice(){				//constructor
	setNum(-1);					//inicia asignando valor negativo al identificador del vertice
}

Vertice::Vertice(Tipo v){		//constructor
	setDato(v);					//inicia el dato con valor recibido
	setNum(-1);					//inicia asignando valor negativo al identificador del vertice
}

Vertice::Vertice(Tipo v, int p){//constructor
	setDato(v);					//inicia el dato con valor recibido
	setNum(p);					//inicia el dato con valor recibido
}

void Vertice::setDato(Tipo v){	//metodo que actualiza el estado del atr
	dato = v;					//actualiza atr
}

void Vertice::setNum(int v){	//metodo que actualiza el estado del atr	
	num = v;					//actualiza atr
}

Tipo Vertice::getDato(){		//metodo que devuelve el estado del atr
	return dato;				//devuelve estado del atr
}
int Vertice::getNum(){			//metodo que devuelve el estado del atr
	return num;					//devuelve estado del atr
}

bool Vertice::esIgualDato(Tipo v){ 	//metodo determina si el atr dato contiene un valor igual al par
	return (getDato() == v);		//devuelve true si se verifica la igualdad
}

bool Vertice::esIgualNum(int v){ 	//metodo determina si el atr num contiene un valor igual al par
	return (getNum() == v);			//devuelve true si se verifica la igualdad
}

#endif