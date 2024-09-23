
// Lista1.cpp
// Implementar una lista simplemente enlazada
// Autor: Julio Santillán C.

using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN	99999		//marcador de final de lectura

int main(){			//programa principal
	system("color f0");
	Lista l;		//crea el objeto de tipo lista
	
	void ingresarLista(Lista* l1);		//funcion que permite el ingreso de valores a la lista
	void imprimirLista(Lista l1);		//funcion que permite el ingreso de valores a la lista
	void buscarEnLista(Lista l1);		//funcion que permite buscar un valor dentro de la lista
	void eliminarDeLista(Lista l1);		//funcion que permite eliminar un nodo de la lista

	cout << endl << "El apuntador primero apunta a: " << l.getPrimero();
	cout << endl << "La lista " << (l.esVacia() ? "SI" : "NO"  )<< " esta vacia";
	
	ingresarLista(&l);		//llamado a la funcion que ingresa lista
	imprimirLista(l);
	
	buscarEnLista(l);		//llamado a funcion de busqueda de un valor	
	
	eliminarDeLista(l);		//llamado a funcion de eliminacion
	
	cout << endl;
	system("pause");
}

void ingresarLista(Lista* l1){		//funcion que permite el ingreso de valores a la lista
	Tipo aux;						//var de lectura
	
	cout << endl << "Ingrese un valor a añadir en la lista. Finalice con [" << FIN << "]: ";	
	cin >> aux;
		
	if (aux != FIN){
//		l1->insertarAlInicio(aux);		//se añade elemento a la lista
//		l1->insertarAlFinal(aux);		//se añade elemento a la lista
		l1->insertarEnOrden(aux);		//se añade elemento a la lista
		ingresarLista(l1);
	}
}

void imprimirLista(Lista l1){		//funcion que permite el ingreso de valores a la lista
	Nodo* act;
	
	act = l1.getPrimero();
	while(act != NULL){
		cout << "> " << act->getDato() << endl;
		act = act->getPunt();
	}

}

void buscarEnLista(Lista l1){		//funcion que permite buscar un valor dentro de la lista
	Tipo vB;						//var del valor a buscar
	Nodo* enc;						//apuntador al nodo encontrado
	
	cout << endl << "Ingrese el valor a buscar: ";
	cin >> vB;
	
	enc = l1.buscarElemento(vB);
	
	cout << endl << "El valor " << vB << (enc == NULL ? " NO" : " SI") << " se encuentra en la lista" << endl;
}

void eliminarDeLista(Lista l1){		//funcion que permite eliminar un nodo de la lista
	Tipo vE;						//var del valor a buscar

	cout << endl << "Ingrese el valor a eliminar: ";
	cin >> vE;
	
	if (l1.eliminarNodo(vE)){		//llamar a metodo de eliminacion => True
		cout << endl << "Elemento eliminado satisfactoriamente.... Nueva lista generada: " << endl;
		imprimirLista(l1);		
	} else {						//fracaso en ejecucion de eliminacion
		cout << endl << "Error al eliminar el valor " << vE  ;
	}
}

