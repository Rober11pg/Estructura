// Resolver este requerimiento: La teoría de los 6 grados de separación
// dice que cualquier persona en la Tierra puede estar conectado a cualquier
// otra persona del planeta a través de una cadena de conocidos que no tiene
// más de cinco intermediarios (conectando a ambas personas con solo seis enlaces).
// Suponiendo que se tiene un grafo G en el que cada vértice es una persona y
// cada arista conecta gente que se conoce: Implementar un programa para comprobar
// si se cumple tal teoría para todo el conjunto de personas representadas en el grafo G.
// Autor: Roberto Jiménez-7048

#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoMatriz g; // declara un grafo para manipular las clases
    int n; // cantidad de vertices a crear
    
    GrafoMatriz ingresarVertices(int n1);
    void ingresarArcos(GrafoMatriz * g); // añade arcos => grafos no valorados
    void imprimirGrafo(GrafoMatriz g);   // prototipo de la funcion que presenta los vertices del grafo
    void comprobarTeoria(GrafoMatriz g);

    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    // imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia

    comprobarTeoria(g);
    system("pause");
}

GrafoMatriz ingresarVertices(int n1)
{
    // funcion que ingresa los datos de los v rtices de un grafo
    string aux;
    GrafoMatriz a(n1);

    for (int i = 0; (i < n1); i++)
    {
        cout << endl<< "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        getline(cin, aux);
        a.nuevoVertice(aux);
    }

    return a;
}

void ingresarArcos(GrafoMatriz *g)
{ // funcion que ingresa los datos de los arcos de un grafo incluido peso
    int nv = g->getNumVerts();
    int na;
    int peso; // peso del arco
    string aux;

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl<< "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";
        cout << endl<< "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE" << endl;
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << endl<< "Identificador del Vertice Destino: ";
            getline(cin, aux);
            g->setArco(x.getNombre(), aux, 1);
        }
    }
}

void imprimirGrafo(GrafoMatriz g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl<< "===============================================";
    cout << endl<< "LISTA DE ADYACENCIA";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl<< "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - "<< "GRADO SALIDA: " << g.gradoSalida(i);

        for (int j = 0; (j < nv); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getNombre();
            }
        }
    }
    cout << endl<< "===============================================";
    cout << endl;
}

void comprobarTeoria(GrafoMatriz g)
{                            // funcion que implementa el algoritmo de Warshall
    int n = g.getNumVerts(); // cantidad de vertices del grafo
    typedef int *pint;       // pint es tipo que apunta a punteros enteros
    int **P = new pint[n];   // P apunta a un vector de punteros enteros
    for (int i = 0; i < n; i++)
    {                      // recorre el vector P
        P[i] = new int[n]; // Cada elemento de P tiene un nuevo vector de enteros: es ahora una matriz de enteros
    }
    // Se obtiene la matriz inicial: matriz de adyacencia
    for (int i = 0; i < n; i++)
    { // recorre los vertices dispuestos en filas
        for (int j = 0; j < n; j++)
        {                                        // recorre los vertices dispuestos en columnas
            P[i][j] = g.adyacente(i, j) ? 1 : 0; // determina adyacencia entre vertices i y j
        }
    }
    // Desde P0 se obtienen P1, P2, P3 ,..., Pn-1, Pn que es la matriz de caminos
    for (int k = 0; k < n; k++)
    { // etapas de programacion dinamica
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (P[i][k] * P[k][j])
                { // k es el indice de la programacion dinamica
                    P[i][j] = 1;
                }
            }
        }
    }
    cout << endl<< "===============================================";
    bool comp = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (comp == false)
                continue;

            if (P[i][j] > 6)
                comp = false;
        }
        cout << "\n";
    }
    cout << "La teoría" << ((comp == true) ? " si " : " no ") << "se cumple" << endl;
}