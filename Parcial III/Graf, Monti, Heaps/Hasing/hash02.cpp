using namespace std;

#include <iostream>
#include <string.h>
#include "utilidades.h"

struct TipoCasa {
	char codigo[5];
	char poblacion[31];
	char direccion[51];
	int habitaciones;
	double precio;
};

class CasaRural{
	protected:
		char codigo[5];
		char poblacion[31];
		char direccion[51];
		int habitaciones;
		double precio;
		bool esAlta;
	public:
		CasaRural(){} // constructor por defecto
		CasaRural (TipoCasa c) { esAlta = true; asigna(c); }
		~CasaRural(){ esAlta = false;}
		char* elCodigo(){ return codigo; } 
		bool OesAlta(){ return esAlta; } 
		void PesAlta(bool sw){ esAlta = sw; }
		void muestra(){
			cout << endl << "=================================================" << endl;
			cout << "DATOS ALMACENADOS DE LA CASA RURAL DE ALQUILER";
			cout << endl << "=================================================" << endl;
			cout << "Codigo: " << codigo << endl;
			cout << "Poblacion: " << poblacion << endl;
			cout << "Direccion: " << direccion << endl;
			cout << "Precio por dia: " << precio << endl;
			cout << endl << "=================================================";
		}
	private:
			void asigna(TipoCasa c){
			strcpy(poblacion, c.poblacion);
			strcpy(direccion, c.direccion);
			strcpy(codigo, c.codigo);
			habitaciones = c. habitaciones;
			precio = c.precio;
		}
};

class TablaDispersa{
	protected:
		int final;
		int numElementos;
		double factorCarga;
		CasaRural ** tabla;
	public:
		TablaDispersa(int n); // constructor
		int direccion(char *clave); // posicion de un elemento
		void insertar(CasaRural r); //inserta un nuevo elemento en la tabla
		CasaRural* buscar(char* clave); // busca un elemento en la tabla
		void eliminar(char *clave); // dar de baja un elemento
	private:
		long transformaCadena(char * c); // calcular la posición de un elemento en la tabla
};

TablaDispersa::TablaDispersa(int n){
	tabla = new CasaRural* [n];
	final = n;
	for(int j = 0; j < final ; j++){
		tabla[j] = NULL;
	}
	numElementos = 0;
	factorCarga = 0.0;
}

int TablaDispersa::direccion(char *clave){
	int i = 0;
	long p, d;
	d = transformaCadena(clave);

	p = d % final;  	// aplica aritmética modular para obtener dirección base
	
	while (tabla[p]!= NULL && strcmp(tabla[p]->elCodigo(),clave)!= 0){   // bucle de exploración
		i++;
		p = p + i * i;	//exploración cuadrática
		p = p % final; // considera el array como circular
	}
	return (int)p;
}

long TablaDispersa::transformaCadena(char* c){
	long d = 0;
	for (int j = 0; j < strlen(c); j++)	{
		d = d * 27 + (int)c[j];
	}
	if (d < 0){
		d = -d;
	}
	return d;
}

void TablaDispersa::insertar(CasaRural r){
	int posicion;
	posicion = direccion(r.elCodigo());
	tabla[posicion] = new CasaRural(r);
	
	numElementos++;
	factorCarga = (double)numElementos/final;

	if (factorCarga > 0.5){
		cout << endl  << "!! Factor de carga supera el 50 % !!.... Conviene aumentar el tamaño." << endl;
	}
}

CasaRural* TablaDispersa::buscar(char* clave){
	CasaRural *pr;
	int posicion;

	posicion = direccion(clave);
	pr = tabla[posicion];

	if (pr != NULL){
		if (!pr->OesAlta()){
			pr = NULL;
		}
	}
	return pr;
}

void TablaDispersa::eliminar(char *clave){
	int posicion;
	posicion = direccion(clave);
	if (tabla[posicion] != NULL){
		tabla[posicion] -> PesAlta(false);
	}
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
	TipoCasa x; 							//registro para lectura

	cin.ignore();
	for (int i = 0; i < n1; i++){
		cout << endl << "=================================================";
		cout << endl << "INGRESAR DATOS DE CASA RURAL DE ALQUILER";
		cout << endl << "=================================================";
		cout << endl << "Codigo: ";
		cin.getline(x.codigo,5);
		cout << "Poblacion: " ;
		cin.getline(x.poblacion,31);
		cout << "Direccion: " ;
		cin.getline(x.direccion,51);
		cout << "Habitaciones: " ;
		cin >> x.habitaciones;
		cout << "Precio por dia: ";
		cin >> x.precio;
		cout << endl << "=================================================";
		cin.ignore();
		t1->insertar(x);				//llamado al metodo de insercion de nuevos datos en la tabla
	}
}

void buscarDatos(int n1, TablaDispersa t1){		//prototipo de la funcion que permite el ingreso de los datos
	TipoCasa x; 							//registro para lectura
	CasaRural * y;

	cin.ignore();
	cout << endl << "=================================================";
	cout << endl << "BUSCAR DATOS DE CASA RURAL DE ALQUILER" << endl;
	cout << endl << "=================================================";
	cout << endl << "Codigo: ";
	cin.getline(x.codigo,5);
	y = t1.buscar(x.codigo);
	if (y){
		y->muestra();
	} else {
	}
	cout << endl << "=================================================";
}

void eliminarDatos(int n1, TablaDispersa *t1){						//prototipo de la funcion que permite el ingreso de los datos
	TipoCasa x; 							//registro para lectura

	cin.ignore();
	cout << endl << "=================================================";
	cout << endl << "ELIMINAR DATOS DE CASA RURAL DE ALQUILER" << endl;
	cout << endl << "=================================================";
	cout << endl << "Codigo: ";
	cin.getline(x.codigo,5);
	t1->eliminar(x.codigo);
}
