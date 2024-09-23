// Nodo binario.h
// definicion de la clase que origina a nodos de un arbol binario

#ifndef _NODO_BINARIO_H
#define _NODO_BINARIO_H

#include <iostream>
using namespace std;
typedef int Tipo;
class NodoBinario // definición de la clase
{
private:
    Tipo dato;        // atr para almacena el valor contenido en
    NodoBinario *izq; // atributo para almacenar dirección del subarbol izquierdo
    NodoBinario *der; // atributo para almacenar dirección del subarbol derecho
public:
    NodoBinario();                                       // Contructor
    NodoBinario(Tipo v);                                 // Contructor
    NodoBinario(Tipo v, NodoBinario *i, NodoBinario *d); // Contructor
    // metodos set es frecuenteme de tipo void, que tenga almaenos un parametro

    void setDato(Tipo v);        // metodo que actualizza el estado del atributo dato
    void setIzq(NodoBinario *v); // metodo que actualizza el estado del atributo del nodo der
    void setDer(NodoBinario *v); // metodo que actualizza el estado del atributo del nodo izq

    // metodo get deven tener tipo
    Tipo getDato(); // metodo que devuelve el estado del atributo
    NodoBinario *getIzq();
    NodoBinario *getDer();
};

NodoBinario ::NodoBinario() // Contructor
{
    setIzq(NULL); // incializar los apuntadores
    setDer(NULL); // incializar los apuntadores
}
NodoBinario ::NodoBinario(Tipo v) // Contructor
{
    setDato(v);
    setIzq(NULL); // incializar los apuntadores
    setDer(NULL); // incializar los apuntadores
}

NodoBinario ::NodoBinario(Tipo v, NodoBinario *i, NodoBinario *d) // Contructor
{
    setDato(v);
    setIzq(i);
    setDer(d);
}

// metodos set es frecuenteme de tipo void, que tenga almaenos un parametro

void NodoBinario ::setDato(Tipo v) // metodo que actualizza el estado del atributo dato
{
    dato = v; // almacena el parametro en el atributo
}
void NodoBinario ::setIzq(NodoBinario *v) // metodo que actualizza el estado del atributo del nodo der
{
    izq = v;
}
void NodoBinario ::setDer(NodoBinario *v) // metodo que actualizza el estado del atributo del nodo izq
{
    der = v; // almacena par en el atributo
}

// metodo get deven tener tipo
Tipo NodoBinario ::getDato() // metodo que devuelve el estado del atributo
{
    return dato; // devuelve estado del atribtuo
}
NodoBinario *NodoBinario ::getIzq()
{
    return izq; // devuelve el estado del atri
}
NodoBinario *NodoBinario ::getDer()
{
    return der; // devuelve el estado del atri
}

#endif