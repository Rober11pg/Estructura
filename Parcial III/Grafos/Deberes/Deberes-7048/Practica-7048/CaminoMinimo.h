// CaminoMinimo.h
// archivo de cabecera con la definicion del algoritmo para encontrar el camino minimo entre vertices de grafo

#ifndef _CAMINOMINIMO_H
#define _CAMINOMINIMO_H

// #include "GrafoMatriz.h"
#include "Grafo.h"

class CaminoMinimo
{
protected:
	int *ultimo; // vector de vertices predecesores
	int *D;		 // vector de distancias m�nimas

private:
	int s, n; // v�rtice origen y n�mero de v�rtices

	int minimo(bool F[]); // metodo privado usado por dijkstra

public:
	CaminoMinimo(GrafoMatriz g, int origen); // constructor
	void Recorrer(GrafoMatriz g);			 // secuencia de vertices adyacentes hasta no encontrar y regresar, hasta recorrer todos los vertices sin visitar
	void Dijkstra(GrafoMatriz g);			 // calcular lo caminos m�nimos del v�rtice origen al resto de los v�rtices
	void recuperaCamino(int v);				 // retomar anteriores vertices del camino minimo
	int *OdistanciaMinima();				 // devuelve el vector de distancias minimas
	int *Oultimo();							 // devuelve el vector de vertices predecesores
};

int CaminoMinimo::minimo(bool F[])
{						// metodo privado para encontrar el �ndice del v�rtice del grafo cuya distancia al origen sea m�nima (elegido entre los no marcados).
	double mx = 0xFFFF; // valor de infinito
	int v;
	for (int j = 0; j < n; j++)
	{
		if (!F[j] && (mx >= D[j]))
		{			   // no marcado e inferior a mx
			mx = D[j]; // actualiza mx
			v = j;	   // actualiza v
		}
	}
	return v; // devuelve valor minimo
}

CaminoMinimo::CaminoMinimo(GrafoMatriz g, int origen)
{ // constructor asignar memoria a los atributos ultimo y D e inicializa los atributos privados
	n = g.getNumVerts();
	s = origen;
	ultimo = new int[n]; // dimensiona vector de vertices
	D = new int[n];		 // dimensiona vector de distancias
}

void CaminoMinimo::Dijkstra(GrafoMatriz g)
{
	bool *F;		 // vector booleano que almacena los v�rtices marcados
	F = new bool[n]; // crea sus elementos
	// valores iniciales
	for (int i = 0; i < n; i++)
	{
		F[i] = false;			// falso si no se conoce su distancia desde vertice origen => inicial
		D[i] = g.getArco(s, i); // distancia
		ultimo[i] = s;
	}
	F[s] = true;
	D[s] = 0; // Marca origen e inicializa distancia
	// Pasos para marcar los n-1 v�rtices. Algoritmo voraz
	for (int i = 1; i < n; i++)
	{ // recorre todos los vertices
		int v = minimo(F);
		// selecciona v�rtice no marcado de menor distancia
		F[v] = true;
		// actualiza distancia de v�rtices no marcados
		for (int w = 0; w < n; w++)
		{
			if (!F[w])
			{
				if (D[v] + g.getArco(v, w) < D[w])
				{
					D[w] = D[v] + g.getArco(v, w);
					ultimo[w] = v;
				}
			}
		}
	}
}

void CaminoMinimo::Recorrer(GrafoMatriz g)
{
	int h =0;
	bool *F;		 // vector booleano que almacena los v�rtices marcados
	F = new bool[n]; // crea sus elementos
	// valores iniciales
	for (int i = 0; i < n; i++)
	{
		F[i] = false; // falso si no se conoce su distancia desde vertice origen => inicial
		ultimo[i] = s;
	}
	F[s] = true; // Marca origen
	// Pasos para marcar los n-1 v�rtices. Algoritmo voraz
	Vertice x = g.getVertice(s);
	cout << x.getNombre() << "->";
	int v = s;
	for (int j = 1; j < n; j++)
	{
		if (!F[j])
		{
			if (g.adyacente(v, j))
			{
				F[j] = true;
				Vertice x = g.getVertice(j);
				cout << x.getNombre() << "->";
				h = x.getNumero();
			}
			else
			{
				for (int w = 0; w < n; w++)
				{
					if (!F[w])
					{
						if (g.adyacente(h, w))
						{
							F[w] = true;
							Vertice x = g.getVertice(w);
							cout << x.getNombre() << "->";
							h = x.getNumero();
						}
					}
				}
			}
		}
	}
}

void CaminoMinimo::recuperaCamino(int v)
{ // metodo para regresar a sucesivos (anteriores) v�rtices que conforman el camino m�nimo
	int anterior = ultimo[v];

	if (v != s)
	{
		recuperaCamino(anterior); // vuelve al anterior vertice
		cout << v << " V <--";
	}
	else
	{
		cout << s;
	}
}

int *CaminoMinimo::OdistanciaMinima()
{ // devuelve el vector de distancias minimas
	return D;
}

int *CaminoMinimo::Oultimo()
{ // devuelve el vector de vertices predecesores
	return ultimo;
}
#endif
