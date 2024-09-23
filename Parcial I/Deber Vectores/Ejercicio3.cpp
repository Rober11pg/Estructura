/*Generar los factores primos de cada uno de varios números 
ingresados por el usuario (aplique el algoritmo de búsqueda binaria 
y ordenamiento por el método de la burbuja, en caso de requerirlo)
Autor: Roberto Jiménez
Código: 7048*/
#include <iostream>
#define EXT 10
using namespace std;

int main() {
    system("color f0");
    int n, a[EXT];
    int LeerN(int limInf, int limSup);
    void LeerArreglo(int v[], int n1);
    void Imprimir(int v[], int n1);
    void Burbuja(int v[], int n1);
    int Busqueda_Binaria(int v, int z[], int n1);
    void FactoresPrimos(int v, int z[], int n1);

    n = LeerN(1, EXT);
    LeerArreglo(a, n);
    Burbuja(a, n);
    Imprimir(a, n);

    for (int i = 0; i < n; i++) {
        cout << "Factores primos de " << a[i] << ": ";
        FactoresPrimos(a[i], a, n);
        cout << endl;
    }

    return 0;
}

int LeerN(int limInf, int limSup) {
    int x;
    do {
        cout << "Ingrese un número en el rango [" << limInf << "..." << limSup << "]: ";
        cin >> x;
    } while (x < limInf || x > limSup);

    return x;
}

void LeerArreglo(int v[], int n1) {
    cout << "INGRESO DE NUMEROS EN EL ARREGLO" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Posicion [" << i << "]: ";
        cin >> v[i];
    }
}

void Burbuja(int v[], int n1) {
    for (int i = 1; i < n1; i++) {
        for (int j = 0; j < (n1 - i); j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int Busqueda_Binaria(int v, int z[], int n1) {
    int ini, fin, med;
    ini = 0;
    fin = n1 - 1;

    while (ini <= fin) {
        med = (ini + fin) / 2;
        if (z[med] == v) {
            return med;
        } else {
            if (z[med] > v) {
                fin = med - 1;
            } else {
                ini = med + 1;
            }
        }
    }

    return -1;
}

void FactoresPrimos(int v, int z[], int n1) {
    int i = 2;
    while (v > 1) {
        if (v % i == 0) {
            cout << i << " ";
            v /= i;
        } else {
            i = z[Busqueda_Binaria(i + 1, z, n1)];
        }
    }
}

void Imprimir(int v[], int n1) {
    cout << "CONTENIDO DEL ARREGLO" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Posicion: [" << i << "] " << v[i] << endl;
    }
}
