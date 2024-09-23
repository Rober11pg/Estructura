// Resolver este requerimiento: Supóngase que se cuenta con un grafo que modela un ecosistema.
// En dicho grafo, cada vértice es una especie, y cada arco (v, w) indica que v es depredador natural de w.
// Considerando la horrible tendencia del ser humano por llevar a la extinción especies, algo que puede interesar
// es saber si existe alguna especie que, si llegara a desaparecer, rompería todo el ecosistema: quienes la depredan
// no tienen un sustituto (y, por ende, pueden desaparecer también) y/o quienes eran depredados por esta ya no tienen
// amenazas, por lo que crecerán descontroladamente. Implementar un programa que permita ingresar el grafo de dichas
// características y devuelva una lista de todas las especies que cumplan lo antes mencionado.
// Autor: Roberto Jiménez-7048
#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear
    ListaG l;
    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista * g);         // añade arcos => grafos no valorados
    void imprimirGrafo(GrafoLista g);           // prototipo de la funcion que presenta los vertices del grafo
    void imprimirLista(GrafoLista g, ListaG l); // prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
    ListaG eliminarArcos(GrafoLista * g);       // añade arcos => grafos no valorados
    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia
    l = eliminarArcos(&g);
    imprimirLista(g, l);
    cout << endl;
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

ListaG eliminarArcos(GrafoLista *g)
{
    ListaG l;
    int nv = g->getNumVerts();
    string aux;
    cout << "Identificador de vertice a eliminar: ";
    getline(cin, aux);
    Vertice y = g->getVertice(aux);
    int n = y.getNumero();
    g->eliminarArco(y.getNombre());
    nv = g->getNumVerts();
    for (int i = 0; (i < nv); i++)
    {
        if (i != n)
        {
            Vertice x = g->getVertice(i);
            cout << endl<< "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - "<< "GRADO SALIDA: " << g->gradoSalida(i) << " - GRADO ENTRADA: " << g->gradosEntrada(i);

            for (int j = 0; (j < nv); j++)
            {
                if (g->adyacente(i, j))
                {
                    Vertice x = g->getVertice(j);
                    cout << endl
                         << "\t\t--->" << x.getNombre();
                }
            }
            if (g->gradoSalida(i) == 0 || g->gradosEntrada(i) == 0)
            {
                l.insertarAlFinal(x.getNumero());
            }
        }
    }
    return l;
}

void imprimirGrafo(GrafoLista g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    cout << endl
         << "===============================================";
    cout << endl
         << "L I S T A    D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - "
             << "GRADO SALIDA: " << g.gradoSalida(i);

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
    cout << endl
         << "===============================================";
    cout << endl;
}

void imprimirLista(GrafoLista g, ListaG l)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    NodoG *actual; // apunta al nodo actual de la lista
    int y = 0;
    actual = l.getPrimero();
    cout << endl
         << endl
         << "ELEMENTOS CONTENIDOS EN LA LISTA" << endl;
    if (!l.esVacia())
    {
        while (actual != NULL)
        {
            Vertice x = g.getVertice(actual->getDato());
            if (g.gradoSalida(x.getNumero()) == 0)
            {
                cout << "DESAPARECE: ";
            }
            else if (g.gradosEntrada(x.getNumero()) == 0)
            {
                cout << "CRECE DESCONTRALADAMENTE: ";
            }
            cout << x.getNombre() << endl;
            actual = actual->getPunt();
        }
    }
    else
    {
        cout << "Ninguna vertice cumple las condiciones" << endl;
    }
}