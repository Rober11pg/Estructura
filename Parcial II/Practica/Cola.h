/*
Cola.h
Definicion del TDA cola
*/
#ifndef _COLA_H
#define _COLA_H

typedef int Tipo;													//definir tipo de datos del TDA
#define EXT 20														//cantidad maxima de elementos del TDA

class Cola{															//definicion del TDA
	private:
		Tipo vec[EXT];												//declaracion del atributo contenedor de datos
		int frente;													//declarar el atributo que contiene posicion del elemento a extraer
		int final;													//declaracion del atributo que contiene la posicion del elemento a incertar
		
	protected:
		void setVec(Tipo v, int pos);								//metodo que actualiza el estado de un elemento del TDA
		void setFrente(int v);										//metodo que actualiza el estado del atributo Frente
		void setFinal(int v);										//metodo que actualiza el estado del atributo Final
		
		Tipo getVec(int pos);										//metodo que devuelve el estado del atributo
		int getFrente();											//metodo que devuelve el estado del atributo
		int getFinal();												//metodo que devuelve el estado del atributo
		
	public:
		
		Cola();														//metodo constructor		
		void borrarCola();											//metodo que reinicializa el TDA
		bool colaVacia();											//metodo que determina si el TDA carece de elementos
		bool colaLlena();											//metodo que determina si el TDA no posee espacio disponible para nuevos elementos
		int tamanioCola();											//metodo que determina la cantidad de elementos contenidos en el TDA
		Tipo quitar();												//metodo que permite extraer un elemento del TDA
		void insertar(Tipo v);										//metodo que permite insertar un elemento nuevo en el TDA
		Tipo frenteCola();											//metodo que devuleve el valor contenido en la posicion frente
};

Cola::Cola(){
	setFinal(-1);													//indicador de carencia de elementos
	setFrente(0);													//indicador de posicion del primer elemento a extraer del TDA
}

void Cola::setVec(Tipo v, int pos){
	vec[pos] = v;
}

void Cola::setFrente(int v){
	frente = v;
}

void Cola::setFinal(int v){
	final = v;
}

Tipo Cola::getVec(int pos){
	return vec[pos];
}

int Cola::getFrente(){
	return frente;
}

int Cola::getFinal(){
	return final;
}	

void Cola::borrarCola(){
	setFinal(-1);
	setFrente(0);
}

bool Cola::colaVacia(){
	return (getFinal() < getFrente());
}

bool Cola::colaLlena(){
	return (getFinal() == EXT-1);
}

int Cola::tamanioCola(){
	return (getFinal() - getFrente()+1); 
}

Tipo Cola::quitar(){
	Tipo aux;
	
	if(!colaVacia()){
		aux = getVec(getFrente());
		setFrente(getFrente()+1);
	}
	
	return aux;
}

void Cola::insertar(Tipo v){
	if(!colaLlena()){
		setFinal(getFinal()+1);
		setVec(v, getFinal());
	}	
}

Tipo Cola::frenteCola(){
	Tipo aux;
	if(!colaVacia()){
		aux = getVec(getFrente());
	}
	
	return aux;
}

#endif