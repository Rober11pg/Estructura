/* Ingresar una lista y modificar sus valores,
sumando a cada uno la cantidad de dígitos que posee
*/

#include <iostream>
using namespace std;
#include "Lista.h"
#define EXT 999
int main()
{
    Lista l;
    void IngresarLista(Lista * l);
    void ImprimirLista(Lista l);
    int DividirDig(Tipo aux);
    void SumaDigLista(Lista * l);
    IngresarLista(&l);
    SumaDigLista(&l);
    cout << "La lista modificada con la suma del valor de sus dígitos " << endl;
    ImprimirLista(l);
    system("pause");
    return 0;
}
void IngresarLista(Lista *l)
{
    Tipo aux;
    cout << "Ingresar un valor. Finalice con [" << EXT << "]" << endl;
    cin >> aux;

    if (aux != EXT)
    {
        l->insertarAlFinal(aux);
        IngresarLista(l);
    }
}
void ImprimirLista(Lista l)
{
    Nodo *act;
    act = l.getPrimero();
    while (act != NULL)
    {
        cout << ">" << act->getDato() << endl;
        act = act->getPunt();
    }
}

int DividirDig(Tipo aux)
{
    int cont = 0;
    while (aux != 0)
    {
        aux /= 10;
        cont++;
    }
    return cont;
}
// 123+3=126
void SumaDigLista(Lista *l)
{
    Nodo *act;
    Tipo aux;
    act = l->getPrimero();
    while (act != NULL)
    {
        aux = act->getDato();
        act->setDatos(aux + DividirDig(aux));
        act = act->getPunt();
    }
}
