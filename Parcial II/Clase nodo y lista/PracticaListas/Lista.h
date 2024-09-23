// Lista.h
// Implementa el TDA Lista Simplemente Enlazada

#ifndef _LISTA_H
#define _LISTA_H

#include "Nodo.h" //incluye la definicion de cada nodo

class Lista
{ // definicion de la clase Lista
private:
	Nodo *primero; // atributo que almacena la direccion de memoria del primer nodo de la lista

public:							   // definicion de metodos publicos
	Lista();					   // metodo constructor
	void setPrimero(Nodo *v);	   // metodo que actualiza el estado del atr
	Nodo *getPrimero();			   // devuelve el estado del atr
	bool esVacia();				   // metodo que determina si la lista esta vacia
	void vaciar();				   // metodo que elimina todos los nodos de la lista
	void insertarAlInicio(Tipo v); // metodo que permite insertar nuevos nodos al inicio de la lista
	void insertarAlFinal(Tipo v);  // metodo que permite insertar nuevos nodos al final de la lista
	void insertarEnOrden(Tipo v);  // metodo que permite insertar nuevos nodos ordenadamente en la lista
	Nodo *buscarElemento(Tipo v);  // metodo que permite devolver la direccion del nodo que contiene el valor v
	bool eliminarNodo(Tipo v);	   // metodo que permite eliminar el nodo que contiene el valor v
	Nodo *ultimo();				   // metodo que devuelve la direccion del ultimo nodo de la lista
};

Lista::Lista()
{					  // metodo constructor
	setPrimero(NULL); // inicializa comienzo de la lista
}

void Lista::setPrimero(Nodo *v)
{				 // metodo que actualiza el estado del atr
	primero = v; // guarda parametro en atributo
}

Nodo *Lista::getPrimero()
{					// devuelve el estado del atributo
	return primero; // retorna estado del atributo
}

bool Lista::esVacia()
{ // metodo que determina si la lista esta vacia
	return (getPrimero() == NULL);
}

void Lista::vaciar()
{					  // metodo que elimina todos los nodos de la lista
	setPrimero(NULL); // actualiza primero a null
}

void Lista::insertarAlInicio(Tipo v)
{				 // metodo que permite insertar nuevos nodos al inicio de la lista
	Nodo *nuevo; // direccion de memoria del nuevo nodo a crear

	nuevo = new Nodo(v, getPrimero()); // crea un nuevo nodo y devuelve su direccion de memoria
	setPrimero(nuevo);				   // actualiza el apuntador primero
}

void Lista::insertarAlFinal(Tipo v)
{				 // metodo que permite insertar nuevos nodos al final de la lista
	Nodo *nuevo; // apuntador al nuevo nodo a crear
	Nodo *ult;	 // apuntador al ultimo nodo

	nuevo = new Nodo(v); // crea nuevo nodo conociendo valor que va a contener el nodo

	if (esVacia())
	{					   // es una lista vacia
		setPrimero(nuevo); // la lista empieza con el nuevo nodo
	}
	else
	{						 // la lista no esta vacia
		ult = ultimo();		 // almacena dir ultimo nodo
		ult->setPunt(nuevo); // actualiza direccion apuntada por el anterior ultimo nodo
	}
}

void Lista::insertarEnOrden(Tipo v)
{			   // metodo que permite insertar nuevos nodos ordenadamente en la lista
	Nodo *act; // apuntador para recorrer la lista
	Nodo *ant; // apuntador al nodo anterior al nuevo
	Nodo *nuevo;

	nuevo = new Nodo(v); // creacion del nuevo nodo

	if (esVacia())
	{					   // si la lista no contiene nodos aun
		setPrimero(nuevo); // se aÃ±ade el nuevo nodo a la lista
	}
	else
	{							  // la lista contiene nodos anteriores
		ant = act = getPrimero(); // iniciamos con la direccion apuntada por inicio de lista
		while ((act != NULL) && (act->getDato() < v))
		{ // recorrido mientras el nodo apuntado no apunta a null
			ant = act;
			act = act->getPunt(); // actualizar apuntador de recorrido
		}

		if (ant == act)
		{
			nuevo->setPunt(getPrimero()); // nuevo nodo apunta al anterior primer nodo
			setPrimero(nuevo);			  // el nuevo nodo es el primero de la lista
		}
		else
		{ // el nuevo nodo se debe insertar entre dos nodos ya existentes
			ant->setPunt(nuevo);
			nuevo->setPunt(act);
		}
	}
}

Nodo *Lista::buscarElemento(Tipo v)
{			   // metodo que permite devolver la direccion del nodo que contiene el valor v
	Nodo *act; // apuntador temporal al nodo actual

	act = getPrimero(); // iniciamos con la direccion apuntada por inicio de lista
	if (!esVacia())
	{ // si la lista contiene nodos
		while ((act != NULL) && (act->getDato() != v))
		{						  // recorrido mientras el nodo apuntado no apunta a null
			act = act->getPunt(); // actualizar apuntador de recorrido
		}
	}
	return act; // devuelve direccion del nodo apuntado
}

bool Lista::eliminarNodo(Tipo v)
{								   // metodo que permite eliminar el nodo que contiene el valor v
	Nodo *act;					   // apuntador al nodo actual
	Nodo *enc = buscarElemento(v); // var que ubica el elemento dentro de la lista

	if (enc == NULL)
	{ // el valor no existe en la lista
		return false;
	}

	if (enc == getPrimero())
	{								// el valor se encuentra en el primer nodo de la lista
		setPrimero(enc->getPunt()); // primero apunta al segundo nodo
	}
	else
	{						// el valor no se encuentra en el primer nodo
		act = getPrimero(); // iniciamos con la direccion apuntada por inicio de lista
		while (act->getPunt() != enc)
		{						  // recorrido mientras el nodo apuntado no apunta a null
			act = act->getPunt(); // actualizar apuntador de recorrido
		}
		act->setPunt(enc->getPunt()); // actualiza apuntador del nodo anterior con la direcion de nodo siguiente
	}
	return true; // devolver bandera de cumplimiento de eliminacion
}

Nodo *Lista::ultimo()
{			   // metodo que devuelve la direccion del ultimo nodo de la lista
	Nodo *act; // apuntador temporal al nodo actual

	act = getPrimero(); // iniciamos con la direccion apuntada por inicio de lista
	if (!esVacia())
	{ // si la lista contiene nodos
		while (act->getPunt() != NULL)
		{						  // recorrido mientras el nodo apuntado no apunta a null
			act = act->getPunt(); // actualizar apuntador de recorrido
		}
	}
	return act; // devuelve direccion del nodo apuntado
}
#endif
