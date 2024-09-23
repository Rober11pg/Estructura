// Implementación de ordenación topologica de un grafo
// Implementación de Algortimo de warshall
// Implementación de Algortimo de dijkstra
// Autor: Roberto Jiménez-7048

#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoMatriz g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear

    GrafoMatriz ingresarVertices(int n1);
    void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
    void ingresarArcosValor(GrafoMatriz * g);        // a�ade arcos => grafos valorados
    void imprimirGrafo(GrafoMatriz g);               // prototipo de la funcion que presenta los vertices del grafo
    void dijkstra(GrafoMatriz g);    //Calcula los caminos mínimos entre dos vértices

    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    //ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
    ingresarArcosValor(&g); // llamado a la funcion que ingresa los arcos valorados del grafo
    imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
    cout << endl;
    cout<<endl<<"ORDENACION TOPOLOGICA"<<endl;
    g.ordenTopologico();
    cout<<endl<<endl<<"MATRIZ DE CAMINOS"<<endl;
    g.matrizDeCaminos();
    dijkstra(g);
    cout << endl;
    system("pause");
}

GrafoMatriz ingresarVertices(int n1)
{ // funcion que ingresa los datos de los v�rtices de un grafo
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

void ingresarArcosValor(GrafoMatriz *g)
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
void imprimirGrafo(GrafoMatriz g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl<< "===============================================";
    cout << endl<< "MATRIZ DE ADYACENCIA";

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

void dijkstra(GrafoMatriz g)    //Calcula los caminos mínimos entre dos vértices
{
    string a, b, x = "xxx";
    while (a != "xxx")
    {
        cout << endl<< "FINALIZAR : xxx" << endl;
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