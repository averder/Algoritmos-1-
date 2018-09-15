#include "PruebasAuxEntrega1.h"

void pruebaEstaContenida(char* inputList1, char* inputList2)
{
	int largoLista1;
	int largoLista2;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	Pila<int> *p1 = FrameworkA1::ConvertirAPila(lista1);
	Pila<int> *p2 = FrameworkA1::ConvertirAPila(lista2);

	bool res = EstaContenida<int>(p1, p2);

	if (res)
	{
		cout << "Esta contenida" << endl;			
	}
	else
	{
		cout << "No esta contenida" << endl;			
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	
	delete p1;
	delete p2;
}

void pruebaUnionListaOrd(char* inputList1, char* inputList2)
{
	int largoLista1;
	int largoLista2;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	ListaOrd<int> *l1 = FrameworkA1::ConvertirAListaOrd(lista1);
	ListaOrd<int> *l2 = FrameworkA1::ConvertirAListaOrd(lista2);

	ListaOrd<int> *res = UnionListaOrd<int>(l1, l2);

	cout << *res << endl;

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);

	delete l1;
	delete l2;

	delete res;
}

void pruebaEnlistar(char* inputTree)
{
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);

	ListaOrd<int> *res = Enlistar(arbol);

	cout << *res << endl;

	FrameworkA1::destruir(arbol);
	delete res;
}

void pruebaCantidadDeHojas(char* inputTree)
{
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);

	int res = CantidadDeHojas(arbol);

	cout << "Cantidad de hojas: " << res << endl;
	FrameworkA1::destruir(arbol);
}

void pruebaImprimirPorNiveles(char* inputTree)
{
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);

	ImprimirPorNiveles(arbol);
	FrameworkA1::destruir(arbol);
}

