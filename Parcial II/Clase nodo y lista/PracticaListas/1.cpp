/*Encontrar el rango de una lista de valores ingresados*/
#include<iostream>
#include"Lista.h"
using namespace std;
#define EXT 999
int main()
{
    Lista l;
    Tipo rg= 0;
    void IngresarListaOrden(Lista *l);
    void ImprimirLista(Lista l);
    int RangoLista(Lista l);
    IngresarListaOrden(&l);
    rg = RangoLista(l);
    ImprimirLista(l);
    

    cout <<"El rango de la lista de los valores ingresados es: "<< rg <<endl;
    system("pause");
    return 0;
}

void IngresarListaOrden(Lista *l)
{
    Tipo aux;
    cout<<"Ingrese un número. Finalice con [" << EXT << "]"<<endl;
    cin>>aux;

    if(aux != EXT)
    {
        l->insertarEnOrden(aux); // inserta en orden en la lista
        IngresarListaOrden(l); // llamado recursivo hasta que ingrese EXT
    }

}

void ImprimirLista(Lista l)
{
    Nodo *act;
    act = l.getPrimero();
    while (act != NULL)
    {
        cout<<"> "<< act->getDato() << endl;
        act = act->getPunt();
    }
}

int RangoLista(Lista l)
{
    Tipo min, max;
    Nodo *act;

    act = l.getPrimero();
    min = act->getDato();
    max = min; // Establecer el primer valor como máximo y mínimo inicialmente

    while (act != NULL)
    {
        Tipo dato = act->getDato();
        if(dato < min)
        { 
            min = dato;
        }
        else
        {
            max = dato;
        }
        act = act->getPunt();
    }

    int rango = max - min;
    return rango;
}