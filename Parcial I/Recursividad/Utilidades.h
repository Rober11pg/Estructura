int Leern()
{
    int x;
    cout << "Ingresar un valor positivo" << endl;
    cin >> x;  // var de lectura
    if (x < 1) // valor no admitido
    {
        x = Leern(); // vikver a ubgresar un valor
    }
    return x; // devolver el valor leído
}