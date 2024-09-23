// recorreGrafo.h
// implementa recorridos en grafos

#ifndef _RECORREGRAFO_H
#define _RECORREGRAFO_H

#include "cola.h"
#include "pila.h"
#include "Grafo.h"
//#include "GrafoMatriz.h"
//#include "GrafoLista.h"

class RecorreGrafo {					//definicion de la clase

public:
	int CLAVE; // Clave para v�rtice no marcado

	RecorreGrafo();						//constructor
	//operaciones con los recorridos con Matriz de adyacencia
	int* recorrerAnchuraMa(GrafoMatriz g, string org);
	int* recorrerProfMa(GrafoMatriz g, string org);
	int* recorrerAnchuraMa(GrafoMatriz g, int v);
	int* recorrerProfMa(GrafoMatriz g, int v);
	//operaciones con los recorridos con Lista de adyacencia
	int* recorrerAnchuraLa(GrafoLista g, string org);
	int* recorrerProfLa(GrafoLista g, string org);
	int* recorrerAnchuraLa(GrafoLista g, int v);
	int* recorrerProfLa(GrafoLista g, int v);
};

RecorreGrafo::RecorreGrafo(){								//constructor
		CLAVE = 0xffff;	 									//Clave v�rtice no marcado
	}

int* RecorreGrafo::recorrerAnchuraMa(GrafoMatriz g, int v){	//recorre grafo en anchura recibiendo numero de vertice inicial
	int w;
	Cola cola;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m;			//V�rtice no existe
	}
	m = new int[g.getNumVerts()];
								// inicializa los v�rtices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {	//inicializa las claves de cada vertice
		m[i] = CLAVE;
	}
	m[v] = 0; // v�rtice origen queda marcado
	cola.insertarVal(v);
	while (!cola.colaVacia()) {				//mientras haya elementos en la cola
		int cw;
		cw = cola.extraerVal();					//extrae un vertice de la cola
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getNombre() << " => visitado" << endl;
		// inserta en la cola los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++){
			if (g.getArco(w,u) && m[u] == CLAVE) { 	// se marca v�rtice u con n�mero de arcos hasta el
				m[u] = m[w] +1;	
				cola.insertarVal(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerAnchuraMa(GrafoMatriz g, string org) {	//recorre grafo en anchura recibiendo nombre de vertice inicial
	
	int v = g.getNumVertice(org);
	if (v >= 0){
		recorrerAnchuraMa(g,v);
	} 
}	

int * RecorreGrafo::recorrerProfMa(GrafoMatriz g, int v) {  		//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m; 													//Vertice de origen no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los v�rtices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = CLAVE;
	}
	m[v] = 0; // v�rtice origen queda marcado
	pila.push(v);
	while (!pila.pilaVacia()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getNombre() << " => visitado" << endl;
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) != 0xffff  && m[u] == CLAVE) { // se marca v�rtice u con n�mero de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerProfMa(GrafoMatriz g, string org) {		//recorre grafo en profundidad recibiendo nombre de vertice inicial
	int v = g.getNumVertice(org);
	if (v >= 0){
		recorrerProfMa(g,v);
	}
}

int* RecorreGrafo::recorrerAnchuraLa(GrafoLista g, int v){		//recorre grafo en anchura recibiendo numero de vertice inicial
	int w;
	Cola cola;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m; 												//V�rtice no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los v�rtices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {					//inicializa las claves de cada vertice
		m[i] = CLAVE;
	}
	m[v] = 0; 													// v�rtice origen queda marcado
	cola.insertarVal(v);
	while (!cola.colaVacia()) {									//mientras haya elementos en la cola
		int cw;
		cw = cola.extraerVal();										//extrae un vertice de la cola
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getNombre() << " => visitado" << endl;
		// inserta en la cola los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++){
			if (g.getArco(w,u) && m[u] == CLAVE) { 				// se marca v�rtice u con n�mero de arcos hasta el
				m[u] = m[w] +1;
				cola.insertarVal(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerAnchuraLa(GrafoLista g, string org) {	//recorre grafo en anchura recibiendo nombre de vertice inicial
	
	int v = g.getNumVertice(org);
	if (v < 0){
		return NULL; 												//Vertice de origen no existe
	} 
	recorrerAnchuraLa(g,v);
}	

int* RecorreGrafo::recorrerProfLa(GrafoLista g, int v) {  			//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return NULL; 												//Vertice de origen no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los v�rtices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = CLAVE;
	}
	m[v] = 0; 														// v�rtice origen queda marcado
	pila.push(v);
	while (!pila.pilaVacia()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getNombre() << " => visitado" << endl;
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) && m[u] == CLAVE) { 					// se marca v�rtice u con n�mero de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerProfLa(GrafoLista g, string org) {
	int v = g.getNumVertice(org);
	if (v < 0){
		return NULL; 												//Vertice de origen no existe
	}
	recorrerProfLa(g,v);
}
#endif
