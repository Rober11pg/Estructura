#include <iostream>
#include <string>
#define EXT 100
#define MAX 20
using namespace std;

int main()
{
    system("color f0");

    string cadenas[EXT];
    void ingresarCadenas(string * cad, int n, int i);
    void imprimirCadenas(string * cad, int n, int i);

    cout << "\nINGRESO DE CADENAS\n";
    ingresarCadenas(cadenas, EXT, 0);
    cout << "\nCadenas ingresadas:\n";
    imprimirCadenas(cadenas, EXT, 0);

    return 0;
}

void ingresarCadenas(string *cad, int n, int i)
{
    if (i < EXT)
    {
        cout << "Ingrese la cadena...[Finalice con la palabra FIN]"
             << ": ";
        getline(cin, cad[i]);

        if (cad[i] != "FIN")
        {
            ingresarCadenas(cad, n, i + 1);
        }
    }
}

int transformarClave(char c[]) // funcion que transfroma una cadena en una valor númerico
{
    // ir acomulando los códigos asqui de la cadena
    int ac = 0;                         // variable acumuladora de códigos aqui de los caracteres de la cadena
    for (int i = 0; i < strlen(c); i++) // ciclo de recorrido de la cadena
    {
        ac += int(c[i]); // acomular el código asqui del caracter de posicion i
    }
    return ac; // devolver ac
}

int dispersionModular(int v) //funcion que calcula valor de dispersion de v aplicando aritmetica modular
{ 
    return v % NC; // devolver el modulo clave vs cantidad disponible de ubicaciones en el arreglo
}
void imprimirCadenas(char[][EC], int n1)
{
    int nClave; // expresión númerica correspondiente a la clave

    for (int i = 0, i < n1; i++)
    {
        cout << "> " << c[i] << endl;
        nClave = transformarClave(c[i]); // calcula la expresión númerica la clave actual;
        cout << "Clave númerica: " << nClave << endl;
        cout<<"Dispersion modular"<< dispersionModular(nClave);
    }
}