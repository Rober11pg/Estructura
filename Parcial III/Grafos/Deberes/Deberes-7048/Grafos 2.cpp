// Determinar los vértices que se encuentran a exactamente N
// arcos de distancia del vértice V (N y V deben ser ingresados por el usuario).
// Autor: Roberto Jiménez-7048
#include "Grafo.h"
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"

int main()
{
	GrafoMatriz g;
	int n;		  // cantidad de vertices a crear

	GrafoMatriz ingresarVertices(int n1);
	void ingresarArcos(GrafoMatriz * g);        // a�ade arcos => grafos valorados
	void imprimirGrafo(GrafoMatriz g);	// prototipo de la funcion que presenta los vertices del grafo
	void distanciaArcos(GrafoMatriz g); // encuentra vertices que se encuentran a N arcos de distancia de un vertice V
	cout << endl<< "CANTIDAD DE VERTICES DEL GRAFO" << endl;
	n = leerN(1, 20); // lectura de cantidad de vertices del grafo
	cin.ignore();

	g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcos(&g);		 // llamado a la funcion que ingresa los arcos del grafo
	imprimirGrafo(g);		 // llamado a la funcion que imprime la matriz de adyacencia
	cout << endl;
	distanciaArcos(g);
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

void distanciaArcos(GrafoMatriz g)	// encuentra vertices que se encuentran a N arcos de distancia de un vertice V
{ // funcion PARA ENCONTRAR LOS CAMINOS DE COSTO MINIMO HASTA VERTICE X
	string aux1;
	int *v1;  // vector de distancias minimas
	int n;
	cout << endl<< "================================================";
	cout << endl<< "Identificador del Vertice Inicio V: ";
	std::getline(cin, aux1);
	cout<<endl<< "Numero de arcos N: ";
	cin >> n;
	cout << endl;
	int v = g.getNumVertice(aux1);
	for (int i = 0; i < g.getNumVerts(); i++)
	{ // recorre todos los vertices del grafo

		if ( v != i)
		{							   // no se calcula el costo minimo desde el mismo vertice x
			CaminoMinimo c(g, v);	   // instancia la clase camino minimo para posibilitar su uso
			c.Dijkstra(g);		   // llama al metodo que aplica alg. Dijkstra
			v1 = c.OdistanciaMinima(); // recibe el vector de distancias minimas desde ese origen
			if (v1[i] == 0xFFFF)
			{ // no se pudo calcular el costo minimo
				cout << "INALCANZABLE"<<endl;
			}
			else
			{
				if (v1[i] == n)
				{
					cout << endl
						 << "Vertice " << g.getVertice(i).getNombre()<<endl;
					cout<<"Arcos: "<<v1[i]<<endl;
				}
			}
		}
	}
}