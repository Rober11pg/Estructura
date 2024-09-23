/* NodoBinario.h
Definicion de la clase que origina a nodos de un arbol binario */

#ifndef _NODO_BINARIO_H
#define _NODO_BINARIO_H
#include<iostream>
using namespace std;

typedef int Tipo;

class NodoBinario{
	private:
		Tipo dato;
		NodoBinario* izq;
		NodoBinario* der;
	public:	
		NodoBinario();
		NodoBinario(Tipo v);
		NodoBinario(Tipo v, NodoBinario* i, NodoBinario* d);
		void setDato(Tipo v);
		void setIzq(NodoBinario* v);
		void setDer(NodoBinario* v);
		Tipo getDato();
		NodoBinario* getIzq();
		NodoBinario* getDer();
};

	NodoBinario::NodoBinario(){
		setIzq(NULL);
		setDer(NULL);				
	}
	
	NodoBinario::NodoBinario(Tipo v){
		setDato(v);
		setIzq(NULL);
		setDer(NULL);				
	}
	
	NodoBinario::NodoBinario(Tipo v, NodoBinario* i, NodoBinario* d){
		setDato(v);
		setIzq(i);
		setDer(d);			
	}
		
	void NodoBinario::setDato(Tipo v){
		dato = v;
	}
		
	void NodoBinario::setIzq(NodoBinario* v){
		izq = v;	
	}
		
	void NodoBinario::setDer(NodoBinario* v){
		der = v;	
	}
		
	Tipo NodoBinario::getDato(){
		return dato;	
	}
		
	NodoBinario* NodoBinario::getIzq(){
		return izq;	
	}
		
	NodoBinario* NodoBinario::getDer(){
		return der;	
	}

#endif