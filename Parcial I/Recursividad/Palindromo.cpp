/*
recursividad
Programa de gesetión de cadenas 
Autor: Roberto Jiménez
 */
#include<iostream>
#include<cstring>
using namespace std;
int main(){     // programa principal
system("color f0");
char f[15];

bool espalindromo(char f[]);
  cout<<"Ingrese una cadena de caracteres: "<<endl;
    cin.getline(f, 15, '.') >>f;

    cout << endl;// todo aquello que no es letra le pone fin de cadena, queda memoria intermedia eso se llama bufer 
    cout<<"Esa cadena "<< (espalindromo(f) ? "si": "no")<< " es un plindromo..."<<endl;
    system("pause");

}
bool espalindromo(char f[]){
        int i, j;
    j = strlen(f)-1;
    for(i = 0; (i < j); i++, j--)
    {
            if(f[i] != f[j]){
                return false;
            } 
    }
    return true;  
}

// 
