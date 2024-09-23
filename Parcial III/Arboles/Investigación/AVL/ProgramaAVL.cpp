/* Autor: Roberto Jiménez-7048*/
typedef int Tipoelemento;

#include <iostream>
#include "stdlib.h" 
#include "NodoAvl.h"
#include "ArbolAvl.h"

using namespace std;

int main(){
	system ("color F4");
	cout<<" ..............................................."<<endl;
	cout<<"                  Arboles AVL                 "<<endl;
	cout<<" ..............................................."<<endl;	
	
	ArbolAvl a;
	Tipoelemento op,numNodos,h;
	
	void Menu(void);
	void recorrerAVL(ArbolAvl avl);
	void buscarNodo(ArbolAvl avl);
	void maxMin(ArbolAvl avl);
	void nodoAl(ArbolAvl avl);
	void imprimirAVL(ArbolAvl a);
	

	cout<<"  Llenar Arbol AVL  \n"<<endl;

	Tipoelemento n,x;
	a.Praiz(NULL);
	
    cout << "\n\t\t  INSERCION DE NODOS EN ARBOL AVL \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++) {
        cout << " Numero del nodo " << i+1 << ": "; cin >> x;
        a.insertarAvl(x);
    }
    imprimirAVL(a);
	cout<<"\n";
	cout<< "Menu Operaciones de Arbol AVL\n"<<endl;
	do {
		cout << "1. Estado de Arbol AVL.\n";
		cout << "2. Numero de Nodos y Altura.\n";
		cout << "3. Recorridos de Arbol AVL .\n";
		cout << "4. Buscar elemento del Arbol AVL.\n";
		cout << "5. Buscar Minimo y Maximo del Arbol AVL.\n";
		cout << "6. Mostar Arbol AVL.\n";
		cout << "7. Vaciar Arbol AVL.\n";
		cout << "8. Mostar todas las operaciones.\n";
		cout << "9. Salir.\n";
		do {
			cin >> op;
		} while (op<1 || op>9);
		
		switch (op) {
			case 1: cout<<" Estado de Arbol AVL:\n";cout<<endl;
				if (a.esVacio()){
				cout << endl << "El arbol aun esta vacio..." << endl ;
				}else {
					cout << endl << "El arbol esta lleno..." << endl ;
				}
				system("pause");
			break;
			case 2: imprimirAVL(a);
					nodoAl(a);
				system("pause");	
			break;
			case 3: imprimirAVL(a);
					recorrerAVL(a);
				system("pause");	
			break;
			case 4: imprimirAVL(a);
					buscarNodo(a); cout<<endl;
				system("pause");
			break;
			case 5: imprimirAVL(a);
					maxMin(a);
				system("pause");
			break;
			case 6: cout << "Mostar Arbol AVL  \n" << endl;
				imprimirAVL(a);
				system("pause");
			break;
			case 7: cout << " Vaciar Arbol AVL  \n "<< endl;
					a.vaciar(a.Oraiz());
				system("pause");
			case 8: cout << "Mostar todas las operaciones  \n" << endl;
					imprimirAVL(a);cout<<endl;
					nodoAl(a);cout<<endl;
					recorrerAVL(a);cout<<endl;
					buscarNodo(a); cout<<endl;
					maxMin(a);cout<<endl;
				system("pause");
			break;
			case 9: cout << "Salir " << endl;
			break;
				
		}
		system("cls");

	}while (op != 9);
		
	return 0;
	
	system("pause");
	return 0;
}


void nodoAl(ArbolAvl avl){
	cout << " Numero de Nodos y Altura \n";
	Tipoelemento numNodos,h;	
	numNodos = avl.cuantos();
	cout << "\n Numero de nodos: " << numNodos << endl;
	h=avl.altura1();
	cout<<" Altura = "<<h<<endl;
}

void recorrerAVL(ArbolAvl avl){		
	cout <<"Recorridos de Arbol AVL\n";
	cout << endl << "Sus nodos recorridos en Preorden son: " << endl ;
	avl.preOrden();
	cout << endl << "Sus nodos recorridos en Postorden son: " << endl ;
	avl.postOrden();
	cout << endl << "Sus nodos recorridos en orden son: " << endl ;
	avl.enOrden();cout<<endl;
}

void buscarNodo(ArbolAvl avl){	
	cout << "Buscar elemento del Arbol AVL  \n " << endl;			
	Tipoelemento x;
    cout << "\n\t\t  UBICAR UN NODO EN ARBOL BINARIO DE BUSQUEDA  \n\n";
    cout << " Valor a buscar:  ";
    cin >> x;
    cout << endl;
    
    if (!avl.buscar(x)){
    	cout << endl << "El valor ingresado NO ha sido encontrado entre los nodos del arbol binario....";
	} else {
    	cout << endl << "El valor ingresado SI ha sido encontrado entre los nodos del arbol binario....";
	}
}

void maxMin(ArbolAvl avl){	
	cout<<endl<< "Buscar Minimo y Maximo del Arbol AVL \n" ;			
	NodoAvl *max,*min;
	max=avl.buscar_max(avl.Oraiz());
	cout<<"\n Maximo = "<<max->valorNodo()<<endl;
	min=avl.buscar_min(avl.Oraiz());
	cout<<"\n Minimo = "<<min->valorNodo()<<endl;
}


void imprimirAVL(ArbolAvl avl){
	cout << endl << "VIZUALISACION DEL ARBOL AVL" << endl;
	avl.dibujarArbol(avl.Oraiz(), 0);
	cout<<endl;
}
