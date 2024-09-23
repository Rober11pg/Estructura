using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "utilidades.h"

#define EXT 20
#define SAL 10

int main()
{
    int n;
    ListaG lis[EXT];
    ListaG listaa;
    GrafoLista g;
    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista * g);
    void ImprimirGrafo(GrafoLista g);
    void imprimirGrafoL(ListaG l[], GrafoLista g);
    void SumaLista(ListaG l[], ListaG * l1, GrafoLista g);
    void ImprimirLista(ListaG l1);
    

    n = leerN(1, EXT);
    cin.ignore();

    g = ingresarVertices(n);
    ingresarArcos(&g);
    ImprimirGrafo(g);

    // SumaLista(lis, &listaa, g);
    // cout << "Imprimir Grafo Lista" << endl;
    // imprimirGrafoL(lis, g);
    

    
    return 0;
}

GrafoLista ingresarVertices(int n1)
{
    Tipo aux;
    GrafoLista a(n1);

    for (int i = 0; i < n1; i++)
    {
        cout << endl
             << "Ingrese el Valor del vertice No. " << (i + 1) << ": ";
        cin >> aux;
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g)
{
    int nv = g->getNumVerts();
    int na;
    Tipo aux;

    for (int i = 0; i < nv; i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";
        cout << endl
             << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
        na = leerN(0, SAL);
        cin.ignore();

        for (int j = 0; j < na; j++)
        {
            cout << endl
                 << "Valor del Vertice Destino: ";
            cin >> aux;
            cin.ignore();
            g->setArco(x.getDato(), aux);
        }
    }
}

void ImprimirGrafo(GrafoLista g)
{
    int nv = g.getNumVerts();
    Tipo aux;

    cout << endl
         << "===============================================";
    cout << endl
         << "L I S T A    D E    A D Y A C E N C I A";

    for (int i = 0; i < nv; i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";

        for (int j = 0; j < nv; j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getDato();
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void imprimirGrafoL(ListaG l[], GrafoLista g)
{
    int nv = g.getNumVerts();
    Tipo aux;

    cout << endl
         << "===============================================";
    cout << endl
         << "       V E C T O R     D E     L I S T A S";

    for (int i = 0; i < nv; i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";

        for (int j = 0; j < nv; j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getDato();
                l[i].insertarEnOrden(x.getDato());
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void SumaLista(ListaG l[], ListaG *l1, GrafoLista g) {
    int nv = g.getNumVerts();

    for (int i = 0; i < nv; i++) {
        NodoG *act = l[i].getPrimero(); // Obtener el primer nodo de la lista l[i]
        int suma = 0;

        while (act != NULL) {
            suma += act->getDato(); // Sumar el valor del nodo actual
            act = act->getPunt(); // Avanzar al siguiente nodo
        }

        l1->insertarEnOrden(suma); // Insertar la suma en la lista l1
    }
}


