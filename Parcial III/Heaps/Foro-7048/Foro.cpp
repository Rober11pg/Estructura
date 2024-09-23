// heaps01
// programa que implementa uso de un heap
// Autor: Julio Santillán Castillo

using namespace std;

#include <iostream>
#include "monticulo.h"
#include "utilidades.h"

int main() {
    system("color fc");
    int n;

    void leerMonticulo(Monticulo* m1, int n1);            //prototipo de la funcion que lee un monticulo de datos
    void imprimirMonticulo(Monticulo m1, int n1);         //prototipo de la funcion que imprime un monticulo
    void imprimirMinimo(Monticulo m1);                    //prototipo de la funcion que imprime el valor minimo del monticulo
    void eliminarMinimo(Monticulo* m1);                   //prototipo de la funcion que elimina el valor minimo del monticulo y lo reordena
    float calcularPromedio(Monticulo m1);                 //prototipo de la funcion que calcula el promedio de los elementos del monticulo

    cout << endl << "CANTIDAD DE ELEMENTOS DEL MONTICULO";
    n = LeerN(1, 20);                                    //cantidad de elementos
    Monticulo m(n);                                      //creacion de monticulo

    leerMonticulo(&m, n);                                //llamada a ingreso de monticulo
    imprimirMonticulo(m, n);                             //llamada a impresion de monticulo

    imprimirMinimo(m);

    //eliminarMinimo(&m);
    imprimirMonticulo(m, n);

    float promedio = calcularPromedio(m);
    cout << endl << "El promedio de los elementos en el Monticulo es: " << promedio << endl;

    cout << endl;
    system("pause");
}

void leerMonticulo(Monticulo* m1, int n1) {        //funcion que lee n datos y los inserta en un monticulo
    Clave aux;

    cout << endl << "INGRESO DE ELEMENTOS DEL MONTICULO";
    for (int i = 0; i < n1; i++) {                //ciclo
        cout << endl << "Ingrese un valor: ";
        cin >> aux;
        m1->Insertar(aux);                        //insercion de elemento en monticulo
    }
}

void imprimirMonticulo(Monticulo m1, int n1) {    //funcion que imprime un monticulo
    Clave aux;

    cout << endl << "IMPRESION DE ELEMENTOS DEL MONTICULO";
    for (int i = 0; i < m1.getNumDatosAct(); i++) {
        aux = m1.getValor(i);                    //calcula valor extraido del monticulo
        cout << endl << ">   " << aux;
    }
}

void imprimirMinimo(Monticulo m1) {                //funcion que imprime el valor minimo del monticulo
    cout << endl << "El valor minimo incluido en el Monticulo es : " << m1.BuscarMinimo();
}

void eliminarMinimo(Monticulo* m1) {                //funcion que elimina el valor minimo del monticulo y lo reordena
    Clave min;

    cout << endl << "Eliminando el valor minimo incluido en el Monticulo .......";
    min = m1->EliminarMinimo();                    //elimina el valor minimo 
    cout << endl << "El valor eliminado del Monticulo es: " << min;
}

float calcularPromedio(Monticulo m1) {            //funcion que calcula el promedio de los elementos del monticulo
    float sum = 0;
    int n = m1.getNumDatosAct();

    for (int i = 0; i < n; i++) {
        sum += m1.getValor(i);
    }

    if (n != 0) {
        return sum / n;
    } else {
        return 0;
    }
}
