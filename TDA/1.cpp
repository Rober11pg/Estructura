// programa que hace uso del TDA vector
// Autor: Roberto Jiménez

#include<iostream>
#include "vector.h" // definicion del TDA   

using namespace std;

int main(){

    vector vec;
    vec.SetElemento(5);               // instanciar el objeto de tipos TDA vector 
    cout<<"El valor del atributo numEle es: "<< vec.getNumEle()<<endl;
    system("pause");
}