// Implementación de ordenación topologica de un grafo
// Implementación de Algortimo de warshall
// Implementación de Algortimo de dijkstra
// Autor: Roberto Jiménez-7048
#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear

    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista * g);      // añade arcos => grafos no valorados
    void ingresarArcosValor(GrafoLista * g); // añade arcos => grafos valorados
    void imprimirGrafo(GrafoLista g);        // prototipo de la funcion que presenta los vertices del grafo
    void imprimirLista(GrafoLista g);        // prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
    void dijkstra(GrafoLista g);             // Calcula los caminos mínimos entre dos vértices

    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    // ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
    ingresarArcosValor(&g); // llamado a la funcion que ingresa los arcos valorados del grafo
    // imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
    imprimirLista(g);
    cout << endl;
    cout << endl<< "ORDENACION TOPOLOGICA" << endl;
    g.ordenTopologico();
    cout << endl
         << endl<< "MATRIZ DE CAMINOS" << endl;
    g.matrizDeCaminos();
    dijkstra(g);
    cout << endl;
    system("pause");
}

GrafoLista ingresarVertices(int n1)
{ // funcion que ingresa los datos de los v�rtices de un grafo
    string aux;
    GrafoLista a(n1);

    for (int i = 0; (i < n1); i++)
    {
        cout << endl<< "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        getline(cin, aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g)
{ // funcion que ingresa los datos de los arcos de un grafo
    int nv = g->getNumVerts();
    int na;
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
            g->setArco(x.getNombre(), aux);
        }
    }
}

void ingresarArcosValor(GrafoLista *g)
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
            cout << endl<< "PESO DEL ARCO" << endl;
            peso = leerN(0, 100);
            cin.ignore();
            g->setArco(x.getNombre(), aux, peso);
        }
    }
}
void imprimirGrafo(GrafoLista g)
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

void imprimirLista(GrafoLista g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    NodoG *actual; // apunta al nodo actual de la lista
    int y = 0;

    cout << endl<< "ELEMENTOS CONTENIDOS EN LA LISTA";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl<< "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";

        ListaG vlista = g.listaAdyacencia(i);
        if (!vlista.esVacia())
        {
            actual = vlista.getPrimero(); // copiar la direccion del primer nodo de la lista
            y = actual->getDato();        // nodo actual
            while (actual != NULL)
            { // repetir el ciclo mientras haya nodos en la lista
                cout << endl<< "> " << y << " > " << actual->getPeso(); // visualiza el contenido del nodo actual de la lista
                actual = actual->getPunt();                      // apuntador actual avanza al siguiente nodo
            }
        }
        else
        {
            cout << "No tiene vertices de salida" << endl;
        }
    }
}

void dijkstra(GrafoLista g) // Calcula los caminos mínimos entre dos vértices
{
    string a, b, x = "xxxx";
    while (a != "xxxx")
    {
        cout << endl<< "FINALIZAR : xxxx" << endl;
        cout << "Ingrese vertice inicial: ";
        cin >> a;
        if (a != x)
        {
            cin.ignore();
            cout << "Ingrese vertice final: ";
            cin >> b;
            cout << endl;
            g.caminoMasCorto(a, b);
        }
    }
}