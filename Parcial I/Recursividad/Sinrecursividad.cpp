/* Programa que permite generar los 10 primeros numeros enteros positivos
Solución recursiva
Autor: Roberto Jiménez
Código: 7048*/
#include <iostream>
using namespace std;
#define NR 10 // Constante para definir cantidad de valores a generar
int main()
{ // programa principal
    system("color f0");
    int Generarnumeros(int n); // enviamos n para que sea más flexible

    cout << "La suma total es:" << Generarnumeros(1) << endl;
    cout << "" << endl;
    system("pause");
}

int Generarnumeros(int n)
{ // parametro por valor
    if (n <= NR)
    { // indetificar el caso base
        return n + Generarnumeros(n + 1);
        // ubicar a mi conveniencia para ordenar descendente o ascendentemente
    }
    return 0; // ultimo llamdo, que va a sumar
    // cout<<"El valor generado: " << n <<endl; // lo que está fuera del if se ejecuta siempre, por que no controla
}
