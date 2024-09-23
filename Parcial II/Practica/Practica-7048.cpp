/*Elaborar un programa recursivo que permita modificar el orden de los elementos de una lista ingresada, 
de forma que los N últimos nodos pasen a ser los primeros.
Autor: Roberto Jiménez-7048*/
#include <iostream>
using namespace std;
#include "Lista.h"
#include "Cola.h"
#include "LeerN.h"
#define FIN 999

int main() {

    int nUltimo, nPrimero;
    Lista lista;
    Cola cola1;
    Cola cola2;

    void ingresarLista(Lista* l);
    void imprimirLista(Lista l);
    void ingresarCola(Nodo* act, Cola* c, int cont, Lista* l);
    void llenarLista(Lista* l, Cola* c, int cont);

    ingresarLista(&lista);
    cout << endl << "Lista original" << endl;
    imprimirLista(lista);

    cout << "Ingrese el numero de elementos que desea pasar como primeros en la lista: ";
    nUltimo = LeerN(1, lista.contarNodos(lista.getPrimero()) - 1);
    nPrimero = lista.contarNodos(lista.getPrimero()) - nUltimo;

    cout << endl << "Lista modificada" << endl;
    ingresarCola(lista.getPrimero(), &cola1, nPrimero, &lista);
    ingresarCola(lista.getPrimero(), &cola2, nUltimo, &lista);
    llenarLista(&lista, &cola2, nUltimo);
    llenarLista(&lista, &cola1, nPrimero);
    imprimirLista(lista);

    cout << endl;
    system("pause");
}

void ingresarLista(Lista* l) {
    Tipo aux;

    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if (aux != FIN) {
        l->insertarAlFinal(aux);
        ingresarLista(l);
    }
}

void imprimirLista(Lista l1) {
    Nodo* act = l1.getPrimero();

    while (act != NULL) {
        cout << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}

void ingresarCola(Nodo* act, Cola* c, int cont, Lista* l) {
    Tipo nod;

    if (cont != 0) {
        nod = act->getDato();
        l->eliminarNodo(nod);
        c->insertar(nod);
        ingresarCola(act->getPunt(), c, cont - 1, l);
    }
}

void llenarLista(Lista* l, Cola* c, int cont) {
    Tipo nn;
    if (cont != 0) {
        nn = c->quitar();
        l->insertarAlFinal(nn);
        llenarLista(l, c, cont - 1);
    }
}
