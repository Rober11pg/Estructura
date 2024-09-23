//Implementa gestion basica de vertices

using namespace std;

#include <iostream>
#include "Vertice.h"
#include "leerN.h"
int main(){
    system("color f0");
    int n;
    Vertice* v0;        //definicion de apuntador 

    void leerVertices(Vertice v1[], int n1);
    void imprimirVertices(Vertice v1[],int n1);

    cout << endl << "Cantidad de veces a procesar";
    n = Leer_N();

    v0 = new Vertice[n];        //crear n vertice osea n objetos

    leerVertices(v0, n);
    imprimirVertices(v0, n);

    Vertice v;
    Vertice v1(500);
    Vertice v2(700,3);
    Tipo aux;
    cout << endl << "Ingrese un valor a guardar en el vertice: ";
    cin >> aux;

    v.setDato(aux);

    cout << endl << "El valor almacenado en el vertice0 es: " << v.getDato();

    cout << endl << "El valor almacenado en el vertice1 es: " << v1.getDato();

    cout << endl << "El valor almacenado en el vertice2 es: " << v2.getDato();
    cout << endl << "La posicion almacenada en el vertice es: " << v2.getNum();

    cout << endl;
    system("pause");
    return 0;
}

void leerVertices(Vertice v1[], int n1){

}
void imprimirVertices(Vertice v1[],int n1){
    
}