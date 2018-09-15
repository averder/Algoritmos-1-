#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

template <class T>
ostream & operator<<<>(ostream &out, const ListaPosImp<T>& l)
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

template <class T>
ListaPosImp<T>::ListaPosImp()
{
	// NO IMPLEMENTADA
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	// NO IMPLEMENTADA
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	// NO IMPLEMENTADA
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e) 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e) 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::BorrarFin()
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::Borrar(const T &e)
{
	// NO IMPLEMENTADA
}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void ListaPosImp<T>::Vaciar()
{
	// NO IMPLEMENTADA
}

template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{ 
	// NO IMPLEMENTADA
	return 0; 
}

template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	// NO IMPLEMENTADA
	return new ListaPosImp<T>();
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}

#endif