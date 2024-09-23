#include <iostream>
#include "Lista.h" // Incluimos el archivo de cabecera de la clase Lista

#define FIN -1 // Marcador final de lectura
#define EXT 99 // Extensión máxima de los vectores

int main()
{
    system("color 0f");
    int nums[EXT];    // Vector de números
    int menores[EXT]; // Vector de dígitos menores
    int men = 9;
    int n = 0; // Cantidad de elementos a procesar

    void ingresarNumeros(int nu[], int *n1);                  // Prototipo de la función de ingreso de valores
    void imprimirDigitosMenores(int nu[], int men[], int n1); // Prototipo de la función que imprime los dígitos menores
    int encontrarDigitoMenor(int num, int menor);             // Prototipo de la función para encontrar el dígito menor
    ingresarNumeros(nums, &n);                           // Llamado a la función de lectura de números
    for (int i = 0; i < n; i++)
    {
        menores[i] = encontrarDigitoMenor(nums[i], men);
    }
    imprimirDigitosMenores(nums, menores, n); // Llamado a la función de impresión de dígitos menores

    cout << endl;
    system("pause");
    return 0;
}

void ingresarNumeros(int nu[], int *n1)
{
    int aux; // Variable de lectura

    do
    { // Ciclo de lectura
        cout << endl
             << "Ingrese un numero entero... Finalice con [" << FIN << "]: ";
        cin >> aux;

        if ((aux != FIN) && (*n1 < EXT))
        {                  // No ingresa el valor de FIN y aún no se ha alcanzado la extensión máxima
            nu[*n1] = aux; // Añadir el elemento en el vector
            (*n1)++;       // Contar el elemento añadido
        }
    } while ((aux != FIN) && (*n1 < EXT));
}

// int encontrarDigitoMenor(int num) {
//     int menor = 9;

//     while (num != 0) {
//         int digito = num % 10;
//         if (digito < menor) {
//             menor = digito;
//         }
//         num /= 10;
//     }

//     return menor;
// }

int encontrarDigitoMenor(int num, int menor)
{
    if (num == 0)
    {
        return menor;
    }

    int digito = num % 10;
    if (digito < menor)
    {
        menor = digito;
    }

    return encontrarDigitoMenor(num / 10, menor);
}

void imprimirDigitosMenores(int nu[], int men[], int n1)
{
    cout << endl
         << "DÍGITOS MENORES";
    for (int i = 0; i < n1; i++)
    {
        cout << endl
             << "> " << nu[i] << " - " << men[i];
    }
}
