// Determinar el vértice que posee el mayor grado de entrada y el vértice
// que posee el mayor grado de salida dentro de un grafo ingresado por el usuario.
// Autor: Roberto Jiménez-7048
#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear

    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista * g);          // añade arcos => grafos no valorados
    void imprimirGrafo(GrafoLista g);            // prototipo de la funcion que presenta los vertices del grafo
    void verticeMayorEntrada(GrafoLista g);      // prototipo de función que permite encontrar el vertice con mayor grado de entrada
    void verticeMayorSalida(GrafoLista g);       // prototipo de funcion que permite encontrar el vertice con mayor grado de salida
    bool comprobarIgualdad(GrafoLista g, int x); // prototipo de funcion que comprueba si todos los vertices tienen el mismo grado de entrada o salida
    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia
    cout << endl;
    verticeMayorEntrada(g);
    verticeMayorSalida(g);
    cout << endl;
    system("pause"/);
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
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";
        cout << endl
             << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE" << endl;
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << endl
                 << "Identificador del Vertice Destino: ";
            getline(cin, aux);
            g->setArco(x.getNombre(), aux);
        }
    }
}

void imprimirGrafo(GrafoLista g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl
         << "===============================================";
    cout << endl<< "LISTA DE ADYACENCIA";

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
    cout << endl<< "===============================================";
    cout << endl;
}

bool comprobarIgualdad(GrafoLista g, int x) // prototipo de funcion que comprueba si todos los vertices tienen el mismo grado de entrada o salida
{
    int nv = g.getNumVerts(),
        cont = 0, y = 0;
    switch (x)
    {
    case 1:
        y = g.gradosEntrada(0);
        for (int i = 1; i < nv; i++)
        {
            if (g.gradosEntrada(i) == y)
            {
                cont++;
            }
        }
        if (cont == nv - 1)
            return true;
        break;
    case 2:
        y = g.gradoSalida(0);
        for (int i = 1; i < nv; i++)
        {
            if (g.gradoSalida(i) == y)
            {
                cont++;
            }
        }
        if (cont == nv - 1)
            return true;
    }
}

void verticeMayorEntrada(GrafoLista g) // prototipo de función que permite encontrar el vertice con mayor grado de entrada
{
    if(!comprobarIgualdad(g,1))
    {
        int nv = g.getNumVerts();
        Vertice x;
        ListaG l, m;

        for (int i = 0; (i < nv); i++)
        {
            l.insertarEnOrden(g.gradosEntrada(i));
        }
        cout << "VERTICE CON MAYOR GRADO DE ENTRADA: ";

        NodoG *actual;
        actual = l.getPrimero();
        while (actual != NULL)
        {
            m.insertarAlInicio(actual->getDato());
            actual = actual->getPunt();
        }
        for (int i = 0; i < nv; i++)
        {
            if (g.gradosEntrada(i) == m.getPrimero()->getDato())
            {
                x = g.getVertice(i);
            }
        }
        cout << endl << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << endl;
    }else{
        cout<<"Los vertices tienen la misma cantidad de grados de entrada"<<endl;
    }
}
void verticeMayorSalida(GrafoLista g) // prototipo de funcion que permite encontrar el vertice con mayor grado de salida
{
    if(!comprobarIgualdad(g,2))
    {
        int nv = g.getNumVerts();
        Vertice x;
        ListaG l, m;

        for (int i = 0; (i < nv); i++)
        {
            l.insertarEnOrden(g.gradoSalida(i));
        }
        cout << "VERTICE CON MAYOR GRADO DE ENTRADA: ";

        NodoG *actual;
        actual = l.getPrimero();
        while (actual != NULL)
        {
            m.insertarAlInicio(actual->getDato());
            actual = actual->getPunt();
        }
        for (int i = 0; i < nv; i++)
        {
            if (g.gradoSalida(i) == m.getPrimero()->getDato())
            {
                x = g.getVertice(i);
            }
        }
        cout << endl << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << endl;
    }else{
        cout<<"Los vertices tienen la misma cantidad de grados de salida"<<endl;
    }
}