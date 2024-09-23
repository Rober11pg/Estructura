// cola.h
// Definicion del TDA Cola
// LAS CONSTANTES SE USAN CON LETRAS MAYUSCULAS
#ifndef _COLA_H // if condición - n not - def definalo si no esta definido definalo
#define _COLA_H

typedef int Tipo; // Definir el tipo de datos del TDA
#define EXT 20    // cantidad maxima de elementos del TDA

class Cola // definicion del TDA
{
private:           // declaración de atributos
    Tipo vec[EXT]; // declaración del atributo contenedor de datos
    int frente;    // declarar el atributo que contiene la posicion del elemento a extraer
    int final;     // declración del atributo que contiene la posicion del elemento a insertar

protected:
    void setVec(Tipo v, int pos); // declaracion del método que actualiza el estado de un elemento del TDA
    void setFrente(int v);        // declaracion del método  que actualiza el estado del atributo frente
    void setFinal(int v);         // declaracion del método  que actualiza el estado del atributo final

    Tipo getVec(int pos); // declaracion del método que devuelve el estado de un elemento del TDA
    int getFrente();      // declaracion del método  que devuelve el estado del atributo frente
    int getFinal();       // declaracion del método  que devuelve el estado del atributo final
public:                   // metodos
    Cola();               // Constructor

    void borrarCola();     // declaración del metodo que reinicializa el método o el TDA (quita todos los elementos)
    bool colaVacia();      // Declaración del metodo que determina si el TDA carece de elementos (determina si está vacia la cola)
    bool colaLlena();      // Declaración del metodo que determina si el TDA no posee capacidad para insertar nuevos elementos
    int tamanioCola();     // declaracion del metodo que determina la cantidad de elementos contenidos en el TDA
    Tipo quitar();         // declaracion del metodo que permite quitar un elemento de getfinal y reducir su tamaño
    void insertar(Tipo v); // inserta un elemento nuevo en el TDA
    Tipo frentecola();     // metodo obtenido que devuelve el elemento frente
};

Cola ::Cola() // constructor
{
    setFinal(-1); // indica de carencia de elementos (vector vacio)
    setFrente(0); // Indicador de la posicion del primer elemento a extrae del TDA
}
void Cola ::setVec(Tipo v, int pos)
{
    vec[pos] = v; // almance el valor v en la posicion pos
}
void Cola ::setFrente(int v)
{
    frente = v; // alamacena el valor v en atributo frente
}
void Cola ::setFinal(int v)
{
    final = v; // alamacena el valor v en atributo final
}

Tipo Cola ::getVec(int pos)
{
    return vec[pos]; // devuelve valor contenido por el TDA en la posicion pos
}
int Cola ::getFrente()
{
    return frente; // devuelve el valor contenido en el atributo frente
}
int Cola ::getFinal()
{
    return final; // devuelve el valor contendio en el atributo final
}

void Cola ::borrarCola()
{
    setFinal(-1); // indica de carencia de elementos (vector vacio)
    setFrente(0); // Indicador de la posicion del primer elemento a extrae del TDA
}

bool Cola ::colaVacia()
{
    return (getFinal() < getFrente()); // verifica que atributo final este situado antes del atributo frente
}

bool Cola ::colaLlena()
{
    return (getFinal() == (EXT - 1)); // verifica que atributo final este situado a la ultima ubicacion posible dentro del vector (ya no hay espacio)
}

int Cola ::tamanioCola()
{
    return (getFinal() - getFrente() + 1); // calcula la cantidad de elementos contenidos en el TDA
}

Tipo Cola ::quitar()
{
    Tipo aux; // var que contiene el valor a extrer del TDA
    if (!colaVacia())
    {
        aux = getVec(getFrente());  // devuelve elemento del vector getVec // getFrente devuelve un valor de la posicion vec   // copiar el contenido del vector a aux
        setFrente(getFrente() + 1); // modifca el atributo frente para que se refiera al siguiente valor del vector
    }
    return aux; // devolver respuesta
}

void Cola ::insertar(Tipo v)
{
    if (!colaLlena()) // Aun hay espacios dispibles en TDA
    {
        setFinal(getFinal() + 1); // incrementa la ubicación del atributo final
        setVec(v, getFinal());    // almacena el nuevo valor en la posicion referida por final
    }
}

Tipo Cola ::frentecola()
{
    Tipo aux; // var que contiene el valor a extrer del TDA
    if (!colaVacia())
    {
        aux = getVec(getFrente()); // devuelve elemento del vector getVec // getFrente devuelve un valor de la posicion vec   // copiar el contenido del vector a aux
    }
    return aux; // devolver respuesta
}

#endif