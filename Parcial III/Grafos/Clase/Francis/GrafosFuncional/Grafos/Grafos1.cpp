//Lo mismo que el anterior pero con listas

using namespace std;
#include <iostream>
#include "Vertice.h"
#include "Global_functions.h"
#include "TDA_lista.h"
#define fin 9999


int main(){
    //
    void leer_vertices(Vertice vv[], int tam, int i=0);
    void Imprimir_vertices(Vertice vv[], int tam, int i=0);


    //
    int n;
    Lista l1;		

    cout<<endl<<"CANTIDAD DE VERTICES A PROCESAR"<<endl; 
    n = Leer_N();

    
    cout<<endl<<"INGRESE LOS VERTICES "<<endl; 
    

    cout<<endl<<"IMPRIMIR LOS VERTICES "<<endl; 
    Imprimir_vertices(vec_ver, n);

    cout<<endl<<"BUSQUEDA EN EL VECTOR"<<endl; 
    Buscar_ver_valor(vec_ver,n);

	cout<<endl;
}


void Ingresar_lista(Lista *lis, ){
    Tipo aux;                       //var de lectura

    cout<<endl<<"Ingrese un valor a aniadir en la lista, finalice con [ "<<fin<<" ] "; cin>>aux;
    if(aux != fin){
        lis->insertarAlFinal(aux);
        Ingresar_lista(lis);
    }
}

void Imprimir_lista(Lista lis){
    Nodo *act;
    act = lis.getPrimero();

    while(act != NULL){
        cout << endl << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}


