#include<iostream>
using namespace std; 

int LeerN(int liminf, int limsup){
    int x=liminf; // variable de lectura 
    cout<<"Ingrese un valor entero comprendido en el rango ["<<liminf<< ".."<< limsup << "]" <<endl;
    cin>>x;	
    if((x < liminf)  || (x > limsup)){
        LeerN(liminf, limsup);
	}
    return x;
}

bool esPrimo(int num, int i){
	if(num <= 1)
		return false;
	if(num == 2)
		return true;
	
	if(i*i <= num){
        esPrimo(i++, num);
		if (num % i == 0)
        	return false; 
            
        if(num % 2 == 0)
        return false;
    }
    return true; 
}