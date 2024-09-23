//numero.h
#include <iostream>

using namespace std;

int leerN(int inf,int sup){
	int val;
	do{
		cout<<"\nIngrese la cantidad de vertices a trabajar"<<endl;
		cin>>val;
	}while((val<inf)||(val>sup));
	return val;
}