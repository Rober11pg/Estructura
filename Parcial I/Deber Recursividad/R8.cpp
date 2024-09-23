/* 8. Imprimir la tabla con las raíces cuadradas de los valores 
comprendidos entre 6.0 y 7.5 con incrementos de 0.001 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 6.0;
    double incre = 0.001;
    void imprimirTablaRaiz(double x, double incremento);
    imprimirTablaRaiz(x, incre);
    
    return 0;
}

void imprimirTablaRaiz(double x, double incremento) {
    double raiz = sqrt(x);
    cout << "La raiz cuadrada de " << x << " es " << raiz << endl;
    
    if (x + incremento <= 7.5) {
        imprimirTablaRaiz(x + incremento, incremento);
    }
}

