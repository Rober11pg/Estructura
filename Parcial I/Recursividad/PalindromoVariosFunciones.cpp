#include<iostream>
#include<cstring>
#define EXT 15 // cte que marca el tamaño maximo de la estructura
using namespace std;



int main() {     
    system("color f0");
    char f[EXT]; 
    char pal[EXT/2][EXT]; 
    int np = 0; 
    // Prototipos de funciones
    void LeerCadena(char f[]);
	bool esPalindromo(char f[]);
	void pasarAPalabras(char f[], char p[][EXT], int *npal);
	void Imprimir(char f[], char p[][EXT], int *npal);
	
  	LeerCadena(f); 
  	pasarAPalabras(f, pal, &np);
    Imprimir(f, pal, &np);

    
    
    system("pause");
    return 0;
}

void LeerCadena(char f[]){
	cout << "Ingrese una cadena de caracteres: " << endl;
    cin.getline(f, EXT, '.'); 
    
}


bool esPalindromo(char f[]) {
    int i, j;
    j = strlen(f) - 1;
    for (i = 0; (i < j); i++, j--) {
        if (f[i] != f[j]) {
            return false;
        } 
    }
    return true;  
}

void pasarAPalabras(char f[], char p[][EXT], int *npal) {
    int i, j, k; 
    j = k = 0; 
    for (i = 0; i < strlen(f); i++) {
        if (((f[i] >= 'A') && (f[i] <= 'Z')) || ((f[i] >= 'a') && (f[i] <= 'z'))) {
            p[j][k] = f[i]; 
            k++;
        } else {
            p[j][k] = '\0'; 
            j++;            
            k = 0;          
        }  
    }
    p[j][k] = '\0'; 
    *npal = j + 1; 
}

void Imprimir(char f[], char p[][EXT], int *npal){
	for (int i = 0; i < *npal; i++) {
        cout << "La palabra ingresada es: " << p[i] << endl; 
        cout << "Esa cadena " << (esPalindromo(p[i]) ? "si" : "no") << " es un palindromo." << endl;
    }
}