/*Determinar los vértices que se encuentran a exactamente N arcos de distancia del vértice V (n y V deben ser ingresados por el usuario).*/

#include "numero.h"
#include "Vertice.h"
#include "GrafoLista.h"
#include "Cola.h"

//DEFINIR EN NodoG.h int

using namespace std;

GrafoLista ingresarVertices(int n1);
void ingresarArcos(GrafoLista *g);
void Distancia(GrafoLista g, int v, int n);
void imprimirLista(ListaG l);

int main(){
    system("color 5c");
    GrafoLista g;
    int n,c;

    cout<<"CANTIDAD DE VERTICES DEL GRAFO"<<endl;
    n=leerN(1,20);
    cin.ignore();

    g= ingresarVertices(n);
    ingresarArcos(&g);

    cout<<"Distancia: ";
    cin>>c;
    Distancia(g,0,c);
    return 0;
}

GrafoLista ingresarVertices(int n1){
    string aux;
    GrafoLista a(n1);

    for(int i=0; (i<n1);i++){
        cout<<"Ingrese el nombre del vertice N°. "<<(i+1)<<": "<<endl;
        getline(cin,aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g){
    int nv=g->getMaxVerts();
    int na;
    string aux;

    for(int i = 0; (i<nv); i++){
        Vertice x = g -> getVertice(i);
        cout<<"Vertice N°. "<<x.getNumero()+1<<" - "<<x.getNombre()<<" - "<<endl;
        cout<<"CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
        na=leerN(0,10);
        cin.ignore();

        for(int j = 0;(j<na);j++){
            cout<<"Identificador del Vertice Destino: "<<endl;
            getline(cin,aux);
            g->setArco(x.getNombre(),aux);
        }
    }
}

void Distancia(GrafoLista g, int v, int n){
    Cola c;
    ListaG l;
    int w;
    int* distancia;
    distancia = new int[g.getNumVerts()];
    for (int i = 0; i < g.getNumVerts(); i++) {					//inicializa las claves de cada vertice
		distancia[i] = 1;
	}
    distancia[v]=0;
    c.insertar(v);
    while(!c.colaVacia()){
        int wc=c.quitar();
        w=wc;
        for(int u=0; u<g.getNumVerts();u++){
            if(g.getArco(w,u) && distancia[u]==1){
                distancia[u]=distancia[w]+1;
                c.insertar(u);
            }
            if(distancia[u]==n){
              l.insertarAlInicio(u+1); 
            }
        }
    }
    cout<<"Vertices a "<< n<<" distancia"<<endl;
    imprimirLista(l);
}

void imprimirLista(ListaG l){						// funcion que ingresa elementos en nuestra lista
	NodoG* actual;									// apunta al nodo actual de la lista

	actual=l.getPrimero();							// funcion que permite copiar la direccion del primer nodod de la lista
	while(actual!=NULL){							// se repite el ciclo mientras haya nodods en la lista
		cout<<"Vertice: "<<actual->getDato()<<endl;		// visualiza el contenido del nodo actual de la lista
		actual=actual->getPunt();					// el apuntador avanza al siguiente elemento
	}
}