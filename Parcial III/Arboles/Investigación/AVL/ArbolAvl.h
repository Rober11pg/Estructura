/* Autor: Roberto Jiménez-7048*/
typedef int Tipoelemento;
#include <iostream>
#include "stdlib.h"
#include "NodoAvl.h"

using namespace std;
class ArbolAvl
{
	NodoAvl *raiz;

private:
	NodoAvl *rotacionII(NodoAvl *n, NodoAvl *n1);
	NodoAvl *rotacionDD(NodoAvl *n, NodoAvl *n1);
	NodoAvl *rotacionDI(NodoAvl *n, NodoAvl *n1);
	NodoAvl *rotacionID(NodoAvl *n, NodoAvl *n1);
	NodoAvl *buscar(Tipoelemento dato, NodoAvl *p);
	void preOrden(NodoAvl *p);
	void enOrden(NodoAvl *p);
	void postOrden(NodoAvl *p);
	int altura1(NodoAvl *p);

public:
	ArbolAvl() { raiz = NULL; }
	ArbolAvl(NodoAvl *r) { raiz = r; }
	NodoAvl *Oraiz() { return raiz; }
	void Praiz(NodoAvl *r) { raiz = r; }

	NodoAvl *insertarAvl(NodoAvl *raiz, Tipoelemento dt, bool &hc);
	void insertarAvl(Tipoelemento dt);
	int mayor(int x, int y);
	int altura(NodoAvl *r);
	int cuantos();
	int cuantos(NodoAvl *r); // numero de nodos
	void dibujarArbol(NodoAvl *r, int h);
	NodoAvl *buscar(Tipoelemento buscado);
	NodoAvl *buscar_min(NodoAvl *p);
	NodoAvl *buscar_max(NodoAvl *p);
	int altura1();
	void vaciar(NodoAvl *r);
	void preOrden();
	void enOrden();
	void postOrden();
	bool esVacio();
};

NodoAvl *ArbolAvl::rotacionII(NodoAvl *n, NodoAvl *n1)
{
	n->ramaIzdo(n1->subarbolDcho());
	n1->ramaDcho(n);
	// actualizacion de los factores de equilibrio
	if (n1->Ofe() == -1) // la condicion es true en la insercion
	{
		n->Pfe(0);
		n1->Pfe(0);
	}
	else
	{
		n->Pfe(-1);
		n1->Pfe(1);
	}
	return n1;
}

NodoAvl *ArbolAvl::rotacionDD(NodoAvl *n, NodoAvl *n1)
{
	n->ramaDcho(n1->subarbolIzdo());
	n1->ramaIzdo(n);
	// actualizacion de los factores de equilibrio
	if (n1->Ofe() == +1) // la condicion es true en la insercion
	{
		n->Pfe(0);
		n1->Pfe(0);
	}
	else
	{
		n->Pfe(+1);
		n1->Pfe(-1);
	}
	return n1;
}

NodoAvl *ArbolAvl::rotacionDI(NodoAvl *n, NodoAvl *n1)
{
	NodoAvl *n2;
	n2 = n1->subarbolIzdo();
	n->ramaDcho(n2->subarbolIzdo());
	n2->ramaIzdo(n);
	n1->ramaIzdo(n2->subarbolDcho());
	n2->ramaDcho(n1);
	// actualizacion de los factores de equilibrio
	if (n2->Ofe() == +1)
	{
		n->Pfe(-1);
	}
	else
	{
		n->Pfe(0);
	}
	if (n2->Ofe() == -1)
	{
		n1->Pfe(+1);
	}
	else
	{
		n1->Pfe(0);
	}
	n2->Pfe(0);
	return n2;
}

