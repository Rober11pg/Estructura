/*Permitir el ingreso de varios números enteros, y proceder 
a ordenarlos descendentemente en base a la cantidad de dígitos
 pares que poseen (aplique ordenamiento por inserción en caso de requerirlo)
 Autor: Roberto Jiménez
 Código: 7048*/
 
#include <iostream>
#define EXT 10
using namespace std;

int main() {
    system("color f0");
    int n, m, a[EXT];
    int LeerN(int limInf, int limSup);
    void LeerArreglo(int v[], int n1);
    void Inserccion(int z[], int n1);
    void ImprimirArreglo(int v[], int n1);
    int DigitosPares(int num);
    n = LeerN(1, EXT);
    LeerArreglo(a, n);

    ImprimirArreglo(a, n);
    cout << "" << endl;
    return 0;
}

int LeerN(int limInf, int limSup) {
    int x;
    do {
        cout << "Ingrese un número en el rango [" << limInf << "..." << limSup << "]" << endl;
        cin >> x;
    } while (x < limInf || x > limSup);

    return x;
}

void LeerArreglo(int v[], int n1) {
    cout << "INGRESO DE NUMEROS EN EL ARREGLO " << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Posicion [" << i << "]: " << endl;
        cin >> v[i];
    }
}

void Inserccion(int z[], int n1) {
    int pos, aux;
    for (int i = 0; i < n1; i++) {
        pos = i;
        aux = z[i];

        while ((pos > 0) && (z[pos - 1] > aux)) {
            z[pos] = z[pos - 1];
            pos--;
        }
        z[pos] = aux;
    }
}

int DigitosPares(int num) {
    int cont = 0;
    while (num > 0) {
        int dig = num % 10;
        if (dig % 2 == 0) {
            cont++;
        }
        num /= 10;
    }
    return cont;
}

void ImprimirArreglo(int v[], int n1) {
    cout << "Contenido del arreglo" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Posicion: [" << i << "]: " << v[i] << endl;
    }
}
