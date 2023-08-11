int Leer_N(){
    int num;

    cout<<"\t(ingresa un valor entero pos.)  "<<endl;
    cin>> num ; 

    if(num <= 0){
        num = Leer_N();
    }

    return num;
}


//void Pasar_frase_min(char f[]){
    
//    for(int i = 0; i < strlen(f); i++) {
//        f[i] = tolower(f[i]);
//    }
//}
