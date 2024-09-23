
using namespace std;

int Leer_N(){
    int num;

    cout<<endl<<"ingresa el numero positivo "<<endl;
    cin>> num ; 

    if(num < 1){
        num = Leer_N();
    }

    return num;


}