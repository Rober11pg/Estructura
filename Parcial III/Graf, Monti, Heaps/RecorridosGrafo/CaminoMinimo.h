// CaminoMinimo.h
// archivo de cabecera con la definicion del algoritmo para encontrar el camino minimo entre vertices de grafo

#ifndef _CAMINOMINIMO_H
#define _CAMINOMINIMO_H

#include "GrafoMatriz.h"

class CaminoMinimo {
	protected:
		int* ultimo;			// vector de vertices predecesores
		int* D; 				// vector de distancias mínimas

	private:
		int s, n; 				// vértice origen y número de vértices

		int minimo( bool F[]); 	// metodo privado usado por dijkstra

	public:
		CaminoMinimo (GrafoMatriz g, int origen); 	// constructor
		void Dijkstra(GrafoMatriz g, int origen); 	// calcular lo caminos mínimos del vértice origen al resto de los vértices
		void recuperaCamino(int v);		  			//retomar anteriores vertices del camino minimo
		int * OdistanciaMinima();		  			//devuelve el vector de distancias minimas
		int * Oultimo();			  				//devuelve el vector de vertices predecesores
};

int CaminoMinimo::minimo(bool F[]){					//metodo privado para encontrar el índice del vértice del grafo cuya distancia al origen sea mínima (elegido entre los no marcados).
	double mx = 0xFFFF; 							// valor de infinito
	int v;
	for (int j = 0; j < n; j++){
		if (!F[j] && (mx >= D[j])){					//no marcado e inferior a mx
			mx = D[j];								//actualiza mx
			v = j;									//actualiza v
		}
	}
	return v;										//devuelve valor minimo
}

CaminoMinimo::CaminoMinimo (GrafoMatriz g, int origen) {	//constructor asignar memoria a los atributos ultimo y D e inicializa los atributos privados
	n = g.getNumVerts();
	s = origen;
	ultimo = new int[n];							//dimensiona vector de vertices
	D = new int[n];									//dimensiona vector de distancias
}

void CaminoMinimo::Dijkstra(GrafoMatriz g, int origen) {
	bool * F;										//vector booleano que almacena los vértices marcados
	F = new bool [n];								//crea sus elementos
	// valores iniciales
	for (int i = 0; i < n; i++) {
		F[i] = false;								//falso si no se conoce su distancia desde vertice origen => inicial
		D[i] = g.getArco(s, i);						//distancia
		ultimo[i] = s;
	}
	F[s] = true; D[s] = 0; 							//Marca origen e inicializa distancia
	// Pasos para marcar los n-1 vértices. Algoritmo voraz
	for (int i = 1; i < n; i++) {					//recorre todos los vertices
		int v = minimo(F);
		//selecciona vértice no marcado de menor distancia
		F[v] = true;
		// actualiza distancia de vértices no marcados
		for (int w = 0; w < n; w++){
			if (!F[w]){
				if (D[v] + g.getArco(v, w) < D[w]) {
					D[w] = D[v] + g.getArco(v, w);
					ultimo[w] = v;
				}
			}
		}
	}
}

void CaminoMinimo::recuperaCamino(int v) { 			//metodo para regresar a sucesivos (anteriores) vértices que conforman el camino mínimo
	int anterior = ultimo[v];

	if (v != s) {
		recuperaCamino(anterior); 					// vuelve al anterior vertice
		cout << v << " V <--" ;
	} else {
		cout << s;
	}
}

int * CaminoMinimo::OdistanciaMinima(){				//devuelve el vector de distancias minimas
	return D;
}

int * CaminoMinimo::Oultimo(){						//devuelve el vector de vertices predecesores
	return ultimo;
}
#endif
