#include "numero.h"
#include "Lista.h"
#include "GrafoMatriz.h"

using namespace std;

GrafoMatriz ingresarVertices(int n1);
void ingresarArcos(GrafoMatriz *g,int b[]);		
void imprimirGrafo(GrafoMatriz g);			
void imprimirLista(Lista l);					
void ecosistema(GrafoMatriz g,int b[],Lista *l);
	

int main(){
    GrafoMatriz g;
    int n, b[10]={0,0,0,0,0,0,0,0,0,0};
    Lista l;
    n = leerN(1,20);					
	cin.ignore();

    g = ingresarVertices(n);				
	ingresarArcos(&g,b);				
	system("cls");
	imprimirGrafo(g);					
	ecosistema(g,b,&l);
	imprimirLista(l);
}

GrafoMatriz ingresarVertices(int n1){				//funcion que ingresa los datos de los v?rtices de un grafo
	string aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre de la especie No. " << (i+1) << ": ";
		getline(cin, aux);
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoMatriz *g, int b[]){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	string aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getNombre(), aux);

            for(int k = 0;(k < nv); k++){
                Vertice y = g->getVertice(k);
                string p = y.getNombre();
                if(aux == p){
                    b[k]++;
                }
            }
		}
	}
}

void imprimirLista(Lista l){						// funcion que ingresa elementos en nuestra lista
	Nodo* actual;									// apunta al nodo actual de la lista
	
	cout<<"\n\nEspecies que si desaparecen rompen el ecosistema: \n"<<endl;
	actual=l.getPrimero();							// funcion que permite copiar la direccion del primer nodod de la lista
	while(actual!=NULL){							// se repite el ciclo mientras haya nodods en la lista
		cout<<"> "<<actual->getDato()<<endl;		// visualiza el contenido del nodo actual de la lista
		actual=actual->getPunt();					// el apuntador avanza al siguiente elemento
	}
}

void imprimirGrafo(GrafoMatriz g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
	string aux;
	cout << endl << "===============================================";
	cout << endl << "M A T R I Z     D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getNombre();
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

void ecosistema(GrafoMatriz g, int b[], Lista* l){
    int max = g.getNumVerts();
    int a[max];

    for (int i = 0; (i < max); i++){							// Recorrido a traves de todos los vertices del grafo
		Vertice x = g.getVertice(i);						// asignacion del vertice
		a[i]=0;											// inicializacion del contador
		for (int j = 0; (j < max); j++){						// Recorrido para saber la cantidad de vertices adyacentes
			if (g.adyacente(i,j)){							// comprobacion de si el vertice es adyacente
				a[i]++;									// aumenta seguna la cantidad de vertices adyacentes
			}
		}
	}

    for(int i=0; i< max; i++){
        if(a[i]==1 & b[i]==1){
            Vertice e = g.getVertice(i);
            l->insertarAlFinal(e.getNombre());
        }
    }

}