// Grafo.h

#ifndef _GRAFO_H
#define _GRAFO_H

typedef int *pint; // para el dimensionamiento de la matriz

#include "Vertice.h"
#include "ListaG.h"
#include "cola.h"
#include <algorithm>
#include <iomanip>

class Grafo
{					// definicion de la clase
protected:			// declaracion de atributos
	int maxVerts;	// m�ximo numero de v�rtices
	int numVerts;	// n�mero de v�rtices que contiene el grafo
	Vertice *verts; // vector de v�rtices

public:			  // m�todos p�blicos de la clase GrafoMatriz
	Grafo();	  // constructor por defecto
	Grafo(int v); // constructor conociendo cantidad m�xima de v�rtices

	void setMaxVerts(int n);				 // actualiza numero maximo de vertices
	void setNumVerts(int n);				 // actualiza numero de vertices existentes en grafo
	void setVertice(int va, Vertice v);		 // modifica los atributos de un vertice, conociendo su nombre
	void setVertice(string a, Vertice v);	 // modifica los atributos de un vertice, conociendo su nombre
	void setArco(int va, int vb);			 // actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);	 // actualiza valor de arco recibiendo numeros de vertices
	void setArco(string a, string b);		 // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(string a, string b, int v); // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	int getMaxVerts();						 // devuelve numero maximo de vertices
	int getNumVerts();						 // devuelve cantidad de vertices existentes en grafo
	Vertice getVertice(int va);				 // devuelve atributos de un vertice, conociendo su numero
	Vertice getVertice(string a);			 // devuelve atributos de un vertice, conociendo su nombre
	int gradosEntrada(int i);				 // Calcula grados de entrada de un vertice
	int gradoSalida(int i);					 // Calcula grados de salida de un vertice
	void ordenTopologico();					 // Ordenamiento topologico
	void matrizDeCaminos();					 // Matriz de caminos, algoritmo warshall
	void caminoMasCorto(string a, string b); // Muestra el camino más corto entre dos vertices alcanzables, algoritmo dijkstra
	bool getArco(int va, int vb);			 // devuelve el valor de un arco recibiendo numeros de vertices
	bool getArco(string a, string b);		 // devuelve el valor de un arco recibiendo nombres de vertices

	int getNumVertice(string v); // devuelve el numero de vertice conociendo su nombre
	void nuevoVertice(string v); // crea un nuevo vertice recibiendo su nombre

	bool adyacente(int va, int vb);		// determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(string a, string b); // determina si dos vertices son adyacentes recibiendo sus nombres
};

Grafo::Grafo()
{								// constructor por defecto (sin par�metros)
	setMaxVerts(1);				// cantidad maxima de vertices por defecto
	setNumVerts(getMaxVerts()); // cantidad de vertices del grafo tomado de max.Num.Vertices
}

Grafo::Grafo(int v)
{
	setMaxVerts(v);			// cantidad maxima de vertices por defecto
	setNumVerts(0);			// cantidad de vertices del grafo tomado de max.Num.Vertices
	verts = new Vertice[v]; // inicializa vector de v�rtices con v elementos
}

void Grafo::setMaxVerts(int n)
{ // actualiza cantidad maxima de vertices
	maxVerts = n;
}

void Grafo::setNumVerts(int n)
{ // actualiza numero de vertices
	numVerts = n;
}

void Grafo::setVertice(int va, Vertice v)
{ // modifica los atributos de un vertice, conociendo su numero
	if ((va >= 0) && (va < getNumVerts()))
	{				   // numero de vertice si existe en el grafo
		verts[va] = v; // actualiza atributos
	}
}

void Grafo::setVertice(string a, Vertice v)
{						   // modifica los atributos de un vertice, conociendo su numero
	int va;				   // variable para contener numero de vertice
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	if ((va >= 0) && (va < getNumVerts()))
	{				   // numero de vertice si existe en el grafo
		verts[va] = v; // actualiza atributos
	}
}

int Grafo::getMaxVerts()
{ // devuelve cantidad maxima de vertices
	return maxVerts;
}

int Grafo::getNumVerts()
{ // devuelve cantidad de vertices
	return numVerts;
}

