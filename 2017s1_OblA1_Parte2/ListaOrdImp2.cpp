#include "ListaOrdImp2.h"

#ifndef LISTAORDIMP2_CPP
#define LISTAORDIMP2_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaOrdImp2<T> &l) 
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaOrd<T>* ListaOrdImp2<T>::CrearVacia() const 
{
	return new ListaOrdImp2<T>();
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2()
{
	// NO IMPLEMENTADA
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrd<T> &l) 
{
	// NO IMPLEMENTADA
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrdImp2<T> &l) 
{
	// NO IMPLEMENTADA
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrd<T> &l) 
{ 
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrdImp2<T> &l) 
{ 
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
ListaOrdImp2<T>::~ListaOrdImp2()
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::AgregarOrd(const T &e) 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::BorrarMinimo() 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	// NO IMPLEMENTADA
}

template <class T>
const T& ListaOrdImp2<T>::Minimo() const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const 
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void ListaOrdImp2<T>::Vaciar() 
{
	// NO IMPLEMENTADA
}

template <class T>
unsigned int ListaOrdImp2<T>::CantidadElementos()const 
{ 
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool ListaOrdImp2<T>::EsVacia()const 
{
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool ListaOrdImp2<T>::EsLlena()const 
{ 
	// NO IMPLEMENTADA
	return false;
}

template<class T>
ListaOrd<T>* ListaOrdImp2<T>::Clon() const
{
	// NO IMPLEMENTADA
	return new ListaOrdImp2<T>();
}

template <class T>
Iterador<T> ListaOrdImp2<T>::GetIterador() const 
{
	// NO IMPLEMENTADA

	ListaPosImp<T> l;
	// SUGERENCIA: aqui cargar en l con los elementos de this ordenados de menor a mayor (con funcion auxiliar)
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}


#endif