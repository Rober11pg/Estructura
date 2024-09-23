/* Ingresar una frase y proceda a invertir el orden de las palabras, por medio del empleo de pilas
Autor Roberto Jiménez
Codigo:7048*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void InvertirPalabras(string frase)
{
    stack<string> pila;
    string palabra;
    size_t inicio = 0;
    size_t fin = frase.find(' ');

    while (fin != string::npos)
    {
        palabra = frase.substr(inicio, fin - inicio);
        pila.push(palabra);
        inicio = fin + 1;
        fin = frase.find(' ', inicio);
    }

    // Agregar la última palabra a la pila
    palabra = frase.substr(inicio, fin);
    pila.push(palabra);

    cout << "Frase invertida: ";

    while (!pila.empty())
    {
        cout << pila.top() << " ";
        pila.pop();
    }

    cout << endl;
}

int main()
{
    string frase;

    cout << "Ingrese una frase: ";
    getline(cin, frase);

    InvertirPalabras(frase);

    return 0;
}