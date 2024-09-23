// implementación de la función de un heap minimal
// Autor: Roberto Jiménez -7048
typedef int Clave;
#ifndef _MONTICULO_H
#define _MONTICULO_H

class Monticulo
{
private:
    Clave *v;         // declaración del arreglo dinamico de valores
    int nDatosMax;    // numero maximo de datos a contener en el heap
    int nDatosActual; // numero actual contenidos en el heap

public:                       // métodos publicos
    Monticulo();              // constructor por defecto
    Monticulo(int v);         // constructor conociendo cantidad maxima de datos a almacenar
    void setNDatosMax(int v); // permite actualizar el estado del atributo
    void setNDatosActual(int v);

    int getNDatosMax();
    int getNDatosActual();
};

Monticulo::Monticulo()
{
    setNDatosMax(0);    // crear el monticulo con 0 posibles elementos
    setNDatosActual(0); // crear el monticulo con 0 posibles elementos
}

Monticulo::Monticulo(int v) // constructor conociendo cantidad maxima de datos a almacenar
{
    setNDatosMax(v);
    setNDatosMax(0);
}
void Monticulo::setNDatosMax(int v) // permite actualizar el estado del atributo
{
    nDatosMax = v;
}
void Monticulo::setNDatosActual(int v)
{
    nDatosActual = v;
}
int Monticulo::getNDatosMax()
{
    return nDatosMax;
}
int Monticulo::getNDatosActual()
{
    return nDatosActual;
}

#endif
