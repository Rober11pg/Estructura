/*Ingresar varios números enteros, y determinar el (los) valor(es) más repetido(s) 
que constan entre ellos (aplique el algoritmo de búsqueda binaria y ordenamiento por selección, 
en caso de requerirlo)
Autor: Roberto Jiménez
Código: 7048*/

#include<iostream>
#define EXT 20
using namespace std;
int main(){
system("color f0");
int n, a[EXT];

int leerN(int limInf, int limSup);
void LeerArreglo(int v[], int n1);
void OrdenSeleccion(int v[], int n1);
void MayorDigitoRepetido(int v[], int n1);
void ImprimirArreglo(int v[], int n1);

n = leerN(1, EXT);
LeerArreglo(a, n);
OrdenSeleccion(a, n);
ImprimirArreglo(a, n);
cout<<""<<endl;
MayorDigitoRepetido(a, n);

    system("pause");
}
int leerN(int limInf, int limSup){
    int x;
    do
    {
        cout<<"Ingrese un numero en el rango ["<< limInf<< "..." << limSup <<endl; cin>>x;
    } while ((x < limInf) || (x>limSup)); 
    return x;
}
void LeerArreglo(int v[], int n1){
    cout<<"INGRESO DE NUMEROS EN EL ARREGLO "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<" Posicion ["<< i << "]: " <<endl; cin>> v[i];
    }
}

void OrdenSeleccion(int v[], int n1){
    int min, aux;
    for(int i=0; i < n1; i++)
	{
        min = i;                         // 3 
        for (int j = i+1 ; j < n1; j++) //3 2 1 5 4 
        {
            if(v[j] < v[min]){ // //2<3, 1<2, 1<5, 1<5
                min=j;                      // 2, 1
            }
           
        }
        aux = v[i]; 
        v[i] = v[min];  
        v[min] = aux;        
    }
}

void ImprimirArreglo(int v[], int n1)
{
    cout<<"Contenido del arreglo"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"Posicion: ["<< i << "]: "<< v[i] <<endl;
    }
}

void MayorDigitoRepetido(int v[], int n1){ // busca mayor digitos que se repiten
 int max_count = 0;						// variable max_count almacenador
for (int i = 0; i < n1; i++) { // primera posicion asigna aux = v[0]
    int aux = v[i];						
    int count = 0; 						// contador
    for (int j = 0; j < n1; j++) {		
        if (v[j] == aux) {				// Compara si son iguales v[0] = aux, v[1] = aux etc...
            count++;
        }
    }
    if (count > max_count) {  // alamacena el numero mayor de count
        max_count = count;
    }
}

if (max_count <= 1) {
    cout << "No existe digitos repetidos...\n" << endl;
} else {
    cout << "NUMEROS CON MAS REPETICIONES: ";
    for (int i = 0; i < n1; i++) {  
        int aux = v[i];
        int count = 0;
        for (int j = 0; j < n1; j++) {
            if (v[j] == aux) {
                count++;
            }
        }
        if (count == max_count) {
            cout << aux << ", ";
        }
    }
    cout << endl;
}
}
