/* Nodo.h
Definicion de la clase que origina cada elemento de una lista simple
*/

#ifndef _NODO_H
#define _NODO_H
#include<iostream>
using namespace std;

typedef int Tipo;

class Nodo{
	private:
		Tipo dato;																//atributo para contener el valor a almacenar
		Nodo* punt;																//atributo para apuntar al siguiente nodo
	public:
		Nodo();
		Nodo(Tipo v); 
		Nodo(Tipo v, Nodo *p);
		void setDato(Tipo v);													//metodo para actualizar el estado del atributo
		void setPunt(Nodo* v);																											
	
		Tipo getDato();															//metodo para devolver el estado del atributo
		Nodo* getPunt();	
	
};

		Nodo::Nodo(){
			setPunt(NULL);
		}
		
		Nodo::Nodo(Tipo v)
		{
		    setDato(v);  
		    setPunt(NULL);
		}
		
		Nodo::Nodo(Tipo v, Nodo* p)
		{
		    setDato(v);
		    setPunt(p);
		}
		
		void Nodo::setDato(Tipo v){
			dato = v;
		}	
														
		void Nodo::setPunt(Nodo* v){
			punt = v;
		}																											
	
		Tipo Nodo::getDato(){
			return dato;
		}	
															
		Nodo* Nodo::getPunt(){
			return punt;
		}

#endif