Vertice Grafo::getVertice(int va)
{ // retorna todos los atributos del v�rtice, si existe en el grafo, conociendo su numero
	if ((va < 0) || (va >= getNumVerts()))
	{ // numero de vertice incorrecto
		Vertice x;
		return x; // como V�rtice no existe, devuelve vertice vac�o
	}
	else
	{					  // numero de vertice existente en el grafo
		return verts[va]; // devuelve atributos del vertice
	}
}

Vertice Grafo::getVertice(string a)
{						   // retorna todos los atributos del v�rtice si est� almacenado en el grafo, conociendo su nombre
	int va;				   // variable para contener numero de vertice
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	if ((va < 0) || (va >= numVerts))
	{ // numero de vertice incorrecto
		Vertice x;
		return x; // como V�rtice no existe, devuelve vertice vac�o
	}
	else
	{					  // numero de vertice existente en el grafo
		return verts[va]; // devuelve atributos del vertice
	}
}

int Grafo::getNumVertice(string v)
{					  // determina el numero de un vertice dentro del grafo, conociendo su nombre
	int i;			  // var para recorrer vertices del grafo
	bool enc = false; // var bandera para indicar si se encuentra

	for (i = 0; (i < getNumVerts()) && !enc;)
	{							 // ciclo de recorrido de vertices del grafo
		enc = verts[i].igual(v); // comprueba si vertice tiene nombre igual a parametro (metodo definido en Vertice.h)
		if (!enc)
		{		 // aun no se encuentra vertice con ese valor
			i++; // continua la b�squeda
		}
	}
	return ((i < getNumVerts()) ? i : -1); // retorna i (si se encontro) o -1 si no encuentra vertice con ese nombre
}

void Grafo::nuevoVertice(string v)
{										   // crea un nuevo vertice recibiendo su nombre
	bool existe = (getNumVertice(v) >= 0); // determina si ese vertice ya existe

	if (!existe)
	{ // si no existe, es nuevo, por lo que lo crea
		if (getNumVerts() < getMaxVerts())
		{									   // si numero de vertices existentes es menor que cantidad maxima de vertices del grafo
			Vertice nv = Vertice(v, numVerts); // construye un nuevo vertice con el nombre recibido
			verts[numVerts] = nv;			   // incorpora el nuevo vertice en vector de v�rtices
			setNumVerts(getNumVerts() + 1);	   // incrementa cantidad de vertices existentes en el grafo
		}
	}
}

class GrafoMatriz : public Grafo // definicion de herencia de clase Grafo
{
private:
	int **matAd; // matriz de adyacencia
public:
	GrafoMatriz();							 // constructor sin par�metros
	GrafoMatriz(int v);						 // constructor conociendo cantidad m�xima de v�rtices
	void setArco(int va, int vb);			 // actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);	 // actualiza valor de arco recibiendo numeros de vertices
	void setArco(string a, string b);		 // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(string a, string b, int v); // actualiza valor de arco recibiendo nombres de vertices
	int getArco(int va, int vb);			 // devuelve el valor de un arco recibiendo numeros de vertices
	int getArco(string a, string b);		 // devuelve el valor de un arco recibiendo nombres de vertices
	bool adyacente(int va, int vb);			 // determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(string a, string b);		 // determina si dos vertices son adyacentes recibiendo sus nombres
	int gradosEntrada(int i);				 // Calcula grados de entrada de un vertice
	int gradoSalida(int i);					 // Calcula grados de salida de un vertice
	void ordenTopologico();					 // Ordenamiento topologico
	void matrizDeCaminos();					 // Matriz de caminos, algoritmo warshall
	void caminoMasCorto(string a, string b); // Muestra el camino más corto entre dos vertices alcanzables, algoritmo dijkstra
};

GrafoMatriz::GrafoMatriz() : Grafo() {}

