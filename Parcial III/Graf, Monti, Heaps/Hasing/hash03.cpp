/*Los elementos de la tabla son socios de un club.
Cada socio se identifica con: número de socio, nombre completo, edad, sexo,
fecha de alta (ingreso)*/

using namespace std;

#include <iostream>
#include <cmath>
#include <string.h>
#include "utilidades.h"

struct Fecha {
	int dia;
	int mes;
	int anno;
};

class TipoSocio {
	protected:
		int codigo;
		char nombre[30];
		int edad;
		Fecha f;
	public:
		TipoSocio(){};
		TipoSocio( int c, char nom[], int ed, Fecha fech){
			codigo = c; strcpy(nombre, nom); edad = ed; f = fech;
		}
		int Ocodigo(){return codigo;}
		void Pcodigo( int c) { codigo = c;}
		void Pedad( int e) { edad = e;}
		int Oedad(){ return edad;}
		void Pnombre(char nom[]){ strcpy(nombre, nom);}
		char * Onombre(){ return nombre;}
		void PFecha(Fecha fech){ f = fech;}
		Fecha OFecha(){ return f;}
};

class Elemento {
	protected:
		TipoSocio socio;
		Elemento *sgte;
	public:
		Elemento(TipoSocio e) {
			socio = e;
			sgte = NULL;
		};
		Elemento(){};
		Elemento* Osgte(){ return sgte;}
		void Psgte( Elemento *sig){ sgte = sig;}
		TipoSocio Osocio(){ return socio;}
		void Psocio(TipoSocio s) { socio = s;}
};

class TablaDispersa {
	protected:
		int final;
		int numElementos;
		Elemento ** tabla;
	public:
		TablaDispersa(int n);
		void insertar(TipoSocio s);
		Elemento* buscar(int codigo);
		void eliminar(int codigo);
	private: 	// operaciones para obtener índices dispersos
		int dispersion(long x);
};

int TablaDispersa::dispersion(long x) {
	double t, R = 0.618034;
	int v;
	t = R * x - floor(R * x); // parte decimal
	v = (int) (final * t);
	return v;
}

TablaDispersa:: TablaDispersa(int n) {// constructor
	tabla = new Elemento * [n];
	final = n;
	for (int k = 0; k < final; k++){
		tabla[k] = NULL;
	}
	numElementos = 0;
}

void TablaDispersa::insertar(TipoSocio s){
	int posicion;
	Elemento *nuevo, *p;
	posicion = dispersion(s.Ocodigo());
	p = buscar(s.Ocodigo());
	if(!p){// el código no se encuentra en la tabla
		nuevo = new Elemento(s);
		nuevo->Psgte(tabla[posicion]);
		tabla[posicion] = nuevo;
		numElementos++;
	} else {
		throw "Repeticion de socio";
	}
}

bool conforme (TipoSocio cod){ }

void TablaDispersa::eliminar(int codigo){
	int posicion;
	posicion = dispersion(codigo);
	
	if (tabla[posicion] != NULL){ // no está vacía
		Elemento* anterior, *actual;
		anterior = NULL;
		actual = tabla[posicion];
		while ((actual->Osgte() != NULL) && actual->Osocio().Ocodigo() != codigo){
			anterior = actual;
			actual = actual->Osgte();
		}
		if (actual->Osocio().Ocodigo() != codigo){
			cout << "No se encuentra en la tabla el socio \n";
		} else {
			if (conforme (actual->Osocio())){ //se retira el nodo
				if (anterior == NULL){ // primer nodo
					tabla[posicion] = actual->Osgte();
				} else {
					anterior->Psgte(actual->Osgte());
				}
				delete actual;
				numElementos--;
			}
		}
	}
}

Elemento* TablaDispersa::buscar(int codigo){
	Elemento *p = NULL;
	int posicion;
	posicion = dispersion(codigo);
	if (tabla[posicion] != NULL){
		p = tabla[posicion];
		while ((p->Osgte() != NULL) && p->Osocio().Ocodigo() != codigo)
			p = p->Osgte();
		if (p->Osocio().Ocodigo() != codigo)
			p = NULL;
	}
	return p;
}

