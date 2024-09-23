#include <iostream>
using namespace std;


int main(){
    void nums(int n);
    nums(5);
    return 0;
}

void nums(int n){
    int num;
    int sum;
    int cont;
    bool individualizar(int n, int *cont, int *sum);

    if(n>1){
        cont=1;
        sum=0;
        cout<<endl<<"Ingrese un numero: ";
        cin>> num;
        nums(n-1);
        if(individualizar(num, &cont, &sum)==true){
            cout<<endl<<"Si cumple con la condicion";
        }else{
            cout<<endl<<"No cumple con la condicion";
        }
    }
}

bool individualizar(int n, int *cont, int *sum){
    int dig, temp=n;
    int exponente(int n, int expo);

    if(*sum<=n){
        if(n!=0){
            dig= n%10;
            *sum+= exponente(dig, *cont);
            individualizar(n/10,cont,sum);
        }
        return true;
        *sum=0;
        *cont+=1;
        n=temp;
        
    }
    return false;
}

int exponente(int n, int expo){

}