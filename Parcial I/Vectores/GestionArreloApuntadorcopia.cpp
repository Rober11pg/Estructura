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
    int a[EXT]; // es el vector de 10 elementos 
    int n; // la cantidad de elementos que quiero ingresar
    // El prototipo de la funcion va dentro del main 

    int LeerN(int limInf, int limSup ); // Protipo de la función, que ubgresar ka cabtudad de va
    void LeerArreglo(int *z, int n1); 
    void ImprimirArreglo(int *z, int n1);// se puede cambiar el nombre por que ada uno tiene su juego de variables 
    int Busqueda_Binaria(int v, int z[], int n1);
    void InsertarElemento(int z[], int *n1); // se pone como n como referencia para poder cambiarle el valor 

    void ElminarElemento(int z[], int *n1); // elimina elementos de un arreglo
    int buscar(int v, int z[], int n1);
    void EliminarElemento2(int *z, int *n1); // eliminar elementos 2 ya no hay que buscar la posicion
    
    


    cout<<"Cantidad de valores a procesar"<<endl;
    n = LeerN(1, EXT);
    LeerArreglo(a, n);
    ImprimirArreglo(a, n);
   InsertarElemento(a, &n); // reucorrerlos hacia la derecha para darles un lugar
    ImprimirArreglo(a, n);//
   // ElminarElemento(a, &n);
   // ElminarElemento(a, &n); // eliminar elemento por posicion 
    EliminarElemento2(a, &n);// eliminar elemento por el dato
    ImprimirArreglo(a, n);
/*int enc = Busqueda_Binaria(10, a, n);
cout<<"El valor 10 "<< ((enc >=0) ? "si " : "NO") << " se ecuentra el arreglo..." <<endl;*/    

/*if(enc >=0) 
{
    cout<<"FELICITACIONES, EL VALOR 10 SE ECUENTRA EN LA POSICICION "<< enc << endl;
}
else
{
  cout<<"LO SIENTO... EL VALOR 10 NO SE ECUENTRA EN EL ARREGLO.. SIGA PARTICIPANDO"<<endl;
}*/



    cout<<" "<<endl;
    system("pause");
    return 0;    // el return 0 es cuando devuelve un valor 
}

int LeerN(int limiInf, int limSup)
{
    int x; // variable de lectura 
    do
    {
        cout<<"Ingrese un valor entero comprendido en el rango ["<< limiInf << "..."<< limSup<< "]" <<endl;
        cin>>x;
    } while ( (x < limiInf)  || (x > limSup)); // le doy los limites inferiores o superiores para poder usar la función 
    // en este caso no tienes que pasar de los límites superiores por que si no la condición regresa hasta que se cumpla el valor 
    // por la condición ingresada 
    return x;
}

void LeerArreglo(int *z, int n1){ // si es variable unidimencional toca pasarle sin dimecion
    cout<<"Ingreso de valores al arreglo"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"Posicion ["<< i  << "] "<<endl;
       cin>> *z++; 
       // z++
   }    
}

void ImprimirArreglo(int *z, int n1){
    cout<<"Contenido del arreglo "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"Posicion ["<< i  << "]: "<< z[i] <<endl;
    }
}
void InsertarElemento(int z[], int *n1){ // funcion que inserta elementos de un arreglo 
    cout<<"Inserccion de un nuevo elemento en el arreglo"<<endl;
    int val, pos;
    cout<<"Ingrese el valor a insertar: "<<endl;
    cin>> val;

    cout<<"Ingrese la posicion en que desea insetar el valor: "<<endl;
    // pos = LeerN(0, (*n1)-1);  // (*n1)-1 se le resta -1 por que el vector empieza z[0]. // revisar 
    pos = LeerN(0, (*n1)-1);
    for (int i = *n1; i >= pos; i--)
    {
        z[i] = z[i-1];
    }
    z[pos] = val;
    *n1 = *n1 + 1; // para pasar de vector se recorre *n1
}

void ElminarElemento(int *z, int *n1){ // elemina elementos de arregla
    cout<<"Eliminacion de en el arreglo"<<endl;
    int pos;

    cout<<"Ingrese la posicion en que desea eliminar el valor: "<<endl;
    pos = LeerN(0, (*n1)-1);  // (*n1)-1 se le resta -1 por que el vector empieza z[0]. 
    for (int i = pos; i <= (*n1-1); i++)
    {
        z[i] = z[i+1];
    }
    *n1 = *n1 +1;
    
}

int buscar(int v, int z[], int n1){ // si el elemento del vector no existe tendría que recorrer todos las posiciones del vector, ahor plantea si se utlian 10000 datos sería más tardado en realizar más procesos
    for(int i = 0; i< n1; i++){
        if(v == z[i]){
            return i;
        }
    }
    return -1; // -1 Es in comvencionalismo- las posiciones de un arreglo son enteros positivos >= 0
}

void EliminarElemento2(int *z, int *n1){
    int val;
    int pos;

    cout<<"Ingrese el numero que desee eliminar: "<<endl;
    cin>> val;
    // pos = buscar(val, z, *n1); // busca la posicion 
    pos = buscar(val, z, *n1);

        if(pos != 1){
        for (int i = pos; i <= (*n1-1); i++) //(*n1-1) 
    {
        z[i] = z[i+1];
    }
    *n1 = *n1 - 1;
    }
    else
    cout<<"El valor no existe en el arreglo"<<endl;
    
}


int Busqueda_Binaria(int v, int z[], int n1){ // busqueda binaria 
    int ini, fin, med;
    ini =0; // posicion inicial del arreglo
    fin = n1-1; // posicion final del arreglo

    while (ini <= fin ) // miestras posicion de ref inicial esta a la izq de pos de refe fina < o <= no puede ser mayor
    {
        med = (ini + fin)/2; // Calcular la posicion mitad
        // operandos enteros resp es entero 
        // mesclas valor float, entero el dígito con mayor gerarquía toma el valor predominante
        if(z[med] == v){
            return med; // devolver posicion en la que se ecuentra v
        }
        else{       // no econtrado v en pos med
            if(z[med]> v) // cuando elemento pos central es mayor que v
            {
                fin = med -1;  // nuevo valor final de ref es el anterior a med
            }
            else{       // cuando el elemento pos central es menor que v 
                ini = med +1; // nuevo valor inicial de ref es el posterior a mee
            }
        }
    }
    return -1; // devolver valor de no econtrado 
    

}
