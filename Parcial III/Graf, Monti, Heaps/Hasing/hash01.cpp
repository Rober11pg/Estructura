// hash01
// Calcula valores de dispersion empleando diversos metodos
// Permite el ingreso de cadena de valores y calcula valor de dispersión en 
// funcion de los caracteres ingresados
// Autor: Julio Santillán C.

using namespace std;
#include <iostream>
#include <cmath>

#define NC 1000			//numero maximo de claves
#define EC 20			//extension de la clave

int main(){
	system("color f0");
	char cad[NC][EC];							//arreglo de cadenas de caracteres
	int n = 0;									//cantidad de cadenas ingresadas
	
	void leerClaves(char c[][EC], int *n1);		//funcion para permitir el ingreso de las cadenas
	void imprimirClaves(char c[][EC], int n1);	//funcion para imprimir las cadenas ingresadas
		
	leerClaves(cad, &n);						//llamado a lectura
	imprimirClaves(cad, n);						//llamado a impresion
	
	cout << endl;
	system("pause");
}

void leerClaves(char c[][EC], int *n1){			//funcion para permitir el ingreso de las cadenas
	char aux[EC];								//cadena auxiliar de lectura
	
	do {
		cout << endl << "Ingrese valor de clave. Finalice con [.]: ";
		cin.getline(aux, EC, '.');
		cin.ignore();
		
		if (strlen(aux) > 0){					//si ingreso caracteres
			strcpy(c[*n1],aux);					//copia la cadena ingresada en arreglo
			(*n1)++;							//cuenta la cadena ingresada
		}
	}while (strlen(aux) > 0);
}

int transformarClave(char c[]){					//funcion que transforma una cadena en un valor numerico entero
	int ac = 0;									//var acumuladora de codigos ascii de los caracteres de la cadena
	
	for (int i = 0; i < strlen(c); i++){		//ciclo de recorrido de los caracteres de la cadena
		ac += int(c[i]);						//acumular el codigo ascii del caracter posicion i de cadena c
	}
	return ac;									//devolver el valor acumulado
}

int dispersionModular(int v){					//funcion que calcula valor de dispersion de v aplicando artirmetica modular
	return v % NC;								//devolver el modulo clave vs cantidad disponible de ubicaciones en el arreglo
}

int dispersionPlegamiento(int v){	//calcula valor de dispersion aplicando aritmetica modular
	int ac = 0;					//acumulador de sumatorias
	
	do{
		ac += v % 1000;			//suma los tres digitos finales
		v /= 1000;				//elimina los tres digitos
	}while (v != 0);			//repite mientras quedan digitos en el numero
	return ac;					//devuelve valor de dispersion
}

int dispersionMitadCuadrado(int v){	//calcula valor de dispersion aplicando aritmetica modular
	int val = pow(v, 2);			//eleva al cuadrado la clave
	int posIni = 3;					//posicion de inicio de valores a considerar
	int posFin = 5;					//posicion de fin de valores a considerar
	int pa = 0;						//indicador de posicon actual
	int ac = 0;						//acumulador del valor de dispersion
	do{
		pa++;						//incrementa contador de posicion actual
		if ((pa >= posIni) && (pa <= posFin)){  //estos valores estan dentro del rango
			ac = (ac * 10) + (val % 10);  //multiplica por 10 acumulador y añade nuevo digito
		}
		val /= 10;					//elimina el digito del valor calculado
	}while (val != 0);			//repite mientras quedan digitos en el numero
	return ac;					//devuelve valor de dispersion
}

int dispersionMultiplicacion(int v){	//calcula valor de dispersion aplicando aritmetica modular
	double t;
	int ac;
	const int m = 1024;
	const float R = 0.618034;

	t = (R * v) - floor(R * v); // parte decimal
	ac = (int) (m * t);
	return ac;					//devuelve valor de dispersion
}

void imprimirClaves(char c[][EC], int n1){	//funcion para imprimir las cadenas ingresadas
	int nClave;					//expresion numerica de la clave

	cout << endl << "CLAVES INGRESADAS" << endl;
	for(int i = 0; i < n1; i++){
		nClave = transformarClave(c[i]);
		cout << endl << "> " << c[i] ;
		cout << endl << "\t - Clave numerica: " << nClave;
		cout << endl << "\t - Dispersion Modular: " << dispersionModular(nClave);
		cout << endl << "\t - Dispersion Plegamiento: " << dispersionPlegamiento(nClave);
		cout << endl << "\t - Dispersion Mitad del Cuadrado: " << dispersionMitadCuadrado(nClave);
		cout << endl << "\t - Dispersion Multiplicacion: " << dispersionMultiplicacion(nClave);
	}
}
