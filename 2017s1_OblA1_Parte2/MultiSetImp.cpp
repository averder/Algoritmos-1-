#include "MultiSetImp.h"

#ifndef MULTISET_IMP_CPP
#define MULTISET_IMP_CPP

template <class T>
MultiSetImp<T>::MultiSetImp() { 
	// NO IMPLEMENTADA
}

template <class T>
MultiSetImp<T>::MultiSetImp(const MultiSet<T> &multiSet) { 
	// NO IMPLEMENTADA
}

template <class T>
MultiSetImp<T>::MultiSetImp(const MultiSetImp<T> &multiSet) { 
	// NO IMPLEMENTADA
}

template <class T>
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSet<T> &multiSet) { 
	if (this != &multiSet) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSetImp<T> &multiSet) { 
	if (this != &multiSet) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
bool MultiSetImp<T>::operator==(const MultiSet<T> &multiSet) const {
	// NO IMPLEMENTADA
	return false;
}

template <class T>
MultiSetImp<T>::~MultiSetImp() { 
	// NO IMPLEMENTADA
}

template <class T>
void MultiSetImp<T>::Insertar(const T &e, unsigned int cantidad) { 
	// NO IMPLEMENTADA
}

template <class T>
void MultiSetImp<T>::Borrar(const T &e, unsigned int cantidad) {
	// NO IMPLEMENTADA
}

template <class T>
const T& MultiSetImp<T>::Elemento() const {
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& MultiSetImp<T>::Recuperar(const T &e) const {
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
unsigned int MultiSetImp<T>::OcurrenciasElemento(const T &e) const {
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool MultiSetImp<T>::Pertenece(const T &e) const { 
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void MultiSetImp<T>::Vaciar() { 
	// NO IMPLEMENTADA
}

template <class T>
bool MultiSetImp<T>::EsVacia() const {
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool MultiSetImp<T>::EsLlena() const { 
	// NO IMPLEMENTADA
	return false;
}

template <class T>
unsigned int MultiSetImp<T>::Cardinal() const { 
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Union(MultiSet<T>& s) const
{
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Interseccion(MultiSet<T>& s) const
{
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();
}
 
template <class T>
MultiSet<T>* MultiSetImp<T>::Diferencia(MultiSet<T>& s) const
{
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();
}
 
template <class T>
bool MultiSetImp<T>::ContenidoEn(const MultiSet<T> &s) const
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Clon() const { 
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();
}

template <class T>
MultiSet<T>* MultiSetImp<T>::CrearVacia() const { 
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();
}

template<class T>
void MultiSetImp<T>::Imprimir(ostream& o) const
{
	// NO IMPLEMENTADA
	// Imprimir los elementos con cout separados por espacio ordenados de menor a mayor
}

#endif
