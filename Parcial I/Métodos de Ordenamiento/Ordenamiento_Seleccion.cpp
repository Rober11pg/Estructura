#include<iostream>
using namespace std;

int main()
{
    int  N, numeros[100];
    int aux, min;
    cout<<"Ingrese la cantidad de elementos : "<<endl;
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        cout<<"Posicion [" << i << "]"<<endl; cin>> numeros[i];
    }

    for(int i=0; i < N; i++){
        min =i;                         // 3 
        for (int j = i+1 ; j < N; j++) //3 2 1 5 4 
        {
            if(numeros[j] < numeros[min]){ // //2<3, 1<2, 1<5, 1<5
                min=j;                      // 2, 1
            }
           
        }

        aux = numeros[i]; 
        numeros[i] = numeros[min];  
        numeros[min] = aux;        
    }
    
    cout<<"Orden Ascendente: "<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<"Posicion [" << i << "]"<< numeros[i] << endl; 
    }

     cout<<"Orden Descendente: "<<endl;
    for (int i = N-1; i >=0; i--)
    {
        cout<<"Posicion [" << i << "]"<< numeros[i] << endl; 
    }
    
return 0;
}