GrafoMatriz::GrafoMatriz(int v) : Grafo(v)
{							// constructor conociendo cantidad maxima de v�rtices
	setMaxVerts(v);			// actualiza cantidad maxima de vertices con el par�metro
	setNumVerts(0);			// actualiza numero de vertices del grafo con 0 (no existen vertices aun)
	verts = new Vertice[v]; // inicializa vector de v�rtices con v elementos
	matAd = new pint[v];	// inicializa //recorre filas de matriz de adyacenciamatriz de adyacencia con v filas
	for (int i = 0; i < v; i++)
	{
		matAd[i] = new int[v]; // crea v elementos asociados a este elemento de la matriz de adyacenciar inicializa cada elemento vector (fila) de matriz de adyacencia con "v" posibles arcos
		for (int j = 0; j < v; j++)
		{						  // recorre todos los "arcos" de cada elemento de la matriz de adyacencia
			matAd[i][j] = 0xFFFF; // inicializa cada "arco" con un valor por defecto (255 => 0xFFFF en haxadecimal)
		}
	}
}

void GrafoMatriz::setArco(int va, int vb)
{ // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = 1; // actualiza valor del arco en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(int va, int vb, int v)
{ // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = v; // actualiza valor del arco en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(string a, string b)
{						   // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = 1; // actualiza valor en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(string a, string b, int v)
{						   // modifica el valor almacenado en matriz de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = v; // actualiza valor en la matriz de adyacencia
	}
}

int GrafoMatriz::getArco(int va, int vb)
{ // retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de v�rtices que recibe como par�metro por numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{						  // comprueba existencia de los dos vertices
		return matAd[va][vb]; // devuelve el valor del arco almacenado en la matriz de adyacencia para estos vertices
	}
	else
	{			   // alguno de los vertices no existe
		return -1; // devuelve valor de error por defecto
	}
}

int GrafoMatriz::getArco(string a, string b)
{						   // retorna el valor del arco almacenado en la matriz de adyacencia para dos v�rtices que recibe como par�metro por nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice correspondiente al primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice correspondiente al segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{						  // comprueba existencia de los dos vertices
		return matAd[va][vb]; // devuelve el valor del arco almacenado en la matriz de adyacencia para estos vertices
	}
	else
	{			   // alguno de los dos vertices no existe
		return -1; // devuelve valor de error por defecto
	}
}

int GrafoMatriz::gradosEntrada(int i)
{
	int cont = 0;
	for (int j = 0; (j < getNumVerts()); j++)
	{
		if (adyacente(j, i))
		{
			cont++;
		}
	}
	return cont;
}

int GrafoMatriz::gradoSalida(int i)
{
	int cont = 0;
	for (int j = 0; (j < getNumVerts()); j++)
	{
		if (adyacente(i, j))
		{
			cont++;
		}
	}
	return cont;
}

void GrafoMatriz::ordenTopologico()
{
	Cola c;
	Vertice v;
	int cont = 0;
	int grado[getNumVerts()]; // vector para guardar grados de entrada
	for (int i = 0; i < getNumVerts(); i++)
	{
		grado[i] = gradosEntrada(getNumVertice(verts[i].getNombre()));
		if (grado[i] == 0) // si el grado de entrada del vertice es 0 se encola
		{
			c.insertarVal(verts[i]);
		}
	}
	Cola d = c;
	while (!d.colaVacia())
	{
		d.extraerVal();
		cont++;
	}
	if (cont <= 1)
	{
		cout << "El grafo tiene un ciclo" << endl;
	}
	else
	{
		cout << "[ ";
		while (!c.colaVacia()) // recorrido de cola
		{
			v = c.extraerVal();
			cout << v.getNombre() << " "; // impresion de vertice
			for (int i = 0; i < getNumVerts(); i++)
			{
				if (adyacente(v.getNumero(), i)) // si los vertices son adyacentes
				{
					grado[i]--; // se reduce el grado de entrada por la adyacencia
					if (grado[i] == 0)
					{
						c.insertarVal(verts[i]); // si el grado es 0 se encola
					}
				}
			}
		}
		cout << "]";
	}
}

