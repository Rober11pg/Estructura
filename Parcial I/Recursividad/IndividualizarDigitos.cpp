/* Prog. que permite individualizar los digitos de cada número
Autor: Roberto Jiménez  */
#include <iostream>
using namespace std;
#include "Utilidades.h"

int main()
{ // programa principal
    system("color f0");
    int n;   // cantidad de valores a procesar
    int dmt; // va a contener el digit mayor de todos los digitos mayores
    void IngresarNumeros(int n1, int *dmt); // Prototipo de la funcion que permite el ingreso de datos
    n = Leern();
    dmt = 0;                  // llamada a la funcion de ingreso cantidad valores a procesar
    IngresarNumeros(n, &dmt); // llamado a la funcion que ingresa valores
    cout << "" << endl;
    cout << "digito mayor tomado de entre los digitos mayors de cada numero:" << dmt << endl;

    system("pause");
    return 0;
}

void IngresarNumeros(int n1, int *dmt)
{ // funcion que permite el ingreso de datos
    int num;
    int DigMay; // var para contener el digit mayor de de cada número

    // debería crearse dentro de la funcion que la llama por recomendación
    void individualizarDigitos(int nu, int *dm); // protopito de la funcion que individualiza los números

    if (n1 > 0) // todavía se debe ingresar un valor
    {
        cout << "Ingrese un valor entero: " << endl;
        cin >> num;
        DigMay = 0; // por defecto, el digito mayor es 0'

        if (num == 0)
        {
            cout << "> " << num << endl;
        }
        else
        {
            individualizarDigitos(abs(num), &DigMay); // llamado a proceso de indivizualisación
        }
        cout << "El digito mayor del numero ingresado es: " << DigMay << endl;

        if (DigMay > *dmt)
        {
            *dmt = DigMay;
        }

        IngresarNumeros(n1 - 1, dmt); // llamado a lectura del siguiente vallor
        cout << "" << endl;
    }
}

void individualizarDigitos(int nu, int *dm)
{ // funcion que individualiza los números
    int dig;
    if (nu != 0)
    {
        individualizarDigitos((nu / 10), dm);
        dig = nu % 10; // extrae un digito
        cout << "> " << dig << endl;
        if (dig > *dm)
        { //  el nuevo digito extraido es mayor
            *dm = dig;
        }
    }
}