NodoAvl *ArbolAvl::rotacionID(NodoAvl *n, NodoAvl *n1)
{
	NodoAvl *n2;
	n2 = n1->subarbolDcho();
	n->ramaIzdo(n2->subarbolDcho());
	n2->ramaDcho(n);
	n1->ramaDcho(n2->subarbolIzdo());
	n2->ramaIzdo(n1); // actualizacion de los factores de equilibrio
	if (n2->Ofe() == +1)
	{
		n1->Pfe(-1);
	}
	else
	{
		n1->Pfe(0);
	}
	if (n2->Ofe() == -1)
	{
		n->Pfe(1);
	}
	else
	{
		n->Pfe(0);
	}
	n2->Pfe(0);
	return n2;
}

NodoAvl *ArbolAvl::insertarAvl(NodoAvl *raiz, Tipoelemento dt, bool &hc)
{
	NodoAvl *n1;
	if (raiz == NULL)
	{
		raiz = new NodoAvl(dt);
		hc = true;
	}
	else if (dt < raiz->valorNodo())
	{
		NodoAvl *iz;
		iz = insertarAvl(raiz->subarbolIzdo(), dt, hc);
		raiz->ramaIzdo(iz);
		// regreso por los nodos del camino de busqueda
		if (hc)
		{ // siempre se comprueba si crecio en altura
			switch (raiz->Ofe())
			{		// decrementa el fe por aumentar la altura de rama izquierda
			case 1: // tenga +1 y crecio su izquierda
				raiz->Pfe(0);
				hc = false; // arbol deja de crecer
				break;
			case 0:			   // tenga 0 y crecio su izquierda
				raiz->Pfe(-1); // arbol sigue creciendo
				break;
			case -1: // aplicar rotacion a la izquierda
				n1 = raiz->subarbolIzdo();
				if (n1->Ofe() == -1)
				{
					raiz = rotacionII(raiz, n1);
				}
				else
				{
					raiz = rotacionID(raiz, n1);
				}
				hc = false; // �rbol deja de crecer en ambas rotaciones
			}
		}
	}
	else if (dt > raiz->valorNodo())
	{
		NodoAvl *dr;
		dr = insertarAvl(raiz->subarbolDcho(), dt, hc);
		raiz->ramaDcho(dr);
		// regreso por los nodos del camino de busqueda
		if (hc)
		{ // siempre se comprueba si crecio en altura
			switch (raiz->Ofe())
			{		// incrementa el fe por aumentar la altura de rama izquierda
			case 1: // aplicar rotacion a la derecha
				n1 = raiz->subarbolDcho();
				if (n1->Ofe() == +1)
				{
					raiz = rotacionDD(raiz, n1);
				}
				else
				{
					raiz = rotacionDI(raiz, n1);
				}
				hc = false; // arbol deja de crecer en ambas rotaciones
				break;
			case 0:			   // tenga 0 y crecio su derecha
				raiz->Pfe(+1); // arbol sigue creciendo
				break;
			case -1: // tenga -1 y crecio su derecha
				raiz->Pfe(0);
				hc = false; // arbol deja de crecer
			}
		}
	}
	else
	{
		throw "No puede haber claves repetidas ";
	}
	return raiz;
}

void ArbolAvl::preOrden(NodoAvl *p)
{ /* Recorre el arbol en Pre-Orden */
	if (p != NULL)
	{
		printf("%d ", p->valorNodo());
		preOrden(p->subarbolIzdo());
		preOrden(p->subarbolDcho());
	}
}

void ArbolAvl::enOrden(NodoAvl *p)
{ /* Recorre el arbol En-Orden */
	if (p != NULL)
	{
		enOrden(p->subarbolIzdo());
		printf("%d ", p->valorNodo());
		enOrden(p->subarbolDcho());
	}
}

void ArbolAvl::postOrden(NodoAvl *p)
{
	if (p != NULL)
	{
		postOrden(p->subarbolIzdo());
		postOrden(p->subarbolDcho());
		printf("%d ", p->valorNodo());
	}
}

void ArbolAvl::preOrden()
{ // recorrido en preorden
	preOrden(raiz);
}

