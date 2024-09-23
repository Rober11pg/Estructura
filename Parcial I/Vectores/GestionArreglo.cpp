/* Programa que implementa gestión basica de un arreglo
   Autor: Roberto Jiménez 
   Código: 7048 
   declarar tipo entero para que no de error
// Implementar solo variables locales por que puede haces las globales es pecado por que incita al error */
#include<iostream> //Archivos de cabecera, lecturas e impresiones 

#define  EXT 10 // Definicion de la extension del arreglo; SIEMPRE DEBE IR CON MAYUSCULAS 

using namespace std; // espacio de memorias estandar, consola 

int main()  // declarar tipo entero para que no de error 
{ 
    // system("color fc"); // cambia el color de pantalla fondo blanco colo rojo 
    system("color f0"); // fondo blanco letra negra 
    int a[EXT];
    int n;
    // El prototipo de la funcion va dentro del main 

    int LeerN(int lim); // Protipo de la función, que ubgresar ka cabtudad de va
    void LeerArreglo(int *z, int n1); 
    void ImprimirArreglo(int *z, int n1);

    n = LeerN(EXT);
    LeerArreglo(a, n);
    ImprimirArreglo(a, n);

    cout<<" "<<endl;
    system("pause");
    return 0;    // el return 0 es cuando devuelve un valor 
}

int LeerN(int lim){
    int x; // variable de lectura 
    do
    {
        cout<<"Cantidad de valores a procesar [ 1.."<< lim << "]" <<endl;
        cin>>x;
    } while ( (x < 1)  || (x > lim));
    return x;
}

void LeerArreglo(int *z, int n1){ // si es variable unidimencional toca pasarle sin dimecion
    cout<<"Ingreso de valores al arreglo"<<endl;
    //for (int i = 0; i < n1; i++)
    //{
        //cout<<"Posicion ["<< i + 1  << "] "<<endl;
       // cin>> z[i];
   // }
   cin>> *z;
}

void ImprimirArreglo(int *z, int n1){
    cout<<"Contenido del arreglo "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"Posicion ["<< i + 1  << "]: "<< z[i] <<endl;
    }
}
