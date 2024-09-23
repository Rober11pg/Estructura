/* Programa que permite generar los 10 primeros numeros enteros positivos 
Solución recursiva
Autor: Roberto Jiménez
Código: 7048*/
#include<iostream>
using namespace std;
#define NR 10 // Constante para definir cantidad de valores a generar
int main(){ // programa principal
    system("color f0");
    int suma=0;
    void Generarnumeros(int n, int *suma); // enviamos n para que sea más flexible

    Generarnumeros(1, &suma);
    cout<<"La suma total es: "<< suma <<endl;
    cout<<""<<endl;
    system("pause");
}

void Generarnumeros(int n, int *suma){ // parametro por valor
    if(n <= NR){ // indetificar el caso base
    *suma +=n;
    Generarnumeros(n+1, suma);
     // ubicar a mi conveniencia para ordenar descendente o ascendentemente 
    }      
}
