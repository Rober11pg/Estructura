#include <iostream>
using namespace std;

int LeerN(int liminf, int limsup)
{
    int x = liminf; // variable de lectura
    cout << "Ingrese un valor entero comprendido en el rango [" << liminf << ".." << limsup << "]" << endl;
    cin >> x;
    if ((x < liminf) || (x > limsup))
    {
        LeerN(liminf, limsup);
    }
    return x;
}