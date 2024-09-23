/*Elabore un programa en C++ que permita el ingreso de un grafo, y determine si al recorrer
sus vertices (tanto en anchura como en pronfundidad) se encuentran ordenados (ascendente o descendentemente)
*/
// Autor: Daryend Castillo - 7165

using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "RecorreGrafo.h"
#include "utilidades.h"

int main() {
    system("color fc"); // interfaz
    GrafoLista g; // declara un grafo para manipular las clases
    int n; // cantidad de vértices a crear

    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista* g); // añade arcos => grafos no valorados
    void ingresarArcosValor(GrafoLista* g); // añade arcos => grafos valorados
    void imprimirGrafo(GrafoLista g); // prototipo de la función que presenta los vértices del grafo
    void imprimirLista(GrafoLista g); // prototipo de la función que presenta los vértices apuntados desde cada uno, y su peso
    bool ordenadoPila(int pila[], int tam); // Prototipo de función que determina si está ordenado por Pila
    bool esGrafoOrdenado(GrafoLista& g); // Prototipo de función que determina si el grafo está ordenado

    cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
    n = leerN(1, 20); // lectura de cantidad de vértices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a función de ingreso de los datos referentes al grafo
    ingresarArcos(&g); // llamado a la función que ingresa los arcos del grafo
    //ingresarArcosValor(&g); // llamado a la función que ingresa los arcos valorados del grafo
    imprimirGrafo(g); // llamado a la función que imprime la matriz de adyacencia
    //imprimirLista(g);

    if (esGrafoOrdenado(g)) {
        cout << "El grafo está ordenado." << endl;
    } else {
        cout << "El grafo no está ordenado." << endl;
    }

    cout << endl;
    system("pause");
}

GrafoLista ingresarVertices(int n1) { // función que ingresa los datos de los vértices de un grafo
    TipoG aux;
    GrafoLista a(n1);

    for (int i = 0; (i < n1); i++) {
        cout << endl << "Ingrese el Valor del vértice No. " << (i + 1) << ": ";
        cin >> aux;
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista* g) { // función que ingresa los datos de los arcos de un grafo
    int nv = g->getNumVerts();
    int na;
    TipoG aux;

    for (int i = 0; (i < nv); i++) {
        Vertice x = g->getVertice(i);
        cout << endl << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";
        cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++) {
            cout << endl << "Valor del Vértice Destino: ";
            getline(cin, aux);
            g->setArco(x.getDato(), aux);
        }
    }
}

void ingresarArcosValor(GrafoLista* g) { // función que ingresa los datos de los arcos de un grafo incluido peso
    int nv = g->getNumVerts();
    int na;
    int peso; // peso del arco
    TipoG aux;

    for (int i = 0; (i < nv); i++) {
        Vertice x = g->getVertice(i);
        cout << endl << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";
        cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++) {
            cout << endl << "Valor del Vértice Destino: ";
            cin >> aux;
            cout << endl << "PESO DEL ARCO";
            peso = leerN(0, 100);
            cin.ignore();
            g->setArco(x.getDato(), aux, peso);
        }
    }
}

void imprimirGrafo(GrafoLista g) { // función que presenta los datos del grafo
    int nv = g.getNumVerts();
    TipoG aux;
    cout << endl << "===============================================";
    cout << endl << "L I S T A    D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++) {
        Vertice x = g.getVertice(i);
        cout << endl << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";

        for (int j = 0; (j < nv); j++) {
            if (g.adyacente(i, j)) {
                Vertice x = g.getVertice(j);
                cout << endl << "\t\t--->" << x.getDato();
            }
        }
    }
    cout << endl << "===============================================";
    cout << endl;
}

void imprimirLista(GrafoLista g) { // función que presenta los datos del grafo
    int nv = g.getNumVerts();
    NodoG* actual; // apunta al nodo actual de la lista

    cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

    for (int i = 0; (i < nv); i++) {
        Vertice x = g.getVertice(i);
        cout << endl << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";

        ListaG vlista = g.listaAdyacencia(i);
        actual = vlista.getPrimero(); // copiar la dirección del primer nodo de la lista

        while (actual != NULL) { // repetir el ciclo mientras haya nodos en la lista
            cout << endl << "> " << actual->getDato() << " > " << actual->getPeso(); // visualiza el contenido del nodo actual de la lista
            actual = actual->getPunt(); // apuntador actual avanza al siguiente nodo
        }
    }
}

bool ordenadoPila(int pila[], int tam) {
    // Verificar si la pila está ordenada ascendentemente
    for (int i = 0; i < tam - 1; i++) {
        if (pila[i] > pila[i + 1]) {
            return false;
        }
    }
    return true;
}

bool esGrafoOrdenado(GrafoLista& g) {
    RecorreGrafo recorre;

    // Obtener el recorrido en anchura del grafo
    int* recorridoAnchura = recorre.recorrerAnchuraLa(g, 0);

    // Verificar si el recorrido en anchura está ordenado ascendentemente
    for (int i = 1; i < g.getNumVerts(); i++) {
        if (recorridoAnchura[i] < recorridoAnchura[i - 1]) {
            delete[] recorridoAnchura;
            return false;
        }
    }

    delete[] recorridoAnchura;

    // Obtener el recorrido en profundidad del grafo
    int* recorridoProfundidad = recorre.recorrerProfLa(g, 0);

    // Calcular el tamaño de la pila
    int tamPila = 0;
    while (recorridoProfundidad[tamPila] != -1) {
        tamPila++;
    }

    // Verificar si el recorrido en profundidad está ordenado ascendentemente
    bool ordenado = ordenadoPila(recorridoProfundidad, tamPila);

    delete[] recorridoProfundidad;

    return ordenado;
}