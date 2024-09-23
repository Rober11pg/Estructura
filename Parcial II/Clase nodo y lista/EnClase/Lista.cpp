// Implementa la gestion basica de nodos de una lista

using namespace std;
#include <iostream>
#include "Nodo.h"

int main()
{
    system("color f0");
    Nodo n;            // constructor por defecto
    Nodo n1(104);      // contructor conociendo el valor a almacenar en el atributo dato
    Nodo n2(103, &n1); // condtructur conociendo y la dirección de memoria
    n.setDatos(105);
    cout << "El valor almancenado en el nodo es: " << n.getDato() << endl;
    cout << "El valor al que apunta es: " << n.getPunt() << endl;

    cout << "El valor almancenado en el segundo nodo es: " << n1.getDato() << endl;
    cout << "El valor al que apunta es: " << n1.getPunt() << endl;

    cout << "El valor almancenado en el tercer nodo es: " << n2.getDato() << endl;
    cout << "El valor al que apunta es: " << n2.getPunt() << endl;

    n1.setPunt(&n);
    cout << "El valor almancenado en el nodo es: " << n.getDato() << endl;
    cout << "El valor al que apunta es: " << n.getPunt() << endl;
    Nodo *aux; // var para recorrer la lista
    aux = &n2; // la lista empieza en
    cout << "> " << aux->getDato() << endl; // 103
    aux = n2.getPunt();                     // solva a apuntar no va a modficar su valor
    cout << "> " << aux->getDato() << endl; // 104
    aux = n1.getPunt();
    cout << "> " << aux->getDato() << endl; // 105
    system("pause");
}
