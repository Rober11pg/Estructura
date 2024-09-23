/*Determinar el vértice que posee el mayor grado de entrada y el vértice que posee el mayor grado de salida dentro de un grafo ingresado por el usuario.*/
#include "numero.h"
#include "Vertice.h"
#include "GrafoLista.h"
#include <iostream>
#include <string>

using namespace std;

GrafoLista ingresarVertices(int n1);
void ingresarArcos(GrafoLista *g, int b[]);
void gradosES(GrafoLista g, int b[]);
void imprimirGrafo(GrafoLista g);

int main()
{
    system("color 5c");
    GrafoLista g;
    int n, b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20);
    cin.ignore();
    g = ingresarVertices(n);
    ingresarArcos(&g, b);
    system("cls");
    imprimirGrafo(g);
    gradosES(g, b);

    return 0;
}

GrafoLista ingresarVertices(int n1)
{
    string aux;
    GrafoLista a(n1);

    for (int i = 0; (i < n1); i++)
    {
        cout << "Ingrese el nombre del vertice N°. " << (i + 1) << ": " << endl;
        getline(cin, aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g, int b[])
{
    int nv = g->getNumVerts();
    int na;
    string aux;

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g->getVertice(i);
        cout << "Vertice N°. " << x.getNumero() + 1 << " - " << x.getNombre() << " - " << endl;
        cout << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE" << endl;
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << "Identificador del Vertice Destino: " << endl;
            getline(cin, aux);
            g->setArco(x.getNombre(), aux);

            for (int i = 0; i < nv; i++)
            {
                Vertice x = g->getVertice(i);
                string y = x.getNombre();
                if (aux == y)
                {
                    b[i]++;
                }
            }
        }
    }
}

void gradosES(GrafoLista g, int b[])
{
    int max = g.getNumVerts(), a[max], salida, entrada, Mayor = 0;

    for (int i = 0; i < max; i++)
    {
        a[i] = 0;
        Vertice x = g.getVertice(i);
        for (int j = 0; j < max; j++)
        {
            if (g.adyacente(i, j))
            {
                a[i]++;
            }
        }
    }

    for (int i = 0; i < max; i++)
    {
        if (a[i] > Mayor)
        {
            Mayor = a[i];
            salida = i;
        }
    }

    Mayor = 0;
    for (int i = 0; i < max; i++)
    {
        if (b[i] > Mayor)
        {
            Mayor = b[i];
            entrada = i;
        }
    }

    Vertice M = g.getVertice(salida);
    cout << "Vertices No. " << M.getNumero() + 1 << " - " << M.getNombre() << " con " << a[salida] << " grados de salida" << endl;
    Vertice N = g.getVertice(entrada);
    cout << "Vertices No. " << N.getNumero() + 1 << " - " << N.getNombre() << " con " << b[entrada] << " grados de entrada" << endl;
}

void imprimirGrafo(GrafoLista g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl
         << "===============================================";
    cout << endl
         << "L I S T A    D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";

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
