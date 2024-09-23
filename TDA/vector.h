/* Definir un TDA vector
   Autor: Roberto Jiménez */

typedef int Tipo; // crear tipo base de datos para el arreglo
#define EXT 10

class vector // definicion de la clase
{
private:
    Tipo v[EXT]; // Declaración del atributo vector
    int numEle;  // numero de elementos ocupados en el vector
public:          // métodos
    vector();    // constructor

    void setV(Tipo val, int pos); // método que actualiza atributo v con valor val en la posicion pos
    void SetElemento(int val);    // método que actualiza

    // método get devuleve el valor, son el mismo tipo de dato del atributo
    // la mayoría de método no necesitan parametros
    Tipo getV(int pos); // método que devuleve el estado v en la posicion pos
    int getNumEle();    // méttodo que devulve el estado val

    // cuando gestiona memoria dinámica de memoria si hay que hacer un destructor, vector de gestión estática de memoria se podría oprimirse el destructor
    ~vector();
};


    vector::vector() { }   

    void vector::setV(Tipo val, int pos){       // método que actualiza atributo v con valor val en la posicion pos
        v[pos] = val;
        
    } 
    void vector::SetElemento(int val){          // método que actualizado
    	numEle = val;
    }    

    // método get devuleve el valor, son el mismo tipo de dato del atributo
    // la mayoría de método no necesitan parametros

    Tipo vector::getV(int pos){  // método que devuleve el estado v en la posicion pos
        return v[pos];

    } 
    int vector::getNumEle(){   // méttodo que devulve el estado val
        return numEle;
    }   

    vector::~vector(){}

    
   








