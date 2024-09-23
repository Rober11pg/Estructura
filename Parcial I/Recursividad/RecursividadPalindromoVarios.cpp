/*
recursividad
Programa de gesetión de cadenas
Autor: Roberto Jiménez
*/
#include <iostream>
#include <cstring>
#define EXT 15 // cte que marca el tamaño macimo de la estructura
using namespace std;
int main()
{ // programa principal
    system("color f0");
    char f[EXT];            // vector que contiene la cadena original
    char pal[EXT / 2][EXT]; // matriz que contiene las palabras original
    int np;                 // cantidad de palabras de la cadena
    bool espalindromo(char f[]);
    void pasarAPalabras(char f[], char p[][EXT], int *npal); // prototipo de la cunion
                                                             // si le envío como parametros no hay que ponerle valores al vector
                                                             // se pasa por refenecia el vector de la matriz
    cout << "Ingrese una cadena de caracteres: " << endl;
    cin.getline(f, EXT, '.') >> f; // llamado a separación de palabras
    pasarAPalabras(f, pal, &np);

    cout << endl;                // todo aquello que no es letra le pone fin de cadena, queda memoria intermedia eso se llama bufer
    for (int i = 0; i < np; i++) // ciclo de recorrido de las palabras que contan en la matriz
    {
        cout << "La palabra ingresada es: " << pal[i] << endl; //
        cout << "Esa cadena " << (espalindromo(pal[i]) ? "si" : "no") << " es un plindromo..." << endl;
    }
    system("pause");
}
bool espalindromo(char f[])
{
    int i, j;
    j = strlen(f) - 1;
    for (i = 0; (i < j); i++, j--)
    {
        if (f[i] != f[j])
        {
            return false;
        }
    }
    return true;
}

void pasarAPalabras(char f[], char p[][EXT], int *npal)
{
    // 3 contadores 1 vector, 2 para matriz
    int i, j, k;                      // i para reccreer vector, j matriz filas, k matriz columnas
    j = k = 0;                        // incializar posiciones en matriz // contador vanual
    for (i = 0; (i < strlen(f)); i++) // ciclo de recorrido de la cadena original // i contador de recorrido
    {
        if (((f[i] >= 'A') && (f[i] <= 'Z')) || ((f[i] >= 'a') && (f[i] <= 'z')))
        {                   // si es letra pasa a la matriz
            p[j][k] = f[i]; // transferir una letra desde la cadena original hacial la matriz
            k++;            // posicionarse en la siguiente columna de la misma palabra
        }
        else
        {                   // cuando no se ecuentra una letra
            p[j][k] = '\0'; // insertar el marcador de fin de cadena para transformar una palabra de nuevo a cadena
            j++;            // incrementa contador de filas
            k = 0;          // marcador de columna vuelve a incio de la palabra
        }
    }
    j++;            // incrementa contador de filas
    p[j][k] = '\0'; // insertar el marcador de fin de cadena para transformar una palabra de nuevo a cadena
    *npal = j;      // para actualizar cantidad de palabras de la frase
}

// llamado esta activa las variables pueden cambiar
// sume acomule, multiplique sería retorno