void GrafoMatriz::matrizDeCaminos() // Matriz de caminos
{
	int nv = getNumVerts();
	int matAdy[nv][nv];
	for (int i = 0; i < nv; i++) // se llena la matriz de adyacencia con 1 o 0 según la adyacencia de vertices
	{
		for (int j = 0; j < nv; j++)
		{
			(adyacente(i, j)) ? matAdy[i][j] = 1 : matAdy[i][j] = 0;
		}
	}
	for (int k = 0; k < nv; k++) // generación de matriz de caminos
	{
		for (int i = 0; i < nv; i++)
		{
			for (int j = 0; j < nv; j++)
			{
				matAdy[i][j] = min(matAdy[i][j] + matAdy[i][k] * matAdy[k][j], 1);
			}
		}
	}
	// impresion de matriz de caminos
	cout << "     ";
	for (int i = 0; i < nv; i++)
	{
		cout << setw(5) << verts[i].getNombre(); // impresion de encabezado de matriz
	}
	cout << endl;
	for (int i = 0; i < nv; i++)
	{
		cout << setw(5) << verts[i].getNombre();
		for (int j = 0; j < nv; j++)
		{
			cout << setw(5) << matAdy[i][j] << " \n"[j == nv - 1];
		}
	}
}

void GrafoMatriz::caminoMasCorto(string a, string b) // Muestra el camino más corto entre dos vertices alcanzables, algoritmo dijkstra
{
	int va = getNumVertice(a);
	int vb = getNumVertice(b);
	if (gradosEntrada(vb) == 0)
	{
		cout << "El vertice no es accesible" << endl;
	}
	else
	{
		if (va < 0 && vb < 0)
		{
			cout << "El vertice no existe" << endl;
		}
		else
		{
			int nv = getNumVerts();
			int matAdy[nv][nv];

			for (int i = 0; i < nv; i++) // generacion de matriz de adyacencia
			{
				for (int j = 0; j < nv; j++)
				{
					if (adyacente(i, j)) // si es adyacente se guardan los pesos en la matriz
					{
						matAdy[i][j] = matAd[i][j];
					}
					else
					{
						matAdy[i][j] = 0; // sino se ponen 0
					}
				}
			}
			// impresion de matriz de adyacencia
			cout << "     ";
			for (int i = 0; i < nv; i++)
			{
				cout << setw(5) << verts[i].getNombre();
			}
			cout << endl;
			for (int i = 0; i < nv; i++)
			{
				cout << setw(5) << verts[i].getNombre();
				for (int j = 0; j < nv; j++)
				{
					cout << setw(5) << matAdy[i][j] << " \n"[j == nv - 1];
				}
			}

			int vi = va;	   // vertice inicial
			int vf = vb;	   // vertice final
			int actual = 0;	   // vertice actual
			int distancia = 0; // distancia
			// Tabla
			// 0 : visitado
			// 1 : distancia
			// 2 : vertice anterior
			int tabla[nv][3];
			for (int i = 0; i < nv; i++) // inicializar tabla
			{
				tabla[i][0] = 0;
				tabla[i][1] = 0xFFFF;
				tabla[i][2] = 0;
			}
			tabla[vi][1] = 0;
			cout << endl;
			for (int i = 0; i < nv; i++)
			{
				cout << i << " -> " << tabla[i][0] << setw(5) << tabla[i][1] << setw(5) << tabla[i][2] << endl;
			}
			cout << endl;
			actual = vi; // vertice actual = inicial
			do
			{
				tabla[actual][0] = 1;
				for (int i = 0; i < nv; i++)
				{
					if (adyacente(actual, i)) // si los vertices son adyacente
					{
						distancia = matAd[actual][i] + tabla[actual][1]; // distancia = al peso del arco
						if (distancia < tabla[i][1])
						{
							tabla[i][1] = distancia; // asignar distancia si la distancia actual es menor a la anterior
							tabla[i][2] = actual;	 // asignar el vertice actual al campo de vertice anterior
						}
					}
				}
				int iMenor = -1;
				int distanciaMenor = 0xFFFF;
				for (int i = 0; i < nv; i++)
				{
					if (tabla[i][1] < distanciaMenor && tabla[i][0] == 0) // si la distancia es menor a la distancia actual && el vertice aun no ha sido visitado
					{
						iMenor = i;
						distanciaMenor = tabla[i][1];
					}
				}
				actual = iMenor;
			} while (actual != -1);
			cout << endl;
			for (int i = 0; i < nv; i++) // impresion de tablas con valores
			{
				cout << i << " -> " << tabla[i][0] << setw(5) << tabla[i][1] << setw(5) << tabla[i][2] << endl;
			}
			cout << endl;

			Vertice v;
			ListaG ruta;
			int nod = vf;
			while (nod != vi) // insercion de vertices en lista
			{
				ruta.insertarAlInicio(nod);
				nod = tabla[nod][2];
			}
			ruta.insertarAlInicio(vi);
			// recorrido de lista
			NodoG *act = ruta.getPrimero();
			cout << "CAMINO MÁS CORTO DESDE " << a << " hacia " << b << endl;
			while (act != NULL)
			{
				v = getVertice(act->getDato());
				cout << v.getNombre() << "->";
				act = act->getPunt();
			}
		}
	}
}

