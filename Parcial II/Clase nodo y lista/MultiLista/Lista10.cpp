//Programa que permita ingresar los elementos sin repeticion en una lista y obtener el MCD del primer y ultimo dato de sus respectivos nodos.
 
#include <iostream>
using namespace std;
#include "Lista.h"
 
#define FIN 9999      
 
int main(){
 
    Lista l1, l2, l3;                          
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    int Proceso_mcd(int a,int b);
    int MCD(int a, int b);
    //
   
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);
    imprimirLista(l1.getPrimero());
    Nodo* ult = l1.ultimo();
    Nodo* prim = l1.getPrimero();
    cout<<endl<<"El MCD( "<< prim->getDato()<<" y "<<ult->getDato()<<" ) es: "<<MCD(prim->getDato() ,ult->getDato())<<endl;
    cout << endl;
}
 
void imprimirLista(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act-> getDato() << endl;
        act = act-> getPunt();
        imprimirLista(act);
    }
}
 
void ingresarLista(Lista* l){
    //
    void InsertarSinRep(int v, Lista *l);
    //
    Tipo aux;          
   
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;
 
    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento a la lista
        // l->insertarAlFinal(aux);
        InsertarSinRep(aux, *&l);
        ingresarLista(l);
    }
}
 
void Esta_ele_lista(Nodo* act, Nodo* nuevo, bool *ban){
    if(act != NULL ) {
        if(act->getDato() == nuevo->getDato()){
            *ban= true;
        }
        Esta_ele_lista(act->getPunt(), nuevo, ban);
    }
}
 
void InsertarSinRep(int v, Lista *l){
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
    Nodo* act;  
    bool ban = false;
    nuevo = new Nodo(v);
    if(l->esVacia()){
        l->setPrimero(nuevo);
    }else{
        act = l->getPrimero();  
        Esta_ele_lista(act, nuevo, &ban);
        if(ban == false){
            l->insertarAlInicio(nuevo->getDato());          //actua como pila LIFO
            // l->insertarAlFinal(nuevo->getDato());            //actua como cola FIFO
        }
    }
}
 
int Proceso_mcd(int a,int b){               //MCD CON ALGORITMO DE EUCLIDES
    if(b == 0) return a;
    return Proceso_mcd(b, a%b);
}
 
int MCD(int a, int b){
    if(b > a) return Proceso_mcd(b,a);
    else return Proceso_mcd(a,b);
}