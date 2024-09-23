// tablaDispersion.h
//  impleta el tda tabla de dispersión
//  se tuviese que incorporar 2 veces el archivos de cabecera, triplemene o doblemete se puede generar una colisión de error
#ifndef _TABLADISPERSION_H
#define _TALBADISPERSION_H

typedef int Tipo; // declara sus elementos de tipo tipo

class TablaDispersion // definicion del TDA
{
private: // elementos propios internos de la clase
    // la tabla es un vector
    Tipo *tabla; // se hace dinamicamente para definir un arreglo dinamico // tabla dinamica de datos
    int nMax;    // numero máximo de elementos de la tabla
    int nAct;    // numero actual de elementos de la tabla

public:                     // Metodos, contructores, destructores // elementos visibles externamente a la clase
    TablaDispersion();      // metodo constructor por defecto
    TablaDispersion(int v); // metodo constructuor conociendo cantidad de elementos

    // set actualizar estados de los objetos // actualizar el estado del atributo no devuelve tipo de respuesta

    void setTabla(Tipo v, int pos); // metodo que actualiza la posicion pos de la tabla dispersion
    void setnMax(int v);            // metodo que actualiza el estado del atributo
    void setnAct(int v);            // metodo que actualiza el estado del atributo

    // get devolver los estados de los objetos
    Tipo getTabla(int pos);         // metodo que devuelve de la tabla en la posicion pos
    int getnMax();                  // metodo que devuelve estado del atributo
    int getnAct();                  // metodo que devuelve estado del atributo
    void insetar(Tipo v)            // metodo que incorpora un número dentro de la tabla
        Tipo buscar(Tipo v);        // metodo que instrumenta la operacion de busqueda de un valor dentro de la tabla
    void eleminar(Tipo v);          // metodo que instrumenta la operacion de eliminación de un valor de la tabla
    int transformarClave(chat c[]); // transforma la clave de acceso en una valor númerico
    int dispersionModular(int v);   // metodo que calcula valor de dispersion de v aplicación modulos
    int dispersionPlegamiento(int v);
    int dispersionMitadCuadrado(int v);   // metodo que calcula valor de dispersion de v aplicación
    int dispersionMultiplicacion(int v);  // metodo que calcula valor de dispersion de v aplicación
    int direccion(char *clave);           // metodo que calcula direccion de un valor dentro de tabla aplicando busqueda lineal
    int direccionCuadratica(char *clave); // metodo que calcula direccion de un valor dentro de tabla aplicando busqueda cuadratica
    // exploracion de listas falta
};

TablaDispersion::TablaDispersion()
{
    setnMax(0); // actualiza numero maximo de elementos en la tabla
    setnAct(0); // actualiza numero actual de elementos en la tabla
}
TablaDispersion::TablaDispersion(int v)
{
    int val;
    val = int(v / (0.8));        // calculo de numero maximo de elemetos considerando el factor de carga 0.8
    setnMax(val);                  // actualiza numero maximo de elementos en la tabla
    setnAct(0);                  // actualiza numero actual de elementos en la tabla
    tabla = new Tipo[getnMax()]; // crear nuevos valores dinamicamente
}
void TablaDispersion::setTabla(Tipo v, int pos) // metodo que actualiza la posicion pos de la tabla dispersion
{
}
void TablaDispersion::setnMax(int v) // metodo que actualiza el estado del atributo
{
}
void TablaDispersion::setnAct(int v) // metodo que actualiza el estado del atributo
{
}
// get devolver los estados de los objetos
Tipo TablaDispersion::getTabla(int pos) // metodo que devuelve de la tabla en la posicion pos
{
}
int TablaDispersion::setnMax() // metodo que devuelve estado del atributo
{
}
#endif