void ArbolAvl::enOrden()
{ // recorrido en ineorden
	enOrden(raiz);
}

void ArbolAvl::postOrden()
{ // recorrido en postorden
	postOrden(raiz);
}

void ArbolAvl::insertarAvl(Tipoelemento dt)
{
	bool hc = false;
	raiz = insertarAvl(raiz, dt, hc);
}

int ArbolAvl::mayor(int x, int y)
{ // calcula el mayor de los numeros que recibe como parametro
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int ArbolAvl::altura(NodoAvl *r)
{ // metodo publico que decide la altura de un arbol apuntado por r
	if (r != NULL)
	{
		return mayor(altura(r->subarbolIzdo()),
					 altura(r->subarbolDcho()));
	}
	else
	{
		return false;
	}
}

int ArbolAvl::cuantos()
{ // metodo publico que calcula el numero de nodos de un arbol
	return cuantos(raiz);
}

int ArbolAvl::cuantos(NodoAvl *r)
{ // metodo privado que calcula el numero de nodos apuntado por r.
	if (r)
	{
		int cuantosIzquierda, cuantosDerecha;
		cuantosIzquierda = cuantos(r->subarbolIzdo());
		cuantosDerecha = cuantos(r->subarbolDcho());
		return cuantosIzquierda + cuantosDerecha + 1;
	}
	else
	{
		return 0;
	}
}

void ArbolAvl::dibujarArbol(NodoAvl *r, int h)
{ // escribe las claves del arbol estableciendo separacion entre nodos
	if (r == NULL)
	{
		return;
	}
	if (r != NULL)
	{
		dibujarArbol(r->subarbolDcho(), h + 1);
		for (int i = 1; i <= h; i++)
			cout << "   ";
		cout << r->valorNodo();
		cout << endl;
		dibujarArbol(r->subarbolIzdo(), h + 1);
	}
}

NodoAvl *ArbolAvl::buscar(Tipoelemento dato, NodoAvl *p)
{
	if (p == NULL)
	{
		return (NULL);
	}
	else
	{
		if (dato < p->valorNodo())
		{
			return (buscar(dato, p->subarbolIzdo()));
		}
		else
		{
			if (dato > p->valorNodo())
			{
				return (buscar(dato, p->subarbolDcho()));
			}
			else
			{
				return (p);
			}
		}
	}
}

NodoAvl *ArbolAvl::buscar(Tipoelemento buscado)
{
	return buscar(buscado, raiz);
}

NodoAvl *ArbolAvl::buscar_min(NodoAvl *p)
{ /* Busca el minimo en el arbol */
	if (p == NULL)
	{
		return (NULL);
	}
	else
	{
		if (p->subarbolIzdo() == NULL)
		{
			return (p);
		}
		else
		{
			return (buscar_min(p->subarbolIzdo()));
		}
	}
}

NodoAvl *ArbolAvl::buscar_max(NodoAvl *p)
{ /* Busca el maximo en el arbol */
	if (p != NULL)
	{
		while (p->subarbolDcho() != NULL)
		{
			p = p->subarbolDcho();
		}
	}
	return (p);
}

int ArbolAvl::altura1(NodoAvl *p)
{ /* Calcula la altura del arbol */
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		int alturaIz = altura1(p->subarbolIzdo());
		int alturaDr = altura1(p->subarbolDcho());
		if (alturaIz > alturaDr)
		{
			return alturaIz + 1;
		}
		else
		{
			return alturaDr + 1;
		}
	}
}

int ArbolAvl::altura1()
{
	return altura1(raiz);
}

void ArbolAvl::vaciar(NodoAvl *r)
{
	if (r != NULL)
	{
		vaciar(r->subarbolIzdo());
		vaciar(r->subarbolDcho());
		cout << "\tNodo borrado. ";
		r = NULL;
	}
}

bool ArbolAvl::esVacio()
{
	return raiz == NULL;
}
