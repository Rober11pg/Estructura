#include<iostream>
#define EXT 10
using namespace std;

int main(){
    system("color f0");
    int n, m, a1[EXT], a2[EXT], a3[EXT*2];
    int LeerN(int limInf, int limSup);
    void LeerArreglo(int v[], int n1);
    void Inserccion(int v1[], int n1); // Prototipo de método de insercción
    void UnirArreglos(int v1[], int v2[], int n1, int n2, int v3[]);
    
    n = LeerN(1, EXT);
    LeerArreglo(a1, n);
    m = LeerN(1, EXT);
    LeerArreglo(a2, m);
    Inserccion(a1, n); // v1[] ordenado ascendente mente
    Inserccion(a2, m); // v2[]	ordenado ascendente mente
    UnirArreglos(a1, a2, n, m, a3); // llamado de la union de lo arreglos 

    return 0;
}

int LeerN(int limInf, int limSup)
{
    int x;
    do
    {
        cout<<"Ingrese un número en el rango [" << limInf << "..." << limSup << "]"<< endl; 
        cin>>x;
    } while (x < limInf || x > limSup);

    return x;
}

void LeerArreglo(int v[], int n1)
{
    cout<<"INGRESO DE NUMEROS EN EL ARREGLO "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"Posicion [" << i << "]: " << endl; 
        cin>> v[i];
    }
}

void Inserccion(int v1[], int n1) // Arreglo de los elementos de manera ascendente
{
   int pos, aux;
    for (int i = 0; i < n1; i++) {
        pos = i;
        aux = v1[i];

        while ((pos > 0) && (v1[pos - 1] > aux)) {
            v1[pos] = v1[pos - 1];
            pos--;
        }
        v1[pos] = aux;
    }
}

void UnirArreglos(int v1[], int v2[], int n1, int n2, int v3[])
{
	int i = 0, j = 0, k = 0; // v1[] = 1, 2 ; v2[] = 1, 2 ,3
	while (i < n1 && j < n2)  // 
	{
		if (v1[i] < v2[j]) 
		{
			v3[k++] = v1[i++];
		}
		else if (v2[j] < v1[i]) 
		{
			v3[k++] = v2[j++];
		}
		else 
		
		{ // Si ambos elementos son iguales, sólo se añade uno
			v3[k++] = v1[i++];
			j++; // Se incrementan ambos índices para evitar agregar duplicados
		}
	}
	while (i < n1) 
	{
	    v3[k++] = v1[i++];
	}
	
	while (j < n2) 
	{
	    v3[k++] = v2[j++];
	}
	
	int n3 = k; // número de elementos en el arreglo unión
	
	// Eliminación de duplicados en el arreglo unión
	int prev = v3[0];
	int idx = 1;
	for (int i = 1; i < n3; i++) 
	{
	    if (v3[i] != prev) {
	        v3[idx++] = v3[i];
	        prev = v3[i];
	    }
	}
	
	// Actualización del número de elementos en el arreglo unión
	n3 = idx;
	
	cout << "CONTENIDO DEL ARREGLO UNION" << endl;
	for (int i = 0; i < n3; i++) 
	{
	    cout << "Posicion [" << i << "]: " << v3[i] << endl;
	}
}