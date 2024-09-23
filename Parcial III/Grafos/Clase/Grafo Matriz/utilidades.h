#include<iostream>
using namespace std;

int Leern()
{
    int x;
    cout << "Ingresar un valor positivo" << endl;
    cin >> x;  // var de lectura
    if (x < 1) // valor no admitido
    {
        x = Leern(); // vikver a ubgresar un valor
    }
    return x; // devolver el valor le�do
}

int Leerx()
{
    int x;
    cout << "Ingresar un valor diferente de 0" << endl;
    cin >> x;  // var de lectura
    if (x == 0) // valor no admitido
    {
        x = Leerx(); // vikver a ubgresar un valor
    }
    return x; // devolver el valor le�do
}
// Utilidades para los puntos de la cirfunferencia
double PinicialA()
{
    double a;
    cout << "Ingresar el punto inicial A" << endl;
    cin >> a;
    return a;
}
double PfinalB()
{
    double b;
    cout << "Ingresar el punto final B" << endl;
    cin >> b;
    return b;
}

// Utilidades para areglo
int LeerN(int limInf, int limSup)
{          // funci�n que lee el valor de n
    int x; // variable de lectura de datos
    do
    {
        cout << "Ingrese un valor comprendido en el rango [" << limInf << "..." << limSup << "]" << endl;
        cin >> x;
    } while (x < limInf || x > limSup); // limites para el rango del n�mero
    return x;
}
void LeerArreglo(int v[], int n1, int i)
{
    
    if (i < n1)
    {
    	LeerArreglo(v, n1, i + 1);
        cout << "Posicion: [" << i + 1 << "]: " << endl;
        cin >> v[i];
    }
}

// Impresion del arreglo
void IprimirAsc(int v[], int n1, int i)
{
    if (i < n1)
    {
    	IprimirAsc(v, n1, i + 1);
        cout << "Posicion: [" << i + 1 << "] " << v[i] << endl;
        
    }
}

void IprimirDes(int v[], int n1, int i)
{
    if (i >= 0)
    {
    	IprimirDes(v, n1, i-1);
        cout << "Posicion: [" << i << "] " << v[i] << endl;
       
    }
}
