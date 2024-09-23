/* Elabore un programa en c++ que permita el ingreso de un grafo, y determine 
si al recorrer sus vértices (tanto en anchura como en prunfundidad) se ecuentran ordenados 
(ascendente o descendentemente)*/

#include "Grafo.h"
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "ListaG.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear

    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista *g);          // añade arcos => grafos no valorados
    void imprimirGrafo(GrafoLista g);            // prototipo de la funcion que presenta los vertices del grafo
    cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia

    // Recorrido en anchura
    RecorreGrafo recorrido;
    int *anchura = recorrido.recorrerAnchuraLa(g, 0); // Recorre en anchura desde el vértice 0

    // Verificar orden en anchura
    bool ascendenteAnchura = true;
    bool descendenteAnchura = true;
    for (int i = 1; i < n; i++) {
        if (anchura[i] < anchura[i-1]) {
            ascendenteAnchura = false;
        }
        if (anchura[i] > anchura[i-1]) {
            descendenteAnchura = false;
        }
    }

    // Recorrido en profundidad
    int *profundidad = recorrido.recorrerProfLa(g, 0); // Recorre en profundidad desde el vértice 0

    // Verificar orden en profundidad
    bool ascendenteProfundidad = true;
    bool descendenteProfundidad = true;
    for (int i = 1; i < n; i++) {
        if (profundidad[i] < profundidad[i-1]) {
            ascendenteProfundidad = false;
        }
        if (profundidad[i] > profundidad[i-1]) {
            descendenteProfundidad = false;
        }
    }

    // Mostrar resultados
    cout << endl;
    if (ascendenteAnchura || descendenteAnchura) {
        cout << "El recorrido en anchura ";
        if (ascendenteAnchura) {
            cout << "es ascendente." << endl;
        } else {
            cout << "es descendente." << endl;
        }
    } else {
        cout << "El recorrido en anchura no está ordenado." << endl;
    }

    if (ascendenteProfundidad || descendenteProfundidad) {
        cout << "El recorrido en profundidad ";
        if (ascendenteProfundidad) {
            cout << "es ascendente." << endl;
        } else {
            cout << "es descendente." << endl;
        }
    } else {
        cout << "El recorrido en profundidad no está ordenado." << endl;
    }

    delete[] anchura;
    delete[] profundidad;

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


