/* 3.Permitir el ingreso de una cadena de caracteres y ordenar los caracteres de cada palabra encontrada  
Autor: Roberto Jiménez-7048*/

#include <iostream>
#include "Cola.h"
#define FIN 9999
using namespace std;

int main(){
    system("color f0");
    Cola c;

    void leerCola(Cola c1);        //Funcion que lee los elementos de la cola
    void ordenarCaracteres(Cola* c1);    //Funcion que ordena los caracteres de una cadena ingresada

    leerCola(c);               //Llamada a la funcion que lee los elementos de la cola
    ordenarCaracteres(&c);      //Llamada a la funcion que ordena los caracteres             

    cout << endl;
    system("pause");
    return 0;
}

void ordenarCaracteres(Cola* c1){       //Funcion que ordena los caracteres de una cadena ingresada
    int n = c1->tamanioCola();
    char* caracteres = new char[n];

    for (int i = 0; i < n; i++) {
        caracteres[i] = c1->quitar();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tolower(caracteres[j]) > tolower(caracteres[j + 1])) {
                char temp = caracteres[j];
                caracteres[j] = caracteres[j + 1];
                caracteres[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        c1->insertar(caracteres[i]);
    }

    delete[] caracteres;
}

void leerCola(Cola c1){        //Funcion que lee los elementos de la cola
    char cadena;

    cout << endl << "Ingrese una cadena: ";
    
    while(cin.get(cadena) && cadena != '\n'){
        if(cadena != ' '){
            c1.insertar(cadena);
        }else{
            ordenarCaracteres(&c1);
            while(!c1.colaVacia()){
                cout << static_cast<char>(c1.quitar());
            }
            cout << " ";
        }
    }

    ordenarCaracteres(&c1);
    while(!c1.colaVacia()){
        cout << static_cast<char>(c1.quitar());
    }
    cout << endl;
}