#include "SetImp.h"
#ifndef SETIMP_CPP
#define SETIMP_CPP


template <class T>
SetImp<T>::SetImp(){
	// NO IMPLEMENTADA
}

template <class T>
SetImp<T>::SetImp(const Set<T> &s) {
	// NO IMPLEMENTADA
}

template <class T>
SetImp<T>::SetImp(const SetImp<T> &s) {
	// NO IMPLEMENTADA
}

template <class T>
Set<T> &SetImp<T>::operator=(const Set<T> &s) { 
	if (this != &s) {
		// NO IMPLEMENTADA
	}
		return *this;
}

template <class T>
Set<T> &SetImp<T>::operator=(const SetImp<T> &s) { 
	if (this != &s) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template <class T>
bool SetImp<T>::operator==(const Set<T> &s) const {
	// NO IMPLEMENTADA
	return false;
}

template <class T>
SetImp<T>::~SetImp(){
	// NO IMPLEMENTADA
}

template <class T>
void SetImp<T>::Insertar(const T &e){
	// NO IMPLEMENTADA
}

template <class T>
void SetImp<T>::Borrar(const T &e){
	// NO IMPLEMENTADA
}

template <class T>
const T& SetImp<T>::Elemento() const{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& SetImp<T>::Recuperar(const T &e) const{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
bool SetImp<T>::Pertenece(const T &e) const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void SetImp<T>::Vaciar(){
	// NO IMPLEMENTADA
}

template <class T>
bool SetImp<T>::EsVacia() const{
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool SetImp<T>::EsLlena() const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
unsigned int SetImp<T>::Cardinal() const{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
Set<T>* SetImp<T>::Union(Set<T>& s) const
{
	// NO IMPLEMENTADA
	return new SetImp<T>();
}

template <class T>
Set<T>* SetImp<T>::Interseccion(Set<T>& s) const
{
	// NO IMPLEMENTADA
	return new SetImp<T>();
}
 
template <class T>
Set<T>* SetImp<T>::Diferencia(Set<T>& s) const
{
	// NO IMPLEMENTADA
	return new SetImp<T>();
}
 
template <class T>
bool SetImp<T>::ContenidoEn(const Set<T> &s) const
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
Set<T>* SetImp<T>::Clon() const{
	// NO IMPLEMENTADA
	return new SetImp<T>();
}

template <class T>
Set<T>* SetImp<T>::CrearVacia() const{
	// NO IMPLEMENTADA
	return new SetImp<T>();
}

template<class T>
void SetImp<T>::Imprimir(ostream& o) const
{
	// NO IMPLEMENTADA
	// Imprimir los elementos con cout separados por espacio ordenados de menor a mayor
}


#endif