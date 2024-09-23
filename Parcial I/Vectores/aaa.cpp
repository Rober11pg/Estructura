#include<iostream>
using namespace std;

int main(){
    int a=0;
    void hola(int *a);
    cout<<a<<endl;
    hola(&a);
    cout<<a<<endl;
    return 0;
}

void hola(int *a){
    cin>>*a;
}