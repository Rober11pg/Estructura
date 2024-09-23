// Definición de la clase que origina cada elemento de una lista simple

#ifndef _NODO_H
#define _NODO_H // evitar duplicaciones de clases 
using namespace std;
#include <iostream>
typedef int Tipo; // cuales setran los valores que se van almacenar 

class Nodo
{
private:                   // definición de la clase
    Tipo dato;             // atributo para contener el valor almacenar
    Nodo *punt;            //  atributo para apuntar al siguiente nodo o tabla 
public:                    // metodos publicos
// sobrecarga de métodos, da la posibilidad de tener distintas versiones de una mismo método hay 3 maneras de crear un nodo 
    Nodo();                // metodo constructor // nodo vacío
    Nodo(Tipo v);          // constructor recibiendo un dato como parametro // conociendo su valor 
    Nodo(Tipo v, Nodo *p); // recibiendo como parametro y el puntero // conociendo su valor y a donde queremos que apunte 
    void setDatos(Tipo v); // metodo para actualizar estado del atributo
    Tipo getDato();        // metood para devolver el estado del atributo
    void setPunt(Nodo *v); // metodo para actualizar estado del atributo
    Nodo *getPunt();       // metood para devolver el estado del atributo
};

Nodo ::Nodo()
{
    // inicializar el valor del apuntador
    setPunt(NULL); // nodos nuevo apuntan a
}

Nodo ::Nodo(Tipo v)
{
    setDatos(v);   // nuevo nodo almacena valor recibido
    setPunt(NULL); // nodos nuevos apuntan a nu
}
Nodo::Nodo(Tipo v, Nodo* p)
{
    /*En otras palabras, este constructor crea un nuevo nodo con un valor inicial
     y lo enlaza al nodo cuya dirección de memoria se proporciona como argumento,
      formando así una conexión en la lista enlazada.*/
      
    setDatos(v);
    setPunt(p);
}
void Nodo ::setDatos(Tipo v)
{
    dato = v; // se actualiza el atributo
}

Tipo Nodo ::getDato()
{
    return dato;
}
void Nodo ::setPunt(Nodo *v)
{
    punt = v; // acutaliza el estado devolver puntero// nodo *v pasa de dirección de memoria de otro nodo como argumento, estable conexión entre dos nodos en una lista 
}
Nodo *Nodo::getPunt()
{
    return punt; // devuelve estado del atributo
}
#endif