/* Ver los factores de un número mediante recursividad
    Nombre: Roberto Jiménez
    Código: 7048*/

    #include<iostream>
    #define NUM 10
    using namespace std;
    int main(){
        system("color f0");
    	int n;

        int IngresarNumero(int limInf, int limSup);
        void FactoresNumeros();
        n = IngresarNumero(1,  NUM);
        system("pause");
    }

    int IngresarNumero(int limInf, int limSup){
        int x;
        do
        {
            cout<<"Ingrese el dígito de un número "<<endl;
            cin>>x;
        } while ((x > limInf )|| (x < limSup));
        
        
        return 
    }