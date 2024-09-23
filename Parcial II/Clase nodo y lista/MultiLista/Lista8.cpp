using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 99999 // marcador de final de lectura
#define EXT 99   // extension maxima de los vectores

int main()
{
    int nums[EXT];
    Lista Listas[EXT]; // vector de listas de digitos

    int n = 0; // cantidad de elementos a procesar

    void ingresarNumeros(int nu[], int *n1);           // prototipo de la funcion de ingreso de valores
    void imprimirNumeros(int nu[], Lista l[], int n1); // prototipo de la funcion que impreme el valor dad
    void generarListas(int nu[], Lista l[], int n1);   // prototipo de la funcion que genera la lista de digitos de cada numero
    ingresarNumeros(nums, &n);
    generarListas(nums, Listas, n); // llamado a funcion que genera la lista de numeros
    imprimirNumeros(nums, Listas, n);
    // imprimirNumeros(nums, n);
    cout << "" << endl;
    system("pause");
    return 0;
}

void ingresarNumeros(int nu[], int *n1) // prototipo de la funcion de ingreso de valores'
{
    int aux;

	cout << "Ingrese un numero entero.. Finalice con [" << FIN << "] " << endl;
    cin >> aux;

    if ((aux != FIN) && (*n1 < EXT)) // NO ingresa el valor de fin y aun hay espacio en el vector
    {
		nu[*n1] = aux; // aÃ±adir el elemento en el vector
        (*n1)++;       // el valor apuntado por el apuntador n1 debe incrementarse // contar el elemento aÃ±adido
        ingresarNumeros(nu, n1);
    }
}

void imprimirNumeros(int nu[], Lista l[], int n1)
{
    cout << "Valores procesados " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "> " << nu[i] << endl;
        Nodo *act;               // nodo actual de la lista
        act = l[i].getPrimero(); // apunta al primer nodo de la lista
        while (act != NULL)      // no se alcanza aun el final de la lista
        {
            cout << "\t> " << act->getDato() << endl;
            act = act->getPunt();
        }
    }
}
void generarListas(int nu[], Lista l[], int n1) // prototipo de la funcion que genera la lista de digitos de cada numero
{
    int aux; // individualizar digitos
    int aux2;
    int cont = 0;
    
    
    for (int i = 0; i < n1; i++)
    {
        aux = nu[i];

        do // ciclo de individualizaciÃ³n de digitos ejem: 120,12,14
        {
            aux2 = aux % 10;
            if ((!l[i].eliminarNodo(aux2))&&(cont=0))
            {
                l[i].insertarAlInicio(aux2);
            }else
			{
				l[i].insertarAlInicio(aux2);
			}
            cont++;
            aux /= 10; // corta el digito 120, 12 ,1, 0
        } while (aux != 0);
    }
}