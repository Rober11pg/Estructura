//Definicion del TDA lista simplemente enlazada
#ifndef _LISTA_H
#define _LISTA_H
using namespace std;
#include "Nodo.h"

class Lista{
private:
    Nodo* primero;              //atributo que almacena la direecion del primer nodo de la lista

public:
    Lista();                    //metodo constructor
    void setPrimero(Nodo* v);   //metodo que actualiza el estado el atributo primero 
    Nodo* getPrimero();         //devuelve el estado del atributo
    bool esVacia();             //metodo que comprueba si la lista es vacia
    void vaciarLista();         //elimina todos los nodos de la lista
    void insertarAlInicio(Tipo v); 
    void insertarAlFinal(Tipo v);
    void insertarEnOrdenAsc(Tipo v);
    void insertarEnOrdenDesc(Tipo v);
    void InsertarSinRep(Tipo v);

    Nodo* buscarElemento(Tipo v);
    bool eliminarNodo(Tipo v);
    Nodo* ultimo();             //metodo que devuelve la direccion del ultimo nodo de la lista

};

Lista::Lista(){
    setPrimero(NULL);           //inicializa el comiendo de la lista
}

void Lista::setPrimero(Nodo* v){
    primero = v;                //actualiza el estado del atributo primero
}

Nodo* Lista::getPrimero(){
    return primero;             //retorna el estado del atributo
} 

bool Lista::esVacia(){
    return (getPrimero() == NULL);
}

void Lista::vaciarLista(){
    setPrimero(NULL);
}

void Lista::insertarAlInicio(Tipo v){
    Nodo* nuevo;                            //direccion de memoria del nuevo nodo a crear
    nuevo = new Nodo(v,getPrimero());       //me da la dirreccion de memoria de nuevo nodo a crear
    setPrimero(nuevo);                      //actualiza el apuntador primero

}

void Lista::insertarAlFinal(Tipo v){
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
    Nodo* ult;                              //aountador al ultimo nodo
//cout << endl << "Direccion 1 de ult: " << ult;
    nuevo = new Nodo(v);                    //crea un nuevo nodo conociendo el valor que va a contener el nuevo valor en el nodo
    
//cout << endl << "Direccion 2 de ult: " << ult;    
    if(esVacia()){                        //es una lista vacia
        setPrimero(nuevo);                  //la lista empieza con el nuevo nodo
    }else{
        ult = ultimo();                         //almacena direccion del ultimo nodo
        ult -> setPunt(nuevo);                  //actualiza direccion apuntada por el anterior ultimo nodo
    }  
}

void Lista::insertarEnOrdenAsc(Tipo v){
    Nodo* nuevo;
    Nodo* act;
    Nodo* ant;
    nuevo = new Nodo(v);

    if(esVacia()){
        setPrimero(nuevo);
    }else{
        ant = act = getPrimero();                  //iniciamos con la direccion apuntada por inicio de lista

        while((act != NULL ) && (act -> getDato()) < v){        //Recorer hasta la posicion anterior a la que el puntero del nodo apunta a NULL
            ant = act;
            act = act->getPunt();
        }
        if(act == ant){
            nuevo -> setPunt(getPrimero());
            setPrimero(nuevo);                          //el nuevo nodo va a ser el nuevo primero de la lista
        
        }else{
            ant -> setPunt(nuevo);
            nuevo -> setPunt(act);
        } 
    }
}

void Lista::insertarEnOrdenDesc(Tipo v){
    Nodo* nuevo;
    Nodo* act;
    Nodo* ant;
    nuevo = new Nodo(v);

    if(esVacia()){
        setPrimero(nuevo);
    }else{
        ant = act = getPrimero();                  //iniciamos con la direccion apuntada por inicio de lista

        while((act != NULL ) && (act -> getDato()) > v){        //Recorer hasta la posicion anterior a la que el puntero del nodo apunta a NULL
            ant = act;
            act = act->getPunt();
        }
        if(act == ant){
            nuevo -> setPunt(getPrimero());
            setPrimero(nuevo);                          //el nuevo nodo va a ser el nuevo primero de la lista
        
        }else{
            ant -> setPunt(nuevo);
            nuevo -> setPunt(act);
        } 
    }
}

void Lista::InsertarSinRep(Tipo v){
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
    Nodo* act;   
    bool ban = false;

    nuevo = new Nodo(v);

    if(esVacia()){
        setPrimero(nuevo);
    }else{
        act = getPrimero();       

        while(act != NULL ) {
            if(act->getDato() == nuevo->getDato()){
                ban= true;
            }
            act= act->getPunt();
        }

        if(ban == false){
            insertarAlInicio(nuevo->getDato());
        }
    }

}


Nodo* Lista::buscarElemento(Tipo v){               //metodo que retorna la direccion de memoria del valor buscado
    Nodo *act;                              //apuntador temporal al nodo
    act = getPrimero();                  //iniciamos con la direccion apuntada por inicio de lista
    
    if(!esVacia()){
        while((act != NULL) && (act -> getDato() != v )){        //Recorer hasta la posicion anterior a la que el puntero del nodo apunta a NULL
            act = act->getPunt();
        }
    }
    return act;                                 //devuelve direccion de memoria del nodo apuntado NULL
}

bool Lista::eliminarNodo(Tipo v){
    Nodo* act;
    Nodo* enc = buscarElemento(v);
    if(enc==NULL){
        return false;
    }
    if (enc == getPrimero()){
        setPrimero(enc -> getPunt());
    }else{
        act = getPrimero();                  //iniciamos con la direccion apuntada por inicio de lista

        while(act -> getPunt() != enc){        //Recorer hasta la posicion anterior a la que el puntero del nodo apunta a NULL
            act = act->getPunt();
        }
        act -> setPunt(enc -> getPunt());    
    }
    return true;
}

Nodo* Lista::ultimo(){
    Nodo *act;                              //apuntador temporal al nodo
    act = getPrimero();                  //iniciamos con la direccion apuntada por inicio de lista
    if(!esVacia()){
        while(act -> getPunt() != NULL){        //Recorer hasta la posicion anterior a la que el puntero del nodo apunta a NULL
        act = act->getPunt();
        }
    }
    return act;                                 //devuelve direccion de memoria del nodo apuntado
}



#endif

