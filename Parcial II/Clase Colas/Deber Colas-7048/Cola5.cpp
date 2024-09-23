/* 5. Encontrar la unión entre varias TDA colas ingresada
Autor: Roberto Jiménez-7048*/

#include <iostream>
#include "Cola.h"
#define FIN 9999
using namespace std;

int main()
{
    system("color f0");
    int cantidadColas; // ingreso de cantidad de colas que desea ingresar
    Cola unionColas;
    void leerCola(Cola * c);
    void imprimirCola(Cola c);
    void IngresoColas(Cola * Colas, int cantColas);
    void ImpresionColas(Cola * Colas, int cantColas);
    void UnionColas(Cola * unionColas, int cantColas, Cola *Colas);
    cout << "Ingrese la cantidad de colas: ";
    cin >> cantidadColas;

    Cola *colas = new Cola[cantidadColas]; // crea un arreglo dinámico
    IngresoColas(colas, cantidadColas);
    ImpresionColas(colas, cantidadColas);
    UnionColas(&unionColas, cantidadColas, colas);

    cout << "La union de los elementos de todas las colas" << endl;
    cout << "***********************************" << endl;
    imprimirCola(unionColas);
    cout << endl;

    system("pause");
    return 0;
}

void leerCola(Cola *c1)
{
    Tipo x;
    cout << "Ingrese el valor a insertar. Finalice con [" << FIN << "]" << endl;
    cin >> x;
    if (x != FIN)
    {
        if (!c1->colaLlena())
        {
            c1->insertar(x);
            leerCola(c1);
        }
        else
        {
            cout << "ERROR... Estructura sin espacio de almacenamiento..." << endl;
        }
    }
}


void imprimirCola(Cola c)
{
    while (!c.colaVacia())
    {
        cout << "> " << c.quitar() << endl;
    }
}

void IngresoColas(Cola *Colas, int cantColas)
{
    for (int i = 0; i < cantColas; i++)
    {
        cout << "Ingresar elementos en la cola " << i + 1 << endl;
        leerCola(&Colas[i]); // llama a la método Leer cola para ingresar los elementos, una vez terminada la primera cola llama a la otra si ingresa mas de una cola
    }
}

void ImpresionColas(Cola *Colas, int cantColas)
{
    for (int i = 0; i < cantColas; i++)
    {
        cout << "Elementos contenidos en la cola " << i + 1 << endl;
        cout << "***********************************" << endl;
        imprimirCola(Colas[i]); // llama al método imprimirCola y luego imprime los elementos de la cola 0, y si exite mas instancias de las colas  haría las demás
        cout << endl;
    }
}
void UnionColas(Cola *unionColas, int cantColas, Cola *Colas)
{
    for (int i = 0; i < cantColas; i++)
    {
        while (!Colas[i].colaVacia())
        {
            unionColas->insertar(Colas[i].quitar());
        }
    }
}