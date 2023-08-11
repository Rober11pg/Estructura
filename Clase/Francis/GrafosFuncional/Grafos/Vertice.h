//Implementar los vertices de un grafo 

#ifndef _VERTICE_H
#define _VERTICE_H

//typedef int Tipo;
typedef string Tipo;

class Vertice{
private:
    Tipo dato;                               //valor contenido en el vertice
    int num;                                //indice o numero asignadp al vertice

public:
    Vertice();                          //crear sin conocer su dato ni numeral
    Vertice(Tipo v);            
    Vertice(Tipo v, int n);


    void setDato(Tipo v);
    void setNum(int v);

    Tipo getDato();
    int getNum();

    bool esIgualDato(Tipo v);
    bool esIgualNum(int n);

};

Vertice::Vertice(){
    setNum(-1);                                 //inicia asignando valor neg. -1 al identificador del vertice 
}
    
Vertice::Vertice(Tipo v){
    setDato(v);
    setNum(-1);
}            

Vertice::Vertice(Tipo v, int n){
    setDato(v);
    setNum(n);
}

void Vertice::setDato(Tipo v){
    dato = v;
}

void Vertice::setNum(int v){
    num = v;
}

Tipo Vertice::getDato(){
    return dato;
}

int Vertice::getNum(){
    return num;
}

bool Vertice::esIgualDato(Tipo v){
    return(getDato() == v);
}

bool Vertice::esIgualNum(int n){
    return(getNum() == n);
}



#endif