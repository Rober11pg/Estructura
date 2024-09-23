/* 10. Determinar las letras más repetidas encontradas en una cadena ingresada (evitar repeticiones)
Autor: Roberto Jiménez
Código: 7048 */
#include <iostream>
#include <string>
#include <ctype.h>
#define EXT 26
using namespace std;

int main()
{
    string cadena;
    int frecuencia[EXT] = {0};
    char max_letras[EXT];
    int num_max_letras = 0;
    int max_frecuencia = 0;
    void LeerCadena(string * cadena);
    void calcularFrecuencia(string cadena, int frecuencia[], int i);
    void encontrarMaxFrecuencia(int frecuencia[], char max_letras[], int &num_max_letras, int &max_frecuencia, int i);
    void imprimirMaxFrecuencia(char max_letras[], int num_max_letras, int i);
    LeerCadena(&cadena);
    calcularFrecuencia(cadena, frecuencia, 0);
    encontrarMaxFrecuencia(frecuencia, max_letras, num_max_letras, max_frecuencia, 0);
     cout << "Las letras mas repetidas son: ";
    imprimirMaxFrecuencia(max_letras, num_max_letras, 0);

    return 0;
}

void LeerCadena(string *cadena)
{
    cout << "Ingrese una cadena, y termine con un punto la oracion: ";
    getline(cin, *cadena, '.');
}

void calcularFrecuencia(string cadena, int frecuencia[], int i)
{
    if (i < cadena.length())
    {
        if (isalpha(cadena[i]))
        {
            int indice = tolower(cadena[i]) - 'a';
            frecuencia[indice]++;
        }
        calcularFrecuencia(cadena, frecuencia, i + 1);
    }
}

void encontrarMaxFrecuencia(int frecuencia[], char max_letras[], int &num_max_letras, int &max_frecuencia, int i)
{
    if (i < 26)
    {
        if (frecuencia[i] > 0)
        {
            if (frecuencia[i] > max_frecuencia)
            {
                max_frecuencia = frecuencia[i];
                max_letras[0] = 'a' + i;
                num_max_letras = 1;
            }
            else if (frecuencia[i] == max_frecuencia)
            {
                max_letras[num_max_letras] = 'a' + i;
                num_max_letras++;
            }
        }
        encontrarMaxFrecuencia(frecuencia, max_letras, num_max_letras, max_frecuencia, i + 1);
    }
}

void imprimirMaxFrecuencia(char max_letras[], int num_max_letras, int i)
{
    if(i < num_max_letras)
    {  
        cout << max_letras[i] << " ";
        imprimirMaxFrecuencia(max_letras, num_max_letras, i+1);
    }
    cout << endl;
}
