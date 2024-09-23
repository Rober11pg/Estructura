/*Resolver este requerimiento: Una persona quiere recorrer un museo. Su idea es hacer un recorrido bastante lógico: empezar en una sala (al azar), luego ir a una adyacente a ésta, luego a una adyacente a la segunda (si no fue visitada aún), y así hasta recorrer todas las salas. Cuando no tiene más salas adyacentes para visitar (porque ya fueron todas visitadas), simplemente vuelve por donde vino buscando otras salas adyacentes. Teniendo un grafo que representa el mapa del museo (donde los vértices son salas, y los arcos (v, w) indican que las salas v y w se encuentran conectadas). Implementar un programa que devuelva una lista con un recorrido posible de la idea de aquella persona para visitar las salas del museo.*/

#include "numero.h"
#include "Vertice.h"
#include "GrafoLista.h"
#include "Lista.h"
#include "Pila.h"

//DEFINIR EN NodoG.h string

using namespace std;

GrafoLista ingresarVertices(int n1);
void ingresarArcos(GrafoLista *g);
void Camino(GrafoLista g, int v);
void imprimirLista(Lista l);

int main(){
    system("color 5c");
    GrafoLista g;
    int n;

    cout<<"CANTIDAD DE VERTICES DEL GRAFO"<<endl;
    n=leerN(1,20);
    cin.ignore();

    g= ingresarVertices(n);
    ingresarArcos(&g);
    Camino(g,0);

    return 0;
}

GrafoLista ingresarVertices(int n1){
    string aux;
    GrafoLista a(n1);

    for(int i=0; (i<n1);i++){
        cout<<"Ingrese el nombre del vertice N°. "<<(i+1)<<": "<<endl;
        getline(cin,aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g){
    int nv=g->getMaxVerts();
    int na;
    string aux;

    for(int i = 0; (i<nv); i++){
        Vertice x = g -> getVertice(i);
        cout<<"Vertice N°. "<<x.getNumero()+1<<" - "<<x.getNombre()<<" - "<<endl;
        cout<<"CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
        na=leerN(0,10);
        cin.ignore();

        for(int j = 0;(j<na);j++){
            cout<<"Identificador del Vertice Destino: "<<endl;
            getline(cin,aux);
            g->setArco(x.getNombre(),aux);
        }
    }
}

void Camino(GrafoLista g, int v) {  			//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
    Lista l;
	Pila pila;
	int* m;

	m = new int[g.getNumVerts()];

	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = 1;
	}
	m[v] = 0; 														// v�rtice origen queda marcado
	pila.push(v);
	while (!pila.pilaVacia()) {
		int cw;
		cw = pila.pop();
		w = cw;
		//cout << "Vertice [" << w << "] => " << g.getVertice(w).getNombre() << " => visitado" << endl;
		l.insertarAlFinal(w+1);
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) && m[u] == 1) { 					// se marca v�rtice u con n�mero de arcos hasta el
				m[u] = m[w] + 1;
				pila.push(u);
			}
		}
	}
	cout<<"Posible camino de vertices a seguir: "<<endl;
	imprimirLista(l);
}

void imprimirLista(Lista l){						// funcion que ingresa elementos en nuestra lista
	Nodo* actual;									// apunta al nodo actual de la lista

	actual=l.getPrimero();							// funcion que permite copiar la direccion del primer nodod de la lista
	while(actual!=NULL){							// se repite el ciclo mientras haya nodods en la lista
		cout<<" - "<<actual->getDato();		// visualiza el contenido del nodo actual de la lista
		actual=actual->getPunt();					// el apuntador avanza al siguiente elemento
	}
}