int main(){
	system("color fc");

	int op;
	int n;

	int menu();															//prototipo de la funcion que presenta las alternativas
	void ingresarDatos(int n1, TablaDispersa *t1);						//prototipo de la funcion que permite el ingreso de los datos 
	void buscarDatos(int n1, TablaDispersa t1);						//prototipo de la funcion que permite el ingreso de los datos
	void eliminarDatos(int n1, TablaDispersa *t1);						//prototipo de la funcion que permite el ingreso de los datos

	cout << endl << "Cantidad de datos a procesar: ";
	n = leerN(1, 100);						//ingreso de cantidad de datos a procesar
	
	TablaDispersa t(n);						//declara la tabla
	
	while (op = menu()){
		switch (op){
			case 1:	ingresarDatos(n, &t);				//llamado a la funcion que ingresa los datos
					break;
			case 2:	buscarDatos(n, t);					//llamado a funcion de busqueda
					break;
			case 3:	eliminarDatos(n, &t);				//llamado a funcion que elimina
					break;
			default:
					cout << endl;
		}
	}
	system("pause");
}

int menu(){
	int op;
	cout << endl << "======================================";
	cout << endl << "  M E N U     D E    O P C I O N E S  ";
	cout << endl << "======================================";
	cout << endl << "1. Ingresar nuevos datos			   ";
	cout << endl << "2. Visualizar un dato				   ";
	cout << endl << "3. Eliminar un dato				   ";
	cout << endl << "0. Finalizar						   ";
	cout << endl << "======================================";
	cout << endl << "INGRESE SU SELECCION";
	op = leerN(0,3);
	return op;
}

void ingresarDatos(int n1, TablaDispersa *t1){	//funcion que permite el ingreso de los datos 
	int codAux;
	char nomAux[30];
	int edadAux;
	Fecha fecAux;
	TipoSocio s;

	for (int i = 0; i < n1; i++){
		cout << endl << "=================================================";
		cout << endl << "INGRESAR DATOS DE SOCIOS";
		cout << endl << "=================================================";
		cout << endl << "Codigo: ";
		cin >> codAux;
		cin.ignore();
		cout << "Nombre: " ;
		cin.getline(nomAux,30);
		cout << "Edad: " ;
		cin >> edadAux;
		cin.ignore();
		cout << "Fecha de Ingreso" ;
		cout << endl << "Dia:" ;
		cin >> fecAux.dia;
		cout << "Mes:" ;
		cin >> fecAux.mes;
		cout << "Anio:" ;
		cin >> fecAux.anno;
		cin.ignore();
		cout << endl << "=================================================";
		s.Pcodigo(codAux);
		s.Pnombre(nomAux);
		s.Pedad(edadAux);
		s.PFecha(fecAux);
		t1->insertar(s);				//llamado al metodo de insercion de nuevos datos en la tabla
	}
}

void buscarDatos(int n1, TablaDispersa t1){		//prototipo de la funcion que permite el ingreso de los datos
	int codAux;
	Elemento* y;
	TipoSocio s;

	cin.ignore();
	cout << endl << "=================================================";
	cout << endl << "BUSCAR DATOS DE UN SOCIO" << endl;
	cout << endl << "=================================================";
	cout << endl << "Codigo: ";
	cin >> codAux;
	cin.ignore();
	y = t1.buscar(codAux);
	if (y){
		s = y->Osocio();
		cout << endl << "Codigo: " << s.Ocodigo();
		cout << endl << "Nombre: " << s.Onombre();
		cout << endl << "Edad: " << s.Oedad();
		cout << endl << "Fecha de Ingreso: " << s.OFecha().dia << "/" << s.OFecha().mes << "/" <<s.OFecha().anno << endl ;
	} else {
	}
	cout << endl << "=================================================";
}

void eliminarDatos(int n1, TablaDispersa *t1){						//prototipo de la funcion que permite el ingreso de los datos
	int codAux;

	cin.ignore();
	cout << endl << "=================================================";
	cout << endl << "ELIMINAR DATOS DE UN SOCIO" << endl;
	cout << endl << "=================================================";
	cout << endl << "Codigo: ";
	cin >> codAux;
	cin.ignore();
	t1->eliminar(codAux);
}
