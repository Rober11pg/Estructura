// archivo de cabecera con utilidades generales

int leerN(int li, int ls)
{
	int x;
	do
	{
		cout << "Ingrese un valor entero: [ " << li << " .. " << ls << " ]: ";
		cin >> x;
	} while (x < li || x > ls); // rechazar valores negativos
	return x;
}