#include "DiccionarioImp.h"

#ifndef DICCIONARIOIMP_CPP
#define DICCIONARIOIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const DiccionarioImp<T> &d) {
	p.Imprimir(out);
	return out;
}

template <class T>
DiccionarioImp<T>::DiccionarioImp(){
	// NO IMPLEMENTADA
}

template <class T>
DiccionarioImp<T>::DiccionarioImp(const Diccionario<T> &d){
	// NO IMPLEMENTADA
}

template<class T>
DiccionarioImp<T>::DiccionarioImp(const DiccionarioImp<T> &d){
	// NO IMPLEMENTADA
}

template <class T>
Diccionario<T>& DiccionarioImp<T>::operator=(const Diccionario<T> &d){
	if(this!= &d){
		// NO IMPLEMENTADA
	}

	return *this;
}

template <class T>
Diccionario<T>& DiccionarioImp<T>::operator=(const DiccionarioImp<T> &d){
	if(this!= &d){
		// NO IMPLEMENTADA
	}

	return *this;
}
	
template<class T>
DiccionarioImp<T>::~DiccionarioImp(){
	// NO IMPLEMENTADA
}

template<class T>
Diccionario<T>* DiccionarioImp<T>::CrearVacia() const {
	// NO IMPLEMENTADA
	return new DiccionarioImp<T>();
}

template<class T>
void DiccionarioImp<T>::Insertar(const T& e){
	// NO IMPLEMENTADA
}

template <class T>
void DiccionarioImp<T>::Borrar(const T& e){
	// NO IMPLEMENTADA
}

template <class T>
const T& DiccionarioImp<T>::Elemento() const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
bool DiccionarioImp<T>::Pertenece(const T& e) const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void DiccionarioImp<T>::Vaciar(){
	// NO IMPLEMENTADA
}
	
template <class T>
unsigned int DiccionarioImp<T>::Cardinal() const{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool DiccionarioImp<T>::EsVacia() const{
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool DiccionarioImp<T>::EsLlena() const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
Diccionario<T>* DiccionarioImp<T>::Clon()const{
	// NO IMPLEMENTADA
	return new DiccionarioImp<T>();
}

template <class T>
bool DiccionarioImp<T>::ContenidoEn(const Diccionario<T> &d) const 
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
bool DiccionarioImp<T>::operator==(const Diccionario<T> &d)
{
	// NO IMPLEMENTADA
	return false;
}

template<class T>
void DiccionarioImp<T>::Imprimir(ostream& o) const
{
	// NO IMPLEMENTADA
	// Imprimir los elementos con cout separados por espacio ordenados de menor a mayor
}

#endif