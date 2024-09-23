#include<iostream>
using namespace std;

int main(){
    int N, b[50], posA;
    cout<<"Ingrese la cantidad de valores que desesa ingresar: ";
    cin>> N;
    
    for (int i = 0; i < N; i++){
    	cout<<"Valor posicion [" << i << "]: ";
        cin >> b[i]; // Almacena los valores ingresados en el arreglo
    }
        
    for (int i = 0; i < N; i++) 
    {
        posA = i;
        int aux = b[i];

        while ((posA > 0) && (b[posA - 1] > aux)) {
            b[posA] = b[posA - 1];
            posA--;
        }
        b[posA] = aux;
    }

	cout<<"\nValores Ordenados...\n";
    // Imprime los valores ordenados
    for(int i = 1; i < N; i++){
    	cout<<"Valor [" << i << "]: " << b[i] << endl;
    }
system("pause");
    return 0;
}