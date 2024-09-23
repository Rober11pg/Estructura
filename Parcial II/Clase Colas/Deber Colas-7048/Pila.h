// TDA pilas
// precaucion de crear un archivo de cabecera
// Roberto Jiménez-7048
typedef int Tipo; // definicion del tipo de datos a almacenar
#define EXT 20    // extencion por defecto de la pila
class Pilas       // defincion de la clase
{
private:
    // datos, atributos
    Tipo vec[EXT]; // areglo para almacenar los datos de la pila
    int top;       // posicion que ocupa el elementos de la cima del vector

public:                           // metodos
    Pilas();                      // contructor
    void setVec(Tipo v, int pos); // definicion del metodo que actualiza el estado del atibuto vec en la pos
    void setTop(int v);           // defincion del metodo que actualiza el estado del atributo top

    // tipo
    Tipo getVec(int pos); // definicion del metodo que devuelve el estado del atributo vect en la posicion pos
    int getTop();         // definicion del metedo que devuelve el estado del atributo top
    bool pilaVacia();     // definicion del metodo que determina si la pila está vacia
    bool pilaLlena();     // definicion del metodo que determina si la pila está llena
    void push(Tipo v);    // fefinicion del metodo que inserta un elemento en la pila
    Tipo pop();           // la definicion del metodo que extrae un elemento de la pila

    // metodo que quede vacia la pila
    void vaciarPila(); // definicion del metodo que vacia una pila
    int tamanioPila(); // definicion del metodo que calcula la cantidad de elementos que contiene la pila
    Tipo cimaPila();   // Definicion del metodo que devuelve el valor que ocupa la posicion cima de la pila (no lo elimina)
};

Pilas ::Pilas()
{
    setTop(-1); // iniciaaliza la pila guardando como posicion del elemento cima el valor -1
}
void Pilas::setVec(Tipo v, int pos)
{
    vec[pos] = v;
}
void Pilas ::setTop(int v)
{
    top = v;
}
// tipo
Tipo Pilas ::getVec(int pos)
{
    return vec[pos];
}
int Pilas ::getTop()
{
    return top;
}

bool Pilas ::pilaVacia()
{
    return (getTop() == -1); // devuelve verdader si top conversa el valor original -1
}

bool Pilas ::pilaLlena()
{
    return (getTop() == EXT - 1); // devuelve verdadero si el top tiene el valor EXT-1
}

void Pilas ::push(Tipo v) // insertar elemento
{
    if (!pilaLlena())
    {                         // Aun hay espacio en la pila
        setTop(getTop() + 1); // incrementa posicion de top
        setVec(v, getTop());  // guarda el valor v en la posicionw
    }
}

Tipo Pilas ::pop() // devuelve elemento
{
    Tipo aux; // variable para almacenar valor de la pos que ocupa top
    if (!pilaVacia())
    {                           // pila tiene elementos
        aux = getVec(getTop()); // almacena temporalemente el valor a devolver
        setTop(getTop() - 1);   // decrementa posicion de tipo
        return aux;             // devolver el valor
    }
    return pilaLlena();
}

void Pilas ::vaciarPila()
{
    setTop(-1); // altera el valor de la cima de la pila
}

int Pilas ::tamanioPila()
{
    return getTop() + 1; // se pone -1 +1 la posicion empezaria en 0 para decirle su posicion
}

int Pilas ::cimaPila()
{
    Tipo aux; // variable para almacenar valor de la pos que ocupa top
    if (!pilaVacia())
    {                           // pila tiene elementos
        aux = getVec(getTop()); // almacena temporalemente el valor a devolver
        return aux;             // devolver el valor
    }
}