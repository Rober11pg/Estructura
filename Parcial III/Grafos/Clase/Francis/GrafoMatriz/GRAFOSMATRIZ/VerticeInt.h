//Vertice.h


#ifndef _VERTICE_H
#define _VERTICE_H

typedef int Tipo;
class Vertice{
private:
    Tipo dato;      //atr que almacena el valor contenido en el Vertice
    int num;        //atr que contiene el numero asignado al vertice

public:
    Vertice();
    Vertice(Tipo v);
    Vertice(Tipo v, int p);
    void setDato(Tipo v);
    void setNum(int v);
    Tipo getDato();
    int getNum();
    bool esIgualDato(Tipo v);
    bool esIgualNum(int p);
};
    Vertice::Vertice(){
        setNum(-1);

    }
    Vertice::Vertice(Tipo v){
        setDato(v);
        setNum(-1);

    }
    Vertice::Vertice(Tipo v,int p){
        setDato(v);
        setNum(p);

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
        return (getDato() == v);
    }
    bool Vertice::esIgualNum(int p){
        return (getNum() == p);
    }


#endif