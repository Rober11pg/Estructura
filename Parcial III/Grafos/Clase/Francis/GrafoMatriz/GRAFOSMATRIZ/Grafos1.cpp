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
    void leerVerticesR(Vertice v1[], int n1,int i);
    void imprimirVerticesR(Vertice v1[],int n1,int i);
    void buscarVerticesDato(Vertice v1[], int n1);
    void buscarVerticesNumero(Vertice v1[], int n1);
    cout << endl << "Cantidad de veces a procesar";
    n = Leer_N();

    v0 = new Vertice[n];        //crear n vertice osea n objetos

    leerVertices(v0, n );
    imprimirVertices(v0, n);

    buscarVerticesDato(v0, n);


    cout << endl;
    system("pause");
    return 0;
}

void leerVertices(Vertice v1[], int n1){
    Tipo aux;       //variable de lectura
    for (int i = 0; i < n1; i++){
        cout << endl << "Ingrese el valor para le vertice: ";
        cin >> aux;
        v1[i].setDato(aux);
        v1[i].setNum(i);
    }

}
void imprimirVertices(Vertice v1[],int n1){
    for (int i = 0; i < n1; i++){
        cout << endl << "Valor almacenado en el vertice[ " <<v1[i].getNum()<< " ]: " << v1[i].getDato();;

    }
}

void leerVerticesR(Vertice v1[], int n1,int i=0){
    Tipo aux;
    if(i<n1){
        cout << endl << "Ingrese el valor para le vertice: ";
        cin >> aux;
        v1[i].setDato(aux);
        v1[i].setNum(i);
        leerVerticesR(v1, n1, i++);
    }
}
void imprimirVerticesR(Vertice v1[],int n1,int i=0){
    if(i<n1){
        cout << endl << "Valor almacenado en el vertice[ " <<v1[i].getNum()<< " ]: " << v1[i].getDato();;
        imprimirVerticesR(v1, n1, i++);
    }
}
void buscarVerticesDato(Vertice v1[], int n1){
    int n;              //cantidad de busquedad a realizar
    Tipo aux;
    bool enc;
    cout << endl << "Cantidad de busquedas por dato: ";
    n = Leer_N();

    for (int i = 0; i < n; i++){
        cout << endl << "Ingrese al valor a buscar: ";
        cin >> aux;
        enc = false;
        for (int j = 0; j < n1; j++){
            if(v1[j].esIgualDato(aux)){
                enc = true;
            }
        }
        cout << endl << "El valor " << aux << (enc ? "si":"no") << " existe entre los vertices...";
    }

}




