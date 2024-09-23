/* Programa que determina si casa valor ingresado es capicua, implementando TDA circular */

// Cola7.cpp
// Programa que deermina si cada valor ingresado es capicua, mediante el empleo del TDA ColaCircular
// Autor: 4to. A
using namespace std;
#include <iostream>
#include "ColaCircular.h"
#define FIN 99999	//definicion del marcador de fin de lectura


int main(){			//programa principal
	system("color f0");
	ColaCircular c;			//declaracion del objeto cola
	void leerNumeros(int valor, ColaCircular *c1);
	void imprimirCola(ColaCircular c1);	
	void ExtreNum(ColaCircular c1);

	leerNumeros(leerN(),&c);
	imprimirCola(c);
	bool valorEsCapicua(Tipo val);

	ExtreNum(c);
	
	
	
	/*leerCola(&c);						//llamado a funcion de ingreso
	cout << endl << "ELEMENTOS CONTENIDOS EN EL TDA COLA CIRCULAR";
	cout << endl << "===================================";
	
	*/
	cout << endl;
	system("pause");
}

bool valorEsCapicua(Tipo val) {
	ColaCircular aux;		//TDA cola auxiliar para acomodar los digitos extraidos de val
	Tipo nNum = 0;			//nuevo numero a formar con digitos invertidos
	Tipo orig = val;		//guardar el valor original
	
	do {
		if (!aux.colaLlena()){
			aux.insertar(val % 10);	
		}
		val /= 10;		//elimina el digito extraido
	} while (val != 0);	//repetir proceso mientras haya digitos en el numero
	
	while (!aux.colaVacia()){
		nNum = (nNum * 10) + aux.quitar();
	}
	return (orig == nNum);		//devuelve true cuando coincidan los valores
}
void ExtreNum(ColaCircular c1) {
	if(c1.colaVacia()) {
		return;
	}
	
	int numero = c1.quitar();
	cout << endl << ">  " << numero << " ";
	// es capicua
	if(valorEsCapicua(numero)) {
		cout << "Es ";
	} else {
		cout << "No es";
	}
	cout << " capicua" << endl;
	
	return ExtreNum(c1);
}

void leerCola(ColaCircular *c1){		//funcion que ingresa valores en el TDA
	Tipo x;								//var de lectura

	cout << endl << "Valor a insertar. Finalice con [" << FIN << "] : ";	
	cin >> x;
	
	if (x != FIN){						//no ingreso el marcador de final
		if (!c1->colaLlena()){			//cuando aun hay disponibilidad para insertar nuevos valores
			c1->insertar(x);			//llamado a metodo de insercion
			leerCola(c1);				//llamado recursivo al metodo de lectura
		} else {						//no hay espacio disponible
			cout << endl << "Error.... Estructura sin espacio de almacenamiento...";
		}
	}
}

void imprimirCola(ColaCircular c1){		//funcion que imprime los datos contenidos en el TDA
	if (!c1.colaVacia()){				//aun hay elementos en el TDA
		cout << endl << ">  " << c1.quitar();
		imprimirCola(c1);				//llamado recursivo a impresion del TDA
	}
}

void leerNumeros(int valor, ColaCircular *c1){
	for(int i = 0; i < valor; i++){
		Tipo valor;
		cout << "Ingrese un valor" << endl;
		cin >> valor;
		c1->insertar(valor);
	}
}