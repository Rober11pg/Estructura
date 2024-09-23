//grafo4.cpp
//Obtener una lista ordenada de los vertices que forman un grafo, en funcion de su grado de entrada 

#include <iostream>
using namespace std;
#include "GrafoLista.h"

int leerN(){		//funcion que ingresa cantidad de valores a procesar
	int x; 			//var de lectura
	
	cout << endl << "Ingrese un valor positivo: ";
	cin >> x;
	
	if (x < 1){			//valor no admitido
		x = leerN();	//volver a ingresar un valor 
	}
	return x;		//devolver el valor leido
}

int leerN(int li, int ls){		//funcion que ingresa cantidad de valores a procesar
	int x; 			//var de lectura
	
	cout << endl << "Ingrese un valor positivo: ";
	cin >> x;
	
	if ((x < li) || (x > ls)){			//valor no admitido
		x = leerN();	//volver a ingresar un valor 
	}
	return x;		//devolver el valor leido
}

int main(){
	system("color f0");							//interfaz
	GrafoLista g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);		//añade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);			//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
	//void imprimirListaOrdenada(GrafoLista g);	//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
    void calcularGradoEntrada(GrafoLista g);    //prototipo de la funcion que calcula el grado de entrada de cada vertice

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	//ingresarArcos(&g);							//llamado a la funcion que ingresa los arcos del grafo
	ingresarArcosValor(&g);					//llamado a la funcion que ingresa los arcos valorados del grafo
	// imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia
	imprimirLista(g);
	calcularGradoEntrada(g);                //llamado a la funcion que calcula el grado de entrada de cada vertice


	cout << endl;
	system("pause");
}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	Tipo aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;									//peso del arco
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();

	Tipo aux;
	cout << endl << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato() ;
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

void imprimirLista(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;								//apunta al nodo actual de la lista

	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}

void calcularGradoEntrada(GrafoLista g){                //calcula el grado de entrada de cada vertice

    int nv = g.getNumVerts();

	Tipo aux;
    int gradoEntrada [nv];                              //arreglo que almacena el grado de entrada de cada vertice
	
    cout << endl << "===============================================";
    cout << endl << "GRADOS DE ENTRADA DE CADA VERTICE";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

        

        for(int j = 0; j < nv; j++){
            ListaG vlista = g.listaAdyacencia(j);
            if(vlista.buscarValorEnLista(x.getDato()) != NULL){
                gradoEntrada[i]=gradoEntrada[i]+1;
            }  
        }
        cout << endl << "Grado de entrada: " << gradoEntrada[i];
	}
	cout << endl << "===============================================";
	cout << endl;
}
