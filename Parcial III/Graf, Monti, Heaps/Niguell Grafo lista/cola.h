// TDA COLA
typedef int Tipo;
#define EXT 20
class Cola
{		 // Definicion de clase
private: // Atributos
	int frente;
	int final;
	Tipo elem[EXT]; // Arreglos de valores de la cola
public:				// Metodos
	Cola();
	void setFrente(int x);		// Actualiza atributo frente
	void setFinal(int x);		// Actualiza atributo final
	void setElem(int v, int p); // Actualiza atributo elem[x,p]
	int getFrente();			// Retorna atributo frente
	int getFinal();				// Retorna atributo final
	Tipo getElem(int p);		// Retorna elemento atributo elem
	void borrarCola();			// Vuelve a inicializar el TDA
	bool colaVacia();			// Retorna si la cola esta vacia
	bool colaLlena();			// Retorna si la cola esta lleno
	int tamanioCola();			// Retorna tamanio cola
	Tipo extraerVal();			// Extrae y elimina un elemento del TDA
	void insertarVal(Tipo x);	// Inserta un elemento en el TDA
	Tipo frenteCola();			// Devuelve elemento del frente de la cola
};

Cola::Cola()
{
	setFrente(0); // Inicializr la pos apuntada por frente
	setFinal(-1); // Inicializr la pos apuntada por final
}
void Cola::setFrente(int x)
{
	frente = x;
}
void Cola::setFinal(int x)
{
	final = x;
}
void Cola::setElem(int v, int p)
{
	elem[p] = v;
}
int Cola::getFrente()
{
	return frente;
}
int Cola::getFinal()
{
	return final;
}
Tipo Cola::getElem(int p)
{
	return elem[p];
}
void Cola::borrarCola()
{
	setFrente(0);
	setFinal(-1);
}

bool Cola::colaVacia()
{
	return (getFinal() < getFrente());
}

bool Cola::colaLlena()
{
	return (getFinal() == EXT - 1);
}

int Cola::tamanioCola()
{
	return (getFinal() - getFrente() + 1);
}

Tipo Cola::extraerVal()
{
	Tipo x; // var para contener el valor a devolver
	if (!colaVacia())
	{
		x = getElem(getFrente());
		setFrente(getFrente() + 1);
		return x;
	}
	return x;
}

void Cola::insertarVal(Tipo x)
{
	if (!colaLlena())
	{
		setFinal(getFinal() + 1);
		setElem(x, getFinal());
	}
}

Tipo Cola::frenteCola()
{
	Tipo x; // var para contener el valor a devolver
	if (!colaVacia())
	{
		x = getElem(getFrente());
		// return x;
	}
	return x;
}