/* ArbolBinario1.cpp
Implementar un primer acercamiento a TDA ArbolBinario
Autro : Roberto Jiménez*/


#include <iostream>
#include "NodoBinario.h"
using namespace std;

int main()
{
    system("color f0");
    NodoBinario n1;
    NodoBinario n2(200);
    NodoBinario n3(300, &n1, &n2);

    n1.setDato(100);
    NodoBinario *act;
    act = &n3;
    cout << "Valor almacenado en el nodo " << act->getDato() << endl;
    act = n3.getIzq();
    cout << "Valor almacenado en el nodo " << act->getDato() << endl;
    act = n3.getDer();
    cout << "Valor almacenado en el nodo " << act->getDato() << endl;



    cout << endl;
    system("pause");
}