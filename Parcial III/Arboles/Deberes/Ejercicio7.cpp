/* 7/ Calcular el ABB resultante de la unión de 2 ABB originales, previamente ingresados
Nombre: Roberto Jiménez-7048 */
#include <iostream>
#include "ArbolBinario.h"
using namespace std;
const int MAX_VALORES = 100;
int main()
{
    system("color f0");

    int valores[MAX_VALORES];
    int tamano;
    void recorridoEnOrden(NodoBinario * nodo, Tipo * valores, int &index);
    void generarABB(Tipo valores[], int tamano, int indice, ArbolBinario &a);
    void generarTodosABB(int valores[], int tamano);
    void unirABBs(ArbolBinario & abb1, ArbolBinario & abb2);
    cout << "Ingrese la cantidad de valores: ";
    cin >> tamano;

    cout << "Ingrese los valores:" << endl;
    for (int i = 0; i < tamano; i++)
    {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];
    }

    cout << "Generando todos los ABB posibles..." << endl;
    generarTodosABB(valores, tamano);

    // Crear los dos ABB originales previamente ingresados
    ArbolBinario abb1, abb2;
    cout << "Ingrese los valores del primer ABB:" << endl;
    for (int i = 0; i < tamano; i++)
    {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];
        abb1.insertarNodo(valores[i]);
    }

    cout << "Ingrese los valores del segundo ABB:" << endl;
    for (int i = 0; i < tamano; i++)
    {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];
        abb2.insertarNodo(valores[i]);
    }

    cout << "Uniendo los dos ABB originales..." << endl;
    unirABBs(abb1, abb2);

    cout << "ABB resultante de la unión:" << endl;
    abb2.imprimirABSimple(abb2.getRaiz());

    cout << endl;
    system("pause");
    return 0;
}
// ============
void recorridoEnOrden(NodoBinario *nodo, Tipo *valores, int &index)
{
    if (nodo == nullptr)
    {
        return;
    }
    recorridoEnOrden(nodo->getIzq(), valores, index);
    valores[index++] = nodo->getDato();
    recorridoEnOrden(nodo->getDer(), valores, index);
}

void generarABB(Tipo valores[], int tamano, int indice, ArbolBinario &a)
{
    if (indice >= tamano)
    {
        // Se han considerado todos los valores, imprimir el ABB generado
        cout << "ABB generado:" << endl;
        a.imprimirABSimple(a.getRaiz());
        cout << endl;
        return;
    }

    // Generar el ABB insertando el valor actual
    a.insertarNodo(valores[indice]);
    generarABB(valores, tamano, indice + 1, a);
    a.eliminarNodo(valores[indice]); // Eliminar el valor insertado para probar la otra opción

    // Generar el ABB sin insertar el valor actual
    generarABB(valores, tamano, indice + 1, a);
}

void generarTodosABB(int valores[], int tamano)
{
    ArbolBinario a;
    generarABB(valores, tamano, 0, a);
}

void unirABBs(ArbolBinario &abb1, ArbolBinario &abb2)
{
    int tamano1 = abb1.calcularAltura(abb1.getRaiz());
    int tamano2 = abb2.calcularAltura(abb2.getRaiz());

    Tipo *valores1 = new Tipo[tamano1];
    Tipo *valores2 = new Tipo[tamano2];
    int index = 0;

    // Obtener los valores de ambos ABB mediante un recorrido en orden
    recorridoEnOrden(abb1.getRaiz(), valores1, index);
    index = 0;
    recorridoEnOrden(abb2.getRaiz(), valores2, index);

    // Insertar los valores del primer ABB en el segundo ABB
    for (int i = 0; i < tamano1; i++)
    {
        abb2.insertarNodo(valores1[i]);
    }
}