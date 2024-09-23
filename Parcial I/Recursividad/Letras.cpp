/*Eleborar un programa recursivo que permita generear las letras minúsculas del alfabeto.
Autor: Roberto Iménez
Código: 7048*/

#include<iostream>
#define NF 25
using namespace std;
int main(){
    system("color f0");
void GenearMinusculas(char n);
GenearMinusculas('A');

cout<<" "<<endl;
    system("puase");
}

void GenearMinusculas(char n){
    if(n <= 'z'){ // "" = cadenas , '' = caracter
        cout<<": "<< n <<endl;
        GenearMinusculas(++n); // si se ponde n ++ lo va hacer infinito

        // n++ incremento el valor de n luego de averlo utilizado .... sufijo despues de 
        /*
          n+1   el valor acutal de n no cambia, cuadno le llamo 
          entra a y luego pasa b
        n ++ en este casova a sar infinito...
          n+=1 desde un inicio cambia a b y luego cambia a cuadno se cumple 
         ++ n; 
        */

    }
}

