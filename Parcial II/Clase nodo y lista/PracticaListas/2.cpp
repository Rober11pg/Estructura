/*Formar una lista con los valores pares y otra con valores impares
 de una lista ingresada*/

#include<iostream>
using namespace std;
#include"Lista.h"
#define EXT 999
int main()
{   Lista l;
    Lista p;
    Lista i;
    void IngresarLista(Lista *l);
    void ImprimirLista(Lista l);
    void ListaParImpar(Nodo *act, Lista *i, Lista *p);

    IngresarLista(&l);
    ListaParImpar(l.getPrimero(),  &p, &i);
    cout<<"Lista de los valores impares"<<endl;
    ImprimirLista(i);
    cout<<"Lista de los valores pares "<<endl;
    ImprimirLista(p);
    system("pause");
}

void IngresarLista(Lista *l)
{
    Tipo aux;
    cout<<"Ingrse un valor. Finalice con ["<< EXT << "]" <<endl;
    cin>> aux;
    if(aux != EXT)
    {
        l->insertarAlInicio(aux);
        IngresarLista(l);
    }
}

void ImprimirLista(Lista l)
{
    Nodo *act;

    act = l.getPrimero();
    while (act != NULL)
    {
        cout<<"> " << act->getDato() << endl;
        act = act->getPunt();
    }  
}

void ListaParImpar(Nodo *act, Lista *i, Lista *p)
{

    if(act != NULL)
    {
       Tipo dato = act->getDato();
        if(act->getDato() % 2 == 0)
        {
            
            i->insertarAlFinal(dato);
        }
        else if(act->getDato() % 2 == 1)
        {
            p->insertarAlFinal(dato);
        }
        ListaParImpar(act->getPunt(), i, p);
    }
}