bool GrafoMatriz::adyacente(int va, int vb)
{ // determina si dos vertices forman un arco conociendo su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{									// comprueba existencia de los dos vertices
		return matAd[va][vb] != 0xFFFF; // comprueba existencia de este arco
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}

bool GrafoMatriz::adyacente(string a, string b)
{						   // determina si dos vertices forman un arco conociendo su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido

	if ((va >= 0) && (vb >= 0))
	{									  // si los dos vertices existen
		return (matAd[va][vb] != 0xFFFF); // comprueba existencia de este arco
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}

class GrafoLista : public Grafo // definicion de herencia de clase Grafo
{
private:
	ListaG **arcos; // Lista de adyacencia
public:
	GrafoLista();							 // constructor sin par�metros
	GrafoLista(int v);						 // constructor conociendo cantidad m�xima de v�rtices
	void setArco(int va, int vb);			 // actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);	 // actualiza valor de arco recibiendo numeros de vertices
	void setArco(string a, string b);		 // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(string a, string b, int v); // actualiza valor de arco recibiendo nombres de vertices
	int getArco(int va, int vb);			 // devuelve el valor de un arco recibiendo numeros de vertices
	int getArco(string a, string b);		 // devuelve el valor de un arco recibiendo nombres de vertices
	bool adyacente(int va, int vb);			 // determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(string a, string b);		 // determina si dos vertices son adyacentes recibiendo sus nombres
	ListaG listaAdyacencia(int v);			 // metodo que devuelve la lista de adyacencia del vertice v
	int gradosEntrada(int i);				 // Calcula grados de entrada de un vertice
	int gradoSalida(int i);					 // Calcula grados de salida de un vertice
	void ordenTopologico();					 // Ordenamiento topologico
	void matrizDeCaminos();					 // Matriz de caminos, algoritmo warshall
	void caminoMasCorto(string a, string b); // Muestra el camino más corto entre dos vertices alcanzables, algoritmo dijkstra
};

GrafoLista::GrafoLista() : Grafo() {}

GrafoLista::GrafoLista(int v) : Grafo(v)
{
	setMaxVerts(v);			 // cantidad maxima de vertices por defecto
	setNumVerts(0);			 // cantidad de vertices del grafo tomado de max.Num.Vertices
	verts = new Vertice[v];	 // inicializa vector de v�rtices con v elementos
	arcos = new ListaG *[v]; // vector de punteros a listas
	for (int i = 0; i < v; i++)
	{						   // recorre vector de arcos
		arcos[i] = new ListaG; // a cada elemento del vector le asigna una lista
	}
}

void GrafoLista::setArco(int va, int vb)
{ // actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{									// comprueba existencia de los dos vertices
		arcos[va]->insertarAlFinal(vb); // a�ade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(int va, int vb, int v)
{ // actualiza valor de arco recibiendo numeros de vertices y factor de peso
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{									   // comprueba existencia de los dos vertices
		arcos[va]->insertarAlFinal(vb, v); // a�ade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(string a, string b)
{						   // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{									// comprueba existencia de los dos vertices
		arcos[va]->insertarAlFinal(vb); // a�ade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(string a, string b, int v)
{						   // modifica el valor almacenado en lista de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{									   // comprueba existencia de los dos vertices
		arcos[va]->insertarAlFinal(vb, v); // a�ade un nuevo vertice en la lista de este elemento del vector
	}
}

int GrafoLista::getArco(int va, int vb)
{ // retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de v�rtices que recibe como par�metro por numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{ // comprueba existencia de los dos vertices
		return arcos[va]->buscarValorEnLista(vb) != NULL;
	}
}

int GrafoLista::getArco(string a, string b)
{						   // retorna el valor del arco almacenado en la matriz de adyacencia para dos v�rtices que recibe como par�metro por nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice correspondiente al primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice correspondiente al segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{ // comprueba existencia de los dos vertices
		return arcos[va]->buscarValorEnLista(getNumVertice(b)) != NULL;
	}
}

bool GrafoLista::adyacente(int va, int vb)
{ // determina si dos vertices forman un arco conociendo su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{ // comprueba existencia de los dos vertices
		return arcos[va]->buscarValorEnLista(vb) != NULL;
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}

int GrafoLista::gradosEntrada(int i)
{
	int cont = 0;
	for (int j = 0; (j < getNumVerts()); j++)
	{
		if (adyacente(j, i))
		{
			cont++;
		}
	}
	return cont;
}

int GrafoLista::gradoSalida(int i)
{
	int cont = 0;
	for (int j = 0; (j < getNumVerts()); j++)
	{
		if (adyacente(i, j))
		{
			cont++;
		}
	}
	return cont;
}

void GrafoLista::ordenTopologico()
{
	Cola c;
	Vertice v;
	int cont = 0;
	int grado[getNumVerts()]; // vector para guardar grados de entrada
	for (int i = 0; i < getNumVerts(); i++)
	{
		grado[i] = gradosEntrada(getNumVertice(verts[i].getNombre()));
		if (grado[i] == 0) // si el grado de entrada del vertice es 0 se encola
		{
			c.insertarVal(verts[i]);
		}
	}
	Cola d = c;
	while (!d.colaVacia())
	{
		d.extraerVal();
		cont++;
	}
	if (cont <= 1)
	{
		cout << "El grafo tiene un ciclo" << endl;
	}
	else
	{
		cout << "[ ";
		while (!c.colaVacia()) // recorrido de cola
		{
			v = c.extraerVal();
			cout << v.getNombre() << " "; // impresion de vertice
			for (int i = 0; i < getNumVerts(); i++)
			{
				if (adyacente(v.getNumero(), i)) // si los vertices son adyacentes
				{
					grado[i]--; // se reduce el grado de entrada por la adyacencia
					if (grado[i] == 0)
					{
						c.insertarVal(verts[i]); // si el grado es 0 se encola
					}
				}
			}
		}
		cout << "]";
	}
}

void GrafoLista::matrizDeCaminos() // Matriz de caminos
{
	int nv = getNumVerts();
	int matAdy[nv][nv];
	for (int i = 0; i < nv; i++) // se llena la matriz de adyacencia con 1 o 0 según la adyacencia de vertices
	{
		for (int j = 0; j < nv; j++)
		{
			(adyacente(i, j)) ? matAdy[i][j] = 1 : matAdy[i][j] = 0;
		}
	}
	for (int k = 0; k < nv; k++) // generación de matriz de caminos
	{
		for (int i = 0; i < nv; i++)
		{
			for (int j = 0; j < nv; j++)
			{
				matAdy[i][j] = min(matAdy[i][j] + matAdy[i][k] * matAdy[k][j], 1);
			}
		}
	}
	// impresion de matriz de caminos
	cout << "     ";
	for (int i = 0; i < nv; i++)
	{
		cout << setw(5) << verts[i].getNombre(); // impresion de encabezado de matriz
	}
	cout << endl;
	for (int i = 0; i < nv; i++)
	{
		cout << setw(5) << verts[i].getNombre();
		for (int j = 0; j < nv; j++)
		{
			cout << setw(5) << matAdy[i][j] << " \n"[j == nv - 1];
		}
	}
}

void GrafoLista::caminoMasCorto(string a, string b) // Muestra el camino más corto entre dos vertices alcanzables, algoritmo dijkstra
{
	int va = getNumVertice(a);
	int vb = getNumVertice(b);
	if (gradosEntrada(vb) == 0)
	{
		cout << "El vertice no es accesible" << endl;
	}
	else
	{
		if (va < 0 && vb < 0)
		{
			cout << "El vertice no existe" << endl;
		}
		else
		{
			int nv = getNumVerts();
			int matAdy[nv][nv];

			for (int i = 0; i < nv; i++) // generacion de matriz de adyacencia
			{
				for (int j = 0; j < nv; j++)
				{
					if (adyacente(i, j)) // si es adyacente se guardan los pesos en la matriz
					{
						matAdy[i][j] = arcos[i]->buscarValorEnLista(j)->getPeso();
					}
					else
					{
						matAdy[i][j] = 0; // sino se ponen 0
					}
				}
			}
			// impresion de matriz de adyacencia
			cout << "     ";
			for (int i = 0; i < nv; i++)
			{
				cout << setw(5) << verts[i].getNombre();
			}
			cout << endl;
			for (int i = 0; i < nv; i++)
			{
				cout << setw(5) << verts[i].getNombre();
				for (int j = 0; j < nv; j++)
				{
					cout << setw(5) << matAdy[i][j] << " \n"[j == nv - 1];
				}
			}

			int vi = va;	   // vertice inicial
			int vf = vb;	   // vertice final
			int actual = 0;	   // vertice actual
			int distancia = 0; // distancia
			// Tabla
			// 0 : visitado
			// 1 : distancia
			// 2 : vertice anterior
			int tabla[nv][3];
			for (int i = 0; i < nv; i++) // inicializar tabla
			{
				tabla[i][0] = 0;
				tabla[i][1] = 0xFFFF;
				tabla[i][2] = 0;
			}
			tabla[vi][1] = 0;
			cout << endl;
			for (int i = 0; i < nv; i++)
			{
				cout << i << " -> " << tabla[i][0] << setw(5) << tabla[i][1] << setw(5) << tabla[i][2] << endl;
			}
			cout << endl;
			actual = vi; // vertice actual = inicial
			do
			{
				tabla[actual][0] = 1;
				for (int i = 0; i < nv; i++)
				{
					if (adyacente(actual, i)) // si los vertices son adyacente
					{
						distancia = arcos[actual]->buscarValorEnLista(i)->getPeso() + tabla[actual][1]; // distancia = al peso del arco
						if (distancia < tabla[i][1])
						{
							tabla[i][1] = distancia; // asignar distancia si la distancia actual es menor a la anterior
							tabla[i][2] = actual;	 // asignar el vertice actual al campo de vertice anterior
						}
					}
				}
				int iMenor = -1;
				int distanciaMenor = 0xFFFF;
				for (int i = 0; i < nv; i++)
				{
					if (tabla[i][1] < distanciaMenor && tabla[i][0] == 0) // si la distancia es menor a la distancia actual && el vertice aun no ha sido visitado
					{
						iMenor = i;
						distanciaMenor = tabla[i][1];
					}
				}
				actual = iMenor;
			} while (actual != -1);
			cout << endl;
			for (int i = 0; i < nv; i++) // impresion de tablas con valores
			{
				cout << i << " -> " << tabla[i][0] << setw(5) << tabla[i][1] << setw(5) << tabla[i][2] << endl;
			}
			cout << endl;

			Vertice v;
			ListaG ruta;
			int nod = vf;
			while (nod != vi) // insercion de vertices en lista
			{
				ruta.insertarAlInicio(nod);
				nod = tabla[nod][2];
			}
			ruta.insertarAlInicio(vi);
			// recorrido de lista
			NodoG *act = ruta.getPrimero();
			cout << "CAMINO MÁS CORTO DESDE " << a << " hacia " << b << endl;
			while (act != NULL)
			{
				v = getVertice(act->getDato());
				cout << v.getNombre() << "->";
				act = act->getPunt();
			}
		}
	}
}

bool GrafoLista::adyacente(string a, string b)
{						   // determina si dos vertices forman un arco conociendo su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido

	if ((va >= 0) && (vb >= 0))
	{ // si los dos vertices existen
		return arcos[va]->buscarValorEnLista(getNumVertice(b)) != NULL;
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}

ListaG GrafoLista::listaAdyacencia(int v)
{ // metodo que devuelve la lista de adyacencia del vertice v
	return *arcos[v];
}
#endif
