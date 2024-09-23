#include <iostream>
using namespace std;
int main()
{

    int Leern(int limInferior, int limSuperior);
    void Base(int b, int a, int *p, int *t);
    void CalExponente(int b, int a, int *p, int *t);
    int b, a, p = 0, t = 1;
    b = Leern(0, 300);
    a = Leern(0, 300);
    if (a == 0)
    {
        cout << "La resultado de " << b << "^ " << a << " =" << 1 << endl;
    }
    else
    {
        CalExponente(b, a, &p, &t);
        cout << "La resultado de " << b << "^ " << a << " =" << t << endl;
    }
    return 0;
    system("pause");
}

int Leern(int limInferior, int limSuperior)
{
    int x;
    cout << "Ingresar las variables " << endl;
    cin >> x;
    if (x < limInferior || x > limSuperior)
    {
        Leern(limInferior, limSuperior);
    }
}

void Base(int b, int a, int *p, int *t)
{
    if (b > 0)
    {
        *p += *t;
        Base(b - 1, a, p, t);
    }
    *t = *p;
}

void CalExponente(int b, int a, int *p, int *t)
{
    if (a > 0)
    {
        *p = 0;
        Base(b, a, p, t);
        CalExponente(b, a - 1, p, t);
    }
}
